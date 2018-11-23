#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int _inner_loop = 0;

int partition (vector<int> *, int, int);
void quickSort (vector<int> *, int, int);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  quickSort(&vetor, 0, vetor.size() - 1);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

int partition (vector<int> *v, int low, int high) {
  int pivot = v->at(high);
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (v->at(j) <= pivot)
      swap (v->at(++i), v->at(j));
    _inner_loop++;
  }

  swap (v->at(i + 1), v->at(high));

  return (i + 1);
}

void quickSort (vector<int> *v, int low, int high) {
  if (low < high) {
    int index_partition = partition (v, low, high);

    quickSort (v, low, index_partition - 1);
    quickSort (v, index_partition + 1, high);
  }
}
