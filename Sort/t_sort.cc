#include <ctime>

#include "sort.hpp"

#define SIZE 10

using namespace std;

int main() {
#if SIZE == 10
  int arr[10]{{1}, {4}, {2}, {5}, {3}, {8}, {6}, {7}, {9}, {0}};
#else
  srand((int)time(nullptr));
  int *arr = new int[100];
  for (int i = 0; i < 100; i++) arr[i] = rand() % 100;
#endif
  MergeSort(arr, 0, SIZE - 1);
  Log(arr, SIZE);
  return 0;
}