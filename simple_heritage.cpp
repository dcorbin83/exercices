#include <iostream>
using namespace std;

class A
{
    public: 
       A(int x) : _x(x) {}
    
    virtual ~A(){}
    
    virtual void foo(){ std::cout << _a  << "\n";}
    
    int getX() const { return _x;}  ;

     protected:
      int _x;  
      char * _a = "A";
};

class B: public A
{
  public: 
   B(int x) : A(x) {
       _a = "B";}
   B(int x, int y) : A(x) , _y(y) {}

    
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
