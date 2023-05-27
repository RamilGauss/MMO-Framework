# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

from Backend.DownloadAndBuild.Downloader import *
from Backend.PropsGenerator.Generator import *
from Backend.Copy.Worker import *
from Backend.SolutionSetup.SolutionSetup import *

if __name__ == '__main__':
    # 1. DownloadNadBuild
    absPath = os.path.abspath(".\\install_instruction.json")
    downloader = Downloader()
    downloader.Setup(absPath)

    # 2. GenerateProps
    absPath = os.path.abspath(".\\props_generator_config.json")
    generator = Generator()
    generator.Setup(absPath)

    # 3. Copy libs and dlls // Libs and Bins Dirs
    absPath = os.path.abspath(".\\copy_paths.json")
    worker = Worker()
    worker.Setup(absPath)

    # 4. SetupSolution
    absPath = os.path.abspath(".\\solution_setup.json")
    solutionSetup = SolutionSetup()
    solutionSetup.Setup(absPath)
