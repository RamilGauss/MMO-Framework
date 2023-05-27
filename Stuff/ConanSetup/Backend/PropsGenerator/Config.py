# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

class Config:
    def __init__(self, propsFile: str, installResult: str, ideParamsPath: str) -> None:
        self.propsFile: str = propsFile
        self.installResult: str = installResult
        self.ideParamsPath: str = ideParamsPath
