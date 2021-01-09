/*****************************************************
 * 少用一个单元，方便判断
 * 判空条件：Q->front == Q->rear
 * 判满条件：Q->front == (Q->rear + 1) % MAX_SIZE
 * 队列长度：(Q->rear - Q->front + MAX_SIZE) % MAX_SIZE
 * ***************************************************/
#ifndef CIRCLE_QUEUE
#define CIRCLE_QUEUE
#include <iostream>

#define MAX_SIZE 21
typedef int ElemType;
typedef struct {
  ElemType data[MAX_SIZE];
  int front;
  int rear;
} CircleQueue;

void InitQueue(CircleQueue *Q) { Q->front = Q->rear = 0; }

bool IsFull(CircleQueue *Q) { return (Q->rear + 1) % MAX_SIZE == Q->front; }

bool QueueEmpty(CircleQueue *Q) { return Q->rear == Q->front; }

int QueueLength(CircleQueue *Q) {
  return (Q->rear - Q->front + MAX_SIZE) % MAX_SIZE;
}

bool EnQueue(CircleQueue *Q, ElemType e) {
  if (IsFull(Q)) return false;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAX_SIZE;
  return true;
}

ElemType DeQueue(CircleQueue *Q) {
  if (QueueEmpty(Q)) return false;
  ElemType e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAX_SIZE;
  return e;
}

void DestoryQueue(CircleQueue *Q) { Q->front = Q->rear = 0; }

void Print(CircleQueue *Q) {
  if (QueueEmpty(Q)) {
    std::cout << "[warning]: Length = 0" << std::endl;
    return;
  }
  int move = Q->front;
  std::cout << "Length: " << QueueLength(Q) << std::endl << "[";
  while (move != Q->rear) {
    std::cout << Q->data[move] << " ";
    move = (move + 1) % MAX_SIZE;
  }
  std::cout << "]" << std::endl;
}

ElemType GetHead(CircleQueue* Q) {
  if (QueueEmpty(Q)) return false;
  return Q->data[Q->front];
}

#endif