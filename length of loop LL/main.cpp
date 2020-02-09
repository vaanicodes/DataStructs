#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;
};


int countNodes(struct Node *n)
{
    int r = 1;
    struct Node *temp = n;
    while (temp->next != n)
    {
        r++;
        temp = temp->next;
    }
    return r;
}


int countNodesinLoop(struct Node *list)
{
    struct Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p &&
                     fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;


        if (slow_p == fast_p)
            return countNodes(slow_p);
    }


    return 0;
}

struct Node *newNode(int key)
{
    struct Node *temp =
   (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}


int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);


    head->next->next->next->next->next = head->next;

    cout << countNodesinLoop(head) << endl;

    return 0;
}
