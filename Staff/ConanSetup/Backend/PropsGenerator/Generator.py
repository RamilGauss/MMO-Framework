# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import json

from Backend.Common.IdeParams import *
from Backend.PropsGenerator.Config import *
from Backend.PropsGenerator.PropsTemplate import *
from Backend.Utils.Relative import *

from Backend.DownloadAndBuild.Config import Result

class Generator:

    def __init__(self) -> None:
        self.absConfigPath: str
        self.config: Config
        self.installResults: Result
        self.ideParams: IdeParams

    def Setup(self, configPath: str):
        self.absConfigPath = configPath

        with open(configPath, 'r') as file:
            j = file.read().replace('\n', '')
            d = json.loads(j)
            self.config = Config(**d)
        
        resultAbsFileName = Relative.Convert(self.absConfigPath, self.config.installResult)
        
        with open(resultAbsFileName, 'r') as file:
            j = file.read().replace('\n', '')
            d = json.loads(j)
            self.installResults = Result(**d)

        ideParamsAbsPath = Relative.Convert(self.absConfigPath, self.config.ideParamsPath)
        
        with open(ideParamsAbsPath, 'r') as file:
            j = file.read().replace('\n', '')
            d = json.loads(j)
            self.ideParams = IdeParams(**d)

        includeDirs: str = ""
        libNames: str = ""
        preprocessorNames: str = ""

        for define in self.installResults.defines:
            preprocessorNames = preprocessorNames + define + ";"

        for name, dirs in self.installResults.packages.items():
            if os.path.exists(dirs.includeDir):
                includeDirs = includeDirs + dirs.includeDir + ";"

            if os.path.exists(dirs.libDir):
                for filename in os.listdir(dirs.libDir):
                    f = os.path.join(dirs.libDir, filename)
                    if os.path.isfile(f):
                        libNames = libNames + filename + ";"

        propsContent = PropsTemplate.GenerateForVS2022(self.ideParams.includeMacros, includeDirs, 
                                                       self.ideParams.libMacros, libNames,
                                                       self.ideParams.preprocessorMacros, preprocessorNames)
        
        propsAbsFilePath = Relative.Convert(self.absConfigPath, self.config.propsFile)

        with open(propsAbsFilePath, 'w') as file:
            file.write(propsContent)


        