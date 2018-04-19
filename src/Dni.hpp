#include <string>

using namespace std;

class Dni : private string
{ char digito[9];
  string letra;
  string nombre;
  char letras[23]={'T','R','W','A','G','M','Y','F','P',
  				'D','X','B','N','J','Z','S','Q','V','H',
				  'L','C','K','E'};

 public:
 Dni();
 int suma();
 operator unsigned long();
 Dni& operator= (const string& m);
 bool operator== (const Dni& m) const;
 bool operator< (const Dni& m) const;
 
 friend ostream& operator<<(ostream& os, const Dni &m);
};



