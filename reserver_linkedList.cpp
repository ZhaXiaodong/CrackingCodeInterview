#include <iostream>

struct Node
{
    Node* next;    
};

void Reverse(Node* root)
{
    Node* cur = root;
    Node* prev = NULL;
    
    while(cur)
    {
        Node* tem = cur;
        cur = cur->next;
        tem->next = prev;
        prev = tem;    
    }
       
    return prev;    
}

void Reverse(Node* root)
{
    Node* cur = root;
    Node* prev = NULL;
    
    while(cur)    
    {
        Node* next = cur->next;
        cur->next = prev;
        cur = next;
        prev = cur;    
    }

    return prev;
}
