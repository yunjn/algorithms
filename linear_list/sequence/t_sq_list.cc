#include <iostream>

#include "sq_list.hpp"
using namespace std;

int main() {
#if 1
  SqList L;
  InitList(L);
  for (int i = 1; i <= 10; i++) Insert(L, i, i);
  print(L);
  cout << "3在第" << GetElem(L, 3) << "个元素" << endl;
  Delete(L, 2);
  print(L);
  cout << "3在第" << GetElem(L, 3) << "个元素" << endl;
  Insert(L, 2, 2);
  print(L);
  cout << "3在第" << GetElem(L, 3) << "个元素" << endl;
  Delete(L, 3);
  print(L);
  cout << "3在第" << GetElem(L, 3) << "个元素" << endl;
  delete[] L.elem;
#else  //合并操作
  SqList La, Lb, Lc;
  for (int i = 1, k = 1; i <= 15; i += 2, k++) Insert(La, k, i);
  cout << "La:" << endl;
  print(La);
  for (int i = 2, k = 1; i <= 10; i += 2, k++) Insert(Lb, k, i);
  cout << "Lb:" << endl;
  print(Lb);
  MergeList(La, Lb, Lc);
  cout << "Lc:" << endl;
  print(Lc);
  delete[] Lc.elem;
#endif
  return 0;
}
