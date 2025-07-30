set PATH=%PATH%;%DEP_PATH_MMO_FRAMEWORK%\Bin
start ..\..\build/Debug/ReflectionCodeGenerator.exe "..\..\Source\Core\TornadoEngine\Configs\ReflectionConfig.json"
@REM start ..\..\build/Debug/ContainerCodeGenerator_d.exe core "..\..\Source\Core\TornadoEngine\Configs\CoreContainerConfig.json"