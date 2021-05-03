#include <iostream>
using namespace std;


template <class T>
struct Point {

  T x;
  T y;
};
template <class T>
class Matrice {
  
  public:
  Matrice(int raw , int cols) : _raw(raw) , _cols(cols) {
    
    Data = new int*[_raw];
    for (int i = 0; i < _raw; ++i)
          Data[i] = new int[_cols];

  } 
  
  T getPoint(int x , int y){
    return Data[x][y];  
  }
  void setPoint(int x , int y, T v ){
     Data[x][y] = v;
  }
 virtual  ~Matrice(){
    
    for (int i = 0; i < _raw; ++i){
      delete [] Data[i];
    }
    delete [] Data;
  }
 
  protected:
  int _raw;
  int _cols;
  Point<T>  p;
  int ** Data ;
  private:
  size_t size;
};

int main() {
	Matrice<int> m(5,5);
  
  m.setPoint(2,2,10);
 std::cout << m.getPoint(2,2);
	return 0;
}
