#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>

using namespace std;

long long int _inner_loop = 0;

void bubbleSort (vector<int> *);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  bubbleSort(&vetor);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

void bubbleSort (vector<int> *v) {
  for (int i = 0; i < v->size() - 1; i++)
    for (int j = 0; j < v->size() - i - 1; j++) {
      if (v->at(j) > v->at(j+1))
	swap (v->at(j), v->at(j+1));
      _inner_loop++;
    }
}
	  
		
