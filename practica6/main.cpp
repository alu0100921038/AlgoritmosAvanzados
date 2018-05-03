#include "Dni.cpp"
#include "Bank.hpp"
#include "Arbol.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{ int nPruebas;
  int N;
  int mode; //0 modo demostracion 1 modo estadistica
  int a;
  char nombre [30];
  string aux;
  Dni M;
  ABB <Dni> A;

  fstream fichero;
  cout << "Seleccione el fichero para ser leido: "; cin >> nombre;
  fichero.open(nombre);
  fichero >> mode;


  if (mode == 0) // modo estadistica
    {fichero >> N >> nPruebas;
     Bank <Dni> B(2*N);
      B.llenado();

     cout << endl << "  NUMERO DE COMPARACIONES: " << endl;
     cout << "    Metodo      N    nPruebas  Minimo   Media    Maximo   Altura"<< endl;
     cout << "=========== ======== ======== ======== ======== ======== ========" << endl;


       for(int j=0; j<N; j++)
        {A.insertar(B.get_valor(j));
        }
       A.reseteototal();
       for(int j=0; j<nPruebas; j++)
        {int randomizado;
         randomizado = rand()%N;
         A.reseteo();
         A.buscar(B.get_valor(randomizado));
         A.calcular();
        }
       A.mostrarresultados("BUSQUEDA ", nPruebas, N);
       A.reseteototal();
       for(int j=0; j<nPruebas; j++)
        {int randomizado;
         randomizado = (rand()%N) +N;
         A.reseteo();
         A.buscar(B.get_valor(randomizado));
         A.calcular();
        }
        A.mostrarresultados("INSERCION", nPruebas, N);

   cout << "=========== ======== ======== ======== ======== ======== ========" << endl;

    }

  if(mode == 1) //modo demostracion
    { do
      { cout << endl;
        cout << "[0] Salir" << endl;
        cout << "[1] Insertar clave" << endl;
        cout << "[2] Eliminar clave" << endl;
        cin >> a;
        switch(a)
          { case 1: cout  << "Escriba la clave: "; cin >> aux; cout << endl;  M = aux; A.insertar(M); cout << endl; break;
            case 2: cout  << "Escriba la clave: "; cin >> aux; cout << endl;  M = aux; A.eliminar(M); cout << endl; break;
          }
       A.imprimirporniveles();
      }while (a != 0);
    }

  fichero.close();
	return 0;
}
