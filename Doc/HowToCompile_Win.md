How to compile project in Windows 7/8/10 x64.

Visual Studio 2022 Community [download link](https://visualstudio.microsoft.com/ru/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&passive=false&cid=2030)
    
1. Install [cmake](https://cmake.org/download/) for build dependenices.
2. Install [python](https://www.python.org/downloads/) with `pip`.
3. Run script at `MMO-Framework\Staff\ConanSetup\Scripts\installDeps.bat`, who installs `pip` requirements (also includes [conan](https://conan.io)).
4. Run script at `MMO-Framework\Staff\Script\install_deps.bat`, who installs project dependencies via `conan`.
5. Open `MMOFramework.sln`, then `Set as Startup project` `Core/Launcher`. 
6. Build `Core/Launcher` and then `Tools/TornadoEditor`.
7. In project `Core/Launcher` in field Debugging->Command arguments set `$(SolutionDir)\Source\Tools\TornadoEditor\Editor.project`.
8. Run `Core/Launcher`.
