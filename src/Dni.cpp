#include <iostream>
#include <string>

#include "Dni.hpp"


Dni::Dni()
  {for(int i=0; i<7; i++){
    digito[i] = '0'+ rand()% 9;
    //letra += digito[i];
    }
    //int numero = atoi(letra.c_str());
    //digito[8] = letras[numero%23];
  }

Dni::operator unsigned long ()
{unsigned long resultado, base;
  base=1;
  resultado = 0;
  //resultado += (digito[8] - 'A')* base;
  for(int i=7; i>=0; i--)
    {resultado += (digito[i] -'0')* base;
     base *= 10;
    }
    return resultado;
}

int Dni::suma()
  {int resultado;
   resultado = 0;
   for(int i=0; i<7; i++)
   { resultado+=digito[i]-'0';
   }
   //resultado += digito[8] - 'A';
   return resultado;
  }

Dni& Dni::operator= (const string& m)
  {for(int i=0; i<7; i++)
  { digito[i] = m[i];
  }
  return *this;
}


bool Dni::operator== (const Dni& m) const
  {bool resultado;
   resultado = true;
   for(int i=0; i<7; i++)
   { if ( digito[i] != m.digito[i] ) resultado = false;
  }
  return resultado;
}


bool Dni::operator< (const Dni& m) const
{ bool resultado;
  for(int i=0; i<7; i++)
    {if(digito[i] < m.digito[i]) return true;
    else if(digito[i] > m.digito[i]) return false;
    }
  return false;
}

ostream& operator<< (ostream& os, const Dni &m)
{for(int i=0; i<7; i++)
  { os << m.digito[i];
  }
    return os;
}
