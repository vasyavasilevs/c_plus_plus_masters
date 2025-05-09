#include <iostream>
using namespace std;

/*
Метод двух указателей (бегунки, заяц и черепаха): один указатель — медленный, 
продвигается по списку на один узел за шаг; второй — быстрый, 
перескакивает сразу два узла. Когда быстрый указатель достигнет 
конца списка, медленный будет находиться в его середине.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* createList(const int* arr, int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    int values[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(values, 5);

    ListNode* mid = middleNode(head);
    cout << "Middle is: " << mid->val << endl; // 3 

    deleteList(head);
    return 0;
}
