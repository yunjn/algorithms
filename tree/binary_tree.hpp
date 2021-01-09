#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <iostream>
#include <queue>

typedef int ElemType;

typedef struct BinNode {
  ElemType data;
  BinNode* left;
  BinNode* right;
} * BiTree;

BiTree CreateNode(ElemType data, BiTree left, BiTree right) {
  BiTree new_node = new BinNode;
  if (!new_node) return nullptr;
  new_node->data = data;
  new_node->left = left;
  new_node->right = right;
  return new_node;
}

void Assign(BinNode* node, ElemType data, BinNode* left, BinNode* right) {
  node->data = data;
  node->left = left;
  node->right = right;
}

void Visit(BinNode* node) { std::cout << node->data << " "; }

void PreOrder(BiTree t) {
  if (t) {
    Visit(t);
    PreOrder(t->left);
    PreOrder(t->right);
  }
}

void InOrder(BiTree t) {
  if (t) {
    InOrder(t->left);
    Visit(t);
    InOrder(t->right);
  }
}

void PostOrder(BiTree t) {
  if (t) {
    PostOrder(t->left);
    PostOrder(t->right);
    Visit(t);
  }
}

void LayOrder(BiTree t) {
  std::queue<BiTree> q;
  q.push(t);
  while (!q.empty()) {
    BiTree node = q.front();
    q.pop();
    if (node) {
      Visit(node);
      q.push(node->left);
      q.push(node->right);
    }
  }
}

void DestroyTree(BiTree t) {
  if (t) {
    DestroyTree(t->left);
    DestroyTree(t->right);
    delete t;
  }
}

#endif