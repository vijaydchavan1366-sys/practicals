#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
    private:
    Node *root;
    Node *insert(Node *root,int val)
    {
        if (root == nullptr)
        {
            return new Node(val);
        }
        if (val <root->data)
        {
            root->left=insert(root->right,val);
        }
        return root;
    }
    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->data <<" ";
            inorder(root->right);
        }
    }
    void preorder(Node *root)
    {
        if (root!= nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
    public:
    BST()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        root = insert(root,val);
    }
    void inorder()
    {
        cout << "inorder traversal :";
        inorder(root);
        cout << endl;
    }
    void postorder()
    {
        cout << "postorder traversal :"
        postorder(root)
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert(23);
    tree.insert(65);
    tree.insert(54);
    tree.insert(89);
    tree.insert(115);
    tree.insert(95);
    tree.insert(45);

    tree.inorder();
    tree.preorder();
    tree.postorder();

    return 0;

}