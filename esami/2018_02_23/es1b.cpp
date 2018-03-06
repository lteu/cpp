#include <iostream>
using namespace std;

int f(char s[], int l){
    if (l > 1){
    	if(*s == 'c' || *s == 'g'){
    		// cout << *s << endl;
    		// cout << *(s+1) << endl;
    		if(*(s+1) == 'h'){
    			return true;
    		}
    	}
    	return f(s+1,l-1);
    }

    return false;
}


int main () {
  
  char stringa[] = "xxxxx";
  int l = sizeof(stringa)/sizeof(char);
  cout << "result: " << f(stringa,l) << endl;
  return 0;
}