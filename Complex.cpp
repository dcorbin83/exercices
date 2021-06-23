#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Z {
  Z(T im , T re) : _im(im) , _re(re){}
  virtual ~Z(){};
  Z operator*(const Z<T>& z1){
  return Z( z1._im * this->_re + z1._re * this->_im ,  z1._re * this->_re - z1._im * this->_im );
  }  
  T getIm() const { return _im;}
  T getRe() const { return _re;}
  
private:
  T _im;
  T _re;
  
};

template <class T>
  std::ostream& operator<<(std::ostream& out, const Z<T>& z){
   return out << z.getIm() << "i ;" << z.getRe() << std::endl;
}

int main() {
  
  //using template
  std::vector<Z<int>> vz;
  vz.push_back(Z(4,1));
  vz.push_back(Z(1,5));
  
  // display vector
  for(const auto&  e : vz){
    std::cout << e ;
  }
  
  // override * 
  Z<int> zP =  vz.at(0) * vz.at(1);
 std::cout << zP ;
  
	return 0;
}
