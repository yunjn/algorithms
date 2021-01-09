#ifndef _LINK_STACK_HPP_
#define _LINK_STACK_HPP_
#include <iostream>
#define SElemType int

typedef struct StackNode {
  SElemType data{0};
  struct StackNode *next{nullptr};
} stack_node, *ptr_node;

typedef struct LinkStack {
  ptr_node top{nullptr};
  int length{0};
} LinkStack;

using std::cout;
using std::endl;

void Push(LinkStack &S, const SElemType e) {
  ptr_node node = new stack_node;
  node->data = e;
  node->next = S.top;
  S.top = node;
  S.length++;
}

bool StackEmpty(const LinkStack S) {
  if (!S.top) return true;
  return false;
}

SElemType Pop(LinkStack &S) {
  if (StackEmpty(S)) return false;
  ptr_node to_del = S.top;
  SElemType e = S.top->data;
  S.top = S.top->next;
  delete to_del;
  S.length--;
  return e;
}

int StackLength(const LinkStack S) { return S.length; }

SElemType GetTop(const LinkStack S) { return S.top->data; }

void LOG(const LinkStack S) {
  cout << "length: " << S.length << endl;
  ptr_node pmove = S.top;
  while (pmove) {
    cout << pmove->data << " ";
    pmove = pmove->next;
  }
  cout << endl;
}

void DestoryStack(LinkStack &S) {
  ptr_node pmove{S.top};
  while (S.top) {
    pmove = S.top;
    S.top = S.top->next;
    delete pmove;
  }
}

#endif
