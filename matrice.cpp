#include <iostream>

using namespace std;

template < class T >
  class Matrice {

    public:
      Matrice(int raw, int cols): _raw(raw), _cols(cols) {

        Data = new int * [_raw];
        for (int i = 0; i < _raw; ++i)
          Data[i] = new int[_cols];

      }

    T getValAt(int x, int y) {
      return Data[x][y];
    }
    void setValAt(int x, int y, T v) {
      Data[x][y] = v;
    }
    virtual~Matrice() {

      for (int i = 0; i < _raw; ++i) {
        delete[] Data[i];
      }
      delete[] Data;
    }

    protected:
      int _raw;
    int _cols;
    T ** Data;
    private:
      size_t size;
  };

int main() {
  Matrice < int > m(5, 5);

  m.setValAt(2, 2, 10);
  std::cout << m.getValAt(2, 2);
  return 0;
}
