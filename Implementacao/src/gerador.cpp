#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main (int argc, char *argv[]) {
  int qtd = atoi(argv[1]);
  int n = 0;

  srand (time(NULL));

  for (int i=0; i<qtd; i++) {
    n = rand() % 1000;
    if ( (rand() % 2) == 0)
      cout << (n * -1) << " ";
    else
      cout << n << " ";
  }
  cout << "\n";
  
  return 0;
}
