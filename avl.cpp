#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string key;
    string meaning;
    node *left;
    node *right;
};
class avl
{
    node *root;

public:
    avl()
    {
        root = NULL;
    }
    void create();
    node *insert(node *root, node *temp);
    node *balance(node *root);
    int dif(node *root);
    int height(node *root);
    int maximum(int a, int b);

    node *LL(node *root);
    node *RR(node *root);
    node *LR(node *root);
    node *RL(node *root);

    void display();
    void accending(node *root);
    void desending(node *root);
    void search();
    bool search_node(node *root, string key);
    void deleten();
    node *delete_node(node *root, string kay);
    node *extract(node *temp);
};
void avl::create()
{
    node *temp;
    char ans;
    do
    {
        temp=new node();
        cout << "enter key : ";
        cin >> temp->key;
        cout << "enter meaning : ";
        cin >> temp->meaning;
        temp->left = temp->right = NULL;

        root = insert(root, temp);
        cout << "countinue : ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
node *avl::insert(node *root, node *temp)
{
    if (root == NULL)
    {
        return temp;
    }
    else if (temp->key < root->key)
    {
        root->left = insert(root->left, temp);
        root=balance(root);
    }
    else if (temp->key > root->key)
    {
        root->right = insert(root->right, temp);
        root=balance(root);
    }
    return root;
}
node *avl::balance(node *root)
{
    int bal = dif(root);
    if (bal >= 2)
    {
        if (dif(root->left) < 0)
        {
            root = LR(root);
        }
        else
        {
            root = LL(root);
        }
    }
    if (bal <= -2)
    {
        if (dif(root->right) < 0)
        {
            root = RR(root);
        }
        else
        {
            root = RL(root);
        }
    }
    return root;
}
int avl::dif(node *root)
{
    int l = height(root->left);
    int r = height(root->right);
    return l - r;
}
int avl::height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return maximum(height(root->left), height(root->right));
    }
}
int avl::maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
node *avl::LL(node *root)
{
    node *temp, *temp1;
    temp = root->left;
    temp1 = temp->right;
    temp->right = root;
    root->left = temp1;
    return temp;
}
node *avl::RR(node *root)
{
    node *temp, *temp1;
    temp = root->right;
    temp1 = temp->left;
    temp->left = root;
    root->right = temp1;
    return temp;
}
node *avl::LR(node *root)
{
    node *temp, *temp1;
    temp = root->left;
    root->left = RR(temp);
    temp1 = LL(root);
    return temp1;
}
node *avl::RL(node *root)
{
    node *temp, *temp1;
    temp = root->right;
    root->right = LL(temp);
    temp1 = RR(root);
    return temp1;
}
void avl::accending(node *root)
{
    if (root != NULL)
    {
        accending(root->left);
        cout << root->key << "\t" << root->meaning<<endl;
        accending(root->right);
    }
}
void avl::desending(node *root)
{
    if (root != NULL)
    {
        desending(root->right);
        cout << root->key << "\t" << root->meaning<<endl;
        desending(root->left);
    }
}
void avl::display()
{
    cout << "accending : " << endl;
    accending(root);
    cout << "desending : " << endl;
    desending(root);
}
bool avl::search_node(node *root, string key2)
{
    if (root != NULL)
    {
        if (root->key == key2)
        {
            return true;
        }
        else if (root->key < key2)
        {
            return search_node(root->right, key2);
        }
        else if (root->key > key2)
        {
            return search_node(root->left, key2);
        }
    }
     return false;
}
void avl::search()
{
    string key1;
    cout << "enter key to search : ";
    cin >> key1;
    if (search_node(root, key1))
    {
        cout << "key found :" << endl;
    }
    else
    {
        cout << "key not found ..." << endl;
    }
}
node *avl::extract(node *temp)
{
    if (temp->left == NULL)
    {
        return temp->right;
    }
    temp->left = extract(temp->left);
    return balance(temp);
}
node *avl::delete_node(node *root, string key2)
{
    if (search_node(root, key2))
    {
        if (key2 < root->key)
        {
            root->left=delete_node(root->left, key2);
        }
        else if (key2 > root->key)
        {
            root->right=delete_node(root->right, key2);
        }
        else
        {
            node *l = root->left;
            node *r = root->right;
            delete root;
            if (r == NULL)
            {
                return l;
            }
            node *m = r;
            while (m->left != NULL)
            {
                m = m->left;
            }
            m->right = extract(r);
            m->left = l;
            return balance(m);
        }
        cout << "key deleted ..."<<endl;
        return balance(root);
    }
    else
    {
        cout << "key not found..."<<endl;
        return balance(root);
    }
}
void avl::deleten()
{
    string key1;
    cout << "enter key to delete : ";
    cin >> key1;
    root = delete_node(root, key1);
}
int main()
{
    char ch1;
    int ch;
    avl o;
    do
    {
        cout << "1)create\n2)display\n3)search\n4)delete\n";
        cout << "choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            o.create();
            break;
        case 2:
            o.display();
            break;
        case 3:
            o.search();
            break;
        case 4:
            o.deleten();
            break;
        default:
            break;
        }
        cout << "continue : ";
        cin >> ch1;
    } while (ch1 == 'y' || ch1 == 'Y');
}