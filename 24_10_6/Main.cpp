//class Solution
//{
//public:
//    ListNode* removeElements(ListNode* head, int val)
//    {
//        if (head == nullptr) return nullptr;
//
//        ListNode* cur = head;
//        ListNode* prev = nullptr;
//        while (cur)
//        {
//            // 检测到目标
//            if (cur->val == val)
//            {
//                // 删除第一个
//                if (prev == nullptr)
//                {
//                    head = head->next;
//                    delete cur;
//                    cur = head;
//                }
//                else
//                {
//                    prev->next = cur->next;
//                    delete cur;
//                    cur = prev->next;
//                }
//            }
//            else
//            {
//                // 向下循环
//                prev = cur;
//                cur = cur->next;
//            }
//        }
//
//        return head;
//    }
//};


//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val)
//    {
//        if (head == nullptr) return nullptr;
//
//        head->next = removeElements(head->next, val);
//        return head->val == val ? head->next : head;
//    }
//};

//class Solution
//{
//public:
//    ListNode* reverseList(ListNode* head)
//    {
//        if (!head || !head->next) return head;
//
//        ListNode* prev = nullptr;
//        ListNode* cur = head;
//        ListNode* next = cur;
//        while (cur)
//        {
//            next = cur->next;
//            cur->next = prev;
//
//            prev = cur;
//            cur = next;
//        }
//
//        return prev;
//    }
//};

//class Solution {
//public:
//    ListNode* reverse(ListNode* prev, ListNode* cur)
//    {
//        if (cur == nullptr) return prev;
//
//        ListNode* temp = cur->next;
//        cur->next = prev;
//
//        return reverse(cur, temp);
//    }
//
//    ListNode* reverseList(ListNode* head) {
//        return reverse(nullptr, head);
//    }
//};

//class Solution {
//public:
//    ListNode* SwapRecursion(ListNode* prev, ListNode* cur)
//    {
//        if (cur == nullptr) return prev;
//
//        ListNode* temp = cur->next;
//        cur->next = prev;
//        prev->next = temp == nullptr ? nullptr : SwapRecursion(temp, temp->next);
//
//        return cur;
//    }
//
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr) return head;
//
//        return SwapRecursion(head, head->next);
//    }
//};


//// 扫描长度
//class Solution
//{
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n)
//    {
//        if (head == nullptr) return head;
//
//        // 扫描长度
//        int len = 0;
//        ListNode* cur = head;
//        while (cur)
//        {
//            cur = cur->next;
//            len++;
//        }
//
//        int index = len - n;
//        cur = head;
//        ListNode* prev = nullptr;
//        while (index--)
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//
//        if (prev == nullptr)
//        {
//            head = head->next;
//        }
//        else
//        {
//            prev->next = cur->next;
//        }
//
//        return head;
//    }
//};

// // 快慢指针
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (head == nullptr) return head;
//
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* slow = dummy;
//        ListNode* fast = dummy;
//        // 快指针先走 n 步
//        while (n-- && fast) fast = fast->next;
//        fast = fast->next; // 再多走一步， 定位到需要删除结点的上一个
//
//        // 一起走
//        while (fast)
//        {
//            fast = fast->next;
//            slow = slow->next;
//        }
//
//        slow->next = slow->next->next;
//
//        return dummy->next;
//    }
//};

//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (!head) return head;
//
//        stack<ListNode*> stk;
//        ListNode* cur = head;
//
//        stk.push(nullptr);
//        while (cur)
//        {
//            stk.push(cur);
//            cur = cur->next;
//        }
//
//        for (int i = 0; i < n; i++)
//        {
//            stk.pop();
//        }
//        ListNode* prev = stk.top();
//        if (prev == nullptr) return head->next;
//        else
//        {
//            prev->next = prev->next->next;
//            return head;
//        }
//    }
//};


//class Solution
//{
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
//    {
//        if (!headA || !headB) return nullptr;
//
//        ListNode* cur = headA;
//        unordered_set<ListNode*> visited;
//        while (cur)
//        {
//            visited.insert(cur);
//            cur = cur->next;
//        }
//
//        cur = headB;
//        while (cur)
//        {
//            if (visited.count(cur) > 0) return cur;
//            cur = cur->next;
//        }
//        return nullptr;
//    }
//};


//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        if (head == nullptr) return nullptr;
//
//        unordered_set<ListNode*> visited;
//
//        while (head)
//        {
//            if (visited.count(head) > 0) return head;
//            visited.insert(head);
//            head = head->next;
//        }
//        return nullptr;
//    }
//};

class MyLinkedList {
public:
    struct Node
    {
        Node(int val = 0)
            : val(val)
            , next(this)
            , prev(this)
        {}

        ~Node()
        {
            next = nullptr;
            prev = nullptr;
        }

        int val;
        Node* next;
        Node* prev;
    };


    MyLinkedList()
        : _head(nullptr)
    {
        _size = 0;
    }

    int get(int index) {
        if (index >= _size) return -1;

        Node* cur = _head;
        while (index--)
        {
            cur = cur->next;
        }

        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(_size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > _size) return;

        Node* newnode = new Node(val);
        if (_head == nullptr)
        {
            _head = newnode;
            _size++;
            return;
        }

        Node* cur = _head;
        int cnt = index;
        while (cnt--)
        {
            cur = cur->next;
        }
        newnode->prev = cur->prev;
        cur->prev->next = newnode;
        newnode->next = cur;
        cur->prev = newnode;

        if (index == 0)
        {
            _head = newnode;
        }

        _size++;
    }

    void deleteAtIndex(int index) {
        if (index > _size || _size == 0) return;

        Node* cur = _head;
        int cnt = index;
        while (cnt--)
        {
            cur = cur->next;
        }

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        if (index == 0) _head = cur->next;
        delete cur;

        _size--;

        if (_size == 0) _head = nullptr;
    }

private:
    Node* _head;
    int _size;
};

int main()
{
    MyLinkedList* list = new MyLinkedList();
    list->addAtHead(2);
    list->deleteAtIndex(1);
    list->addAtHead(2);
    list->addAtHead(7);
    list->addAtHead(3);
    list->addAtHead(2);
    list->addAtHead(5);
    list->addAtTail(5);
    list->get(5);
    list->deleteAtIndex(6);
    list->deleteAtIndex(4);



    delete list;

    return 0;
}