#include <iostream>
using namespace std;

template <class T> 
class Generique {

  public: 
    Generique(const T& attribute) : _attribute(attribute) {}
    virtual ~Generique(){}
    T getAttribute(){
      return _attribute;
    }
    void setAttribute(const T& attribute){
      _attribute = attribute ;
    }
  protected:
    T _attribute;
};

template <class T, class P>
class Inheritance final : public Generique<T> {
  
  public: 
   Inheritance(const T& attribute) : Generique<T>(attribute) {
     _ptrAttribute = new P();
   }
   ~Inheritance(){
     delete _ptrAttribute;
   }
  
  protected:
    P *  _ptrAttribute;

};

int main() {
   
   Inheritance <int,float> objH(10) ;;
   Generique <int> objG(5);
   
  std::cout << objG.getAttribute() << std::endl; 
  std::cout << objH.getAttribute() << std::endl; 
	
	return 0;
}
