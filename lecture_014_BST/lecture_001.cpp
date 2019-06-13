#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <list>
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

Node *constructor()
{

    vector<int> pre = {50, 20, 30, 40, 70, 60, 80};
    vector<int> in = {10, 20, 30, 40, 50, 60, 70, 80};
    vector<int> post = {10, 30, 20, 60, 80, 70, 50};

    // return constructor_preIn_(pre,in,0,pre.size()-1,0,in.size()-1);
    // return constructor_postIn_(post,in,0,post.size()-1,0,in.size()-1);
    // return constructor_preIn_(pre,in,0,pre.size()-1,0,in.size()-1);

    constructor_01();
}

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

Node *constructor_levelOderSerailize(vector<> arr)
{
    list<Node *> que;
    Node *root = new Node(arr[0]);
    que.push_back(root);
    int i = 1;
    while (que.size() > 0 && i < arr.length)
    {
        Node *nn = que.pop_front();

        if (i < arr.length && arr[i] != -1)
        {
            Node *n = new Node(arr[i]);
            nn->left = n;
            que.push_back(n);
        }
        i++;

        if (i < arr.length && arr[i] != -1)
        {
            Node *n = new Node(arr[i]);
            nn->right = n;
            que.push_back(n);
        }
        i++;
    }

    return root;
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
    else if (node->data < key)
        node = node->right;
    else
        node = node->left;

    return NULL;
}

int MaxValue(Node *node)
{
    if (node == nullptr)
        return INT_MIN;

    while (node->right != NULL)
    {
        node = node->right;
    }
    return node->data;
}

int MinValue(Node *node)
{
    if (node == nullptr)
        return INT_MAX;

    while (node->left != NULL)
    {
        node = node->left;
    }
    return node->data;
}

void generalFunction(Node *node)
{
    cout << (size(node)) << endl;
    cout << (height(node)) << endl;
    cout << (ContainsKey(node, 70)->data) << endl;
    cout << (MaxValue(node)) << endl;
    cout << (MinValue(node)) << endl;
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

void displayMethods(Node *node)
{
    display(node);
    cout << endl;

    preOrder(node);
    cout << endl;

    postOrder(node);
    cout << endl;

    inOrder(node);
    cout << endl;
}

// RangeAndSum.========================================================

void RangeAndSum(Node *node)
{
    searchInRange(node, 9, 78);
    cout << replaceWithGreaterSum(node) << endl;
}

void searchInRange(Node *node, int low, int heigh)
{
    if (node == nullptr)
        return;

    if (node->data > low && node->data < heigh)
    {

        searchInRange(node->left, low, heigh);
        cout << (node->data + " ");
        searchInRange(node->right, low, heigh);
    }
    else if (node->data > heigh)
        searchInRange(node->left, low, heigh);
    else if(node->data < low )
        searchInRange(node->right, low, heigh);
}

int replaceWithGreaterSum(Node *node)
{
    if (node == nullptr)
        return 0;

    int right = replaceWithGreaterSum(node->right);

    int oldSum = node->data;
    node->data = right;

    int left = replaceWithGreaterSum(node->left);

    return right + oldSum + left;
}

// targetSumType.==============================================================

void targetsumtype(Node *node)
{
    targetSum(node, node, 100);
}

void targetSum(Node *node, Node *root, int target)
{
    if (node == nullptr)
        return;

    targetSum(node->left, root, target);

    Node *key = ContainsKey(root, target - node->data);
    if (key != nullptr && key->data > node->data)
        cout << node->data << " " << (target - node->data);

    targetSum(node->right, root, target);
}
