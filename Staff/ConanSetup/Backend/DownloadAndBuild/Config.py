# Author: Gudakov Ramil Sergeevich a.k.a. Gauss
# Гудаков Рамиль Сергеевич
# Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
# See for more information LICENSE.md.

import datetime

class Profile:
    def __init__(self, arch: str, build_type: str, compiler: str, compiler_cppstd: str, 
                 compiler_runtime: str, compiler_runtime_type: str, compiler_version: str, os: str) -> None:
        self.arch = arch # 'x86_64'
        self.build_type = build_type # 'Debug'
        self.compiler = compiler # 'msvc'
        self.compiler_cppstd = compiler_cppstd # '14'
        self.compiler_runtime = compiler_runtime # 'dynamic'
        self.compiler_runtime_type = compiler_runtime_type # 'Debug'
        self.compiler_version = compiler_version # '193'       
        self.os = os # 'Windows'

class PackageInfo:
    def __init__(self, name: str, version: str, shared: bool) -> None:
        self.name: str = name
        self.version: str = version
        self.shared: bool = shared

class Config:
    def __init__(self, packages: list[PackageInfo], profile: Profile, resultFileName: str, debugFlag: bool, forceRebuild: bool) -> None:
        self.packages: list[PackageInfo] = []
        for p in packages:
            self.packages.append(PackageInfo(**p))
        self.profile: Profile = Profile(**profile)
        self.resultFileName: str = resultFileName
        self.debugFlag: bool = debugFlag
        self.forceRebuild: bool = forceRebuild

class PackageResult:
    def __init__(self, includeDir: str = "", libDir: str = "", binDir: str = "") -> None:
        self.includeDir: str = includeDir
        self.libDir: str = libDir
        self.binDir: str = binDir

class Result:
    def __init__(self, date: str = str(datetime.datetime.now()), packages: dict[str, PackageResult] = {}) -> None:
        self.date: str = date
        self.packages: dict[str, PackageResult] = {}
        for key, value in packages.items():
            self.packages[key] = PackageResult(**value)
