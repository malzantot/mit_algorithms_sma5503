/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/

#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;


/** Prints an array **/
template <typename T>
void PrintArray(const vector<T>& arr) {
  for (const T& x : arr) {
    cout << x << " ";
  }
  cout << endl;
}



template <typename T>
void Merge(vector<T>& arr, int start1, int start2, int end) {
  int n = arr.size();
  vector<int> tmp(end-start1);
  int idx1 = start1;
  int idx2 = start2;
  int idx = start1;
  while (idx1 < start2 && idx2 < end) {
    if (arr[idx1] < arr[idx2]) {
      tmp[idx-start1] = arr[idx1];
      idx1++;
    } else {
      tmp[idx-start1] = arr[idx2];
      idx2++;
    }
    idx++;
  }
  while(idx1 < start2) {
    tmp[idx-start1] = arr[idx1];
    idx1++;
    idx++;
  }
  while (idx2 < end) {
    tmp[idx-start1] = arr[idx2];
    idx2++;
    idx++;
  }

  for (int i = start1; i < end; i++) {
    arr[i] = tmp[i-start1];
  }
}

template <typename T>
void MergeSortHelper(vector<T>& arr, int start, int end) {
  int n = end-start;
  if (n <= 1) return;
  int mid = start + n / 2;
  MergeSortHelper(arr, start, mid);
  MergeSortHelper(arr, mid, end);
  Merge(arr, start, mid, end);
}

/** Sorts an array using merge sort algorithm **/
template <typename T>
void MergeSort(vector<T>& arr) {
  const int n = arr.size();
  MergeSortHelper(arr, 0, n);
}

int main() {
  int n;
  cout << "Enter number of inputs: ";
  cin >> n;
  vector<int> vec(n);
  cout << "Enter " << n << " input numbers: ";
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  cout << endl;

  cout << "Before sorting: " << endl;
  PrintArray(vec);
  
  MergeSort(vec);
  cout << "After sorting: " << endl;
  PrintArray(vec);
  return 0;
}
