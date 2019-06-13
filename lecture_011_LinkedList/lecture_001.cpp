#include <iostream>

using namespace std;

class LinkedList
{

  private:
    class Node
    {
      public:
        int data = 0;
        Node *next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };

  private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int elementCount = 0;

  public:
    ~LinkedList()
    {
        Node *node = this->head;
        while (node != nullptr)
        {
            Node *temp = node;
            node = node->next;
            delete temp;
        }
    }

    // GeneralFunctions.=====================================================================================

    int size()
    {
        return this->elementCount;
    }

    bool isEmpty()
    {
        return (this->elementCount == 0);
    }

    void display()
    {
        Node *node = this->head;
        while (node != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

  private:
    void swapData(Node *one, Node *two)
    {
        int temp = one->data;
        one->data = two->data;
        two->data = temp;
    }

    Node *midNode(Node *start, Node *end)
    {
        Node *slow = start;
        Node *fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *getNodeAt(int index)
    {
        if (index < 0 || index >= this->elementCount)
            throw "NullPointException";

        if (index == 0)
            return this->head;
        if (index == this->elementCount - 1)
            return this->tail;

        Node *node = this->head;
        while (index-- > 0)
            node = node->next;

        return node;
    }

    void clear()
    {
        this->tail = nullptr;
        this->head = nullptr;
        this->elementCount = 0;
    }

    // AddFunctions.=========================================================================================

  private:
    void addNodeFirst(Node *node)
    {
        if (this->elementCount == 0)
            this->tail = node;
        else
            node->next = this->head;

        this->head = node;
        this->elementCount++;
    }

    void addNodeLast(Node *node)
    {
        if (this->elementCount == 0)
            this->head = node;
        else
            this->tail->next = node;

        this->tail = node;
        this->elementCount++;
    }

    void addNodeAt(int index, Node *node)
    {
        if (index == 0)
            addNodeFirst(node);
        else if (index == this->elementCount)
            addNodeLast(node);
        else
        {
            Node *nodeAt = getNodeAt(index - 1);
            node->next = nodeAt->next;
            nodeAt->next = node;
            this->elementCount++;
        }
    }

  public:
    void addFirst(int data)
    {
        Node *node = new Node(data);
        addNodeFirst(node);
    }

    void addLast(int data)
    {
        Node *node = new Node(data);
        addNodeLast(node);
    }

    void addAt(int index, int data)
    {
        Node *node = new Node(data);
        addNodeAt(index, node);
    }

    // GetFunctions.==========================================================================================

  private:
    Node *getNodeFirst()
    {
        if (this->elementCount == 0)
            throw "NoSuchElementException";

        return this->head;
    }

    Node *getNodeLast()
    {
        if (this->elementCount == 0)
            throw "NoSuchElementException";

        return this->tail;
    }

  public:
    int getFirst()
    {
        int data = -1;
        data = getNodeFirst()->data;
        return data;
    }

    int getLast()
    {
        int data = -1;
        data = getNodeLast()->data;
        return data;
    }

    int getAt(int index)
    {
        int data = -1;
        data = getNodeAt(index)->data;
        return data;
    }

    // RemoveFunctions.=======================================================================================

  private:
    Node *removeNodeFirst()
    {
        if (this->elementCount == 0)
            throw "NoSuchElementException";

        Node *node = this->head;
        this->head = this->head->next;

        if (this->elementCount == 1)
            this->tail = nullptr;

        node->next = nullptr;
        this->elementCount--;
        return node;
    }

    Node *removeNodeLast()
    {
        if (this->elementCount == 0)
            throw "NoSuchElementException";

        Node *node = nullptr;
        if (this->elementCount == 0)
        {
            node = this->tail;
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node *temp = getNodeAt(this->elementCount - 2);
            node = temp->next;

            this->tail = temp;
            temp->next = nullptr;
        }

        this->elementCount--;
        return node;
    }

    Node *removeNodeAt(int index)
    {
        if (this->elementCount == 0)
            throw "NoSuchElementException";
        else if (index < 0 || index >= this->elementCount)
            throw "NullPointException";

        if (index == 0)
            return removeNodeFirst();
        else if (index == this->elementCount - 1)
            return removeNodeLast();

        Node *node = getNodeAt(index - 1);
        Node *temp = node->next;

        node->next = temp->next;
        temp->next = nullptr;

        this->elementCount--;
        return temp;
    }

  public:
    int removeFirst()
    {
        int data = -1;
        Node *node = removeNodeFirst();
        data = node->data;

        delete node;
        return data;
    }

    int removeLast()
    {
        int data = -1;
        Node *node = removeNodeLast();
        data = node->data;

        delete node;
        return data;
    }

    int removeAt(int index)
    {
        int data = -1;
        Node *node = removeNodeAt(index);
        data = node->data;
        delete node;
        return data;
    }

    // Reverse.=============================================================================================

  private:
    void reverseDataRecu(Node *node, Node *heap, int floor)
    {
        if (node == nullptr)
        {
            return;
        }

        reverseDataRecu(node->next, heap, floor + 1);
        if (floor >= this->elementCount / 2)
        {
            swapData(heap->next, node);
            heap->next = heap->next->next;
        }
    }

    void reverseDataRecuPointer(Node *node, Node **heap, int floor)
    {
        if (node == nullptr)
            return;

        reverseDataRecuPointer(node->next, heap, floor + 1);
        if (floor >= this->elementCount / 2)
        {
            swapData(*heap, node);
            *heap = (*heap)->next;
        }
    }

    void diplayReverseRec(Node *node)
    {
        if (node == nullptr)
            return;

        diplayReverseRec(node->next);
        cout << node->data << " ";
    }

    void reversePointerRec(Node *node)
    {
        if (node == this->tail)
            return;

        reversePointerRec(node->next);
        node->next->next = node;
    }

  public:
    void reverseDataIter()
    {
        int i = 0;
        int j = this->elementCount - 1;
        while (i < j)
        {
            Node *left = getNodeAt(i);
            Node *right = getNodeAt(j);
            swapData(left, right);
            i++;
            j--;
        }
    }

    void reverseDataRecu()
    {
        Node *heap = new Node(-1);
        heap->next = this->head;
        reverseDataRecu(this->head, heap, 0);
    }

    void reverseDataRecuPointer()
    {
        Node *heap = this->head;
        reverseDataRecuPointer(this->head, &heap, 0);
    }

    void displayReverseItre()
    {
        int i = this->elementCount - 1;
        while (i >= 0)
        {
            Node *node = getNodeAt(i);
            cout << node->data << " ";
            i--;
        }
        cout << endl;
    }

    void diplayReverseRec()
    {
        diplayReverseRec(this->head);
    }

    void reversePointerItr()
    {
        Node *prev = nullptr;
        Node *curr = this->head;
        while (curr != nullptr)
        {
            Node *forw = curr->next;
            curr->next = prev;

            prev = curr;
            curr = forw;
        }
        this->tail = this->head;
        this->head = prev;
    }

    void reversePointerRec()
    {
        reversePointerRec(this->head);
        Node *temp = this->head;
        this->head = this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }

    // palindrome_and_Fold.=============================================================================

  private:
    bool palindrome(Node *node, Node *heap)
    {
        if (node == nullptr)
            return true;

        if (palindrome(node->next, heap))
        {
            if (node->data == heap->next->data)
            {
                heap->next = heap->next->next;
                return true;
            }
            else
                return false;
        }

        return false;
    }

    void fold(Node *node, Node **heap, int floor)
    {
        if (node == nullptr)
            return;

        fold(node->next, heap, floor + 1);
        if (floor > this->elementCount / 2)
        {
            Node *temp = (*heap)->next;
            (*heap)->next = node;
            node->next = temp;

            *heap = temp;
        }
        else if (floor == this->elementCount / 2)
        {
            this->tail = node;
            this->tail->next = nullptr;
        }
    }

    Node *unfold(Node *node)
    {
        if (node->next == nullptr || node->next->next == nullptr)
            return node;

        Node *PartialUnfold = unfold(node->next->next);

        Node *temp = node->next;
        node->next = PartialUnfold;

        this->tail->next = temp;
        this->tail = temp;
        temp->next = nullptr;

        return node;
    }

  public:
    bool palindrome()
    {
        Node *heap = new Node(-1);
        heap->next = this->head;
        return palindrome(this->head, heap);
    }

    void fold()
    {
        Node *heap = this->head;
        fold(this->head, &heap, 0);
    }

    void unfold()
    {
        this->head = unfold(this->head);
    }

    void KreverseItr(int k)
    {
        if (this->elementCount < 2 || k % this->elementCount < 2)
            return;

        k = k % this->elementCount;
        LinkedList real;
        while (this->elementCount != 0)
        {
            LinkedList temp;
            for (int i = 0; i < k && this->elementCount != 0; i++)
            {
                temp.addNodeFirst(removeNodeFirst());
            }

            if (real.elementCount == 0)
            {
                real = temp;
            }
            else
            {
                real.tail->next = temp.head;
                real.tail = temp.tail;
                real.elementCount += temp.elementCount;
            }

            temp.clear();
        }

        this->head = real.head;
        this->tail = real.tail;
        this->elementCount = real.elementCount;

        real.clear();
    }

    void evenOddSegre()
    {
        LinkedList odd, even;
        while (this->elementCount != 0)
        {
            Node *node = this->removeNodeFirst();
            if ((node->data & 1) != 0)
                odd.addNodeLast(node);
            else
                even.addNodeLast(node);
        }

        this->elementCount = odd.elementCount + even.elementCount;
        this->head = odd.elementCount > 0 ? odd.head : even.head;
        this->tail = even.elementCount > 0 ? even.tail : odd.tail;
        if (odd.elementCount > 0)
        {
            odd.tail->next = even.head;
        }

        odd.clear();
        even.clear();
    }

    Node *kthNodeFromBack(int k)
    {
        if (k >= this->elementCount)
            throw "NoSuchElementException";

        if (k == this->elementCount - 1)
            return this->head;

        Node *slow = this->head;
        Node *fast = this->head;

        while (k-- > 0)
            fast = fast->next;

        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    int kthFromBack(int k)
    {
        Node *node = kthNodeFromBack(k);
        return node->data;
    }

    //removeDuplicates.========================================================================

    void removeDuplicates()
    {
        LinkedList ll;
        while (this->elementCount > 0)
        {
            Node *node = this->removeNodeFirst();
            if (ll.elementCount == 0 || ll.getLast() != node->data)
                ll.addNodeLast(node);
        }

        this->head = ll.head;
        this->tail = ll.tail;
        this->elementCount = ll.elementCount;

        ll.clear();
    }

    void removeDuplicatesComplete()
    {
        LinkedList ll;
        bool flag = false;
        while (this->elementCount > 0)
        {
            Node *node = this->removeNodeFirst();
            if (ll.elementCount == 0 || ll.getLast() != node->data)
            {
                if (flag)
                {
                    ll.removeLast();
                    flag = false;
                }
                ll.addNodeLast(node);
            }
            else
                flag = true;
        }

        if (flag)
            ll.removeLast();

        this->head = ll.head;
        this->tail = ll.tail;
        this->elementCount = ll.elementCount;

        ll.clear();
    }

    //Arithmatic.==========================================================

    LinkedList *addLinkedList(LinkedList &other)
    {
        LinkedList *ans = new LinkedList();

        this->reversePointerItr();
        other.reversePointerItr();
        Node *one = this->head;
        Node *two = other.head;

        int carry = 0;
        while (one != NULL || two != NULL)
        {

            int sum = carry;
            if (one != NULL)
            {
                sum += one->data;
                one = one->next;
            }

            if (two != NULL)
            {
                sum += two->data;
                two = two->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            ans->addLast(sum);
        }

        ans->reversePointerItr();
        return ans;
    }

    //Sorting_Logn====================================================

    LinkedList *mergeTwoList(LinkedList &other)
    {

        LinkedList *ans = new LinkedList();
        Node *one = this->head;
        Node *two = other.head;

        while (one != NULL && two != NULL)
        {
            if (one->data < two->data)
            {
                ans->addLast(one->data);
                one = one->next;
            }
            else
            {
                ans->addLast(two->data);
                two = two->next;
            }
        }

        while (one != NULL)
        {
            ans->addLast(one->data);
            one = one->next;
        }

        while (two != NULL)
        {
            ans->addLast(two->data);
            two = two->next;
        }

        return ans;
    }

  private:
    LinkedList *mergeSort(Node *sp, Node *ep)
    {
        if (sp == ep)
        {
            LinkedList *base = new LinkedList();
            base->addLast(sp->data);
            return base;
        }

        Node *mid = midNode(sp, ep);
        return mergeSort(sp, mid)->mergeTwoList(*mergeSort(mid->next, ep));
    }

  public:
    LinkedList *mergeSort()
    {
        if (this->elementCount < 1)
            return this;

        return mergeSort(this->head, this->tail);
    }

    //Floyd’s Cycle-Finding Algorithm.==================================================

    void loopRemove(Node *fast)
    {
        Node *slow = this->head;
        Node *prev = NULL;

        bool isSlowFastEqual = this->head == fast ? 1 : 0;
        if (isSlowFastEqual)
        {
            prev = fast;
            fast = fast->next;
        }

        while (slow != fast)
        {
            if (!isSlowFastEqual)
                slow = slow->next;

            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
    }

    bool loopDetect()
    {
        if (this->head == NULL || this->head->next == NULL)
            return false;

        this->tail->next = getNodeAt(4);

        Node *slow = this->head;
        Node *fast = this->head;
        bool flag = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                loopRemove(fast);
                flag = true;
                break;
            }
        }

        return flag;
    }
};

void Arithmatic()
{
    LinkedList ll;

    ll.addLast(3);
    ll.addLast(4);
    ll.addLast(5);
    ll.addLast(7);
    ll.addFirst(2);
    ll.addFirst(1);
    ll.addAt(5, 6);

    LinkedList other;

    other.addLast(3);
    other.addLast(4);
    other.addLast(5);
    other.addFirst(2);
    other.addFirst(1);

    LinkedList *ans = other.addLinkedList(ll);
    ans->display();
}

void solve1()
{
    LinkedList ll;
    ll.addLast(1);
    ll.addLast(2);
    ll.addLast(3);
    ll.addLast(4);
    ll.addLast(4);
    ll.addLast(4);
    ll.addLast(4);
    ll.addLast(5);
    ll.addLast(6);
    ll.addLast(6);
    ll.addLast(6);
    ll.addLast(6);
    ll.addLast(7);
    ll.addLast(7);
    // cout << boolalpha << ll.palindrome() << endl;

    // ll.fold();
    // ll.unfold();
    // ll.KreverseItr(1);

    // ll.evenOddSegre();
    // ll.addFirst(-10);
    // ll.addLast(100);

    // cout << ll.kthFromBack(4) << endl;4
    // ll.removeDuplicates();
    // ll.removeDuplicatesComplete();

    cout << boolalpha << ll.loopDetect() << endl;
    ll.display();
}

void solve()
{

    LinkedList ll;

    ll.addLast(3);
    ll.addLast(40);
    ll.addLast(5);
    ll.addLast(70);
    ll.addFirst(2);
    ll.addFirst(10);
    ll.addAt(5, 6);
    // ll.display();
    // cout << ll.removeLast() << endl;
    // cout << ll.getLast() << endl;
    // cout << ll.removeAt(10) << endl;
    // ll.addAt(100, 10);

    // ll.displayReverseItre();
    // ll.reverseDataIter();
    // ll.reverseDataRecu();
    // ll.reverseDataRecuPointer();
    // ll.reversePointerItr();
    // ll.reversePointerRec();
    // ll.addLast(80);
    // ll.display();
    cout << ll << endl;

    // solve1();
    // Arithmatic();

    // LinkedList *ans = ll.mergeSort();
    // ans->display();
}

int main(int argc, char **argv)
{
    solve();
    return 0;
}