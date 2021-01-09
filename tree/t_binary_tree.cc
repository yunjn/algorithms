/*******************************
 *      建立如下二叉树
 *            1
 *          /  \
 *         2    3
 *       / \   / \
 *      4   5 6   7
 *     /   /       \
 *    8   9         10
 * 先序遍历：1 2 4 8 5 9 3 6 7 10
 * 中序遍历：8 4 2 9 5 1 6 3 7 10
 * 后序遍历：8 4 9 5 2 6 10 7 3 1
 * 层级遍历：1 2 3 4 5 6 7 8 9 10
 *********************************/
#include <iostream>

#include "binary_tree.hpp"

using namespace std;
BiTree t = nullptr;

void CreateTree() {
  BiTree* tree = new BiTree[10];
  for (int i = 0; i < 10; i++) tree[i] = new BinNode;
  Assign(tree[0], 1, tree[1], tree[2]);
  Assign(tree[1], 2, tree[3], tree[4]);
  Assign(tree[2], 3, tree[5], tree[6]);
  Assign(tree[3], 4, tree[7], nullptr);
  Assign(tree[4], 5, tree[8], nullptr);
  Assign(tree[5], 6, nullptr, nullptr);
  Assign(tree[6], 7, nullptr, tree[9]);
  Assign(tree[7], 8, nullptr, nullptr);
  Assign(tree[8], 9, nullptr, nullptr);
  Assign(tree[9], 10, nullptr, nullptr);
  t = tree[0];
  delete[] tree;
}

int main() {
  CreateTree();
  PreOrder(t);
  cout << endl;
  InOrder(t);
  cout << endl;
  PostOrder(t);
  cout << endl;
  LayOrder(t);
  cout << endl;
  DestroyTree(t);
  return 0;
}