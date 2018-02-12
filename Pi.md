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

*6.hourly send email informing external ip address  
```python
from urllib.request import urlopen  # in python3
# from urllib import urlopen - In python2
import re
import smtplib


# Setup our login credentials
from_address = "pineoserver@gmail.com"
to_address = "pineoserver@gmail.com"
subject = "RPi3 IP"
username = "pineoserver@gmail.com"
password = "Password"  # password of your newly created gmail account.

# Setup where we will get our IP address
url = "http://checkip.dyndns.org"
print ("Our chosen IP address service is:", url)

# Open upthe url, then read the content, and take away to IP address
request = urlopen(url).read().decode("utf-8")
# Extract the IP address only
ourIP = re.findall(r'[\d.-], request)
ourIP = str(ourIP)
print ("Our IP address is:", ourIP)


def send_email(ourIP):
    # Body of the email
    body_text = ourIP + " is our RPi3 IP address"
    msg = "\n".join(["To: %s" % to_address,
                       "From: %s" % from_address,
                       "Subject: %s" % subject,
                       "", body_text])

    # Actually send the email!
    server = smtplib.SMTP("smtp.gmail.com:587")
    server.starttls()  # Our security for transmission of credentials
    server.login(username, password)
    server.sendmail(from_address, to_address, msg)
    server.quit()
    print ("Our email has been sent!")

# send_email(ourIP)

# Open up last_ip.txt, and extract the contents
with open("/home/pi/Desktop/ipemail/last_ip.txt", "rt") as last_ip:
    last_ip = last_ip.read()  # Read the text file

# Check to see if our IP address has really changed
if last_ip == ourIP:
    print ("Our IP address has not changed.")
else:
    print ("We have a new IP address.")
    with open("/home/pi/Desktop/ipemail/last_ip.txt", "wt") as last_ip:
        last_ip.write(ourIP)
    print ("We have written the new IP adddress to the text file.")
    send_email(ourIP)

