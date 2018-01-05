## python with keyword
[with keyword](http://preshing.com/20110920/the-python-with-statement-by-example/)  

#### fabonacci  
```python
def fab(n):
    a,b,c=0,0,1
    for i in range(n):
        a,b,c=b,c,b+c
    return c
#or
def fab(n):
    a,b=0,1
    for i in range(n):
        a,b=b,a+b
    return b
```
