#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

class Node
{
public:
  int data = 0;
  vector<Node *> children;

  Node(int data)
  {
    this->data = data;
  }
};

// Constructor.=============================================================================

Node *constructor01(vector<int> &arr)
{
  if (arr.size() == 0)
    return NULL;

  vector<Node *> stack;
  stack.push_back(new Node(arr[0]));

  Node *root = stack[0];

  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] != -1)
    {
      Node *node = stack.back();
      Node *nnode = new Node(arr[i]);

      node->children.push_back(nnode);
      stack.push_back(nnode);
    }
    else
      stack.pop_back();
  }
  return root;
}

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " Child: ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
  }
}

// GenerallFuctions.=======================================================================

int sizeRec(Node *node)
{
  int size = 0;
  for (Node *child : node->children)
  {
    size += sizeRec(child);
  }
  return size + 1;
}

int height(Node *node)
{
  int ht = 0;
  for (Node *child : node->children)
  {
    ht = max(ht, height(child));
  }
  return ht + 1;
}

int maxEle(Node *node)
{
  int OverMax = node->data;
  for (Node *child : node->children)
  {
    OverMax = max(OverMax, maxEle(child));
  }
  return OverMax;
}

bool find(Node *node, int data)
{
  if (node->data == data)
    return true;

  for (Node *child : node->children)
    if (find(child, data))
      return true;

  return false;
}

// loopRegionAndInsight====================================================================

void loopRegion(Node *root)
{

  cout << ("a: " + to_string(root->data));
  for (Node *child : root->children)
  {
    cout << ("preLoop : " + to_string(root->data) + " -> " + to_string(child->data));
    loopRegion(child);
    cout << ("postLoop : " + to_string(root->data) + " -> " + to_string(child->data));
  }
  cout << ("a: " + to_string(root->data));
}

void displaAllCombination(Node *node, int data)
{
  cout << data << " -> " << node->data << endl;
  for (Node *child : node->children)
  {
    displaAllCombination(child, data);
  }
}

void displaAllCombinationParent(Node *node, Node *root)
{
  displaAllCombination(root, node->data);

  cout << endl;
  for (Node *child : node->children)
  {
    displaAllCombinationParent(child, root);
  }
}

void loopRegionAndInsight(Node *root)
{
  // loopRegion(root);
  displaAllCombinationParent(root, root);
}

//rootToNodeTyeAndLevelOder==============================================================================

vector<int> *rootNodeToPath(Node *node, int data)
{

  if (node->data == data)
  {
    vector<int> *base = new vector<int>();
    base->push_back(data);
    return base;
  }

  vector<int> *ans = new vector<int>();
  for (Node *child : node->children)
  {
    vector<int> *recAns = rootNodeToPath(child, data);
    if (recAns->size() > 0)
    {
      recAns->push_back(node->data);
      return recAns;
    }
  }
  return ans;
}

int lca(Node *node, int data1, int data2)
{
  vector<int> onePath = *rootNodeToPath(node, data1);
  vector<int> twoPath = *rootNodeToPath(node, data2);

  int i = onePath.size() - 1;
  int j = twoPath.size() - 1;
  bool flag = false;
  while (i >= 0 && j >= 0 && onePath[i] == twoPath[j])
  {
    flag = true;
    i--;
    j--;
  }

  int ans = 0;
  if (flag)
  {
    ans = onePath[i++];
  }
  return ans;
}

int distance(Node *node, int data1, int data2)
{
  vector<int> onePath = *rootNodeToPath(node, data1);
  vector<int> twoPath = *rootNodeToPath(node, data2);

  int i = onePath.size() - 1;
  int j = twoPath.size() - 1;
  bool flag = false;
  while (i >= 0 && j >= 0 && onePath[i] == twoPath[j])
  {
    flag = true;
    i--;
    j--;
  }

  int ans = 0;
  if (flag)
  {
    ans = i++ + j++ + 1;
  }
  return ans;
}

void levelOderSimple(Node *node)
{
  if (node == NULL || node->children.size() == 0)
    return;

  queue<Node *> que;
  que.push(node);
  string ans = "";
  while (!que.empty())
  {
    Node *nd = que.front();
    que.pop();
    ans += to_string(nd->data) + " ";

    for (Node *child : nd->children)
      que.push(child);
  }

  cout << ans << endl;
}

void levelOderLineWiseUsingTwoQueue(Node *node)
{
  if (node == NULL || node->children.size() == 0)
    return;

  queue<Node *> que, que2;
  que.push(node);

  while (!que.empty())
  {
    Node *nd = que.front();
    que.pop();
    cout << nd->data << " ";

    for (Node *child : nd->children)
      que2.push(child);

    if (que.empty())
    {
      swap(que, que2);
      cout << endl;
    }
  }
  cout << endl;
}

void levelOderLineWiseUsingOneQueueWithNull(Node *node)
{
  if (node == NULL || node->children.size() == 0)
    return;

  queue<Node *> que;
  que.push(node);
  que.push(NULL);

  while (que.size() != 1)
  {
    Node *nd = que.front();
    que.pop();
    cout << nd->data << " ";

    for (Node *child : nd->children)
      que.push(child);

    if (que.front() == NULL)
    {
      que.pop();
      que.push(NULL);
      cout << endl;
    }
  }
  cout << endl;
}

void levelOderLineWiseUsingOneQueueWithCount(Node *node)
{
  if (node == NULL || node->children.size() == 0)
    return;

  queue<Node *> que;
  que.push(node);
  int Rootchilds = 1;
  int localChild = 0;

  while (que.size() != 0)
  {
    Node *nd = que.front();
    que.pop();
    Rootchilds--;
    cout << nd->data << " ";

    for (Node *child : nd->children)
    {
      que.push(child);
      localChild++;
    }
    if (Rootchilds == 0)
    {
      cout << endl;
      Rootchilds = localChild;
      localChild = 0;
    }
  }
  cout << endl;
}

void levelOderLineWiseUsingOneQueueWithLevel(Node *node)
{

  if (node == NULL || node->children.size() == 0)
    return;

  queue<Node *> que;
  que.push(node);
  queue<int> level;
  level.push(0);
  int lev = 0;
  while (que.size() != 0)
  {
    Node *nd = que.front();
    que.pop();
    int nl = level.front();
    level.pop();

    for (Node *child : nd->children)
    {
      que.push(child);
      level.push(nl + 1);
    }

    if (lev != nl)
    {
      cout << endl;
      lev = nl;
    }
    cout << nd->data << " ";
  }
  cout << endl;
}

void levelOderZigZag(Node *node)
{
  if (node == NULL || node->children.size() == 0)
    return;

  stack<Node *> st, st1;
  st.push(node);
  int count = 0;
  while (!st.empty())
  {
    Node *nd = st.top();
    st.pop();
    cout << nd->data << " ";

    if ((count & 1) == 0)
    {
      for (Node *child : nd->children)
        st1.push(child);
    }
    else
    {
      for (int i = nd->children.size() - 1; i >= 0; i--)
        st1.push(nd->children[i]);
    }

    if (st.size() == 0)
    {
      swap(st, st1);
      cout << endl;
      count++;
    }
  }
}

void rootToNodeTyeAndLevelOder(Node *root)
{
  // printVector(*rootNodeToPath(root, 120));

  levelOderSimple(root);
  cout << endl;

  levelOderLineWiseUsingTwoQueue(root);
  cout << endl;

  levelOderLineWiseUsingOneQueueWithNull(root);
  cout << endl;

  levelOderLineWiseUsingOneQueueWithCount(root);
  cout << endl;

  levelOderLineWiseUsingOneQueueWithLevel(root);
  cout << endl;

  levelOderZigZag(root);
}

//understandingOfRecusrsion================================================================

void mirrorTransform(Node *node)
{

  for (Node *child : node->children)
  {
    mirrorTransform(child);
  }

  // reverse(node->children);
  for (int i = 0, j = node->children.size() - 1; i < j; i++, j--)
  {
    Node *one = node->children[i];
    Node *two = node->children[j];

    node->children[i] = two;
    node->children[j] = one;
  }
}

bool isMirrorDataType(Node *node1, Node *node2)
{
  if (node1->children.size() != node2->children.size())
    return false;

  for (int i = 0; i < node1->children.size(); i++)
  {
    if (!isMirrorDataType(node1->children[i], node2->children[i]) || node1->children[i]->data != node2->children[i]->data)
      return false;
  }

  return true;
}

void removeLeaves(Node *node)
{

  vector<Node *> *childs = new vector<Node *>();
  for (Node *child : node->children)
  {
    if (child->children.size() != 0)
      childs->push_back(child);
  }

  node->children = *childs;

  for (Node *child : node->children)
  {
    removeLeaves(child);
  }
}

Node *linearize(Node *node)
{
  if (node->children.size() == 0)
    return node;

  Node *finalTail = linearize(node->children.back());
  for (int i = node->children.size() - 2; i >= 0; i--)
  {
    Node *tail = linearize(node->children[i]);

    tail->children.push_back(node->children.back());
    node->children.pop_back();
  }

  return finalTail;
}

void flattern(Node *node)
{
  vector<Node *> *childs = new vector<Node *>();
  for (Node *child : node->children)
  {
    flattern(child);
    childs->push_back(child);
    for (Node *ch : child->children)
      childs->push_back(ch);
  }
}

class HeapMover
{
public:
  bool isFind = false;
  int size = 0;
  int height = 0;

  int maxEle = INT_MIN;
  int minEle = INT_MAX;

  Node *pred = NULL;
  Node *succ = NULL;

  Node *prev = NULL;

  int ceil = -1e9;
  int floor = 1e9;
};

void heapMoverAns_(Node *node, HeapMover *hp, int data, int height)
{
  hp->isFind = (hp->isFind) || (node->data == data);
  hp->size++;
  hp->height = max(height, hp->height);

  hp->maxEle = max(node->data, hp->maxEle);
  hp->minEle = min(node->data, hp->minEle);

  hp->ceil = node->data < data ? max(hp->ceil, node->data) : hp->ceil;
  hp->floor = node->data > data ? min(hp->floor, node->data) : hp->floor;

  if (node->data == data)
    hp->pred = hp->prev;

  if (hp->prev != NULL && hp->prev->data == data)
    hp->succ = node;

  hp->prev = node;

  for (Node *child : node->children)
    heapMoverAns_(child, hp, data, height + 1);
}

void heapMoverAns(Node *node, int data)
{
  HeapMover *hp = new HeapMover();
  heapMoverAns_(node, hp, data, 0);

  cout << boolalpha << hp->isFind << endl;
  cout << hp->size << endl;
  cout << hp->height << endl;

  cout << hp->maxEle << endl;
  cout << hp->minEle << endl;

  cout << hp->ceil << endl;
  cout << hp->floor << endl;

  cout << (hp->pred != NULL ? hp->pred->data : -1) << endl;
  cout << (hp->succ != NULL ? hp->succ->data : -1) << endl;
}

void understandingOfRecusrsion(Node *root)
{
  // mirrorTransform(root);
  // removeLeaves(root);
  // linearize(root);
  // flattern(root);

  display(root);
  heapMoverAns(root, 100);

  // display(root);
}

//kthType.======================================================

int KThLargest_(Node *node, int largest)
{

  int ans = -1e9;
  for (Node *child : node->children)
  {
    int recAns = KThLargest_(child, largest);
    if (recAns < largest)
      ans = max(ans, recAns);
  }

  return (node->data < largest ? max(ans, node->data) : ans);
}

void KThLargest(Node *root, int k)
{
  int kthMaxNum = 1e9;
  while (k-- > 0)
    kthMaxNum = KThLargest_(root, kthMaxNum);
  cout << kthMaxNum << endl;
}

int KthSmallest_(Node *node, int smallest)
{

  int ans = 1e9;
  for (Node *child : node->children)
  {
    int recAns = KthSmallest_(child, smallest);
    if (recAns > smallest)
      ans = min(ans, recAns);
  }

  return (node->data > smallest ? min(ans, node->data) : ans);
}

void KthSmallest(Node *root, int k)
{
  int kthMinNum = INT_MIN;
  while (k-- > 0)
    kthMinNum = KthSmallest_(root, kthMinNum);
  cout << kthMinNum << endl;
}

int justSmallest(Node *node, int data)
{

  int ans = -1e9;
  for (Node *child : node->children)
  {
    int recAns = justSmallest(child, data);
    if (recAns < data && recAns > ans)
      ans = recAns;
  }

  return ((node->data < data && node->data > ans) ? node->data : ans);
}

int justLargest(Node *node, int data)
{

  int ans = 1e9;
  for (Node *child : node->children)
  {
    int recAns = justLargest(child, data);
    if (recAns > data && recAns < ans)
      ans = recAns;
  }

  return ((node->data > data && node->data < ans) ? node->data : ans);
}

void kthType(Node *root)
{
  KThLargest(root, 1);
  KthSmallest(root, 1);

  cout << justSmallest(root, 17) << endl;
  cout << justLargest(root, 17) << endl;
}

//=====================================================================

void printVector(vector<int> &arr)
{
  for (auto i : arr)
    cout << i << " ";

  cout << endl;
}

void solve()
{
  vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1,
                     -1};
  Node *root = constructor01(arr);
  // display(root);

  // loopRegionAndInsight(root);
  // rootToNodeTyeAndLevelOder(root);
  // understandingOfRecusrsion(root);
  kthType(root);
}

int main(int argc, char **args)
{
  solve();
  return 1;
}
