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
