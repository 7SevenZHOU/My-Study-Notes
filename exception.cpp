#include<iostream>

int divide(int y,int x){
    if(x==0){
        throw "Divide by 0\n";
    }
    if(x<0){
        throw -1;
    }
    return y/x;
}

int compare(int a,int b){
    if(a<0||b<0){
        throw std::invalid_argument("a or b negative.");
    }
    return a>b?a:b;
}

int main(){
    int x=-1;
    std::cout<<"Before try\n"; 
    try{
        if(x<0)
            throw 1;
    }
    catch(int y){
        std::cout<<"Catch! " <<y<<std::endl;
    }

    try{
        divide(5,0);
    }
    catch(const char *s){
        std::cout<<s;
    }
    catch(int y){
        std::cout<<y<<std::endl;
    }
    catch(...){
        std::cout<<"Default exception!"<<std::endl;
    }

    try{
        compare(-1,2);
    }
    catch(const std::invalid_argument &s){
        std::cerr<<s.what()<<std::endl;
    }

    
    return 0;
}
