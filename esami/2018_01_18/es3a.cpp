#include <iostream>
using namespace std;

class Abitazione {
  private: int metratura, stanze;
  public:
    Abitazione (int m,int s){
      metratura = m;
      stanze = s;
    }

    Abitazione (){
    }
    

   

    int prezzo (int p){
      return p * metratura;
    }
};


class Apartamenti:public Abitazione {
  public: int piani;
  public:

    // approccio 1
    // Apartamenti (int m,int s, int p): Abitazione(m,s){
    //   piani = p;
    // }

    // approccio 2
    Apartamenti (int m,int s, int p){
      Abitazione::Abitazione(m,s);
      piani = p;
    }
};

class Viletta:public Abitazione {
  public:
    Viletta (int m,int s):Abitazione(m,s){
    }
    double prezzo(int p){
      return (double)Abitazione::prezzo(p) * 1.1;
    }
};

int main () {
  Apartamenti appt1 (3,4,5);
  Apartamenti appt2 = Apartamenti(3,4,5);
  Viletta *v =  new Viletta(3,4);

  cout << "p: " << appt2.piani << endl;
  cout << "prezzo: " << v->prezzo(3) << endl;
  return 0;
}