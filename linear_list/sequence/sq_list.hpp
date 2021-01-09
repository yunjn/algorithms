#ifndef SQ_LIST
#define SQ_LIST
#include <iostream>
#define LIST_INIT_SIZE 50  //初始分配量
#define LISTINCRE 30       //增量
typedef int ElemType;

typedef struct {
  ElemType *elem{NULL};  //储存基地址
  int length{0};         //当前长度
  int listsize{0};       //当前分配的容量
} SqList;

using namespace std;

// recalloc
void ReNew(SqList &L) {
  ElemType *new_elem = new ElemType[L.listsize + LISTINCRE];   // new
  for (int i = 0; i < L.length; i++) new_elem[i] = L.elem[i];  // data
  delete[] L.elem;
  L.elem = new_elem;
  L.listsize += LISTINCRE;
}

//初始化
void InitList(SqList &L) {
  L.elem = new ElemType[LIST_INIT_SIZE];
  if (!L.elem) cout << "储存空间分配失败！！！" << endl;
  L.length = 0;
  L.listsize = LIST_INIT_SIZE;
}

//插入
void Insert(SqList &L, const int i, const ElemType e) {
  if (i < 1 || i > L.length + 1) return;  //检查i是否合法
  if (L.length >= L.listsize) ReNew(L);   //若内存不足，重新分配
  // ElemType *q = &(L.elem[i - 1]);
  // for (ElemType *p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
  //*q = e;
  for (int k = L.length - 1; k >= i - 1; k--) L.elem[k + 1] = L.elem[k];
  L.elem[i - 1] = e;
  L.length++;
}

//按序号删除
void Delete(SqList &L, int i) {
  if (i < 1 || i > L.length) return;  //检查i是否合法
  // for (ElemType *p = &(L.elem[i]); p < L.elem + L.length; ++p) *(p - 1) = *p;
  for (i; i < L.length; i++) L.elem[i - 1] = L.elem[i];
  L.length--;
}

//打印
void print(const SqList L) {
  for (int i = 0; i < L.length; i++) cout << L.elem[i] << " ";
  cout << endl;
}

//查找
ElemType GetElem(SqList &L, const ElemType e) {
  for (int i = 0; i < L.length; i++)
    if (L.elem[i] == e) return i + 1;
  cout << "  we cannt find " << e;
  return false;
}

//合并
void MergeList(const SqList La, const SqList Lb, SqList &Lc) {
  Lc.length = La.length + Lb.length;
  Lc.listsize = Lc.length;
  Lc.elem = new ElemType[Lc.listsize];
  ElemType *pa = La.elem, *pb = Lb.elem, *pc = Lc.elem;
  ElemType *pa_last = La.elem + La.length - 1;
  ElemType *pb_last = Lb.elem + Lb.length - 1;
  while (pa <= pa_last && pb <= pb_last) {
    if (*pa <= *pb)
      *pc++ = *pa++;  //赋值并后移pa,pc指针
    else
      *pc++ = *pb++;
  }
  while (pa <= pa_last) *pc++ = *pa++;
  while (pb <= pb_last) *pc++ = *pb++;
  delete[] La.elem;
  delete[] Lb.elem;
}
#endif
