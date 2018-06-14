# scope
## local nonlocal gobal

```python
def scope_test():
    def do_local():
        spam = "local spam"
    def do_nonlocal():
        nonlocal spam
        spam = "nonlocal spam"
    def do_global():
        global spam
        spam = "global spam"
    spam = "test spam"
    do_local()
    print("After local assignment:", spam)
    do_nonlocal()
    print("After nonlocal assignment:", spam)
    do_global()
    print("After global assignment:", spam)

scope_test()
print("In global scope:", spam)
```

_The output of the example code is:_
```
After local assignment: test spam
After nonlocal assignment: nonlocal spam
After global assignment: nonlocal spam
In global scope: global spam
```
```
with open("testfile.txt","w") as file:
	file.write("Hello World\n") 
	file.write("This is our new text file\n") 
	file.write("and this is another line.\n") 
	file.write("Why? Because we can.\n") 

import json
d={"one":1,"two":2}
json.dump(d,open("./testfile2.txt","w"))

d2 = json.load(open("./testfile2.txt"))
```
