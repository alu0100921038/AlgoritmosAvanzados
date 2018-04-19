
//#include "Matricula.cpp"
#include "Dni.cpp"
#include "Bank.hpp"
#include "Functions.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{ int nPruebas;
  int funcion;
  int N;
  int mode; //0 modo demostracion 1 modo estadistica
  char a;
  float alfa = 1; //alfa determinado
  char nombre [30];


  fstream fichero;
  cout << "Seleccione el fichero para ser leido: "; cin >> nombre;
  fichero.open(nombre);
  fichero >> mode >> N;
  Bank<Dni> B(N, mode);
  B.llenado();
  funcion = 4;
  if(mode == 0)
   {fichero >> funcion;
    cout << "Pulse 0 para empezar (se recomienda maximizar primero) " ; cin >> a;
    //if(funcion == 4)
    fichero >> alfa;

    cout << "VECTOR DESORDENADO Metodo " << B.nombre_metodo(funcion) << endl;
    B.mostrar();
    fgeneral(funcion, B, N, alfa);
    B.mostrar();
   }

  if(mode == 1)
    {fichero >> nPruebas >> alfa;
     cout << "  NUMERO DE COMPARACIONES: " << nPruebas << " Pruebas de " << N << " elementos." << endl;
     cout << "    Metodo          Minimo   Media    Maximo" << endl;
     cout << "================== ======== ======== ========" << endl;
     for(int funcion=0; funcion<5; funcion++)
      { B.reseteo();
       for(int i=0; i<nPruebas; i++)
        { B.llenado();
          fgeneral(funcion, B, N, alfa);
        }
       B.mostrarresultados(funcion, nPruebas);
      }
    }

	return 0;
}
