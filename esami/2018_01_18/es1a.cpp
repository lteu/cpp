#include <iostream>
using namespace std;


void print3(int n){
  if (n > 2)
  {
    print3(n-1);
    if ((n-1) % 3 == 0)
    {
      cout << (n-1)  << ' ';
    }
  }
}

int main () {
  print3(6);
  cout << endl;
  return 0;
}