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

### const
```C++
class Student{
public:
    //getAge() can't modify any member variable
	int getAge() const{
        //age=20; //compile error
		return age;
	}
    //return a const reference
    //const int& s=Stu.getScore(); otherwise compile error
	const int& getScore() const{
		return score;
	}

	Student(int a=18,int s=0):age(a),score(s){}

private:
	int age;
	int score;
};
```
```C++
string *ps1=new string; //default initialized to empty string
string *ps2=new string(); //value initialized to empty string
int *p(new int(20));

int *pi1=new int; //default initialized to a undefined int,*pi1 is undefined
int *pi2=new int(); //value initialized to 0,*pi2=0
string *ps=new string(10,'9'); //*ps is "9999999999"
vector<int> *pv=new vector<int>{0,1,2,3,4,5,6,7,8,9};

auto pi3=new auto(pi2);

//a pointer to a const, must initialize;
const int *pi4=new const int(1024);
const string *pcs=new const string; //implicit initialization

//if allocation fails,new returns a null pointer
int *pi5=new int; //if allocation fails,new throws std::bad_alloc
int *pi6=new (nothrow) int;//if allocation fails,new returns a null pointer

```

The pointer we pass to delete must either point to dynamically allocated memory or be a null pointer.  
Deleting a pointer to memory that was not allocated by new,or deleting the same pointer value more than once,is undefined  

```C++
int main ()
{
  string str;
  do {
    cout << "Enter text: ";
    getline (cin,str);
    cout << "You entered: " << str << '\n';
  } while (str != "goodbye");
  
  string str1 {"Hello!"};
  for (char c : str1)
  {
    cout<< c <<endl;
  }
}

int main ()
{
  for (int n=10; n>0; n--)
  {
    cout << n << ", ";
    if (n==3)
    {
      cout << "countdown aborted!";
      break;
    }
  }
}

int main ()
{
  for (int n=10; n>0; n--) {
    if (n==5) continue;
    cout << n << ", ";
  }
  cout << "liftoff!\n";
}

```
```C++
for ( n=0, i=100 ; n!=i ; ++n, --i )
{
   // whatever here...
}
```
```C++
int main ()
{
  int n=10;
mylabel:
  cout << n << ", ";
  n--;
  if (n>0) goto mylabel;
  cout << "liftoff!\n";
}

switch (x) {
  case 1:
  case 2:
  case 3:
    cout << "x is 1, 2 or 3";
    break;
  default:
    cout << "x is not 1, 2 nor 3";
  }
```
# pointer to function
```C++
int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    /* p is pointer to function */
    int (* p)(int, int) = & max; // & can eliminate
    int a, b, c, d;

    printf("please input 3 numbers:");
    scanf("%d %d %d", & a, & b, & c);

   
    d = p(p(a, b), c); 

    printf("the maxumum number is: %d\n", d);

    return 0;
}
```
```C++
#include <iostream>


class aClass
{
public:
    void aTest(int a, int b)
    {
        printf("%d+%d=%d",a,b,a+b);
    }
};

void function1(void (*function)(int,int))
{
    function(1,1);
}

void test(int a,int b)
{
    printf("%d-%d=%d",a,b,a-b);
}

int main (int argc, const char * argv[])
{
    aClass a();

    function1(&test);
    function1(&aClass::aTest ); // <-- how should I point to a's aClass::test function?

    return 0;
}
```


