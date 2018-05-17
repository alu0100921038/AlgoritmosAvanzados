#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

template <class Clase>
class nodoBB
{ Clase dato;
  int balanceo;
  nodoBB <Clase>* izq;
  nodoBB<Clase>* der;

  public:
/*  nodoBB(const Clase data, nodoBB* left = NULL, nodoBB* right = NULL)
    { izq = left;
      dato = data;
      der = right;
    }
    */
  nodoBB(const Clase data)
    { izq = NULL;
      dato = data;
      der = NULL;
      balanceo = 0;
    }

  void mostrar()
    { cout << "[" << dato << ";" << balanceo << "]";
    }

  void set_dato(Clase data) { dato = data;}
  Clase get_dato() {return dato;}
  nodoBB<Clase>* &get_izq () {return izq;}
  nodoBB<Clase>* &get_der () {return der;}
  int get_bal(){return balanceo;}
  void set_bal(int bal) {balanceo = bal;}


};


template <class Clase>
class AVL
{ private:
  nodoBB <Clase>* root;
  int minimo, maximo;
  float media;
  int contador;


  void incrementarcontador() { contador++;}

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
       { nodo-> mostrar();}
      return false;
    }

/*ROTACIONES*/
//////////////////////////////
  void rotacion_II(nodoBB<Clase>* &nodo)
    {//cout << "ROTAMOS II" << endl;
     nodoBB<Clase>* nodo1 = nodo->get_izq();
     nodo->get_izq() = nodo1 -> get_der();
     nodo1->get_der() = nodo;
     if(nodo1->get_bal() == 1)
        {nodo->set_bal(0); nodo1->set_bal(0);
        }
     else //==0
        {nodo->set_bal(1); nodo1->set_bal(-1);
        }
     nodo = nodo1;
    }

  void rotacion_DD (nodoBB<Clase>* &nodo)
      {//cout << "ROTAMOS DD" << endl;
        nodoBB<Clase>* nodo1 = nodo->get_der();
        nodo->get_der() = nodo1->get_izq();
        nodo1->get_izq() = nodo;
        if(nodo1->get_bal() == -1)
          {nodo->set_bal(0);
           nodo1->set_bal(0);
          }
        else //==0
          {nodo->set_bal(-1);
           nodo1->set_bal(1);
          }
        nodo = nodo1;
      }

  void rotacion_ID (nodoBB<Clase>* &nodo)
      {//cout << "ROTAMOS ID" << endl;
       nodoBB<Clase>* nodo1 = nodo->get_izq();
       nodoBB<Clase>* nodo2 = nodo1->get_der();
       nodo->get_izq() = nodo2->get_der();
       nodo2->get_der() = nodo;
       nodo1->get_der() = nodo2->get_izq();
       nodo2->get_izq() = nodo1;
       if(nodo2->get_bal() == -1) nodo1->set_bal(1);
       else nodo1->set_bal(0);
       if(nodo2->get_bal() == 1) nodo->set_bal(-1);
       else nodo->set_bal(0);
       nodo2->set_bal(0);
       nodo = nodo2;
      }

  void rotacion_DI (nodoBB<Clase>* &nodo)
      {//cout << "ROTAMOS DI" << endl;
       nodoBB<Clase>* nodo1 = nodo->get_der();
       nodoBB<Clase>* nodo2 = nodo1->get_izq();
       nodo->get_der() = nodo2->get_izq();
       nodo2->get_izq() = nodo;
       nodo1->get_izq() = nodo2->get_der();
       nodo2->get_der() = nodo1;
       if(nodo2->get_bal() == 1) nodo1->set_bal(-1);
       else nodo1->set_bal(0);
       if(nodo2->get_bal() == -1) nodo->set_bal(1);
       else nodo->set_bal(0);
       nodo2->set_bal(0);
       nodo = nodo2;
      }

/*METODOS INSERCION*/
/////////////////////////////////
  void insert_rebalancear_izq(nodoBB<Clase>* &nodo, bool& crece)
      { switch (nodo->get_bal())
          {case -1: nodo -> set_bal(0);
                    crece = false;
                    break;
           case 0: nodo->set_bal(1);
                    break;
           case 1: nodoBB<Clase>* nodo1 = nodo->get_izq();
                    if(nodo1->get_bal() == 1) rotacion_II(nodo);
                    else rotacion_ID(nodo);
                    crece = false;
          }
      }

    void insert_rebalancear_der(nodoBB<Clase>* &nodo, bool& crece)
      { switch (nodo -> get_bal())
          {case 1: nodo -> set_bal(0);
                    crece = false;
                    break;
           case 0: nodo -> set_bal(-1);
                    break;
           case -1: nodoBB<Clase>* nodo1 = nodo->get_der();
                    if(nodo1-> get_bal() == -1) rotacion_DD(nodo);
                    else rotacion_DI(nodo);
                    crece = false;
          }
      }

  void insertarBalanceo( nodoBB<Clase>* &nodo, nodoBB<Clase>* nuevo, bool& crece)
     {if ( nodo == NULL )
        {nodo = nuevo; crece = true;
        }
      else if ( nuevo->get_dato() < nodo->get_dato() )
        {insertarBalanceo( nodo->get_izq(), nuevo, crece);
         if(crece) insert_rebalancear_izq (nodo, crece);
        }
      else
        {insertarBalanceo( nodo->get_der(), nuevo, crece);
         if(crece) insert_rebalancear_der (nodo, crece);
        }
    }

  /*METODOS DE ELIMINACION*/
  /////////////////////////////
  void delete_rebalancear_izq(nodoBB<Clase>* &nodo,  bool& decrece)
    {switch (nodo->get_bal())
      {case -1:
                {nodoBB<Clase>* nodo1 = nodo->get_der();
                if(nodo1->get_bal() > 0) rotacion_DI(nodo);
                else
                  {if(nodo1->get_bal() == 0) decrece = false;
                   rotacion_DD(nodo);
                  }
                break;
                }
       case 0: nodo->set_bal(-1); decrece = false; break;
       case 1: nodo->set_bal(0);
      }
    }

  void delete_rebalancear_der(nodoBB<Clase>* &nodo,  bool& decrece)
    {switch (nodo->get_bal())
      {case 1:
               {nodoBB<Clase>* nodo1 = nodo->get_izq();
                if(nodo1->get_bal() < 0) rotacion_ID(nodo);
                else
                  {if(nodo1->get_bal() == 0) decrece = false;
                   rotacion_II(nodo);
                  }
                break;
               }
       case 0:  nodo->set_bal(1); decrece = false; break;
       case -1: nodo->set_bal(0);
      }
    }

  void sustituir(nodoBB<Clase>* &eliminado, nodoBB<Clase>* &sust, bool &decrece)
    { if(sust->get_der() != NULL)
        {sustituir(eliminado, sust->get_der(), decrece);
         if(decrece) delete_rebalancear_der(sust, decrece);
        }
      else
        {eliminado->set_dato( sust->get_dato());
         eliminado = sust;
         sust = sust->get_izq();
         decrece = true;
        }
    }

  void eliminaRama (nodoBB<Clase>* &nodo, Clase valor, bool& decrece)
    { nodoBB<Clase>* eliminado;
        if(nodo == NULL) return;
        if(valor < nodo->get_dato())
          {eliminaRama(nodo->get_izq(), valor, decrece);
          if (decrece) delete_rebalancear_izq(nodo, decrece);
          }
        else if ( nodo->get_dato() < valor)
          {eliminaRama(nodo->get_der(), valor, decrece);
          if (decrece) delete_rebalancear_der(nodo, decrece);
          }
        else //clave = nodo->get_dato()
          { eliminado = nodo;
            if(nodo->get_der() == NULL)
              {nodo = nodo->get_izq();
               decrece = true;
              }
            else if(nodo->get_izq() == NULL)
              {nodo = nodo -> get_der();
               decrece = true;
              }
            else
              {sustituir(eliminado, nodo->get_izq(), decrece);
               if(decrece) delete_rebalancear_izq(nodo, decrece);
              }
            delete(eliminado);
          }
      }

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

   AVL() { root= nullptr;}


   int calcularaltura ( nodoBB <Clase> *nodo)
      { if ( nodo == NULL ) return 0;
        int alt_i = calcularaltura ( nodo->get_izq());
        int alt_d = calcularaltura ( nodo->get_der());
        return max(alt_d, alt_i) + 1;
      }

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


   void insertar(Clase valor)
      {nodoBB<Clase>* nuevo =  new nodoBB<Clase>(valor);
       bool crece = false;
       insertarBalanceo( root, nuevo, crece);
      }


    void eliminar(Clase valor)
      {bool decrece = false;
       eliminaRama(root, valor, decrece);
      }


  /*  void buscarinsertar(Clase valor)
      { if(!buscarRama(root, valor)) insertar(valor);
      }
  */

    bool buscar(Clase valor)
      { //cout << endl << "BUSCAR " << valor << endl;
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
