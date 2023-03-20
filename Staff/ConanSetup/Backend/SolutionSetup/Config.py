# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

class Config:
    def __init__(self, solutionFilePath: str, ideParamsPath: str, propsFile: str) -> None:
        self.solutionFilePath: str = solutionFilePath
        self.ideParamsPath: str = ideParamsPath
        self.propsFile: str = propsFile
