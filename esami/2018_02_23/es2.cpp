#include <iostream>
#include <string>
#include <sstream>
using namespace std;



struct artista {
  bool tipo;
  char *nome;
};

struct brano {
  const char *titolo;
  artista a;
  int durata;
  brano * next;
};


void getTitleWithDuration(brano *s, char *c){
  brano *tmp = s;
  int durata_max = 0;
  while (tmp!=NULL) {
    if (tmp->durata > durata_max) {
      strcpy(c, tmp->titolo);
      durata_max = tmp->durata;
    }
    tmp = tmp->next;
  }
  
}

// debug only
void stampa(brano *s){
  brano *tmp = s;
  while (tmp!=NULL) {
    cout << tmp->titolo << " * ";
    tmp = tmp->next;
  }
  cout << endl;
}

brano* ordina(brano *head){
  brano *tmp = head;
  while (tmp->next!=NULL) {
  if (!tmp->next->a.tipo)
    {
      brano *gruppo= tmp->next;
      tmp->next = tmp->next->next;
      gruppo->next = head;
      head = gruppo; 
    }else
      tmp = tmp->next;
  }
  return head;
}

int main ()
{


  artista a1,a2;
  a1.tipo = true;
  a1.nome = (char *)"hi-life";

  a2.tipo = false;
  a2.nome = (char *)"gi-life";

  brano b1,b2,b3,b4,b5;
  b1.titolo = "c1";
  b1.a = a1;
  b1.durata = 2;
  
  b2.a = a2;
  b2.titolo = "g2";
  b2.durata = 1;

  b3.a = a1;
  b3.titolo = "c3";
  b3.durata = 2;

  b4.a = a2;
  b4.titolo = "g4";
  b4.durata = 6;

  b5.a = a1;
  b5.titolo = "c5";
  b5.durata = 3;

  b1.next = &b2;
  b2.next = &b3;
  b3.next = &b4;
  b4.next = &b5;
  b5.next = NULL;

  char chr[20]; 

  getTitleWithDuration(&b1, chr);

  stampa(&b1);
  stampa(ordina(&b1));
  return 0;
}