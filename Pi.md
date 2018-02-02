config shadowsocks server on raspberry pi
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
*show statitics*
```
sudo netstat -anp | grep python
```
*4.fix bugs*  
[openssl bug](https://blog.lyz810.com/article/2016/09/shadowsocks-with-openssl-greater-than-110/)  
*5.bbr*  
[config bbr](https://github.com/iMeiji/shadowsocks_install/wiki/%E5%BC%80%E5%90%AFTCP-BBR%E6%8B%A5%E5%A1%9E%E6%8E%A7%E5%88%B6%E7%AE%97%E6%B3%95)  
