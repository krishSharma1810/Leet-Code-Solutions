#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
    ListNode(int x, ListNode *next)
    {
        this->val = x;
        this->next = next;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
    }
};

void InsertTail(int value, ListNode *&tail)
{
    // creating a temp node
    ListNode *temp = new ListNode(value);

    tail->next = temp;
    tail = tail->next;
}

void PrintList(ListNode *&head)
{
    // creating a temp with the value of head node which will treavers
    // and print the node it will treaverse.
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    ListNode *tail1 = list1;
    ListNode *head1 = list1;
    InsertTail(2, tail1);
    InsertTail(4, tail1);
    PrintList(head1);

    ListNode *list2 = new ListNode(1);
    ListNode *tail2 = list2;
    ListNode *head2 = list2;
    InsertTail(3, tail2);
    InsertTail(4, tail2);
    PrintList(head2);
    return 0;
}