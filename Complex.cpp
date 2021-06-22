#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Z {
  Z(T im , T re) : _im(im) , _re(re){}
  Z operator*(Z<T> z1){
  return Z( (z1._im * this->_im)*-1 ,  z1._re * this->_re  );
  }  
  
  void toPrint() const { std::cout << _im << "i ;" << _re << std::endl;  }
  T _im;
  T _re;
};

int main() {
  
  //using template
  std::vector<Z<int>> vz;
  vz.push_back(Z(1,2));
  vz.push_back(Z(1,3));
  
  // display vector
  for(const auto&  e : vz){
    e.toPrint();
  }
  
  // override * 
  Z<int> zP =  vz.at(0) * vz.at(1);
  zP.toPrint();
  
  //bonus ovveride << 
 
	return 0;
}
