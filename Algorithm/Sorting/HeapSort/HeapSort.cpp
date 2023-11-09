#include "../../../.lib/baselib"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

class TreeNode {
public:
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int value, TreeNode* left, TreeNode* right)
      : value(value), left(left), right(right) { }
};

int leftChildIdx(int idx) { return (idx + 1) * 2 - 1; }
int rightChildIdx(int idx) { return (idx + 1) * 2; }
int parentIdx(int idx) { return (idx + 1) / 2 - 1; }

TreeNode* buildHeap(int* arr, size_t arr_size)
{
  if (arr_size <= 0) return NULL;

  TreeNode** nodes = (TreeNode**)malloc(arr_size);
  for (size_t i = 0; i < arr_size; i++) {
    TreeNode* node = new TreeNode(arr[i], NULL, NULL);
    nodes[i] = node;
  }

  for (size_t i = 0; i < arr_size; i++) {
    nodes[i]->left = leftChildIdx(i) >= arr_size ? NULL : nodes[leftChildIdx(i)];
    nodes[i]->right = rightChildIdx(i) >= arr_size ? NULL : nodes[rightChildIdx(i)];
  }

  TreeNode* root = nodes[0];
  free(nodes);
  return root;
}

void heapify(TreeNode* node) { }

void levelOrder(TreeNode* root)
{
  std::queue<TreeNode*> q;
  q.push(root);

  TreeNode* node = NULL;
  while (!q.empty()) {
    node = q.front();
    q.pop();
    printf("%d ", node->value);

    if (node->left != NULL) q.push(node->left);
    if (node->right != NULL) q.push(node->right);
  }
}

int main()
{
  int arr[10] = {50, 40, 45, 30, 20, 40, 35, 10, 20, 5};
  TreeNode* root = buildHeap(arr, DATALEN(arr, int));
  levelOrder(root);
}
