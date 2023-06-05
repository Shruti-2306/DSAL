#include<iostream>
#define Max 15
using namespace std;

struct node
{
    string name;

    node *left, *right;
};
class Tree
{
    node *root;

    public:
    Tree()
    {
        root = NULL;
    }

    node *create()
    {
        string a;
        node *temp = new node;

        cout<<"Enter name(NULL for no name): ";
        cin>>a;

        if(a != "NULL")
        {
            temp -> name = a;
            cout<<"Enter left child of "<<a<<": ";
            temp -> left = create();
            cout<<"Enter right child of "<<a<<": ";
            temp -> right = create();
        }
        else
        {
            temp = NULL;
        }
        return temp;

    }

    void recInorder(node *t)
    {
        if(t != NULL)
        {
            recInorder(t -> left);
            cout<< t-> name<<"  ";
            recInorder(t->right);
        }
    }

    
    void recPreorder(node *t)
    {
        if(t != NULL)
        {
            cout<< t-> name<<"  ";
            recPreorder(t -> left);
            
            recPreorder(t->right);
        }
    }

     void recPostorder(node *t)
    {
        if(t != NULL)
        {
            recPostorder(t -> left);
            
            recPostorder(t->right);
            
            cout<< t-> name<<"  ";
        }
    }
    
    
    void menu()
    {
        cout<<"Create binary tree\n";
        root = create();

        cout<<"Recursive: \n";
        cout<<"\nInorder: \n"<<endl;
        recInorder(root);
         cout<<"\nPreorder: \n"<<endl;
        recPreorder(root);
         cout<<"\nPostorder: \n"<<endl;
        recPostorder(root);

        
    }

};
int main()
{
    Tree book;
    book.menu();
    return 0;
}
