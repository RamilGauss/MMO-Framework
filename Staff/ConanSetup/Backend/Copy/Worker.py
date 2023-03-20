# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import json
import shutil

from Backend.Utils.Relative import *
from Backend.Copy.Config import *
from Backend.DownloadAndBuild.Config import Result

class Worker:

    def __init__(self) -> None:
        self.absConfigPath: str
        self.config: Config
        self.installResults: Result

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


        binDirs: list[str] = []
        libDirs: list[str] = []

        for name, dirs in self.installResults.packages.items():
            if os.path.exists(dirs.binDir):
                for filename in os.listdir(dirs.binDir):
                    f = os.path.join(dirs.binDir, filename)
                    file_name, file_extension = os.path.splitext(f)
                    if os.path.isfile(f) and file_extension == ".dll":
                        binDirs.append(f)

            if os.path.exists(dirs.libDir):
                for filename in os.listdir(dirs.libDir):
                    f = os.path.join(dirs.libDir, filename)
                    if os.path.isfile(f):
                        libDirs.append(f)

        binAbsDirPath = Relative.Convert(self.absConfigPath, self.config.binDir)

        for b in binDirs:
            dst = os.path.join(binAbsDirPath, os.path.basename(b))
            shutil.copyfile(b, dst)

        libAbsDirPath = Relative.Convert(self.absConfigPath, self.config.libDir)

        for l in libDirs:
            dst = os.path.join(libAbsDirPath, os.path.basename(l))
            shutil.copyfile(l, dst)