#include <bits/stdc++.h>
using namespace std;

#define N 10
#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

string q[N];
int pr[N];
int f = -1, r = -1;

void enqueue(string d, int p)
{
    if (f == 0 && r == N - 1)
    {
        cout << "hospital is full.. " << endl;
    }
    else
    {
        if (f == -1)
        {
            f++;
            r++;
            q[r] = d;
            pr[r] = p;
        }
        else if (r == N - 1)
        {
            for (int i = f; i <= r; i++)
            {
                q[i - f] = q[i];
                pr[i - f] = pr[i];
            }
            f=0;
            r=r-f;
            int j;
            for (j = r; j >= f; j--)
            {
                if (p > pr[j])
                {
                    q[j + 1] = q[j];
                    pr[j + 1] = pr[j];
                }
                else
                {
                    break;
                }
            }
            q[j + 1] = d;
            pr[j + 1] = p;
            r++;
        }
        else
        {
            int j;
            for (j = r; j >= f; j--)
            {
                if (p > pr[j])
                {
                    q[j + 1] = q[j];
                    pr[j + 1] = pr[j];
                }
                else
                {
                    break;
                }
            }
            q[j + 1] = d;
            pr[j + 1] = p;
            r++;
        }
    }
}
void print()
{
    for (int i = f; i <= r; i++)
    {
        cout << "data : " << q[i] << endl;
        switch (pr[i])
        {
        case 10:
            cout << "priority : SERIOUS " << endl;
            break;
        case 5:
            cout << "priority : NONSERIOUS " << endl;
            break;
        case 1:
            cout << "priority : CHECKUP " << endl;
            break;
        }
    }
}
void dequeue()
{
    if (f == -1)
    {
        cout << "hospital is empty...." << endl;
    }
    else
    {
        cout << "discharged patien " << q[f] << endl;
        cout << "priority " << pr[f] << endl;
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }
    }
}

int main()
{
    int ch, n, p;
    char ch1;
    string data;
    do
    {
        cout << "\n1)Insertion of new entry\n2)Display entries\n3)Delete entries\n"
             << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        int k = 0;
        switch (ch)
        {
        case 1:
            cout << "No. of patient entries you wants to do : ";
            cin >> n;

            while (k < n)
            {
                cout << "enter the name of patient : ";
                cin >> data;
                cout << "1)0:SERIOUS\n2)1:NONSERIOUS\n3)2:CHECKUP" << endl;
                cout << "Enter priority : ";
                cin >> p;
                switch (p)
                {
                case 0:
                    enqueue(data, SERIOUS);
                    break;
                case 1:
                    enqueue(data, NONSERIOUS);
                    break;
                case 2:
                    enqueue(data, CHECKUP);
                    break;
                default:
                    cout << "Enter valid choice..." << endl;
                    break;
                }
                k++;
            }
            break;
        case 2:
            print();
            break;
        case 3:
            dequeue();
            break;
        default:
            cout << "Enter valid choice...." << endl;
        }
        cout << "Do you want to continue (Y/N) : ";
        cin >> ch1;
    } while (ch1 == 'y' || ch1 == 'Y');
    // return 0;
}