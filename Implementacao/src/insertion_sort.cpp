#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int _inner_loop = 0;

void insertionSort (vector<int> *);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  insertionSort(&vetor);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

void insertionSort (vector<int> *v) {
  int key, j;

  for (int i = 1; i < v->size(); i++) {
    key = v->at(i);
    j = i - 1;
    
    while (j >= 0 && v->at(j) > key) {
      v->at(j + 1) = v->at(j);
      j--;
      _inner_loop++;
    }
    v->at(j+1) = key;
  }
}  
