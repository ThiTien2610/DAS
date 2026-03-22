#include<iostream>
class Node
{
public:
    int value;
    Node* next;
};

Node* getKthNode(Node* temp, int k)
{
    int count=1;
    while ( temp != nullptr && count <k)
    {
        temp= temp->next;
        ++count;
    }
    return temp;
}

Node* reverseLinkedList(Node*head)
{
    Node*prev =nullptr;
    Node*cur = head;

    while(cur != nullptr)
    {
        Node* nxt = cur-> next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}

Node* kReverse(Node*head, int k)
{
    if (head == nullptr|| k<=1)
    {
        return head;
    }

    Node*temp =head;
    Node*prevLast = nullptr;

    while (temp !=nullptr)
    {
        Node* kthNode =getKthNode(temp,k);

        if(kthNode == nullptr)
        {
            if (prevLast != nullptr) 
            {
                prevLast->next=temp;
            }
            break;
        }

        Node* nextNode= kthNode->next;
        kthNode->next = nullptr;

        Node* newHeadOfGroup = reverseLinkedList(temp);
        Node* newTailOfGroup = temp;

        if (temp == head)
        {
            head= newHeadOfGroup;
        }
        else
        {
            prevLast -> next= newHeadOfGroup;
        }

        prevLast= newTailOfGroup;
        temp= nextNode;
    }

    return head;
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

    head= kReverse(head,k);

    std::cout<< "Complete List: ";
    printList(head);
    
    return 0;
}
