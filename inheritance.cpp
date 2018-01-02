#include<iostream>
#include<string>

class Animal{
public:
    virtual void eat()=0;
    void setWeight(int n){weight=n;}
    void setLength(int n){length=n;}

    Animal(int w,int l,std::string c):weight(w),length(l),color(c){
        std::cout<<"Animal created! "<<std::endl;
    }
    Animal(){
        std::cout<<"Anmal default created"<<std::endl;
    }

    int getWeight(){return weight;}
    int getLength(){return length;}
    virtual ~Animal(){
        std::cout<<"Animal destroyed."<<std::endl;
    }


private:
    int weight;
    int length;

protected:
    std::string color;
};

class FourLegs{
public:
    FourLegs(){
        std::cout<<"FourLegs created."<<std::endl;
    }
    void run(){
        std::cout<<"FourLegs can run!"<<std::endl;
    }
    virtual void jump()=0;
    virtual ~FourLegs(){
        std::cout<<"Fourlegs destoryed"<<std::endl;
    }
protected:
    int height;
};

class Dog:public Animal,public FourLegs{
public:
    Dog(int w,int l,int s,std::string c):Animal(w,l,c),runSpeed(s){
        std::cout<<"Dog created! "<<std::endl;
    }
    Dog(){
        std::cout<<"Dog default created!"<<std::endl;
    }

    void eat(){
        std::cout<<"Dog eat bones!"<<std::endl;
    }

    void jump(){
        std::cout<<"Dog can jump! "<<std::endl;
    }
    void bark(){
        std::cout<<"Dog bark! "<<std::endl;
    }
    void setHeight(int h){
        height=h;
    }

    void broatcast(){
        std::cout<<"Weight: "<<getWeight()<<" kg"<<std::endl;
        std::cout<<"Lenght: "<<getLength()<<" cm"<<std::endl;
        std::cout<<"Color: "<<color<<std::endl;
        std::cout<<"Height: "<<height<<" cm"<<std::endl;
        std::cout<<"runspeed: "<<runSpeed<<std::endl;
    }
    ~Dog(){
        std::cout<<"Dog destoryed"<<std::endl;
    }

private:
    int runSpeed;
};

int main(){
    Dog Wangcai(26,60,80,"Brown");
    Animal *p= new Dog;
    Wangcai.run();
    Wangcai.bark();
    Wangcai.jump();
    Wangcai.setHeight(60);
    Wangcai.broatcast();
    delete p;
    return 0;
}

/*

#include<iostream>

class D{
public:
    D(){std::cout<<"Hello D"<<std::endl;}
    ~D(){std::cout<<"Bye D"<<std::endl;}
};

class B:virtual public D{
public:    
    B(){std::cout<<"Hello B"<<std::endl;}
    ~B(){std::cout<<"Bye B"<<std::endl;}
};

class C:virtual public D{
public:
    C(){std::cout<<"Hello C"<<std::endl;}
    ~C(){std::cout<<"Bye C"<<std::endl;}
};

class A:public B,public C{
public:
    A(){std::cout<<"Hello A"<<std::endl;}
    ~A(){std::cout<<"Bye A"<<std::endl;}
};


int main(){
    A a;
    B b;
    C c;
    D d;
    return 0;
}

*/
