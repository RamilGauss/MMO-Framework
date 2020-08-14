/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#if 1

#include "SingletonManager.h"
#include "Config.h"
#include "TokenInfoManager.h"
#include "TokenInfo.h"
#include "Parser.h"
#include "ConfigContainer.h"
#include "Requirements.h"
#include "readerwriterqueue.h"
#include "TypeManager.h"
#include "CodeGeneratorFusion.h"
#include "fmt/core.h"
#include "MemberTypeExtendedInfoAnalyzer.h"
#include "SetupConfig.h"
#include "ProgramInfo.h"

#include "HiTimer.h"
#include "TestClass.h"

#include "DstEvent.h"


#include <iostream>
#include <string>
#include <cstdlib>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/printf.h>

#include <iostream>
#include <clang-c/Index.h>


using namespace nsReflectionCodeGenerator;
using namespace boost::wave;

using namespace moodycamel;
void TestQueue()
{
    ReaderWriterQueue<int> q(100);       // Reserve space for at least 100 elements up front

    q.enqueue(17);                       // Will allocate memory if the queue is full
    bool succeeded = q.try_enqueue(18);  // Will only succeed if the queue has an empty slot (never allocates)
    assert(succeeded);

    int number;
    succeeded = q.try_dequeue(number);  // Returns false if the queue was empty

    assert(succeeded && number == 17);

    // You can also peek at the front item of the queue (consumer only)
    int* front = q.peek();
    assert(*front == 18);
    succeeded = q.try_dequeue(number);
    assert(succeeded && number == 18);
    front = q.peek();
    assert(front == nullptr);           // Returns nullptr if the queue was empty
}
//---------------------------------------------------------------------------------------
void ShowTitle()
{
    fmt::print("{} version {} build {}\n", nsProgramInfo::NAME, nsProgramInfo::VERSION, nsProgramInfo::COUNTER_BUILD);
}
//---------------------------------------------------------------------------------------
void ClangExp()
{
    const char* command_line_args[] = { "-x", "c++" };

    CXIndex index = clang_createIndex(false, // excludeDeclarationFromPCH
        true   // displayDiagnostics  
    );
    CXTranslationUnit unit = clang_parseTranslationUnit(
        index,                           // CIdx
        "./Sources/BaseStruct.h",                      // source_filename
        command_line_args,                        // command_line_args
        2,                        // num_command_line_args
        0,                                // unsave_files
        0,                                // num_unsaved_files
        CXTranslationUnit_None // options
    );
    if ( unit != 0 )
        std::cout << "Translation unit successfully created" << std::endl;
    else
        std::cout << "Translation unit was not created" << std::endl;

    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);
}
//---------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    //###
    //ClangExp();
    //###

    ShowTitle();

    TSetupConfig setupConfig;
    if ( setupConfig.Work() == false )
        return 0;

    TParser parser;
    parser.Work();

    // дополнить расширенной информацией
    TMemberTypeExtendedInfoAnalyzer analyzer;
    analyzer.Work();

    TCodeGeneratorFusion cgFusion;
    cgFusion.Work();
    return 0;
}

#else

#include <iostream>
#include <clang-c/Index.h>
#include <clang-c/Platform.h>


void printDiagnostics(CXTranslationUnit translationUnit);
void printTokenInfo(CXTranslationUnit translationUnit, CXToken currentToken);
void printCursorTokens(CXTranslationUnit translationUnit, CXCursor currentCursor);

CXChildVisitResult cursorVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data);
CXChildVisitResult functionDeclVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data);

int main(int argc, const char* argv[])
{
    CXIndex index = clang_createIndex(false, true);

    if ( index == 0 ) {
        fprintf(stderr, "error creating index\n");
        return 1;
    }

    const char* command_line_args[] = { "-x", "c++" };

    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, "./Sources/BaseStruct.h",
        command_line_args, 2, 0, 0, CXTranslationUnit_None);

    if ( translationUnit == 0 ) {
        fprintf(stderr, "error creating translationUnit\n");
        return 1;
    }

    printDiagnostics(translationUnit);


    CXCursor rootCursor = clang_getTranslationUnitCursor(translationUnit);

    printCursorTokens(translationUnit, rootCursor);

    unsigned int res = clang_visitChildren(rootCursor, *cursorVisitor, 0);

    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
    return 0;
}

void printDiagnostics(CXTranslationUnit translationUnit)
{
    int nbDiag = clang_getNumDiagnostics(translationUnit);
    printf("There is %i diagnostics\n", nbDiag);

    for ( unsigned int currentDiag = 0; currentDiag < nbDiag; ++currentDiag ) {
        CXDiagnostic diagnotic = clang_getDiagnostic(translationUnit, currentDiag);
        CXString errorString = clang_formatDiagnostic(diagnotic, clang_defaultDiagnosticDisplayOptions());
        fprintf(stderr, "%s\n", clang_getCString(errorString));
        clang_disposeString(errorString);
    }
}

void printTokenInfo(CXTranslationUnit translationUnit, CXToken currentToken)
{
    CXString tokenString = clang_getTokenSpelling(translationUnit, currentToken);
    CXTokenKind kind = clang_getTokenKind(currentToken);

    switch ( kind ) {
        case CXToken_Comment:
            printf("Token : %s \t| COMMENT\n", clang_getCString(tokenString));
            break;
        case CXToken_Identifier:
            printf("Token : %s \t| IDENTIFIER\n", clang_getCString(tokenString));
            break;
        case CXToken_Keyword:
            printf("Token : %s \t| KEYWORD\n", clang_getCString(tokenString));
            break;
        case CXToken_Literal:
            printf("Token : %s \t| LITERAL\n", clang_getCString(tokenString));
            break;
        case CXToken_Punctuation:
            printf("Token : %s \t| PUNCTUATION\n", clang_getCString(tokenString));
            break;
        default:
            break;
    }
}

void printCursorTokens(CXTranslationUnit translationUnit, CXCursor currentCursor)
{
    CXToken* tokens;
    unsigned int nbTokens;
    CXSourceRange srcRange;

    srcRange = clang_getCursorExtent(currentCursor);

    clang_tokenize(translationUnit, srcRange, &tokens, &nbTokens);

    for ( int i = 0; i < nbTokens; ++i ) {
        CXToken currentToken = tokens[i];

        printTokenInfo(translationUnit, currentToken);
    }

    clang_disposeTokens(translationUnit, tokens, nbTokens);
}

CXChildVisitResult cursorVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{

    CXCursorKind kind = clang_getCursorKind(cursor);
    CXString name = clang_getCursorSpelling(cursor);
    if ( kind == CXCursor_FunctionDecl || kind == CXCursor_ObjCInstanceMethodDecl ) {
        printf("method '%s'\n", clang_getCString(name));

        // visit method childs
        int nbParams = 0;
        clang_visitChildren(cursor, *functionDeclVisitor, &nbParams);

        printf("nb Params : %i'\n", nbParams);


        CXSourceLocation location = clang_getCursorLocation(cursor);

        CXString filename;
        unsigned int line, column;

        clang_getPresumedLocation(location, &filename, &line, &column);

        printf("source location : %s, (%i,%i)\n", clang_getCString(filename), line, column);
        return CXChildVisit_Continue;
    }
    //printf("cursor '%s' -> %i\n",clang_getCString(name),kind);
    return CXChildVisit_Recurse;
}

CXChildVisitResult functionDeclVisitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
    CXCursorKind kind = clang_getCursorKind(cursor);
    CXType type = clang_getCursorType(cursor);

    if ( kind == CXCursor_ParmDecl ) {
        CXString name = clang_getCursorSpelling(cursor);
        printf("\tparameter: '%s' of type '%i'\n", clang_getCString(name), type.kind);
        int* nbParams = (int*) client_data;
        (*nbParams)++;
    }

    return CXChildVisit_Continue;

}
#endif