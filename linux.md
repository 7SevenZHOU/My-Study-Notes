ctrl-z  
command fg return to the job  
### copy files to a folder  
cp /home/ankur/folder/{file1,file2} /home/ankur/dest  
### rename file  
mv oldname newname  

### check resource usage  
*top* *free -m*  
### copy and paste  
ctrl+shift+c ctrl+shift+v  
### cat and copy 
cat Yourfile | xsel -b  
xsel -b < Yourfile  
### Copying Directory Trees with cp -r

## _*ImageMagick*_ a powerful image tool in linux!  
dispaly img.jpg  
shortcut for quit: q  

# Git  
### change commit after push  
[change commit after push](https://stackoverflow.com/questions/8981194/changing-git-commit-message-after-push-given-that-no-one-pulled-from-remote)

### ssh via unnormal port  
git clone ssh://git@10.137.20.113:2222/root/test.git  

### remote transfer file via ssh  
```
scp <source> <destination>
//To copy a file from B to A while logged into B:
scp /path/to/file username@a:/path/to/destination
//To copy a file from B to A while logged into A:
scp username@b:/path/to/file /path/to/destination
```
### check the file size in a directory
```
ls -lh
```
## startup script  
[1](http://blog.pzxbc.com/2016/03/08/raspberrypi-debian-startup-script-config/)  
[2](https://wiki.debian.org/LSBInitScripts)  

```
#!/bin/sh
### BEGIN INIT INFO
# Provides:          eth0
# Required-Start:    $network $local_fs $remote_fs
# Required-Stop:     $remote_fs
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: eth0
# Description:       eth0
### END INIT INFO

VAR="/var/log/eth0.log"
SLEEP="/bin/sleep"
PING="/bin/ping"

while [ 1 ]
do
	var=$(/bin/date "+%Y-%m-%d %H:%M:%S")
	$PING -c 1 192.168.3.1 > /dev/null 2>&1
	if [ $? -eq 0 ]
	then
		echo "${var}   Network OK!" >> ${VAR}
	else
		echo "${var}   Network Broken! Restart" >> ${VAR}
		/usr/bin/sudo ifconfig eth0 down && sudo ifconfig eth0 up
		/usr/bin/sudo /etc/init.d/networking restart
		/usr/bin/sudo dhclient eth0
	fi
	$SLEEP 60
done
```
### crontab  
```
crontab -e 
*/2 * * * * sudo /bin/sh /var/eth0
```
```
#!/bin/sh
VAR="/var/log/eth0.log"
SLEEP="/bin/sleep"
PING="/bin/ping"

var=$(/bin/date "+%Y-%m-%d %H:%M:%S")
$PING -c 1 192.168.3.1 > /dev/null 2>&1
if [ $? -eq 0 ]
then
	echo "${var}   Network OK!" >> ${VAR}
else
	echo "${var}   Network Broken! Restart" >> ${VAR}
	/usr/bin/sudo ifconfig eth0 down && sudo ifconfig eth0 up
	/usr/bin/sudo /etc/init.d/networking restart
	/usr/bin/sudo dhclient eth0
fi
```
```
ls -I "*.jpg" -I "*.svg" 
ls | wc -l  
du -sh ./
```
```
ls [ape]* ls files headed with a,p,e  
```
```
sort. ctrl-D end input.  
sort <in >out
```

```
export PYTHONPATH=$PYTHONPATH:$PWD:$PWD/slim
```
export usage  
```
https://www.tutorialspoint.com/unix_commands/export.htm
```
```
chmod u=rwx,go=rx .bashrc
```
