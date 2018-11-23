#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

long long int _inner_loop = 0;

void selectionSort (vector<int> *);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  selectionSort(&vetor);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

void selectionSort (vector<int> *v) {
  int min_index;
  for (int i = 0; i < v->size() - 1; i++) {
    min_index = i;
    for (int j = i + 1; j < v->size(); j++) {
      if (v->at(j) < v->at(min_index)) min_index = j;
      _inner_loop++;
    }
    swap (v->at(min_index), v->at(i));
  }
}
	  
		
