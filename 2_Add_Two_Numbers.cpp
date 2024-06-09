#include<iostream>
using namespace std;

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in 
// reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as 
// a linked list.You may assume the two numbers do not contain any leading zero, except the number 0 itself.


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// solution for leetcode..
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead= new ListNode(0);
        ListNode* tail =dummyhead;
        int carry =0;
        int digit1,digit2;
        while(l1 != nullptr || l2 != nullptr || carry!=0)
        {
            if(l1 != nullptr){
                digit1=l1->val;
            }
            else{
                digit1=0;
            }
            if(l2 != nullptr){
                digit2=l2->val;
            }
            else{
                digit2=0;
            }

            int sum=digit1+digit2+carry;
            int digit=sum%10;
            carry=sum/10;

            ListNode* newNode=new ListNode(digit);
            tail->next =newNode;
            tail = tail->next;


            if (l1!=nullptr){
                l1=l1->next;
            }
            else{
                l1=nullptr;
            }
            if (l2!=nullptr){
                l2=l2->next;
            }
            else{
                l2=nullptr;
            }
        }
        ListNode* result =dummyhead->next;
        delete dummyhead;
        return result;
    }
};


void InsertAtHead(ListNode* &head,int data){
    ListNode* temp =new ListNode(data);
    temp->next=head;
    head=temp;
}

void Print(ListNode* &head){
    ListNode* temp=head;
    while(temp != nullptr){
        cout << temp->val<<" ";
        temp=temp->next;
    }
    cout << endl;
}

// Driver code 

int main(){
    ListNode* dummyhead1=new ListNode();
    int list1[3]={2,4,6};
    for (int i=0;i< 3;i++){
        InsertAtHead(dummyhead1,list1[i]);
    }
    ListNode* head1=dummyhead1->next;
    delete dummyhead1;
    cout << "List1" << endl;
    Print(head1);

    ListNode* dummyhead2=new ListNode();
    int list2[3]={3,5,7};
    for (int i=0;i< 3;i++){
        InsertAtHead(dummyhead2,list2[i]);
    }
    ListNode* head2=dummyhead2->next;
    delete dummyhead2;
    cout << "List2" << endl;
    Print(head2);

    // Solution sol;
    // sol.addTwoNumbers(head1 ,head2);
    return 0;
}