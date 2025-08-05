set PATH=%PATH%;%DEP_PATH_MMO_FRAMEWORK%\Bin
@REM start ..\..\build/Debug/ReflectionCodeGenerator.exe "..\..\Source\Core\TornadoEngine\Configs\ReflectionConfig.json"
start ..\..\build/Debug/ContainerCodeGenerator.exe core "..\..\Source\Core\TornadoEngine\Configs\CoreContainerConfig.json"