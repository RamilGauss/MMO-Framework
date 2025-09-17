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

int main(int argc, char* argv[])
{
    const char* sLocale = setlocale(LC_CTYPE, "");
    sLocale = setlocale(LC_CTYPE, sLocale);
    if (sLocale == nullptr) {
        BL_FIX_BUG();
        return -1;
    }
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "Help")
        ("type,t", po::value<std::string>(), "type of task")
        ("task_file,f", po::value<std::string>(), "path to task file")
        ("common_options,c", po::value<std::string>(), "content of common options in json format");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (const po::error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << "Example:\n" << desc << std::endl;
        return 1;
    }
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return -2;
    }
    std::string type;
    if (vm.count("type")) {
        type = vm["type"].as<std::string>();
    }
    std::string taskFile;
    if (vm.count("task_file")) {
        taskFile = vm["task_file"].as<std::string>();
    }
    std::string commonOptions;
    if (vm.count("common_options")) {
        commonOptions = vm["common_options"].as<std::string>();
    }
    if (type.empty() || taskFile.empty() || commonOptions.empty()) {
        std::cout << desc << std::endl;
        return -3;
    }
    std::shared_ptr<nsContainerCodeGenerator::TContainerCodeGenerator> ccg;
    if (type == "core") {
        ccg = std::make_shared<nsContainerCodeGenerator::TCoreContainerCodeGenerator>();
    } else if (type == "project") {
        ccg = std::make_shared<nsContainerCodeGenerator::TProjectContainerCodeGenerator>();
    } else {
        std::cout << desc << std::endl;
        return -3;
    }
    return static_cast<int>(ccg->Generate(taskFile));
}
