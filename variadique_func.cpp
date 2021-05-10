#include <iostream>
#include <stdarg.h>
using namespace std;

//additonner les nbParam arguments de type T

template < typename T>
T somme(int nbParam, ...)	{
  T x = 0;
  va_list params;	// pointeur de la liste des paramètres
  va_start(params, nbParam);	// initialise le pointeur grâce

  for (int i = 0; i < nbParam; i++)	{
	  x += va_arg(params, T);	// va_args s'incremente tout seul..
  }
  va_end(params);	// fermeture de la liste
  return x;	
}

int main() {
int s =	somme<int> (3, 1, 2, 3);	// 1+2+3
std::cout << s;
}
