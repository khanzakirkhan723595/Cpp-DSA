#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
        }
};

//method 1 by using queue

/*int main()
{
    int x;
    cout<<"Enter the root: "<<endl;
    cin>>x;
    queue<Node*>q;
    int first,second;
    Node *root=new Node(x);
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<"Enter the left of "<<temp->data<<endl;
        cin>>first;
        if(first!=-1)
        {
            temp->left=new Node(first);
            q.push(temp->left);
        }
        cout<<"Enter the right of "<<temp->data<<endl;
        cin>>second;
        if(second!=-1)
        {
            temp->right=new Node(second);
            q.push(temp->right);
        }
    }
    

    return 0;
}*/


//method 2 using recursion
Node *BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    {
        return NULL;

    }
    Node *temp=new Node(x);
    //left child
    cout<<"Enter left of "<<temp->data<<" : "<<endl;
    temp->left=BinaryTree();
    //right child
    cout<<"Enter right of "<<temp->data<<" : "<<endl;
    temp->right=BinaryTree();
    return temp; //return address
}
int main()
{
    cout<<"Enter root of Binary Tree: "<<endl;
    Node *root;
    root=BinaryTree();
}