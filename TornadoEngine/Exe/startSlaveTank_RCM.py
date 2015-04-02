import subprocess;
import time;

#########################################################
# First Slave, for Clients
#########################################################
if 1 :
	port = 9000;
	
	cmd  = "start Tornado_d.exe -v 2 -d DeveloperDLL_d.dll -p port_self %d" % port;
	PIPE = subprocess.PIPE;
	p = subprocess.Popen(cmd, shell = True);
	time.sleep(1.0)


#########################################################
# Second Slave
#########################################################
if 1 :
	port = 1235;
	
	cmd  = "start Tornado_d.exe -v 2 -d DeveloperDLL.dll -p port_self %d" % port;
	PIPE = subprocess.PIPE;
	p = subprocess.Popen(cmd, shell = True);

