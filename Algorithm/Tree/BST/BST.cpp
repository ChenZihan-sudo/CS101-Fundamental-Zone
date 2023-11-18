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

enum TreeBranch
{
  BRANCH_UNKNOWN,
  BRANCH_LEFT,
  BRANCH_MID,
  BRANCH_RIGHT,
  BRANCH_CUST = 10,
  BRANCH_1,
  BRANCH_2,
  BRANCH_3,
  BRANCH_4,
  BRANCH_5,
  BRANCH_6,
  BRANCH_7,
  BRANCH_8,
  // ...
  // BRANCH_N = BRANCH_CUST + N
};

template <class T>
class TreeNodeParent {
public:
  TreeNode<T>* parent;
  int branchType;
  TreeNode<T>* node;

  TreeNodeParent(TreeNode<T>* parent, int branchType, TreeNode<T>* node) : parent(parent), branchType(branchType), node(node){};
};

template <class T>
void LVR(TreeNode<T>* root, std::function<void(TreeNode<int>* node, int endtag)>* outputer = NULL, int end = 1)
{
  NULL_CHECK_VOID_RET(root);
  if (root->left != NULL) { LVR(root->left, outputer, 0); }
  if (outputer != NULL) (*outputer)(root, 0);
  if (root->right != NULL) { LVR(root->right, outputer, 0); }
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

template <class T>
void VLR(TreeNode<T>* root, std::function<void(TreeNode<int>* node, int endtag)>* outputer = NULL, int end = 1)
{
  NULL_CHECK_VOID_RET(root);
  if (outputer != NULL) (*outputer)(root, 0);
  if (root->left != NULL) { VLR(root->left, outputer, 0); }
  if (root->right != NULL) { VLR(root->right, outputer, 0); }
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

template <class T>
void LRV(TreeNode<T>* root, std::function<void(TreeNode<int>* node, int endtag)>* outputer = NULL, int end = 1)
{
  NULL_CHECK_VOID_RET(root);
  if (root->left != NULL) { LRV(root->left, outputer, 0); }
  if (root->right != NULL) { LRV(root->right, outputer, 0); }
  if (outputer != NULL) (*outputer)(root, 0);
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

template <class T>
void RVL(TreeNode<T>* root, std::function<void(TreeNode<int>* node, int endtag)>* outputer = NULL, int end = 1)
{
  NULL_CHECK_VOID_RET(root);
  if (root->right != NULL) { RVL(root->right, outputer, 0); }
  if (outputer != NULL) (*outputer)(root, 0);
  if (root->left != NULL) { RVL(root->left, outputer, 0); }
  if (end == 1 && outputer != NULL) (*outputer)(NULL, end);
}

template <class T>
void treeInsert(TreeNode<T>* root, T value)
{
  NULL_CHECK_VOID_RET(root);
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

/**
 * @brief Find node in BST tree.
 * @param comparer Callback. Set return 0 if v1 == v2. Set return 1 if v1 > v2. For others set -1.
 * @return TreeNodeParent<T> Return the node and its parent. If not found, return NULL.
 */
template <class T>
TreeNodeParent<T> treeNodeFind(TreeNode<T>* root, T value, std::function<int(T v1, T v2)>* comparer)
{
  TreeNodeParent<T> tnp(NULL, BRANCH_UNKNOWN, root);
  NULL_CHECK_CUST_RET(root, tnp);

  while (1) {
    int comp = (*comparer)(value, tnp.node->value);
    switch (comp) {
      case -1:
      {
        if (tnp.node->left != NULL) {
          tnp.parent = tnp.node;
          tnp.branchType = BRANCH_LEFT;
          tnp.node = tnp.node->left;
          continue;
        }
      }
      case 1:
      {
        if (tnp.node->right != NULL) {
          tnp.parent = tnp.node;
          tnp.branchType = BRANCH_RIGHT;
          tnp.node = tnp.node->right;
          continue;
        }
      }
    }

    break;
  }

  return tnp;
}

template <class T>
void treeNodeDelete(TreeNodeParent<T>* stNodeParent)
{
  NULL_CHECK_VOID_RET(stNodeParent);

  TreeNode<T>* node = stNodeParent->node;

  // Deal with the conjuction of parent node
  if (stNodeParent->parent != NULL)
    stNodeParent->branchType == BRANCH_LEFT
        ? stNodeParent->parent->left = NULL
        : stNodeParent->parent->right = NULL;

  // For leaf node
  if (node->left == NULL && node->right == NULL) return;

  // For branch node
  TreeNode<T>* lastNode = NULL;
  TreeNode<T>* lastOfItsParentNode = NULL;
  bool isNodeLeft = node->left != NULL;
  int times = 0;
  std::function<void(TreeNode<int> * node, int endtag)> outputer = [&](TreeNode<int>* node, int endtag) {
    if (times == 0) { lastNode = node; }
    if (times == 1) { lastOfItsParentNode = node; }
    times++;
  };
  if (isNodeLeft)
    RVL(node->left, &outputer);
  else
    LVR(node->right, &outputer);
  NULL_CHECK_VOID_RET(lastNode);
  printf("Find last node:%d\n", lastNode->value);

  // Eliminate the conjunction between the node that ready to take place 
  // the deleted position and the origin parent of the node just said.
  isNodeLeft ? lastOfItsParentNode->right = NULL
             : lastOfItsParentNode->left = NULL;
  printf("lastOfItsParentNode:%d\n", lastOfItsParentNode->value);

  // Connect new node with the parent of deleted position
  if (stNodeParent->parent != NULL)
    stNodeParent->branchType == BRANCH_LEFT
        ? stNodeParent->parent->left = lastNode
        : stNodeParent->parent->right = lastNode;

  // Connect new node with the children of deleted position
  lastNode->left = node->left;
  lastNode->right = node->right;
}

template <class T>
void levelOrder(TreeNode<T>* root)
{
  NULL_CHECK_VOID_RET(root);
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

int main()
{
  TreeNode<int>* root = NULL;

  //   int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 55, 75, 5, 15, 32, 52, 65, 77, 1, 12, 31, 51, 62, 67, 78};
  int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 55, 75, 5, 65, 62, 68, 61, 63, 67, 69};
  root = new TreeNode<int>(arr[0]);
  for (size_t i = 1; i < DATALEN(arr, int); i++) {
    treeInsert(root, arr[i]);
  }

  std::function<void(TreeNode<int> * node, int endtag)> output_fun = [](TreeNode<int>* node, int endtag) {
    if (endtag) {
      printf("\n");
      return;
    }
    printf("%d ", node->value);
  };

  levelOrder(root);

  VLR(root, &output_fun);
  LVR(root, &output_fun);
  LRV(root, &output_fun);


  std::function<int(int v1, int v2)> comparer_fun = [](int v1, int v2) {
    if (v1 == v2) return 0;
    if (v1 > v2) return 1;
    return -1;
  };

  auto node = treeNodeFind(root, 70, &comparer_fun);
  printf("Result: %s\n", node.node == NULL ? "failed to find the target." : "find the target.");
  printf("Parent: %d, BranchType: %d, Node: %d\n", node.parent->value, node.branchType, node.node->value);

  RVL(node.node->left, &output_fun); // For precursor node.

  treeNodeDelete(&node);
  levelOrder(root);

  //   treeNodeFind(root, 65, &comparer_fun);
}
