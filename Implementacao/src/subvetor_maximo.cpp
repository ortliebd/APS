#include <iostream>
#include <vector>
#include <time.h>
#include <limits>

using namespace std;

vector<int> findMaxCrossingSubArray (vector<int>, int, int, int);
vector<int> findMaximumSubArray (vector<int>, int, int);

int _inner_loop = 0;

int main (int argc, char **argv) {
  clock_t execution_time;

  int in;
  vector<int> max_subarray;

  vector<int> vetor;

  while (cin >> in) {
    vetor.push_back(in);
  }

  execution_time = clock ();
  max_subarray =  findMaximumSubArray(vetor, 0, vetor.size() - 1);
  execution_time = clock() - execution_time;

  cout << ((float)execution_time)/CLOCKS_PER_SEC << "\n";
  cout << _inner_loop << "\n";
  
  return 0;
}

vector<int> findMaxCrossingSubArray (vector<int> v, int left, int mid, int right) {
  int sum_left = numeric_limits<int>::max() * - 1;
  int sum = 0;
  int max_left;
  int max_right;

  for (int i = mid; i >= left; i--) {
    sum += v[i];
    if (sum > sum_left) {
      sum_left = sum;
      max_left = i;
    }
    _inner_loop++;
  }

  int sum_right = numeric_limits<int>::max() * - 1;
  sum = 0;
  for (int i = mid + 1; i <= right; i++) {
    sum += v[i];
    if (sum > sum_right) {
      sum_right = sum;
      max_right = i;
    }
    _inner_loop++;
  }

  vector<int> return_values;
  return_values.push_back(max_left);
  return_values.push_back(max_right);
  return_values.push_back(sum_left + sum_right);
  return return_values;
}
vector<int> findMaximumSubArray (vector<int> v, int left, int right) {
  vector<int> return_values;
  vector<int> left_return;
  vector<int> right_return;
  vector<int> cross_return;
  
  int mid;
  
  if (left == right) {    
    return_values.push_back(left);
    return_values.push_back(right);
    return_values.push_back(v[left]);
    return return_values;
  } else {
    mid = (left + right) / 2;
    left_return = findMaximumSubArray (v, left, mid);
    right_return = findMaximumSubArray (v, mid + 1, right);
    cross_return = findMaxCrossingSubArray (v, left, mid, right);
    if (left_return[2] >= right_return[2] && left_return[2] >= cross_return[2])
      return left_return;
    else if (right_return[2] >= left_return[2] && right_return[2] >= cross_return[2])
      return right_return;
    else
      return cross_return;
  }
}
