#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int _inner_loop = 0;

void heapSort (vector<int> *);
void siftDown (vector<int> *, int, int);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  heapSort(&vetor);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

void heapSort (vector<int> *v) {
  for (int i = (v->size() / 2) - 1; i >= 0; i--)
    siftDown (v, i, v->size() - 1);

  for (int i = v->size() - 1; i >= 1; i--) {
    swap (v->at(0), v->at(i));
    siftDown (v, 0, i - 1);
  }
}

void siftDown (vector<int> *v, int root, int bottom) {
  bool done = false;
  int maxChild;

  while ((root * 2 <= bottom) && (!done)) {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (v->at(root * 2) > v->at(root * 2 + 1))
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;

    if (v->at(root) < v-> at(maxChild)) {
      swap (v->at(root), v->at(maxChild));
      root = maxChild;
    } else {
      done = true;
    }
    _inner_loop++;
  }
}
