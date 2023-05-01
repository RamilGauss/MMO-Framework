How to compile project in Windows 7/8/10 x64.

[Visual Studio 2022 Community]()
    
1. Install [cmake]() for build dependenices.
2. Install [python]() with `pip`.
3. Run script at `MMO-Framework\Staff\ConanSetup\Scripts\installDeps.bat`, who installs `pip` requirements.
4. Run script at `MMO-Framework\Staff\Script\install_deps.bat`, who installs project dependencies via [conan]().
5. Open `MMOFramework.sln`, then Set as Startup project `Core/Launcher`. 
6. Build `Core/Launcher` and then `Tools/TornadoEditor`.
7. In project `Core/Launcher` in field Debugging->Command arguments set `$(SolutionDir)\Source\Tools\TornadoEditor\Editor.project`.
8. Run `Core/Launcher`.
