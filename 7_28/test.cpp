#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void Test1() {

    ListNode h1(1, nullptr);
    ListNode h2(2, &h1);
    ListNode h3(3, &h2);
    ListNode h4(4, &h3);
    ListNode h5(5, &h4);

    ListNode* head = &h5;


    if (head == nullptr || head->next == nullptr) {
        while (head != nullptr) {
            cout << head->val << "->";
        }
        cout << "NULL";
    }

    ListNode* tail = head;
    head = head->next;
    ListNode* temp = head ->next;
    head->next = tail;
    tail->next = nullptr;

    while (head->next) {
        tail = head;
        head = temp;
        temp = head->next;
        head->next = tail;
        tail->next = nullptr;
    }

    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL";
}

void Test2() {
    ListNode h1(1, nullptr);
    ListNode h2(2, &h1);
    ListNode h3(3, &h2);
    ListNode h4(4, &h3);
    ListNode h5(1, nullptr);
    ListNode* head = &h5;

    int n = 1;
    ListNode* headNode = new ListNode(0);
    headNode->next = head;
    ListNode* fast = head;
    ListNode* slow = headNode;

    while (n--) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free (temp);
    temp = nullptr;
 }

int main(){
	//Test1();
    Test2();

	return 0;
}