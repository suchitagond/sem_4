#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    char v[10];
    char m[20];
    node *left;
    node *right;
};

class dict
{
public:
    node *root;
    void create();
    void display(node *);
    void insert(node *, node *);
    int search(node *, char[]);
    int update(node *, char[]);
    node *del(node *, char[]);
    node *min(node *);
};

void dict::create()
{
    char ch;
    node *temp;
    do
    {
        temp = new node;
        cout << "enter keyword : ";
        cin >> temp->v;
        cout << "enter meaning : ";
        cin >> temp->m;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }
        cout << "do you want to add more (y/n) : ";
        cin >> ch;
    } while (ch == 'y');
}

void dict::insert(node *root, node *temp)
{
    if (strcmp(temp->v, root->v) < 0)
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
}

void dict::display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << "keyword : " << root->v << endl;
        cout << "meaning : " << root->m << endl;
        display(root->right);
    }
}

int dict::search(node *root, char v[10])
{
    int c = 0;
    while (root != NULL)
    {
        c++;
        if (strcmp(v, root->v) == 0)
        {
            cout << "no of comparision : " << c << endl;
            return 1;
        }
        else if (strcmp(v, root->v) < 0)
        {
            root = root->left;
        }
        else if (strcmp(v, root->v) > 0)
        {
            root = root->right;
        }
    }
    return -1;
}

int dict::update(node *root, char v[10])
{
    while (root != NULL)
    {
        if (strcmp(v, root->v) == 0)
        {
            cout << "enter new meaning of keyward " << root->v<<" : ";
            cin >> root->m;
            return 1;
        }
        else if (strcmp(v, root->v) < 0)
        {
            root = root->left;
        }
        else if (strcmp(v, root->v) > 0)
        {
            root = root->right;
        }
    }
    return -1;
}

node *dict::del(node *root, char v[10])
{
    node *temp;
    if (root == NULL)
    {
        cout << "element not fount : " << endl;
        return root;
    }
    if (strcmp(v, root->v) < 0)
    {
        root->left = del(root->left, v);
        return root;
    }
    if (strcmp(v, root->v) > 0)
    {
        root->right = del(root->right, v);
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        temp = root;
        delete temp;
        return NULL;
    }
    else if (root->left == NULL)
    {
        temp = root;
        root = root->right;
        delete temp;
        return root;
    }
    else if (root->right == NULL)
    {
        temp = root;
        root = root->left;
        delete temp;
        return root;
    }
    temp = min(root->right);
    strcpy(root->v, temp->v);
    root->right = del(root->right, temp->v);
    return root;
}

node *dict::min(node *q)
{
    while (q->left != NULL)
    {
        q = q->left;
    }
    return q;
}

int main()
{
    int ch;
    char ch1;
    dict d;
    d.root = NULL;
    do
    {
        cout << "1)create\n2)display\n3)search\n4)update\n5)delete\n";
        cout<<"enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.create();
            break;
        case 2:
            if (d.root == NULL)
            {
                cout << "no any keyward : ";
            }
            else
            {
                d.display(d.root);
            }
            break;
        case 3:
            if (d.root == NULL)
            {
                cout << "empty dictionary : " << endl;
            }
            else
            {
                char n[10];
                cout << "enter keyward that you want to search :";
                cin >> n;
                if (d.search(d.root, n) == 1)
                {
                    cout << "keyward found : " << endl;
                }
                else
                {
                    cout << "keyward not found : " << endl;
                }
            }
            break;
        case 4:
            if (d.root == NULL)
            {
                cout << "empty dictionary : " << endl;
            }
            else
            {
                char n[10];
                cout << "enter keyward that you want to update : ";
                cin >> n;
                if (d.update(d.root, n) == 1)
                {
                    cout << "meaning updated : " << endl;
                }
                else
                {
                    cout << "keyward not found :" << endl;
                }
            }
            break;
        case 5:
            if (d.root == NULL)
            {
                cout << "empty dictionary : " << endl;
            }
            else
            {
                char n[10];
                cout << "enter keyward that you want to delete : ";
                cin >> n;
                if (d.root == NULL)
                {
                    cout << "dictionary is empty : ";
                }
                else
                {
                    d.root = d.del(d.root, n);
                }
            }
            break;
        default:
            cout << "invalid choice : " << endl;
            break;
        }
        cout << "do you want to continue (y/n) : ";
        cin >> ch1;
    } while (ch1 == 'y');
    return 0;
}