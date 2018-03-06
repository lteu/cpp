#include <iostream>
using namespace std;

int f(char *s, int l){
    if (l > 1){
      l = l - 1;
      if(s[l] == 'h' && (s[l-1] == 'c' || s[l-1] == 'g')){
        return true;
      }else
      return f(s,l);
    }
    return false;
}


int main () {
  char stringa[] = "xxghxx";
  int l = sizeof(stringa)/sizeof(char);
  cout << "result: " << f(stringa,l) << endl;
  return 0;
}