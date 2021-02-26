#include <iostream>
using namespace std;

class A
{
    public: 
       A(int x) : _x(x) {}
    
    virtual ~A(){}
    
    virtual void foo() const { std::cout << "A\n";}
    
    int getX() const { return _x;}  ;

     protected:
      int _x;  
  
};

class B final : public A
{
  public: 
   B(int x) : A(x) {}
   B(int x, int y) : A(x) , _y(y) {}
   
   void foo() const override { std::cout << "B\n";}

  void static bar(){};
   protected:
      int _y; 
      
};

void f1( const A& a){
   a.foo();
}
int main(void)
{
   B *b = new B(5);
   //move contructor 
   A &a = *b;
   
   b->foo(); // should display B
   a.foo(); // should display B
   f1(a); // should display B
   delete b;
   
   return 0;
}
