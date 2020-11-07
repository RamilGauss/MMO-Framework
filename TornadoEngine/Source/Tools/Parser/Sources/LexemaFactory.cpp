/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "LexemaFactory.h"

#include "EmptyLexema.h"
#include "NamespaceLexema.h"
#include "ClassLexema.h"
#include "StructLexema.h"
#include "AccessLexema.h"
#include "EnumLexema.h"
#include "FriendLexema.h"
#include "MethodDefinitionLexema.h"
#include "MethodDeclarationLexema.h"
#include "MemberLexema.h"
#include "FunctionDefinitionLexema.h"
#include "FunctionDeclarationLexema.h"
#include "PragmaLexema.h"
#include "IdentifierLexema.h"

using namespace nsCppParser;

ILexema* TLexemaFactory::New(ILexema::LexemaType lexemaType)
{
    ILexema* newLexema = nullptr;

    switch (lexemaType) {
        case ILexema::LexemaType::EMPTY:
            newLexema = new TEmptyLexema();
            break;
        case ILexema::LexemaType::NAMESPACE:
            newLexema = new TNamespaceLexema();
            break;
        case ILexema::LexemaType::ACCESS:
            newLexema = new TAccessLexema();
            break;
        case ILexema::LexemaType::CLASS:
            newLexema = new TClassLexema();
            break;
        case ILexema::LexemaType::STRUCT:
            newLexema = new TStructLexema();
            break;
        case ILexema::LexemaType::ENUM:
            newLexema = new TEnumLexema();
            break;
        case ILexema::LexemaType::FUNCTION_DECLARATION:
            newLexema = new TFunctionDeclarationLexema();
            break;
        case ILexema::LexemaType::FUNCTION_DEFINITION:
            newLexema = new TFunctionDefinitionLexema();
            break;
        case ILexema::LexemaType::MEMBER:
            newLexema = new TMemberLexema();
            break;
        case ILexema::LexemaType::METHOD_DECLARATION:
            newLexema = new TMethodDeclarationLexema();
            break;
        case ILexema::LexemaType::METHOD_DEFINITION:
            newLexema = new TMethodDefinitionLexema();
            break;
        case ILexema::LexemaType::FRIEND:
            newLexema = new TFriendLexema();
            break;
        case ILexema::LexemaType::PRAGMA:
            newLexema = new TPragmaLexema();
            break;        
        case ILexema::LexemaType::IDENTIFIER:
            newLexema = new TIdentifierLexema();
            break;
        default:
            break;
    }

    return newLexema;
}
