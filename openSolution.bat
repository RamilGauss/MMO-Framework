set PATH=%PATH%;%DEP_PATH_MMO_FRAMEWORK%\Bin;

xcopy %DEP_PATH_MMO_FRAMEWORK%\Bin\*.dll .\Exe /Y

start MMOFramework.sln