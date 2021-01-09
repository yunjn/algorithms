#include <iostream>

#include "link_queue.hpp"
using namespace std;
int main() {
  Queue Q;
  InitQueue(&Q);
  for (int i = 1; i <= 10; i++) EnQueue(&Q, i);
  Print(&Q);
  for (int i = 0; i < 9; i++) DeQueue(&Q);
  Print(&Q);
  cout << GetHead(&Q) << endl;
  DestoryQueue(&Q);
  return 0;
}
