#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Node
{
  public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    Node(int data)
    {
        this->data = data;
    }

    Node()
    {
    }
};

//constructor.=========================================

Node *constructor_preIn_(vector<int> &pre, vector<int> &in, int psi, int pei, int isi, int iei)
{
    if (psi > pei || isi > iei)
        return NULL;

    int i = isi;
    while (i <= iei && in[i] != pre[psi])
        i++;

    int gap = i - isi;
    Node *node = new Node(pre[psi], NULL, NULL);
    node->left = constructor_preIn_(pre, in, psi + 1, psi + gap, isi, i - 1);
    node->right = constructor_preIn_(pre, in, psi + gap + 1, pei, i + 1, iei);
    return node;
}

Node *constructor_postIn_(vector<int> &post, vector<int> &in, int psi, int pei, int isi, int iei)
{
    if (psi > pei || isi > iei)
        return NULL;

    int i = isi;
    while (i <= iei && in[i] != post[pei])
        i++;

    int gap = i - isi;
    Node *node = new Node(post[pei]);
    node->left = constructor_postIn_(post, in, psi, psi + gap - 1, isi, i - 1);
    node->right = constructor_postIn_(post, in, psi + gap, pei - 1, i + 1, iei);
    return node;
}

Node *constructor_01(vector<int> arr)
{
    Node *Tree[arr.size()];
    Tree[0] = new Node(arr[0], NULL, NULL);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != -1)
        {
            Node *nn = new Node(arr[i], NULL, NULL);
            int parent = (i - 1) >> 1;

            if (((parent << 1) + 1) == i)
                Tree[parent]->left = nn;
            else
                Tree[parent]->right = nn;
        }
    }

    return Tree[0];
}

Node *constructor_02(vector<int> &arr)
{
    vector<Node *> st;
    st.push_back(new Node(arr[0], NULL, NULL));

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] != -1)
            st.push_back(new Node(arr[i], NULL, NULL));
        else
        {
            Node *nn = st.back();
            st.pop_back();

            if (st.back()->left == NULL)
                st.back()->left = nn;
            else
                st.back()->right = nn;
        }
    }

    return st.back();
}

Node *constructor_preIn(vector<int> &pre, vector<int> &in)
{
    return constructor_preIn_(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
}

//generalFunction.=========================================

int size(Node *node)
{
    if (node == nullptr)
        return 0;
    return size(node->left) + size(node->right) + 1;
}

int height(Node *node)
{
    if (node == nullptr)
        return -1;
    return max(height(node->left), height(node->right)) + 1;
}

Node *ContainsKey(Node *node, int key)
{
    if (node == nullptr)
        return nullptr;

    if (node->data == key)
        return node;

    Node *IsInLeft = ContainsKey(node->left, key);
    if (IsInLeft != nullptr)
        return IsInLeft;
    Node *IsInRight = ContainsKey(node->right, key);
    if (IsInRight != nullptr)
        return IsInRight;

    return nullptr;
}

int MaxValue(Node *node)
{
    if (node == nullptr)
        return INT_MIN;
    return max(max(MaxValue(node->left), MaxValue(node->right)), node->data);
}

int MinValue(Node *node)
{
    if (node == nullptr)
        return INT_MAX;
    return min(min(MinValue(node->left), MinValue(node->right)), node->data);
}

//displayMethods.===================================================================

void display(Node *node)
{
    if (node == NULL)
        return;

    string ans = "";
    ans += node->left != NULL ? to_string(node->left->data) : ".";
    ans += " -> " + to_string(node->data) + " <- ";
    ans += node->right != NULL ? to_string(node->right->data) : ".";
    cout << ans << endl;

    display(node->left);
    display(node->right);
}

void preOrder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void inOrder(Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

//LeavesAndChild.===================================================================

void printOnlyChild(Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        cout << node->data << endl;
        return;
    }

    printOnlyChild(node->left);
    printOnlyChild(node->right);
}

Node *removeLeaves(Node *node)
{
    if (node == NULL)
        return NULL;
    if (node->left == NULL && node->right == NULL)
        return NULL;

    node->left = removeLeaves(node->left);
    node->right = removeLeaves(node->right);
    return node;
}

void removeLeavesParent(Node *node, Node *par, bool isLeft)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        if (isLeft)
            par->left = NULL;
        else if (!isLeft)
            par->right = NULL;

        return;
    }

    removeLeavesParent(node->left, node, true);
    removeLeavesParent(node->right, node, false);
}

//RootToNodeType.============================================

void kDown_(Node *node, int k)
{
    if (node == NULL)
        return;

    if (k == 0)
    {
        cout << node->data << endl;
        return;
    }

    kDown_(node->left, k - 1);
    kDown_(node->right, k - 1);
}

bool rootToNodePath(Node *node, int data)
{
    if (node == nullptr)
        return false;
    if (node->data == data)
    {
        cout << data << " ";
        return true;
    }

    if (rootToNodePath(node->left, data))
    {
        cout << node->data << " ";
        return true;
    }

    if (rootToNodePath(node->right, data))
    {
        cout << node->data << " ";
        return true;
    }

    return false;
}

vector<int> *rootToNodePathReturnType(Node *node, int data)
{
    if (node == nullptr)
    {
        return NULL;
    }

    if (node->data == data)
    {
        vector<int> *arr = new vector<int>();
        arr->push_back(node->data);
        return arr;
    }

    vector<int> *left = rootToNodePathReturnType(node->left, data);
    if (left != NULL)
    {
        left->push_back(node->data);
        return left;
    }

    vector<int> *right = rootToNodePathReturnType(node->right, data);
    if (right != NULL)
    {
        right->push_back(node->data);
        return right;
    }

    return NULL;
}

void kDown(Node *node, int k, int data)
{
    Node *nn = ContainsKey(node, data);
    if (nn != NULL)
        kDown_(node, k);
}

void AllNodeDistance_KAway(Node *node, int k, int data)
{
}

//diameter.==================================================

class diaPair
{
  public:
    int height = -1;
    int diameter = 0;
};

diaPair *diameterPair_(Node *node)
{
    if (node == NULL)
        return new diaPair();

    diaPair *p1 = diameterPair_(node->left);
    diaPair *p2 = diameterPair_(node->right);

    diaPair *myAns = new diaPair();
    myAns->height = max(p1->height, p2->height) + 1;
    myAns->diameter = max(max(p1->diameter, p2->diameter), p1->height + p2->height + 2);

    return myAns;
}

int diamterePairReturnType_(Node *node, diaPair *pair)
{
    if (node == NULL)
        return -1;

    int le = diamterePairReturnType_(node->left, pair);
    int ri = diamterePairReturnType_(node->right, pair);

    pair->diameter = max(pair->diameter, le + ri + 2);
    return max(le, ri) + 1;
}

int diameterSimple(Node *node)
{
    if (node == NULL)
        return 0;

    int h1 = height(node->left);
    int h2 = height(node->right);

    int d1 = diameterSimple(node->left);
    int d2 = diameterSimple(node->right);

    return max(max(d1, d2), h1 + h2 + 2);
}

int diameterPair(Node *node)
{
    return diameterPair_(node)->diameter;
}

int diamterePairReturnType(Node *node)
{
    diaPair *p = new diaPair();
    diamterePairReturnType_(node, p);
    return p->diameter;
}

//BSTRelated.===============================================

class pair_
{
  public:
    Node *root = NULL;
    int count = 0;
    int BstSize = 0;

    int max = INT_MIN;
    int min = INT_MAX;

    bool isBst = false;
    bool isBal = false;

    int height = -1;
};

pair_ *isBstAll(Node *node)
{
    if (node == NULL)
        return new pair_();

    pair_ *left = isBstAll(node->left);
    pair_ *right = isBstAll(node->right);

    pair_ *myPair = new pair_();

    myPair->height = max(left->height, right->height) + 1;
    myPair->max = max(left->max, right->max);
    myPair->min = min(left->min, right->min);
    myPair->isBal = left->isBal && right->isBal && abs(left->height - right->height) <= 1;
    myPair->isBst = left->isBst && right->isBst && left->max < node->data && node->data < right->min;

    if (myPair->isBst)
    {
        myPair->isBst = true;
        myPair->BstSize = left->BstSize + right->BstSize;
        myPair->root = node;
    }
    else
    {
        myPair->BstSize = left->BstSize > right->BstSize ? left->BstSize : right->BstSize;
        myPair->root = left->BstSize > right->BstSize ? left->root : right->root;
    }
    return myPair;
}

//===========================================================

void printVector(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";

    cout << endl;
}

void displayMethods(Node *node)
{
    preOder(node);
    postOder(node);
    inOder(node);
}

void LeavesAndChild(Node *node)
{
    printOnlyChild(node);
    // node = removeLeaves(node);
    // removeLeavesParent(node,node,true);

    display(node);
}

void RootToNodeType(Node *node)
{
    cout << (boolalpha) << rootToNodePath(node, 87) << endl;
    printVector(*rootToNodePathReturnType(node, 87));
}

void diameter(Node *node)
{
    cout << diameterSimple(node) << endl;
    cout << diameterPair(node) << endl;
    cout << diamterePairReturnType(node) << endl;
}

void solve()
{
    vector<int> arr = {50, 25, 12, -1, 37, 30, -1, 52, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};
    Node *root = constructor_02(arr);
    // display(root);

    // displayMethods(root);
    // LeavesAndChild(root);
    // RootToNodeType(root);
    diameter(root);
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}