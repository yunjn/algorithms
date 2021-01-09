#ifndef SINGLE_LIST
#define SINGLE_LIST
#include <iostream>

/*数据域类型*/
typedef int Data;

typedef struct Node {
  Data data{0};
  struct Node *next{nullptr};
} LNode, *LinkList;

//产生空节点
LinkList InitList() {
  LinkList new_node = new LNode;
  new_node->data = 0;
  new_node->next = nullptr;
  return new_node;
}

//产生非空节点
LinkList CreateNode(const Data data) {
  LinkList new_node = new LNode;
  new_node->data = data;
  new_node->next = nullptr;
  return new_node;
}

//打印链表
void PrintList(const LinkList list) {
  if (!list->next) return;
  LinkList pmove;
  pmove = list->next;
  while (pmove) {
    std::cout << pmove->data << " ";
    pmove = pmove->next;
  }
  std::cout << std::endl;
}

//头插法
void InsertNodeHead(LinkList list, const Data data) {
  LinkList node = CreateNode(data);
  node->next = list->next;
  list->next = node;
}

//尾插法
void InsertNodeTail(LinkList list, const Data data) {
  while (list) {
    if (!list->next) {
      list->next = CreateNode(data);
      return;
    }
    list = list->next;
  }
}

// i位置前插入
void Insert(const LinkList list, const int i, const Data data) {
  LinkList pmove = list;
  int j = 0;
  while (pmove && j < i - 1) {
    pmove = pmove->next;
    ++j;
  }
  if (!pmove || j > i - 1) return;
  LinkList temp_node = CreateNode(data);
  temp_node->next = pmove->next;
  pmove->next = temp_node;
}

//得到元素
Data GetElem(const LinkList List, const int n) {
  LinkList pmove = List->next;
  int j = 1;
  while (pmove && j < n) {
    pmove = pmove->next;
    ++j;
  }
  return pmove->data;
}

//删除节点
void DeleteNode(const LinkList list, const int n) {
  int j = 1;
  LinkList pmove = list;
  while (pmove && j < n) {
    pmove = pmove->next;
    ++j;
  }
  LinkList del_node = pmove->next;
  pmove->next = del_node->next;
  delete del_node;
}

//删除链表
void DeleteList(LinkList list) {
  LinkList pmove;
  while (list) {
    pmove = list;
    list = list->next;
    delete pmove;
    pmove = nullptr;
  }
}

//合并
LinkList MergeList(LinkList La, LinkList Lb) {
  LinkList pa = La->next, pb = Lb->next, Lc = La, pc = La;
  while (pa && pb) {
    if (pa->data <= pb->data) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    } else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  pc->next = pa ? pa : pb;
  delete Lb;
  return Lc;
}
#endif
