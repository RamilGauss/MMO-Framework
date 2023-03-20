# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import os
import sys

sys.path.insert(0, ".")

from Backend.SolutionSetup.SolutionSetup import *

if __name__ == '__main__':

    if len(sys.argv) != 1:
        absPath = os.path.abspath(sys.argv[1])

        solutionSetup = SolutionSetup()
        solutionSetup.Setup(absPath)
    else:
        print("Not have enough args. Example: xxx ./p.json\n")
