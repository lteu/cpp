// prova a giocare "public, protected e private"
// cosi capite il diritto di accesso.

#include <iostream>
using namespace std;

class Squadra {
  public:
    int scudetti;
    char *nome;
  public:
    Squadra (int scudetti,char nome[]){
      this->scudetti = scudetti;
      this->nome = nome;
    }
     ~Squadra(); // optional destructor 
};

class Calciatore {
  protected:
   Squadra *s;
   int fatti;
   char *nome;

  public:
   Calciatore (char nome[], Squadra *s, int fatti){
      this->s = s;
      fatti = fatti;
      this->nome = nome;
    }
    void incre(int n){
      fatti = fatti + n;
    }
    bool maiScudetti(){
      if(this->s->scudetti == 0){
        return true;
      }
      return false;
    }

};

class Portiere:public Calciatore {
  private: int subiti;

  public:
   Portiere (char nome[], Squadra *s,int fatti,int subiti):Calciatore(nome, s,fatti){
      this->subiti = subiti;
   }
   void incre(int n){
      subiti += n;
   }
   int numeroSubiti(){
    return subiti;
   }
};

int main () {
  char nomeSquadra[] = "Juventus"; // correct
  // char[] nomeSquadra= "Juventus"; // error
  // char *nomeSquadra = "Juventus"; // conversion deprecated

  char nomeSquadra2[] = "Monfalcone"; // correct

  Squadra *s = new Squadra (3,nomeSquadra);
  Squadra *s2 = new Squadra (0,nomeSquadra2);

  char nome1[] = "Andrea";
  char nome2[] = "Enzo";
  Calciatore *c1 = new Calciatore(nome1,s,3);
  Portiere *c2 = new Portiere(nome2,s2,0,1);

  cout << "c1 mai vinto? " << c1->maiScudetti() << endl;
  cout << "c2 mai vinto? " << c2->maiScudetti() << endl;
  cout << "c2 subiti " << c2->numeroSubiti() << endl;
  c2->incre(5);
  cout << "c2 subiti dopo aggiornamento:" << c2->numeroSubiti() << endl;
  return 0;
}