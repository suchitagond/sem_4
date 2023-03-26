#include<iostream>
using namespace std;
struct node
{
    char name[20];
    int ch_count;
    int section_count;
    int sub_sc_count;
    struct node *child[10];
}*root;
class tree
{
    public:
        void insert();
        void display(node *ptr);
        tree()
        {
            root=NULL;
        }
};
void tree::insert()
{
    root=new node;
    cout<<"enter the name of Book : ";
    cin>>root->name;
    cout<<"enter number of chapters in a book : ";
    cin>>root->ch_count;
    for(int i=0;i<root->ch_count;i++)
    {
        root->child[i]=new node;
        cout<<"enter chapter "<<i+1<<" name : ";
        cin>>root->child[i]->name;
        cout<<"enter number of sections in a chapter : ";
        cin>>root->section_count;
        for(int j=0;j<root->section_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"enter section "<<j+1<<" name : ";
            cin>>root->child[i]->child[j]->name;
            cout<<"enter number of sub sections in a section : ";
            cin>>root->sub_sc_count;
            for(int k=0;k<root->sub_sc_count;k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"enter sub section "<<k+1<<" name : ";
                cin>>root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}
void tree::display(node *ptr)
{
    if(ptr!=NULL)
    {
        cout<<"-----------"<<endl;
        cout<<"\nBook : "<<ptr->name<<endl;
        for(int i=0;i<ptr->ch_count;i++)
        {
            cout<<"   Chapter "<<i+1<<" :  "<<ptr->child[i]->name<<endl;
            for(int j=0;j<ptr->section_count;j++)
            {
                cout<<"      Section "<<j+1<<" :  "<<ptr->child[i]->child[j]->name<<endl;
                for(int k=0;k<ptr->sub_sc_count;k++)
                {
                    cout<<"         Sub Section "<<k+1<<" :  "<<ptr->child[i]->child[j]->child[k]->name<<"\n";     
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
        cout<<"-----------"<<endl;
    }
}
int main()
{
    int ch;
    tree t;
    while(1)
    {
        cout<<"\n 1)create tree\n 2)display tree\n 3)exit"<<endl;
        cout<<"enter your choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            t.insert();
            break;
        case 2:
            t.display(root);
            break;
        case 3:
            exit(0);
        default:
            cout<<"invalid choice : "<<endl;
            break;
        }
    }
    return 0;
}