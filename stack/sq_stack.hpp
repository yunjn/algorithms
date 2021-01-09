#ifndef _SQ_STACK_HPP_
#define _SQ_STACK_HPP_

#define SElemType int
#include <iostream>
#define STACK_INIT_SIZE 50  // init
#define STACKINCREMENT 10   // increment

typedef struct {
  SElemType* base{nullptr};
  SElemType* top{nullptr};
  int stacksize{0};
} SqStack;

using std::cout;
using std::endl;

void ReNew(SqStack& S) {
  SElemType* new_base = new SElemType[S.stacksize + STACKINCREMENT];
  for (int i = 0; i < S.stacksize; i++) new_base[i] = S.base[i];
  delete[] S.base;
  S.base = new_base;
  S.top = S.base + S.stacksize;
  S.stacksize += STACKINCREMENT;
}

void InitStack(SqStack& S) {
  S.base = new SElemType[STACK_INIT_SIZE];
  if (!S.base) cout << "[error]: initialization failed" << endl;
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
}

void DestoryStack(SqStack& S) {
  delete[] S.base;
  S.base = nullptr;
  cout << "stack has been destoryed" << endl;
}

void ClearStack(SqStack& S) { S.top = S.base; }

bool StackEmpty(const SqStack S) {
  if (S.top == S.base)
    return true;
  else
    return false;
}

int StackLength(const SqStack S) { return int(S.top - S.base); }

SElemType GetTop(const SqStack S) {
  if (S.top == S.base) {
    cout << "[warning]: Empty stack" << endl;
    return false;
  }
  return *(S.top - 1);
}

void Push(SqStack& S, const SElemType e) {
  if (S.top - S.base >= S.stacksize) ReNew(S);
  *S.top++ = e;
}

SElemType Pop(SqStack& S) {
  if (S.top == S.base) {
    cout << "[error]: Empty stack" << endl;
    return false;
  }
  SElemType e = *--S.top;
  return e;
}

void LOG(const SqStack S) {
  cout << "Length: " << StackLength(S) << endl << "base -> top:" << endl;
  for (int i = 0; i < S.top - S.base; i++) cout << S.base[i] << " ";
  cout << endl;
}

void Conversion(long num, int R) {
  long temp = num;
  if (R <= 1) cout << "R vaule is illegal" << endl;
  SqStack S;
  InitStack(S);
  while (temp) {
    Push(S, temp % R);
    temp /= R;
  }
  cout << num << "(10) 的 " << R << " 进制为: ";
  while (!StackEmpty(S)) cout << Pop(S);
  cout << endl;
  DestoryStack(S);
}
#endif
