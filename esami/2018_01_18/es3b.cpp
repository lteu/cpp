// un altro modo di dichiarazione

#include <iostream>
using namespace std;


class Abitazione {
  protected: int metratura, stanze;
  public:
    Abitazione();
    // Abitazione (int m,int s); // modo 1
    Abitazione (int,int); // modo 2
    int prezzo (int p);
    float area_stanza (void) {return ((float) metratura/stanze);} // test
};

Abitazione::Abitazione (int m,int s){
  metratura = m;
  stanze = s;
}

Abitazione::Abitazione (){
}

int Abitazione::prezzo (int p){
  return p * metratura;
}

class Apartamenti: Abitazione {
  public: int piani, metratura, stanze;

  public:
     Apartamenti (int m,int s, int p);
   
};

Apartamenti::Apartamenti (int m,int s, int p){
    piani = p;
    metratura = m;
    stanze = s;
}

class Viletta:public Abitazione {
  public:
    Viletta (int m,int s);
    virtual double prezzo_r(int p); // virtual is optional
    // virtual keyword tells the compiler not to make the decision (of function binding) at compile time, rather postpone it for run time
};

// approccio migliore
Viletta::Viletta(int m,int s):Abitazione(m,s){
}

// approccio possibile ma non conviene
// Viletta::Viletta(int m,int s){
//   metratura = m,
//   stanze =  s;
// }

double Viletta::prezzo_r(int p){
   // return (double)this->metratura * p * 1.1; // modo 1
   return (double)Abitazione::prezzo(p) * 1.1; // modo 2
}
int main () {
  Apartamenti appt (3,4,5); // modo 1, per il metodo usate appt.metodo
  Viletta *v =  new Viletta(3,4); // modo 2, per il metodo usate appt->metodo

  cout << "p: " << appt.piani << endl;
  cout << "prezzo: " << v->prezzo_r(3) << endl;
  return 0;
}