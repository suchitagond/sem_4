#include <bits/stdc++.h>
using namespace std;

struct node
{
    int ch_count;
    int sec_count;
    int sub_section;
    char name[20];
    struct node *child[10];
} *root;

class tree
{
public:
    void display(node *ptr);
    void insert();
    tree()
    {
        root = NULL;
    }
};

void tree::insert()
{
    root = new node;
    cout << "enter name of book : ";
    cin >> root->name;
    cout << "enter no of chapters : ";
    cin >> root->ch_count;
    for (int i = 0; i < root->ch_count; i++)
    {
        root->child[i] = new node;
        cout << "enter chapter " << i + 1 << " name : ";
        cin >> root->child[i]->name;
        cout << "no of sections : ";
        cin >> root->sec_count;
        for (int j = 0; j < root->sec_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "enter section " << j + 1 << " name : ";
            cin >> root->child[i]->child[j]->name;
            cout << "no of sub sections : ";
            cin >> root->sub_section;
            for (int k = 0; k < root->sub_section; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "enter sub section " << k + 1 << " name : ";
                cin >> root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}
void tree::display(node *ptr)
{
    if (ptr != NULL)
    {
        cout << "-----------" << endl;
        cout << "\nBook : " << ptr->name << endl;
        for (int i = 0; i < ptr->ch_count; i++)
        {
            cout << "   Chapter " << i + 1 << " :  " << ptr->child[i]->name << endl;
            for (int j = 0; j < ptr->sec_count; j++)
            {
                cout << "      Section " << j + 1 << " :  " << ptr->child[i]->child[j]->name << endl;
                for (int k = 0; k < ptr->sub_section; k++)
                {
                    cout << "         Sub Section " << k + 1 << " :  " << ptr->child[i]->child[j]->child[k]->name << "\n";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "-----------" << endl;
    }
}
int main(){
    tree o;
    o.insert();
    o.display(root);
    return 0;
}