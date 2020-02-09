#include<iostream>
using namespace std;


struct Node
{
    struct Node *left, *right;
    int data;
};


Node *concatenate(Node *leftList, Node *rightList)
{

    if (leftList == NULL)
        return rightList;
    if (rightList == NULL)
        return leftList;


    Node *leftLast = leftList->left;


    Node *rightLast = rightList->left;


    leftLast->right = rightList;
    rightList->left = leftLast;


    leftList->left = rightLast;


    rightLast->right = leftList;

    return leftList;
}


Node *bTreeToCList(Node *root)
{
    if (root == NULL)
        return NULL;

    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);


    root->left = root->right = root;


    return concatenate(concatenate(left, root), right);
}


void displayCList(Node *head)
{
    cout << "Circular Linked List is :\n";
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << "\n";
}



Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


int main()
{
    cout << "Enter elements of Binary Tree" <<endl;
    int x,y,z,a,b,c;
    cin >> x;
    cin >> y;
    cin >> z;
    cin >> a;
    cin >> b;
    cin >> c;
    Node *root = newNode(x);
    root->left = newNode(y)
    ;
    root->right = newNode(z);
    root->left->left = newNode(a);
    root->left->right = newNode(b);
    root->right->left = newNode(c);

    Node *head = bTreeToCList(root);
    displayCList(head);

    return 0;
}
