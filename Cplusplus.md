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

```C++
//c++17  Structrued binding
auto fun(){
return tuple(1,'c');}
auto[a,b]=fun();

//c++14
std::tuple<int,char> fun(){
return std::make_tuple(1,'c');}
auto t=fun();
int a=std::get<0>(t);
char b=std::get<1>(t);
```

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
# pure virtual function  
[pure virtual function](https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/)  

### virtual destuctor  
when design a base class, we should use virutal destructor.  
[when to use virtual destructor](https://www.zhihu.com/question/41538182)  

### virtual inheritance
```C++
class D{};
class A:virtual public D{};
class B:virtual public D{};
class C:public A,public B{};
//if not virtual inheritance,will get two D instances when create C;
```
友元关系没有继承性和传递性  
## static member and friend class  
```c++
#include<iostream>

class Dog{
public:
    friend class Cat;
    Dog(int a):age(a){}
    static void run(){
        std::cout<<"Dog run!"<<std::endl;
    }
    void setLength(int n){
        length=n;
    }
    static int length;
private:
    void bark(){std::cout<<"bark!"<<std::endl;}
    int age;
};

int Dog::length=20; //must initialize outside the class.

class Cat{
public:
    Cat(){}
    void meow(Dog a){
        std::cout<<a.age<<std::endl;
        a.bark();
        std::cout<<"Dog length:"<<a.length<<std::endl<<std::endl;
    }
private:

};

int factorial(int n){
    static int r=1;
    r=r*n;
    return r;
}


int main(){
    Dog d(7);
    d.run();
    std::cout<<"Dog length: "<<Dog::length<<std::endl;
    Dog::run();
    Cat c;
    c.meow(d);
    d.setLength(30);
    c.meow(d);
    Dog e(8);
    c.meow(e);
    e.length=40;
    c.meow(e);
    for(int i=1;i<7;i++){
        std::cout<<factorial(i)<<std::endl;
    }


    return 0;
}
```
```c++
class Something
{
private:
    static int s_value;
public:
    static int getValue() { return s_value; } // static member function
};
 
int Something::s_value = 1; // initializer
 
int main()
{
    std::cout << Something::getValue() << '\n';
}
```
std::vector::size() returns a unsigned number,so it is better to convert it to integer when use in loop  
in c++11:  
```c++
for (auto iter = myVec.begin(); iter != myVec.end(); ++iter)
{
    int i = *iter;
}

for (auto i : myVec)
{
}
```
#### ascii operation  
```c++
class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        for(char c:s){
            ans=ans*26+c-'A'+1;
        }
        return ans;
    }
};
```
### unordered_map  
```C++
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<B.size();i++){
            m[B[i]]=i;
        }
        for(int i=0;i<A.size();i++){
            A[i]=m.find(A[i])->second;
            //auto p=m.find(A[i]);
	    //a[i]=p->second;
        }
        return A;
    }
};

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(!m.count(nums[i])) //count usage!
                m[nums[i]]=i;
            else if(abs(i-m[nums[i]])>k)
                m[nums[i]]=i;
            else
                return true;
        }
        return false;   
    }

```

### unordered_set
```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};
```
```C++
class Solution {
public:
    /**
     * 0            k           2k          3k
     * |-----------|-----------|-----------|---
     * +--reverse--+           +--reverse--+
     */
    string reverseStr(string s, int k) {
        for (int left = 0; left < s.size(); left += 2 * k) {
            for (int i = left, j = min(left + k - 1, (int)s.size() - 1); i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};

string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) reverse(s.begin()+i, min(s.begin()+i+k, s.end()));
        return s;
    }
```
#### implicit invert from char to int
```C++
char A='a';
int B=A;
std::cout<<"B: "<<B<<std::endl;
int C[256]={0};
C[A]=1;
```
#### vector  
```C++
vector<int> fun1(){
    return {1,2};
    //or
    return vector<int> {1,2};
    }
```
### bitset
```C++
vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}
/*For objects that add classes to a container, emplace_back avoids copying and moving operations of additional classes compared to push_back.

“Emplace_back avoids the extra copy or move operation required when using push_back.”

See: http://en.cppreference.com/w/cpp/container/vector/emplace_back
https://www.codeday.top/2017/07/11/28790.html
*/
```
*A void pointer can point to objects of any data type*

### handle exceptions  
```C++
#include <iostream>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main () {
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
      z = division(x, y);
      cout << z << endl;
   } catch (const char* msg) {
     cerr << msg << endl;
   }

   return 0;
}
```
*C++ class can include pointer member point to itself*
```c++
class Node {
    char *cargo;
    Node* left;   // I'm not a Node; I'm just a pointer to a Node
    Node* right;  // Same here
};
```
*Explicit Specifier*
```c++
Specifies that a constructor or conversion function (since C++11) is explicit, that is, it cannot be used for implicit conversions and copy-initialization.
```
```c++
#include <stdio.h>
#include <algorithm> 
bool cmp(int a, int b){
	return a > b;
}

int main(void){
	int a[8] = {5,43,1,7,8,13,0,74};
	std::sort(a,a+10,cmp);//callback
	return 0;
}
```
```c++
#include <algorithm>  
#include <cmath>  
  
void abssort(float* x, unsigned n) {  
    std::sort(x, x + n,  
        // Lambda expression begins  
        [](float a, float b) {  
            return (std::abs(a) < std::abs(b));  
        } // end of lambda expression  
    );  
}  
```
```c++
#include <iostream>
#include <thread>

struct functor {
  void operator() (int a, int b) {
    std::cout << a << "+" << b << "=" << a + b << std::endl;
  }
};

int main()
{
  std::thread td(functor(), 1, 2); // 使用functor对象创建线程对象并传递参数1和2
  td.join(); // 等待线程执行结束
}
```

```c++
char c[]="hello world!"
std::cout<<sizeof(c)<<std::Endl;
>>13
```

```c++
/*

 * Example of a singleton design pattern.

 * Copyright (C) 2011 Radek Pazdera



 * This program is free software: you can redistribute it and/or modify

 * it under the terms of the GNU General Public License as published by

 * the Free Software Foundation, either version 3 of the License, or

 * (at your option) any later version.



 * This program is distributed in the hope that it will be useful,

 * but WITHOUT ANY WARRANTY; without even the implied warranty of

 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the

 * GNU General Public License for more details.



 * You should have received a copy of the GNU General Public License

 * along with this program. If not, see <http://www.gnu.org/licenses/>.

 */



#include <iostream>



class Singleton

{

    private:

        /* Here will be the instance stored. */

        static Singleton* instance;



        /* Private constructor to prevent instancing. */

        Singleton();



    public:

        /* Static access method. */

        static Singleton* getInstance();

};



/* Null, because instance will be initialized on demand. */

Singleton* Singleton::instance = 0;



Singleton* Singleton::getInstance()

{

    if (instance == 0)

    {

        instance = new Singleton();

    }



    return instance;

}



Singleton::Singleton()

{}



int main()

{

    //new Singleton(); // Won't work

    Singleton* s = Singleton::getInstance(); // Ok

    Singleton* r = Singleton::getInstance();



    /* The addresses will be the same. */

    std::cout << s << std::endl;

    std::cout << r << std::endl;

}
```
```c++
class can have static member of itself
class Test(){
static Test self;
};
int main(){
Test t;
return 0;
} //ok
```

RAII: Resource acquisition is initialization  
MVC,Observer Pattern  

virtual function: dynamic binding,static binding(without virtual declaration)  
polymorphic class  

array of funtions:[https://stackoverflow.com/questions/5309859/how-to-define-an-array-of-functions-in-c] 

```c++
#include <chrono>
#include <thread>
std::this_thread::sleep_for(std::chrono::milliseconds(x));
```
```c++
class A
{
public:
	A():a(1){};
	void printA(){cout<<a<<endl;}
	int a;
};
 
class B : virtual public A
{
};
 
class C : virtual public A
{
};
 
class D:  public B ,  public C
{
};
 
int _tmain(int argc, _TCHAR* argv[])
{
	D d;
	cout<<sizeof(d);
	d.a=10;
	d.printA();
}



class istream : virtual public ios{...};
class ostream : virtual public ios{...};
class iostream : public istream, public ostream{...};


```
friend function can't be derived.  
all member function and static member use(share) the same space.  
