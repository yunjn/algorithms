#include <iostream>

#include "link_stack.hpp"
using namespace std;

int main() {
  LinkStack S;
  for (int i = 20; i >= 1; i--) Push(S, i);
  LOG(S);
  for (int i = 1; i <= 20; i++) Pop(S);
  LOG(S);
  for (int i = 10; i >= 1; i--) Push(S, i);
  LOG(S);
  cout << "栈顶元素为" << GetTop(S) << endl;
  DestoryStack(S);
  return 0;
}