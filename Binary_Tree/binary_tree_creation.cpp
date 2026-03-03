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


int main()
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
}