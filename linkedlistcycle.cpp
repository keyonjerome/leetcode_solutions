using namespace std;

#include <iostream>

class ListNode {
public:
    int value = 0;
    ListNode *next;

    ListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedListCycle {
public:
    static bool hasCycle(ListNode *head) {
        // TODO: Write your code here
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow->next != nullptr) {
            for(int i = 0; i < 2; i++) {
                if (fast->next == nullptr) return false;
                else if(fast->next == slow) return true;
                else fast = fast->next;
            }
            slow = slow->next;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

    head->next->next->next->next->next->next = head->next->next;
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

    head->next->next->next->next->next->next = head->next->next->next;
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
}
