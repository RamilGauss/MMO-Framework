set PATH=%PATH%;%DEP_PATH_MMO_FRAMEWORK%\Bin;%DEP_PATH_MMO_FRAMEWORK%\Bin\ssl32;%DEP_PATH_MMO_FRAMEWORK%\Bin\ssl64

start Client.exe begin_port 20000 begin_id 7777 count 10 subnet 2 ping_time 100 server_ip 192.168.61.1
#3500
#ip_server 192.168.61.129 
#6100
