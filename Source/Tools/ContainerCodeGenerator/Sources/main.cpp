/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <locale.h>

#include <boost/program_options.hpp>

#include "Base/Common/BL_Debug.h"
#include "ContainerCodeGeneratorLib/Sources/CoreContainerCodeGenerator.h"
#include "ContainerCodeGeneratorLib/Sources/ProjectContainerCodeGenerator.h"

namespace po = boost::program_options;

void PrintUsage(char* argv[])
{
    printf("usage: %s --type \"core\"|\"project\" --task_file filePath --common_options json_content", argv[0]);
}

int main(int argc, char* argv[])
{
    // const char* sLocale = setlocale(LC_CTYPE, "");
    // sLocale = setlocale(LC_CTYPE, sLocale);
    // if (sLocale == nullptr) {
    //     BL_FIX_BUG();
    //     return -1;
    // }

    // if (argc != 3) {
    //     PrintUsage(argv);
    //     return -2;
    // }

    // std::string generatorType = argv[1];
    // std::string filePath = argv[2];

    //###
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", po::value<std::string>(), "Help")
        ("type,t", po::value<std::string>(), "type of task")
        ("task_file,f", po::value<std::string>(), "path to task file")
        ("common_options,c", po::value<std::string>(), "content of common options in json format");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    if (vm.count("type")) {
        std::cout << "type: " << vm["type"].as<std::string>() << std::endl;
    }
    if (vm.count("task_file")) {
        std::cout << "task_file: " << vm["task_file"].as<std::string>() << std::endl;
    }
    if (vm.count("common_options")) {
        std::cout << "common_options: " << vm["common_options"].as<std::string>() << std::endl;
    }
    //###


    // nsContainerCodeGenerator::TContainerCodeGenerator* ccg = nullptr;
    // if (generatorType == "core") {
    //     ccg = new nsContainerCodeGenerator::TCoreContainerCodeGenerator();
    // } else if (generatorType == "project") {
    //     ccg = new nsContainerCodeGenerator::TProjectContainerCodeGenerator();
    // } else {
    //     PrintUsage(argv);
    //     return -3;
    // }
    // auto result = static_cast<int>(ccg->Generate(filePath));
    // delete ccg;

    // return result;
}