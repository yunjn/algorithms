#ifndef LINK_QUEUE
#define LINK_QUEUE
#include <iostream>

typedef int ElemType;

typedef struct Node {
  ElemType data{0};
  struct Node* next{nullptr};
} Node, *node_ptr;

typedef struct {
  Node* front{nullptr};
  Node* rear{nullptr};
} Queue;

bool InitQueue(Queue* Q) {
  if (!Q) return false;
  Q->front = Q->rear = new Node;
  Q->front->next = nullptr;
  return true;
}

int QueueLength(Queue* Q) {
  node_ptr pmove = Q->front->next;
  int sum = 0;
  while (pmove) ++sum, pmove = pmove->next;
  return sum;
}

bool QueueEmpty(Queue* Q) { return Q->rear == Q->front; }

void EnQueue(Queue* Q, ElemType e) {
  node_ptr new_node = new Node;
  new_node->data = e;
  new_node->next = nullptr;
  Q->rear->next = new_node;
  Q->rear = new_node;
}

ElemType DeQueue(Queue* Q) {
  if (QueueEmpty(Q)) return false;
  ElemType data = Q->front->next->data;
  node_ptr to_del = Q->front;
  Q->front = Q->front->next;
  delete to_del;
  return data;
}

ElemType GetHead(Queue* Q) {
  if (QueueEmpty(Q)) return false;
  return Q->front->next->data;
}

void DestoryQueue(Queue* Q) {
  node_ptr to_del = Q->front;
  node_ptr pmove = Q->front;
  while (pmove) {
    pmove = pmove->next;
    delete to_del;
    to_del = pmove;
  }
  Q->front = Q->rear = nullptr;
}

void Print(Queue* Q) {
  if (QueueEmpty(Q)) return;
  node_ptr pmove = Q->front->next;
  std::cout << "Length: " << QueueLength(Q) << std::endl << "[";
  while (pmove->next) {
    std::cout << pmove->data << ",";
    pmove = pmove->next;
  }
  std::cout << pmove->data << "]" << std::endl;
}

#endif