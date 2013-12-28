set QMAKESPEC=win32-msvc2008
set QTDIR=C:\qt\4.5.0.vc2008
set PATH=%PATH%;%QTDIR%\bin;

start Tornado.exe -v 0 -r m -d ..\..\Developer\DLL\DeveloperDLL.dll -p "ip 192.168.23.226 port 1236"