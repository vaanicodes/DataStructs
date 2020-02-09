#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

void zizagtraversal(struct Node* root)
{

    if (!root)
        return;

    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;


    currentlevel.push(root);


    bool lefttoright = true;
    while (!currentlevel.empty()) {


        struct Node* temp = currentlevel.top();
        currentlevel.pop();


        if (temp) {


            cout << temp->data << " ";


            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}

// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


int main()
{
 cout << "Enter elements of Binary Tree" <<endl;
 int a,b,c,d,e,f,g;
 cin >> a;
 cin >> b;
 cin >> c;
 cin >> d;
 cin >> e;
 cin >> f;
 cin >> g;
    struct Node* root = newNode(a);
    root->left = newNode(b);
    root->right = newNode(c);
    root->left->left = newNode(d);
    root->left->right = newNode(e);
    root->right->left = newNode(f);
    root->right->right = newNode(g);
    cout << "ZigZag Order traversal of binary tree is \n";

    zizagtraversal(root);

    return 0;
}
