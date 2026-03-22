#include <iostream>
class Node
{
public:
    int value;
    Node* next;
};

Node* rotateRight(Node* head, int k)
{
    if (head== nullptr || head->next == nullptr || k==0)
    {
        return head;
    }

    int length=1;
    Node* tail= head;
    while (tail->next != nullptr)
    {
        tail=tail->next;
        length++;
    }

    k %= length;
    if (k ==0)
    {
        return head;
    }
    tail->next= head;

    Node* newLast = head;
    for (int i=1; i<length-k; i++)
    {
        newLast= newLast-> next;
    }

    Node* newHead= newLast-> next;
    newLast-> next = nullptr;

    return newHead;
}

void printList(Node* head)
{
    while(head!=nullptr)
    {
        std::cout<< head->value << " ";
        head=head-> next;
    }
}


int main()
{
    Node* head = new Node{1,nullptr};
    head->next = new Node{2,nullptr};
    head->next->next= new Node{3,nullptr};
    head->next->next->next= new Node{4,nullptr};
    head->next->next->next->next= new Node{5,nullptr};

    std::cout<< "Original List: ";
    printList(head);

    int k=2;

    head= rotateRight(head,k);

    std::cout<< "After rotate List: ";
    printList(head);
    
    return 0;
}