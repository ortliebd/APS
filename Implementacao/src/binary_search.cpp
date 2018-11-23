#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>

using namespace std;

int _inner_loop = 0;

int binarySearch (vector<int>, int, int, int);

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;
  int key = atoi(argv[1]);
  int index_key;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  index_key =  binarySearch(vetor, 0, vetor.size() - 1, key);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

int binarySearch (vector<int> v, int left, int right, int key) {
  int mid = left + (right - left) / 2;
  _inner_loop++;

  if (right >= left) {

    if (v[mid] == key)
      return mid;
    
    if (v[mid] > key)
      return (binarySearch (v, left, mid - 1, key));

    return binarySearch (v, mid + 1, right, key);
  }
  
  return - 1;
}
