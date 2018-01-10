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

