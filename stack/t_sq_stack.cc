#include <iostream>

#include "sq_stack.hpp"
using namespace std;

int main() {
  SqStack S;
  InitStack(S);
  for (int i = 1; i <= 20; i++) Push(S, i);
  LOG(S);
  for (int i = 1; i <= 10; i++) Pop(S);
  LOG(S);
  Push(S, 11);
  LOG(S);
  cout << "栈顶元素为" << GetTop(S) << endl;
  ClearStack(S);
  if (StackEmpty(S)) cout << "此时为空栈" << endl;
  DestoryStack(S);
  Conversion(201930, 8);  // 17027021330
  return 0;
}