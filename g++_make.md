```
g++ -c -o w1.o w1.cpp
g++ -c -o w2.o w2.cpp
g++ -c -o w3.o w3.cpp
g++ -o testtest.cpp w1.o w2.o w3.o
```
-c only compile,not link  
### makefile
```
test:test.cppw1.o w2.o w3.o
    g++ -o test test.cpp w1.o w2.o w3.o
w1.o:w1.cpp
    g++ -c -o w1.o w1.cpp
w2.o:w2.cpp
    g++ -c -o w2.o w2.cpp
w3.o:w3.cpp
    g++ -c -o w3.o w3.cpp
```
```
clean:
    -rm -f test *.o
```
make clean  
### g++ compile use static library  

```
cat.h dog.h cat.cpp dog.cpp main.cpp
g++ -c cat.cpp  
g++ -c dog.cpp
ar -crv libcat.a cat.o
ar -crv libdog.a dog.o
g++ main.cpp -L ./ {-lcat,-ldog}
```
###makefile without library dependency  
```all:createDog.out clean

createDog.out:createDog.o cat.o dog.o
	g++ createDog.o cat.o dog.o -o createDog.out

cat.o:cat.cpp
	g++ -c cat.cpp

dog.o:dog.cpp
	g++ -c dog.cpp

createDog.o:createDog.cpp
	g++ -c createDog.cpp

clean:
	rm -f *o createDog.out
```
