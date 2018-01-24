#### config shadowsocks server on raspberry pi
_operating system:raspberry 3B,debian 9(Linux 4.9)_  

*1.install*  
```
apt-get install python-pip python-m2crypto
pip install shadowsocks
```

*2.config*  
```
sudo vim /etc/shadowsocks.json
```
```
{
"server":"0.0.0.0",
"server_port":xxxx, //any large number i.e 8998
"local_address":"127.0.0.1",
"local_port":xxxx, //any large number i.e 6776
"password":"xxxxxx",
"timeout":300,
"method":"aes-256-cfb",
"fast_open":false,
"workers":1
}
```
*3.start at boot*  
```
sudo vim /etc/rc.local
```
add one line
```
sudo ssserver -c /etc/shadowsocks.json -d start
```
