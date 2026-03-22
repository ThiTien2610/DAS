#include<iostream>
class Node
{
public:
    int value;
    Node* next;
    Node* previous;
};

void insertAfter(Node** head, Node** tail, int x)
{
    Node* node = new Node();
    node->value =x;
    node->next = nullptr;
    node->previous= nullptr;

    if (*head==nullptr)
    {
        *head= node;
        *tail=node;
    }
    else
    {
        node->previous=*tail;
        (*tail)->next=node;
        *tail=node;
    }
}

void insertBefore(Node** head, Node** tail, int x)
{
    Node* node = new Node();
    node->value =x;
    node->next = nullptr;
    node->previous= nullptr;

    if (*head==nullptr)
    {
        *head= node;
        *tail=node;
    }
    else
    {
        node->next=*head;
        (*head)->previous=node;
        *head=node;
    }
}

void printForward(Node* head)
{
    while(head!=nullptr)
    {
        std::cout<< head->value << " ";
        head=head-> next;
    }
}

void splitOddEven(Node* inputHead, Node** head1,Node** tail1,Node** head2,Node** tail2)
{
    Node* current=inputHead;
    while(current != nullptr)
    {
        if (current->value %2 !=0)
            insertAfter(head1, tail1, current->value);
        else
            insertBefore(head2,tail2,current->value);

        current=current-> next;
    }
}

int main()
{
    Node* head=nullptr;
    Node* tail=nullptr;

    int n;
    std::cout<< "Enter N: ";
    std::cin>>n;

    std::cout<<"Enter the list: ";
    for (int i=0; i<n;++i)
    {
        int x;
        std::cin>>x;
        insertAfter(&head,&tail,x);
    }
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* tail1 = nullptr;
    Node* tail2 = nullptr;

    splitOddEven(head,&head1,&tail1,&head2,&tail2);

    std::cout<< "1st List: ";
    printForward(head1);
    std::cout<< "2nd List: ";
    printForward(head2);

    return 0;

}
