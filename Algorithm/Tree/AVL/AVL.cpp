#include "../../../.lib/baselib"
#include <algorithm>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <sys/_types/_ssize_t.h>
#include <sys/_types/_time_t.h>

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
void treeBSTInsert(TreeNode<T>* root, T value)
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

template <class T>
ssize_t treeHeight(TreeNode<T>* root)
{
  NULL_CHECK_CUST_RET(root, -1);
  int treeL = 0, treeR = 0;
  if (root->left != NULL) {
    treeL++;
    treeL += treeHeight(root->left);
  }
  if (root->right != NULL) {
    treeR++;
    treeR += treeHeight(root->right);
  }
  size_t height = std::max(treeL, treeR);
  return (ssize_t)height;
}

template <class T>
ssize_t treeBalanceFactor(TreeNode<T>* root)
{
  NULL_CHECK_CUST_RET(root, -1);
  int treeL = 0, treeR = 0;
  treeL = treeHeight(root->left);
  treeR = treeHeight(root->right);
  return treeL - treeR;
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

template <class T>
TreeNode<T>* leftRotate(TreeNode<T>* root)
{
  NULL_CHECK_CUST_RET(root, NULL);
  NULL_CHECK_CUST_RET(root->right, NULL);
  TreeNode<T>* lNode = root;
  root = root->right;
  TreeNode<T>* proxyLR = root->left;
  root->left = lNode;
  lNode->right = proxyLR;
  return root;
}

template <class T>
TreeNode<T>* rightRotate(TreeNode<T>* root)
{
  NULL_CHECK_CUST_RET(root, NULL);
  NULL_CHECK_CUST_RET(root->left, NULL);
  TreeNode<T>* rNode = root;
  root = root->left;
  TreeNode<T>* proxyRL = root->right;
  root->left = rNode;
  rNode->right = proxyRL;
  return root;
}

template <class T>
TreeNode<T>* LRRotate(TreeNode<T>* root){
    
}

template <class T>
TreeNode<T>* RLRotate(TreeNode<T>* root){

}

int main()
{
  TreeNode<int>* root = NULL;
  // int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 55, 75, 5, 65, 62, 68, 61, 63, 67, 69};
  //   int arr[] = {7, 8, 9, 6, 5, 3, 2, 4};
  int arr[] = {30, 29, 34, 33, 35, 36};

  root = new TreeNode<int>(arr[0]);
  for (size_t i = 1; i < DATALEN(arr, int); i++) {
    treeBSTInsert(root, arr[i]);
  }
  levelOrder(root);
  printf("%zd\n", treeBalanceFactor(root));
  root = leftRotate(root);
  levelOrder(root);

  // left > 1 (2)
  // right < -1 (-2)
}