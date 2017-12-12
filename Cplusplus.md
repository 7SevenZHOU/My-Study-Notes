INT_MIN  
INT_MAX  
_swap()_ can swap two nodes in tree;

In g++ compiler,must specify c++11 if we want c++11 standard.  
g++ -std=c++11 your_file.cpp -o your_program  
So we can initialize a vector:  
```C++
vector<int> b{1,2,3,4}; 
```
_*rand seed:*_  
```C++
srand(time(NULL))
```

### _*How to return multiple values in C++:*_  

[How to return multiple values in C++?](https://www.zhihu.com/question/57540006)  
[Returning Multiple Values from Functions in C++](https://dzone.com/articles/returning-multiple-values-from-functions-in-c)

### _*Print Unicode in C++*_  

_keyboard input in vim:_ ctrl+v u2190 can get a ←  
```C++
string u="\u2190";
//or
string u="←";
cout<<u<<endl;
```
### _*C++11 new feature*_  
####constexpr  
```C++
constexpr int N=5;
int arr[N];
```
#### static
*static global variable*  
if two files, in one file define static int a=5;then a is not visible even declare _*extern int a;*_  

*static local variable*  
```C++
int factorial(int n){
    static int k=1;
    k=k*n;
    return k;
}

int main(){
    for(int i=1;i<=5;i++)
    {
        cout<<factorial(i)<<endl;
    }
    return 0;
}
//the result is 1 2 6 24 120
//so k remains valid until the program ends
```
_*what is companion class?*_

_*what is protected member in class?*_  
_*stl list?*_  

_*typedef*_ alias  
```C++
typedef unsigned long ulong;
unsigned long l1;
ulong l2;
```
_string::size_type_ guarantees just that. It is a type that is big enough to represent the size of a string, no matter how big that string is.  
```C++
std::string::size_type len=myString.size();
```
### Returning values by reference in C++  
[Returning values by reference in C++](https://www.tutorialspoint.com/cplusplus/returning_values_by_reference.htm)

```C++
#include <iostream>
#include <string>
using namespace std;

int vals[]={1,2,3,4,5};

int& setValue(int i){
    return vals[i];
}


int main()
{
    for(int i=0;i<5;i++)
    {
        cout<<vals[i]<<endl;
    }
    
    setValue(0)=6;
    setValue(1)=7;
    //note! int r=setValue(2); will not work
    int &r=setValue(2);
    r=8;
    for(int i=0;i<5;i++)
    {
        cout<<vals[i]<<endl;
    }
    
    return 0;
}
```
```C++
int& func() {
   int q;
   //! return q; // Compile time error
   static int x;
   return x;     // Safe, x lives outside this scope
}
```
### initializer_list  
[std::initializer_list](http://en.cppreference.com/w/cpp/utility/initializer_list)  
