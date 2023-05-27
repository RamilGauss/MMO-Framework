# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

class IdeParams:
    def __init__(self, vsVersion: str, includeMacros: str, libMacros: str, preprocessorMacros: str) -> None:
        self.vsVersion: str = vsVersion
        self.includeMacros: str = includeMacros
        self.libMacros: str = libMacros
        self.preprocessorMacros: str = preprocessorMacros