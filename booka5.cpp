#include<iostream>
#define Max 15
using namespace std;

struct node
{
    string name;

    node *left, *right;
};

class stack
{
    node *arr[Max];
    bool flag[Max];
    int top;

    stack()
    {
        top = -1;

    }

    bool empty()
    {
        if( top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(node *p)
    {
        if(top == Max-1)
        {
            return;
        }
        else
        top++;
        arr[top] = p;
    }

    void push(node *p, bool f)
    {
        if(top == Max-1)
        {
            return;
        }
        else
        top++;
        arr[top] = p;
        flag[top] = f;
    }
    bool flagValue()
    {
        return flag[top];
    }

    node *pop()
    {
        node *temp;
        temp = arr[top];
        top--;
        return temp;
        
    }
};

class Queue
{
    node *arr[Max];
    int front, rear;

    public:
    Queue()
    {
        front = rear = -1;
    }

    bool empty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(node *p)
{
    if(empty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = p;
}

node *remove()
{
    node *t = arr[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {front++;}
    return t;
}

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

    
void BFS(node *t)
{
    Queue *q1 = new Queue;
    Queue *q2 = new Queue;
    q1->insert(t);
    cout << t->name;
    while (!(q1->empty()))
    {
        q2 = new Queue;
        cout << endl;
        while (!(q1->empty()))
        {

            node *t = q1->remove();
            if (t->left != NULL)
            {
                std::cout << t->left->name << "    ";
                q2->insert(t->left);
            }
            if (t->right != NULL)
            {
                std::cout << t->right->name << "   ";
                q2->insert(t->right);
            }
        }
        q1 = q2;
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

        cout<<"\nBreadth first traversal: \n";
        BFS(root);

    }

};
int main()
{
    Tree book;
    book.menu();
    return 0;
}

