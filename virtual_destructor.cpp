#include <iostream>
using namespace std;

struct A
{
     A(){};
     virtual ~A(){std::cout << "delete A\n";}
};

struct B final : public A
{ 
   B(){};
   ~B(){std::cout << "delete B\n"; }   
};

A* factory(const std::string& ioType){
  if(ioType == "B"){
       return new B();
  }
}
int main(void)
{
   
   A * Objb = factory("B"); //specialise object type A into type B

   delete Objb; // if ~A()  is virtual -> should display B and A
   return 0;
}
