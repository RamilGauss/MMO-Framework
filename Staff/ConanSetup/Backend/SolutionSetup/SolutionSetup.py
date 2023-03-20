# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import json
from bs4 import BeautifulSoup

from Backend.Common.IdeParams import *
from Backend.Utils.Relative import *
from Backend.SolutionSetup.Config import *

class SolutionSetup:
    def __init__(self) -> None:
        self.absConfigPath: str
        self.config: Config
        self.ideParams: IdeParams

    def Setup(self, configPath: str):
        self.absConfigPath = configPath

        with open(configPath, 'r') as file:
            j = file.read().replace('\n', '')
            d = json.loads(j)
            self.config = Config(**d)

        ideParamsAbsPath = Relative.Convert(self.absConfigPath, self.config.ideParamsPath)
        
        with open(ideParamsAbsPath, 'r') as file:
            j = file.read().replace('\n', '')
            d = json.loads(j)
            self.ideParams = IdeParams(**d)

        solutionAbsPath = Relative.Convert(self.absConfigPath, self.config.solutionFilePath)

        projectPaths: list[str] = []

        with open(solutionAbsPath, 'r') as file:
            lines = file.readlines()
            for line in lines:

                projectExt = ".vcxproj\""

                if "Project" in line and projectExt in line:
                    projIndex = line.find(projectExt)
                    beginIndex = line.rfind("\"", 0, projIndex)
                    projectPath = line[beginIndex + 1:projIndex + len(projectExt) - 1]
                    projectAbsPath = Relative.Convert(solutionAbsPath, projectPath)

                    projectPaths.append(projectAbsPath)

        propsAbsFilePath = Relative.Convert(self.absConfigPath, self.config.propsFile)

        for project in projectPaths:

            relConanPropsPath = Relative.RelativePath(project, propsAbsFilePath)

            soup: BeautifulSoup
            isEdited: bool = False
            with open(project, 'r') as file:
                content = file.read()
                soup = BeautifulSoup(content, 'xml')
            projectTag = soup.find_all("ItemDefinitionGroup")

            # Project linker and compiler configs
            for prTag in projectTag:
                clCompileTag = prTag.find("ClCompile")
                addDir = clCompileTag.find("AdditionalIncludeDirectories")
                addDirText = addDir.get_text()

                includeMacrosText = f"$({self.ideParams.includeMacros})"
                if not includeMacrosText in addDirText:
                    addDir.string = includeMacrosText + ";" + addDirText
                    isEdited = True

                link = prTag.find("Link")
                addDep = link.find("AdditionalDependencies")
                if addDep is None:
                    addDep = soup.new_tag("AdditionalDependencies")
                    addDep.string = f"$({self.ideParams.libMacros})"
                    link.insert(1, addDep)
                    isEdited = True
                else:
                    addDepText = addDep.get_text()
                    libMacrosText = f"$({self.ideParams.libMacros})"
                    if not libMacrosText in addDepText:
                        addDep.string = libMacrosText + ";" + addDepText
                        isEdited = True
                
            importGroupTag = soup.find_all("ImportGroup")

            # Add a ref to the props
            for importGroup in importGroupTag:
                if importGroup.has_attr("Label") and importGroup.attrs["Label"] == "PropertySheets":
                    importProps = importGroup.find_all("Import")
                    hasProps = False
                    for importProp in importProps:
                        if importProp.has_attr("Project") and importProp.attrs["Project"] == self.config.propsFile:
                            hasProps = True
                            break
                    if not hasProps:
                        importProps = soup.new_tag("Import")
                        importProps.attrs["Project"] = relConanPropsPath
                        importGroup.insert(1, importProps)
                        isEdited = True

            if isEdited:
                with open(project, 'w') as file:
                    file.write(str(soup))