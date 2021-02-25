#include <iostream>
using namespace std;

class A
{
    public: 
       A(int x) : _x(x) {}
    
    virtual void foo(){ std::cout << "A\n";}
    
    int getX() const { return _x;}  ;

     protected:
      int _x;  
};

class B: public A
{
  public: 
   B(int x) : A(x) {}
   B(int x, int y) : A(x) , _y(y) {}
   virtual void foo(){ std::cout << "B\n";}
   protected:
      int _y; 
};

int main(void)
{
   B *b = new B(5);
   //move contructor 
   A &a = *b;
   
   a.foo(); // should display B
   delete b;
   
   return 0;
}

