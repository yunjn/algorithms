#ifndef SORT
#define SORT
#include <iostream>

int count = 1;
void Log(int arr[], int len) {
  try {
    if (len == 0) throw "[warning]: Empty sequence!";
    std::cout << "[" << count << "]: ";
    for (int i = 0; i < len; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    count++;
  } catch (const char *msg) {
    std::cerr << msg << std::endl;
    return;
  }
}

/*********************************归并排序*********************************
 * 分而治之：分解原问题 -> 解决子问题 -> 合并问题解
 * 递归：
 * 循环：把 n 个待排序列，看作 n 个长度为 1 的有序序列，然后两两归并...直到 1 个
 *      长度为 n 的有序序列
 **************************************************************************/

void Merge(int arr[], const int left, const int mid, const int right) {
  int i = left, j = mid + 1, k = 0;
  int *tmp = new int[right - left + 1];
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j])
      tmp[k++] = arr[i++];
    else
      tmp[k++] = arr[j++];
  }
  while (i <= mid) tmp[k++] = arr[i++];    //左边剩余
  while (j <= right) tmp[k++] = arr[j++];  //右边剩余
  for (i = left, k = 0; i <= right; i++, k++) arr[i] = tmp[k];
  delete[] tmp;  //释放内存
}

//递归,自顶向下
void MergeSort(int arr[], const int left = 0 /*start*/,
               const int right = 0 /*end*/) {
  if (left >= right) return;
  /*
  if (right - left == 1) {
    if (arr[right] < arr[left]) {
      std::swap(arr[left], arr[right]);
      return;
    }
  }*/
  int mid = (right + left) / 2;
  MergeSort(arr, left, mid);       //左边
  MergeSort(arr, mid + 1, right);  //右边
  /*减少不必要的排序，测试了n = 100 的随机无序序列50次，Log数减少了 30%-40%*/
  if (arr[mid] < arr[mid + 1]) return;
  Merge(arr, left, mid, right);  //合并
  // Log(arr, 100);
}

//循环，自底向上
void MergeSortLoop(int arr[], const int len /*sequence length*/) {
  int left, mid, right;
  for (int size = 1; size < len; size *= 2) {
    for (left = 0; left + size < len; left += 2 * size) {
      mid = left + size - 1;
      right = left + 2 * size - 1;
      if (right > len - 1) right = len - 1;
      Merge(arr, left, mid, right);
    }
  }
}

#endif