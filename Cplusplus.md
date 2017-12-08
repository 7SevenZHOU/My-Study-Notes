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

### Print Unicode in C++  

_keyboard input in vim:_ ctrl+v u2190 can get a ←  
```C++
string u="\u2190";
//or
string u="←";
cout<<u<<endl;
```

```C++
//C++11 new feature
constexpr int N=5;
int arr[N];
```
