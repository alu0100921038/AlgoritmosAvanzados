using namespace std;


template <class Clave>
void fgeneral(int funcion, Bank<Clave> &B, int tam, float alfa)
{ switch (funcion)
    { case 0: fseleccion(B, tam); break;
      case 1: fintercambio(B, tam); break;
      case 2: fmergesort(B, 0, tam-1); break;
      case 3: fquicksort(B, 0, tam-1); break;
      case 4: fshellsort(B, tam, alfa); break;
    }
   B.calcular();
}

template <class Clave>
 void fseleccion( Bank<Clave> &B, int tam)
 { int minimo;
  for(int i=0; i<(tam-1); i++)
    {minimo = i;
     for(int j=i+1; j< tam; j++)
      {if(B.menor(j, minimo)) minimo = j;
      }
      B.intercambio(minimo, i);
    }
 }


template <class Clave>
 void fintercambio( Bank<Clave> &B, int tam)
 { int inicial, fin, cambio;
   inicial = 1; fin = tam-1; cambio = tam;
   while(inicial < fin)
   {for(int j = fin; j>=inicial; j--)
    {if(B.menor(j, j-1))
      { B.intercambio(j, j-1);
       cambio = j;
      }
    }
    inicial = cambio+1;
    for(int j=inicial; j<= fin; j++)
      {if(B.menor(j,j-1))
        {B.intercambio(j, j-1);
         cambio = j;
        }
      }
     fin = cambio-1;
   }
 }


template <class Clave>
 void fmergesort( Bank<Clave> &B, int inicial, int fin)
 { int centro, i, j, k;
   if(inicial < fin)
    {centro = (inicial + fin) / 2;
     fmergesort(B, inicial, centro);
     fmergesort(B, centro+1, fin);
     i=inicial; j= centro+1; k=inicial;
     while((i<=centro) && (j<= fin))
     {if(B.menor(i,j))
        { B.almacen2aux(i,k);

         i++;
        }
      else
        {B.almacen2aux(j,k);
          j++;
        }
      k++;
     }
     if(i>centro)
        {while(j<= fin)
          { B.almacen2aux(j,k);
            j++; k++;
          }
        }
     else
        {while(i<=centro)
          {B.almacen2aux(i,k);
          i++; k++;
          }
        }
    for(int k=inicial; k<= fin; k++) B.aux2almacen(k,k);

    }
 }


template <class Clave>
 void fquicksort( Bank<Clave> &B, int inicial, int fin)
 { Clave p;
   int i, f;
   i= inicial; f=fin;
   if ( fin == (inicial + 1) )
   { if ( B.menor(fin,inicial) ) B.intercambio(fin,inicial);
     return;
   }
   p = B.get_almacen( (i + f)/2 );
   while(i < f)
    { while(B.get_almacen(i) < p)
      { B.mostrar(i,(i+f)/2, 0); i++; B.incrementarcontador();
      }
      while(p < B.get_almacen(f))
      { B.mostrar(f,(i+f)/2, 0); f--; B.incrementarcontador();
      }
      if(i < f)
        { B.intercambio(i, f);
          i++; f--;
        }
    }
//    cout << " P " << p << " ini=" << inicial << " i=" << i << " f=" << f << " fin=" << fin << endl;

    if(inicial < f) fquicksort(B, inicial, f);
    if(i<fin) fquicksort(B, i, fin);
 }


template <class Clave>
 void fshellsort( Bank<Clave> &B, int tam, float alfa)
 { for( int del=tam*alfa; del>=1; del *= alfa)
    for(int i=del; i<tam; i++)
      for(int j=i-del; j>=0 && B.menor(j+del,j); j-=del)
        B.intercambio(j, j+del);
 }



