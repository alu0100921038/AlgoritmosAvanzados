#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include "colision.h"

using namespace std;

template <class Clase>
class nodoBB
{ Clase dato;
  nodoBB <Clase>* izq;
  nodoBB<Clase>* der;
  Colision colision;

  public:
  	
  nodoBB(const Clase data)
    { izq = NULL;
      dato = data;
      der = NULL;
    }

  void mostrar()
    { cout << "[" << dato << "]" << endl;
    }

  void set_dato(Clase data) { dato = data;}
  Clase get_dato() {return dato;}
  nodoBB<Clase>* &get_izq () {return izq;}
  nodoBB<Clase>* &get_der () {return der;}
  
   int get_colision(void){
        return colision.get_colision();
    }
            
    void aumentar_colision(void){
        colision.aumentar();
    }
    
    void disminuir_colision(void){
        colision.disminuir();
    }

};


template <class Clase>
class ABB
{ private:
  nodoBB <Clase>* root;
  int minimo, maximo;
  float media;
  int contador;


  void incrementarcontador() { contador++;}
	
  /* Intercambia el dato a eliminar con el mayor de la rama especificada (normalmente la izquierda) */
  void sustituir(nodoBB<Clase>* &eliminado, nodoBB<Clase>* &sust)
    {  // Si el nodo tiene hijo derecho (mayor), vuelve a llamar a la funcion con dicho hijo derecho
	  if(sust->get_der() != NULL) sustituir(eliminado, sust->get_der());
	  // Si el nodo no tiene hijo derecho, ya se ha encontrado el valor mayor de la rama
      else //se intercambia el dato a eliminar con el valor mayor encontrado
        {eliminado->set_dato( sust->get_dato());
         eliminado = sust;
         sust = sust->get_izq();
        }
    }
 
  /* Imprime el nivel del arbol especificado */
  bool imprimirnivel(int nivel, int nivelactual, nodoBB<Clase>* nodo)
   { if(nodo == NULL)
          { if(nivel == nivelactual) cout << "[.]";
            return false;
          }
      if(nivel > nivelactual)
      {
        imprimirnivel(nivel, nivelactual+1, nodo-> get_izq());
        imprimirnivel(nivel, nivelactual+1, nodo-> get_der());
      }
      if(nivel == nivelactual)
       { cout << "[" <<  nodo->get_dato() << "]" ;}
      return false;
    }
  
  /* Inserta un elemento en una rama */
  void insertarRama( nodoBB<Clase>* &nodo, Clase valor)
     {
      if ( nodo == NULL ) nodo = new nodoBB<Clase> ( valor ); //si el nodo está vacío lo inserta en esa rama
      else if ( valor < nodo->get_dato() ) insertarRama( nodo->get_izq(), valor); //si el valor es menor que el nodo lo insertamos en la rama izquierda
      else if (valor == nodo->get_dato()){ //si el valor es igual al nodo, hay colision
                        nodo->aumentar_colision();
                        cout<<"colision"<<nodo->get_colision();
           
                    }
      else insertarRama( nodo->get_der(), valor); //si el valor es mayor que el nodo lo insertamos en la rama derecha
    }

  /* Elimina un dato de una rama */
  void eliminaRama (nodoBB<Clase>* &nodo, Clase valor)
    { nodoBB<Clase>* eliminado;
        if(nodo == NULL) return; // si la rama de la que se va a eliminar esta vacía
        if (nodo->get_colision() == 0){
	        if(valor < nodo->get_dato()) eliminaRama(nodo->get_izq(), valor); // Si el dato es mayor que el que se quiere eliminar, se vuelve a llamar al metodo con la rama izquierda
	        else if ( nodo->get_dato() < valor) eliminaRama(nodo->get_der(), valor); // Si el dato es menor que el que se quiere eliminar, se vuelve a llamar al metodo con la rama derecha
	        else
	          { eliminado = nodo;
	            if(nodo->get_der() == NULL) nodo = nodo->get_izq(); // Si la rama derecha esta vacia, se sustituye el nodo a eliminar por el nodo raiz de la rama izquierda
	            else if(nodo->get_izq() == NULL) nodo = nodo -> get_der(); // Si la rama izquierda esta vacia, se sustituye el nodo a eliminar por el nodo raiz de la rama derecha
	            else sustituir(eliminado, nodo->get_izq());  // Si el nodo tiene 2 hijos, se intercambia el dato a eliminar con el mayor de la rama izquierda
	            delete(eliminado);
	          }
	    }
		else{
		 nodo->disminuir_colision();
		 cout << "Colision" << nodo->get_colision() << endl;
		}
      }

	/* Busca un dato en una rama */
  bool buscarRama(nodoBB<Clase>* &nodo, Clase valor)
    { bool resultado;
      incrementarcontador();
      if (nodo == NULL) return 1;
      if(valor < nodo->get_dato()) resultado = buscarRama(nodo->get_izq(), valor);
      else if ( nodo->get_dato() < valor) resultado =buscarRama(nodo->get_der(), valor);
      else return true;
      return resultado;
    }


  public:

   ABB() { root= nullptr;}

   /* Calculamos la altura del arbol */
   int calcularaltura ( nodoBB <Clase> *nodo)
      { if ( nodo == NULL ) return 0;
        int alt_i = calcularaltura ( nodo->get_izq());
        int alt_d = calcularaltura ( nodo->get_der());
        return max(alt_d, alt_i) + 1;
      }
	
	/* Vamos imprimiendo todos los niveles del arbol */
    void imprimirporniveles()
     {int nivelactual;
      bool aux;
      int nivelmax;
      if(root == NULL) cout << endl << "ARBOL VACIO" << endl;
      nivelmax = calcularaltura ( root );
       nivelactual = 0;
          do
            {cout << "Nivel " << nivelactual << ": ";
             aux = imprimirnivel(nivelactual, 0, root);
             cout << endl;
             nivelactual++;
            } while (nivelactual <= nivelmax );
      }

   /* Inserta un dato en el arbol */
   void insertar(Clase valor)
      {
       insertarRama( root, valor);
      }

	/* Elimina un dato del arbol */
    void eliminar(Clase valor)
      {
       eliminaRama(root, valor);
      }
	
	/* Buscar un elemento en el arbol */
    bool buscar(Clase valor)
      { 
        return buscarRama(root, valor);
      }

   //mostrar resultados, dividiendo media primero
   void mostrarresultados(string s, int nPruebas, int N)
    {media = media/nPruebas;
     cout << s << ": ";
      cout <<" " << setw(8) << N << " " << setw(8) << nPruebas << " " << setw(8) << minimo << " " << setw(8)<< media << " " << setw(8) <<  maximo << " " << setw(8) << calcularaltura(root) << endl;
    }

  //calcula min y max
  void calcular()
    {minimo = min(contador, minimo);
     maximo = max(maximo, contador);
     media += contador;
    }


  void reseteo() { contador = 0;}
  void reseteototal ()
    { minimo = INFINITY;
      maximo = 0;
      media = 0;
    }

};
