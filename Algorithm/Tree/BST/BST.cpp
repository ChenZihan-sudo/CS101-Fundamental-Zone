#include "../../../.lib/baselib"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <sys/_types/_size_t.h>

template <class T>
class TreeNode {
public:
  T value;
  TreeNode* left;
  TreeNode* right;

  // clang-format off
  TreeNode(T value) : value(value) { left = NULL; right = NULL; }
  // clang-format on
  TreeNode(TreeNode* node)
  {
    this->value = node->value;
    this->left = node->left;
    this->right = node->right;
  }
  TreeNode(T value, TreeNode* left, TreeNode* right)
      : value(value), left(left), right(right) { }
};

template <class T>
void treeInsert(TreeNode<T>* root, T value)
{
  TreeNode<T>* insertNode = new TreeNode<T>(value);

  TreeNode<T>* node = root;
  while (1) {
    TreeNode<T>** cellNode = NULL;
    cellNode = value > node->value ? &node->right : &node->left;

    if (*cellNode == NULL) {
      *cellNode = insertNode;
      break;
    }

    node = *cellNode;
  }
}

template <class T>
void levelOrder(TreeNode<T>* root)
{
  std::queue<TreeNode<T>*> q;
  q.push(root);

  TreeNode<T>* node = NULL;
  while (!q.empty()) {
    node = q.front();
    q.pop();
    printf("%d ", node->value);

    if (node->left != NULL) q.push(node->left);
    if (node->right != NULL) q.push(node->right);
  }
  printf("\n");
}

template <class T>
void LVR(TreeNode<T>* root, std::function<void(T* value, int endtag)>* outputer = NULL, int end = 1)
{
  if (root->left != NULL) { LVR(root->left, outputer, 0); }
  if (outputer != NULL) (*outputer)(&root->value, 0);
  if (root->right != NULL) { LVR(root->right, outputer, 0); }
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

template <class T>
void VLR(TreeNode<T>* root, std::function<void(T* value, int endtag)>* outputer = NULL, int end = 1)
{
  if (outputer != NULL) (*outputer)(&root->value, 0);
  if (root->left != NULL) { VLR(root->left, outputer, 0); }
  if (root->right != NULL) { VLR(root->right, outputer, 0); }
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

template <class T>
void LRV(TreeNode<T>* root, std::function<void(T* value, int endtag)>* outputer = NULL, int end = 1)
{
  if (root->left != NULL) { LRV(root->left, outputer, 0); }
  if (root->right != NULL) { LRV(root->right, outputer, 0); }
  if (outputer != NULL) (*outputer)(&root->value, 0);
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

int main()
{
  TreeNode<int>* root = NULL;

  int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 55, 75, 5, 15, 32, 52, 65, 77, 1, 12, 31, 51, 62, 67, 78};
  root = new TreeNode<int>(arr[0]);
  for (size_t i = 1; i < DATALEN(arr, int); i++) {
    treeInsert(root, arr[i]);
  }

  std::function<void(int* value, int endtag)> output_fun = [](int* val, int endtag) {
    if (endtag) {
      printf("\n");
      return;
    }
    printf("%d ", *val);
  };

  levelOrder(root);

  VLR(root, &output_fun);
  LVR(root, &output_fun);
  LRV(root, &output_fun);
}
