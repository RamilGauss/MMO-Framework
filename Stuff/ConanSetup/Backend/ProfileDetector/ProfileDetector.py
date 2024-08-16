# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import os
import subprocess

class ProfileDetector:
    def Setup(self, absPath):
        os.environ["CONAN_HOME"] = absPath
        os.environ["CONAN_USER_HOME"] = absPath

        cmd = ["conan", "profile", "detect"]
        subprocess.run(cmd, stdout=subprocess.PIPE)
