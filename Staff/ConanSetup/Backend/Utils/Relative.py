# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import os

from pathlib import Path

class Relative:
    def Convert(absFilePath:str, relFilePath:str) -> str:
        if not os.path.isabs(relFilePath):
            absDirPath = Path(absFilePath).parent.absolute().__str__()
            relFilePath = os.path.join(absDirPath, relFilePath)

        return relFilePath
    
    def RelativePath(masterAbsFilePath:str, absFilePath:str) -> str:
        absDirPath = Path(masterAbsFilePath).parent.absolute().__str__()
        relativePath = os.path.relpath(absFilePath, absDirPath)
        return relativePath