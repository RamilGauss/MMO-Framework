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

#include "ContainerCodeGeneratorLib/Sources/GeneratedFiles/JsonSerializer.h"

#include "ContainerCodeGenerator/Sources/ConfigPrefabs.h"

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
        ("type,t", po::value<std::string>(), "type of task, [core, project]")
        ("path_setting,p", po::value<std::string>(), "content of path setting (see nsContainerCodeGenerator::TPathSetting) in json format")
        ("project_namespace,n", po::value<std::string>(), "project namespace");

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
    std::string pathSettingJson;
    if (vm.count("path_setting")) {
        pathSettingJson = vm["path_setting"].as<std::string>();
    }
    if (type.empty() || pathSettingJson.empty()) {
        std::cout << desc << std::endl;
        return -3;
    }
    std::string projectNameSpace;
    if (type == "project") {
        projectNameSpace = vm["project_namespace"].as<std::string>();
        if (projectNameSpace.empty()) {
            std::cout << desc << std::endl;
            return -4;
        }
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

    nsContainerCodeGenerator::TPathSetting pathSetting;
    std::string err;
    auto deserRes = nsContainerCodeGenerator::TJsonSerializer::Deserialize(&pathSetting, pathSettingJson, err);
    if (deserRes == false) {
        std::cout << "Fail with deserilize" << pathSettingJson << ", cause " << err << std::endl;
        return -5;
    }

    TConfigPrefabs configPrefabs;
    auto coreConfig = configPrefabs.MakeCoreDefault();
    auto projectConfig = configPrefabs.MakeProjectDefault(projectNameSpace);
    return static_cast<int>(ccg->Generate(pathSetting, coreConfig, projectConfig));
}
