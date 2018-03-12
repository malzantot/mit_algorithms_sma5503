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


template <typename T>
void PrintArray(const vector<T>& array) {
    for (const T& x : array) {
      cout << x << " ";
    }
    cout << endl;
}


/**
  Sorts an array using insertion sort algorithm.
**/
template <typename T>
void InsertionSort(vector<T>& arr) {
  const int n = arr.size();
  for (int i = 1; i < n; ++i) {
    T key = arr[i];
    int j = i - 1;
    for ( ; j >= 0; j--) {
      if (arr[j] < key) break;
      arr[j+1] = arr[j];
    }
    arr[j+1] = key;
  }
}


int main() {
  cout << "Enter number of inputs: ";
  int n; cin >> n;
  vector<int> vec(n);
  cout << "Enter " << n << " input numbers : ";
  for (int i = 0; i < n; i++)
    cin >> vec[i];
  cout << endl;

  cout << "Before Sorting :" << endl;
  PrintArray(vec);

  InsertionSort(vec);
  cout << "After Sorting :" << endl;
  PrintArray(vec);
  return 0;
}
