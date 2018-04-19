#include <vector>
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

template <class Clave>
class Bank
{ vector <Clave> almacen;
  vector <Clave> aux;
  int contador,minimo, maximo;
  float media;
  int mode;
  public:

 //llena o cambia de valores en el almacen
  void llenado()
  { for(int i=0; i<almacen.size(); i++)
      { Clave c;
        almacen[i] = c;
      }
    contador = 0;
  }

  //caso entero
  void llenado_int()
  { for(int i=0; i<almacen.size(); i++)
      {
        almacen[i] = rand() % 10;
      }
    contador = 0;
  }

  //constructor con tamaño y modo de ejecucion
  Bank(int tam, int modo)
  { almacen.resize(tam);
    aux.resize(tam);
    llenado();
    mode = modo;
  }

  //mostrar el vector
  void mostrar()
  { cout << "(";
    for(int i=0; i<almacen.size(); i++)
      cout << almacen[i] << " ";
    cout << ")" << endl;
  }

  //mostrar el vector resaltando la operacion
   void mostrar(int A, int B, int operation)
  {const char* normal = "\033[0m";
   const char* red = "\033[0;40;31m";
   const char* green = "\033[0;40;32m";
    if(mode == 0)
    { cout << "(";
    for(int i=0; i<almacen.size(); i++)
      {if((i==A) || (i== B))
       { if ( operation == 0 ) cout << green << almacen[i] << normal << " ";
         else cout << red << almacen[i] << normal << " ";
         }
      else cout << almacen[i] << " ";
      }
    cout << ")" << endl;
    }
  }

  void incrementarcontador()
    { contador++;
    }

  //calcula min y max
  void calcular()
    {minimo = min(contador, minimo);
     maximo = max(maximo, contador);
     media += contador;
    }

  //devuelve valores min max y media iniciales
   void reseteo()
   {maximo = 0; minimo = INFINITY; media = 0;
   }

   //mostrar resultados, dividiendo media primero
   void mostrarresultados(int funcion, int nPruebas)
    {media = media/nPruebas;
     cout << setw(18) << nombre_metodo(funcion) << " " << setw(8) << minimo << " " << setw(8)<< media << " " << setw(8) <<  maximo << endl;
    }

    //devolver el valor dentro del vector
  Clave& get_almacen( int pos)
  { return almacen[pos];
  }

 //devuelve true si A es menor que B
  int menor(int A, int B)
    { if(mode == 0) mostrar(A, B, 0);
      incrementarcontador();
      if(almacen[A] < almacen[B]) return true;
      else return false;
    }

  //intercambia los valores dentro de la pos A y B
  void intercambio(int i, int j)
    { swap(almacen[i], almacen[j]);
      if(mode == 0 ) mostrar(i,j,1);
    }

  //insertar el vaalor de la posicion i del vector principal en pos k de aux
  void almacen2aux(int i, int k)
    { aux[k] = almacen[i];
    }
//insertar el vaalor de la posicion i del vector aux en pos k de principal
 void aux2almacen(int i, int k)
    { almacen[k] = aux[i];
    }

    //display nombre metodo
 string nombre_metodo(int metodo)
 { const char* A[] ={"SELECCION", "INTERCAMBIO", "MERGESORT", "QUICKSORT", "SHELLSORT" };
   return A[metodo];
 }

};
