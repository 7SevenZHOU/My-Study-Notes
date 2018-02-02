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
