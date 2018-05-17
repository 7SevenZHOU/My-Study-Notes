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

## delete element when use for iterator  
```python
def getMaxAverage(a):
    maxA=0
    while a:
        k=a[0]
        total=0
        count=0
        for x in a[:]:
            if x[0]==k[0]:
                total=total+x[1]
                count=count+1
                a.remove(x)
        total=total/count
        if total>maxA:
            maxA=total
            print("%d\n"%maxA)
        print(a)
    return maxA


student=[["A",-20],["B",30],["C",40],["D",70],["B",120],["A",140],["C",170],["C",200],["E",300]]

print(getMaxAverage(student))

b=[1,2,3,4,5,6,7]
for item in b[:]:
    b.remove(item)
    print(b)
```
[reference](http://www.cnblogs.com/bananaplan/p/remove-listitem-while-iterating.html)  

## copy list  
1.new_list=old_list[:]  
2.new_list=list(old_list)
3.import copy  
  newlist=copy.copy(old_list)  
4.newlist=copy.deepcopy(old_list)11111111111111  
[*Reference*](https://stackoverflow.com/questions/2612802/how-to-clone-or-copy-a-list)

random sample from list  
```python
import random
a=[1,2,4,6,8,11,13]
b=random.sample(a,3)
```
#### how to use readlines() multiple times
```
with open(filename) as f:
    for r in f.readlines():
        #do some work
    f.seek(0)
    for r in f.readlines():
        continue do some work
```

## lambda function  
[*lambda function*](http://www.secnetix.de/olli/Python/lambda_functions.hawk)  
```python
from functools import reduce

DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def str2int(s):
    def fn(x, y):
        return x * 10 + y
    def char2num(s):
        return DIGITS[s]
    return reduce(fn, map(char2num, s))
```
```python
from functools import reduce

DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def char2num(s):
    return DIGITS[s]

def str2int(s):
    return reduce(lambda x, y: x * 10 + y, map(char2num, s))
```

```python
def g_odd():
    n=1
    while True:
        n+=2
        yield n
        

def not_divide(n):
    return lambda x:x%n>0
    

def prime():
    yield 2
    it=g_odd()
    while True:
        n=next(it)
        yield n
        it=filter(not_divide(n),it)
    

for n in prime():
    if n<1000:
        print(n)
    else:
        break
```
```
>>> nums = range(2, 50) 
>>> for i in range(2, 8): 
...     nums = filter(lambda x: x == i or x % i, nums)
... 
>>> print nums
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
```
### **
```python
3**2=9
4**3=64
```
### matplotlib  
```python
plt.contourf(x,y,Z, 50, alpha=0.5, cmap=plt.get_cmap('jet'))
plt.plot([-188.4], [2.67], 'x', ms=12, markeredgewidth=3, color='orange')
plt.plot(b_history, w_history, 'o-', ms=3, lw=1.5, color='black')
plt.xlim(-200,-100)
plt.ylim(-5,5)
plt.xlabel(r'$b$', fontsize=16)
plt.ylabel(r'$w$', fontsize=16)
plt.show()
```
### integer division  
in python3 //(floor division) /(true division)  

### add virtualenv support in jupyter notebook  
```
sudo pip3 install -U jupyter
sudo pip3 install ipykernel
python3 -m ipykernel install --user --name=tensorflow
```

## argparse
[Argparse Tutorial](https://docs.python.org/3/howto/argparse.html)
```python
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("square", type=int,
                    help="display a square of a given number")
parser.add_argument("-v", "--verbose", action="store_true",
                    help="increase output verbosity")
args = parser.parse_args()
answer = args.square**2
if args.verbose:
    print("the square of {} equals {}".format(args.square, answer))
else:
    print(answer)
```
```python
a = 1  
print(a.__class__)  
print(issubclass(a.__class__, object))
```


```python
>>> def functionA(*a, **kw):
       print(a)
       print(kw)
       
>>> functionA(1, 2, 3, 4, 5, 6, a=2, b=3, c=5)
(1, 2, 3, 4, 5, 6)
{'a': 2, 'c': 5, 'b': 3}

>>>import numpy as np
>>>a=(1,2,3)
>>>b=np.zeros((4,*a))
>>>print(b.shape)
(4,1,2,3)
```
