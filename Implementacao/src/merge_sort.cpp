#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>

using namespace std;

int _inner_loop = 0;

void merge (vector<int> *, int, int, int);
void mergeSort (vector<int> *, int, int);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  mergeSort(&vetor, 0, vetor.size() - 1);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
 
  return 0;
}

void merge (vector<int> *v, int l, int m, int r) {
  int index_left = m - l + 1;
  int index_right = r - m;

  int sub_vector_left[index_left];
  int sub_vector_right[index_right];

  for (int i = 0; i < index_left; i++) {
    sub_vector_left[i] = v->at(l + i);
    _inner_loop++;
  }
  for (int i = 0; i < index_right; i++) {
    sub_vector_right[i] = v->at(m + 1 + i);
    _inner_loop++;
  }

  int i = 0;
  int j = 0;
  int k = l;

  while (i < index_left && j < index_right) {
    if (sub_vector_left[i] <= sub_vector_right[j])
      v->at(k) = sub_vector_left[i++];
    else
      v->at(k) = sub_vector_right[j++];
    k++;
  }

  while (i < index_left)
    v->at(k++) = sub_vector_left[i++];
  while (j < index_right)
    v->at(k++) = sub_vector_right[j++];
}

void mergeSort (vector<int> *v, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort (v, l, m);
    mergeSort (v, m + 1, r);

    merge (v, l, m, r);
  }
}
	  
		
