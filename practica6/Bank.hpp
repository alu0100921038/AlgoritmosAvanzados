#include <vector>
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

template <class Clave>
class Bank
{ vector <Clave> almacen;
  public:

 //llena o cambia de valores en el almacen
  void llenado()
  { for(int i=0; i<almacen.size(); i++)
      { Clave c;
        almacen[i] = c;
      }
  }

  //caso entero
  void llenado_int()
  { for(int i=0; i<almacen.size(); i++)
      {
        almacen[i] = rand() % 10;
      }
  }

  //constructor con tamaño y modo de ejecucion
  Bank(int tam)
  { almacen.resize(tam);
    llenado();
  }

  int get_size() {return almacen.size();}
  Clave get_valor(int pos) {return almacen[pos];}




};
