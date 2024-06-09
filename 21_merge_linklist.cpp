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

    void InsertTail(int value, ListNode *&tail)
    {
        // creating a temp node
        ListNode *temp = new ListNode(value);

        tail->next = temp;
        tail = tail->next;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list3 = new ListNode();
        ListNode *tail = list3;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val >= list2->val)
            {
                InsertTail(list2->val, tail);
                list2 = list2->next;
            }
            else
            {
                InsertTail(list1->val, tail);
                list1 = list1->next;
            }
        }
        while (list1 != NULL)
        {
            InsertTail(list1->val, tail);
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            InsertTail(list2->val, tail);
            list2 = list2->next;
        }

        list3 = list3->next;
        return list3;
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
    ListNode obj;

    ListNode *list1 = new ListNode(1);
    ListNode *tail1 = list1;
    ListNode *head1 = list1;
    obj.InsertTail(2, tail1);
    obj.InsertTail(4, tail1);
    PrintList(head1);

    ListNode *list2 = new ListNode(1);
    ListNode *tail2 = list2;
    ListNode *head2 = list2;
    obj.InsertTail(3, tail2);
    obj.InsertTail(4, tail2);
    PrintList(head2);

    ListNode *list3 = obj.mergeTwoLists(head1, head2);
    PrintList(list3);
    return 0;
}