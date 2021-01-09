#include <iostream>

#include "link_list.hpp"
using namespace std;
int main() {
  LinkList list = InitList();
  for (int i = 1; i < 11; i++) Insert(list, i, i);
  PrintList(list);
  cout << GetElem(list, 1) << endl;
  DeleteNode(list, 2);
  PrintList(list);
  Insert(list, 2, 2);
  PrintList(list);

  LinkList list2 = InitList();
  for (int i = 1; i < 11; i++) Insert(list2, i, i * 2);
  PrintList(list2);
  LinkList list3 = MergeList(list, list2);
  PrintList(list3);
  // MergList();重置了list,list2的顺序，所以内存释放list3即可
  DeleteList(list3);
  return 0;
}
