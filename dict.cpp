#include <bits/stdc++.h>
using namespace std;

struct node
{
    char value[20];
    char meaning[20];
    node *left;
    node *right;
    // node *root;
};
class dict
{
public:
    node *root;
    // dict()
    // {
    //     root = NULL;
    // }
    void create();
    void insert(node *root, node *temp);
    void display(node *root);
    int update(node *root, char v[]);
    int search(node *root, char v[]);
    node *del(node *root, char v[]);
    node *min(node *root);
};

void dict ::create()
{
    char ch;
    node *temp;
    do
    {
        temp = new node;
        cout << "enter value : ";
        cin >> temp->value;
        cout << "enter meaning : ";
        cin >> temp->meaning;
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
        cout << "do you want to add more : ";
        cin >> ch;
    } while (ch == 'y');
}
void dict::insert(node *root, node *temp)
{
    if (strcmp(temp->value, root->value) < 0)
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
        cout << "value : " << root->value << endl;
        cout << "meaning : " << root->meaning << endl;
        display(root->right);
    }
}
int dict::update(node *root, char v[20])
{
    while (root != NULL)
    {
        if (strcmp(v, root->value) == 0)
        {
            cout << "key found...";
            cout << "enter new meaning for " << root->value;
            cin >> root->meaning;
            return 1;
        }
        else if (strcmp(v, root->value) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return -1;
}
int dict::search(node *root, char v[20])
{
    int c = 0;
    while (root != NULL)
    {
        c++;
        if (strcmp(v, root->value) == 0)
        {
            cout << "key found...";
            cout << "no of comparission : " << c;
            return 1;
        }
        else if (strcmp(v, root->value) < 0)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return -1;
}

node *dict::del(node *root, char v[20])
{
    node *temp;
    if (root == NULL)
    {
        cout << "element not found...";
        return root;
    }
    if (strcmp(v, root->value) < 0)
    {
        root->left = del(root->left, v);
        return root;
    }
    if (strcmp(v, root->value) > 0)
    {
        root->right = del(root->right, v);
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        temp = root;
        delete temp;
        root = NULL;
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
    temp = min(root);
    strcpy(root->value, temp->value);
    root->right = del(root->right, temp->value);
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
        cout << "enter your choice : ";
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