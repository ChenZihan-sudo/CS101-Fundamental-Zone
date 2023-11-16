#include "../../../.lib/baselib"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sys/_types/_size_t.h>
#include <sys/_types/_ssize_t.h>

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

TreeNode* buildTree(int* arr, size_t arr_size)
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

enum SORT_TYPE
{
  SORT_NONE,
  ASCENDING,
  DECENDING
};

enum HEAP_TYPE
{
  HEAP_NONE,
  MAX_HEAP,
  MIN_HEAP,
};

void heapify(int* arr, size_t posi, size_t arr_size, int type = MAX_HEAP)
{
  auto lposi = leftChildIdx(posi);
  auto rposi = rightChildIdx(posi);

  auto sposi = (type == MAX_HEAP && arr[lposi] > arr[rposi]) || (type == MIN_HEAP && arr[lposi] < arr[rposi]) ? lposi : rposi;

  while (sposi <= arr_size - 1) {
    if ((type == MAX_HEAP && arr[posi] >= arr[sposi]) ||
        (type == MIN_HEAP && arr[posi] <= arr[sposi])) break;

    // printf("swap r:%d p:%d\n", arr[sposi], arr[posi]);
    baselib::swap<int>(&arr[sposi], &arr[posi]);
    heapify(arr, sposi, arr_size, type);
    break;
  }
}

void heapBuild(int* arr, size_t arr_size, int type = MAX_HEAP)
{
  for (ssize_t i = arr_size - 1; i > 0; i -= 2) {
    auto pposi = parentIdx(i);
    // printf("i:%d parent:%d val:%d\n ", i, pposi, arr[pposi]);
    heapify(arr, pposi, arr_size, type);
  }
}

void heapSort(int* arr, size_t arr_size, int type = ASCENDING)
{
  heapBuild(arr, arr_size, type == ASCENDING ? MAX_HEAP : MIN_HEAP);
  size_t temp_idx = arr_size - 1;

  while (temp_idx > 1) {
    baselib::swap<int>(&arr[0], &arr[temp_idx]);
    temp_idx--;
    heapify(arr, 0, temp_idx + 1, type == ASCENDING ? MAX_HEAP : MIN_HEAP);
  }
}

int main()
{
  TreeNode* root = NULL;
  int arr[11] = {1, 10, 4, 2, 5, 3, 0, 7, 6, 8, 12};

  heapBuild(arr, DATALEN(arr, int), MAX_HEAP);
  root = buildTree(arr, DATALEN(arr, int));
  levelOrder(root);
  printf("\n");

  heapSort(arr, DATALEN(arr, int), ASCENDING);
  for (size_t i = 0; i < DATALEN(arr, int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  heapSort(arr, DATALEN(arr, int), DECENDING);
  for (size_t i = 0; i < DATALEN(arr, int); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
