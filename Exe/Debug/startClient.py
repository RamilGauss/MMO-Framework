import subprocess;
import time;

port     = 9000;
max_port = 9020;
while port < max_port:
	cmd = "start client.exe %d 100 1" % port;
	PIPE = subprocess.PIPE;
	p = subprocess.Popen(cmd, shell = True);
	time.sleep(0.7)
	port = port + 1;
