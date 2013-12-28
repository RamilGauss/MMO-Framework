import subprocess;
import time;

port     = 9000;
max_port = 9250;
while port < max_port:
	cmd = "start client.exe %d 1000 1 192.168.23.230" % port;
	PIPE = subprocess.PIPE;
	p = subprocess.Popen(cmd, shell = True);
	time.sleep(1.0)
	port = port + 1;
