import subprocess;
import time;

#########################################################
# First Slave, for Clients
#########################################################
if 1 :
	port = 9000;
	
	cmd  = "start Tornado.exe -v 0 -r s -d ..\..\Developer\DLL\DeveloperDLL.dll -p port %d" % port;
	PIPE = subprocess.PIPE;
	p = subprocess.Popen(cmd, shell = True);
	time.sleep(1.0)


#########################################################
# Second Slave
#########################################################
if 1 :
	port = 1235;
	
	cmd  = "start Tornado.exe -v 0 -r s -d ..\..\Developer\DLL\DeveloperDLL.dll -p port %d" % port;
	PIPE = subprocess.PIPE;
	p = subprocess.Popen(cmd, shell = True);

