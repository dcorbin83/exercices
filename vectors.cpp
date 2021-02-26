#include <iostream>

using namespace std;

namespace own {

  template < class T >
    class Vector {

      public:
        Vector(): _size(0) {}

      void clear(){

        delete[] _elements;
        _elements = nullptr;
        _size = 0;
      }
      bool isEmpty(){
        return( _elements == nullptr && _size == 0 ) ;
      }
      //delete element
      void pop_back() {

        if (_size == 1) {
          delete _elements;
          _size = 0;
          return;
        }
        T * tmpPtr = new T[_size - 1];
        for (int i = 0; i < _size - 1; i++) {
          tmpPtr[i] = _elements[i];
        }
        delete[] _elements;
        _elements = tmpPtr;
        _size--;
      }
      //add element 
      void push_back(const T & element) {

        // init first element 
        if (_size == 0) {
          _elements = new T();
          * _elements = element;
        }
        T * tmpPtr = new T[_size + 1];

        for (int i = 0; i < _size; i++) {
          tmpPtr[i] = _elements[i];
        }
        //assigne the new element
        tmpPtr[_size] = element;
        //free old list
        delete[] _elements;

        //assign old list to the new one
        _elements = tmpPtr;
        //incrase size
        _size++;
      }
      T at(uint i) {
        return _elements[i];
      }
      
      void setAt(uint i, const T& t){
        _elements[i] = t;
      }
      
      void toString() {
        for (int i = 0; i < _size; i++) {
            std::cout << '[' << at(i) << ']' ;
             }
      }
      protected:
        T * _elements;

      private:
        size_t _size;
    };

}

int main() {

  own::Vector < int > v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  
  std::cout << v.isEmpty() << endl ;
  
  v.toString();
  puts("\n");

  v.pop_back();
  v.setAt(1,50);
  
  v.toString();
   puts("\n");
  v.clear() ;
  std::cout << v.isEmpty() << endl ;
   

  return 0;
}
