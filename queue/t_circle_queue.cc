#include <iostream>

#include "circle_queue.hpp"

using namespace std;

int main() {
  CircleQueue Q;
  InitQueue(&Q);
  int i = 1;
  while (EnQueue(&Q, i)) ++i;
  Print(&Q);
  while (DeQueue(&Q)) --i;
  Print(&Q);
  while (EnQueue(&Q, i)) ++i;
  Print(&Q);
  for (int j = 0; j < 10; j++) DeQueue(&Q);
  Print(&Q);
  DestoryQueue(&Q);
  return 0;
}
