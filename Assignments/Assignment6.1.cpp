#include <iostream>
using namespace std;
class node
{
    public:
          string name;
          int birth_date;
          node *next;
};
class linkedlist
{
    public:
          node *head;
          void insert(string name,int birth_date);
          int dele(int del_date);
          void search(int key);
          void display();
          linkedlist()
          {
              head=NULL;
          }
};
void linkedlist :: insert(string name,int birth_date)
{
    node *temp;
    temp=new node;
    temp->name = name;
    temp->birth_date = birth_date;
    temp->next = nullptr;
    if (head == nullptr || head->birth_date >= temp->birth_date)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        node *c = head;
        while (c->next != nullptr && c->next->birth_date < temp->birth_date)
        {
            c = c->next;
        }
        temp->next = c->next;
        c->next = temp;
    }
}

int linkedlist :: dele(int del_date)
{
    node *temp = head;
    node *p = NULL;
    if(temp!=NULL && temp->birth_date==del_date)
    {
        head=temp->next;
        delete temp;
        cout<<"\nRecord deleted Successfully \n" ;
        return 0;
    }
    while (temp != NULL && temp->birth_date!= del_date)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Record does not Exist\n";
        return -1;
    }
        p->next = temp->next;

        delete temp;
        cout << "Record Deleted " << "Successfully\n";
        return 0;
}
void linkedlist :: search(int key)
{
    if(head==nullptr)
    {
        cout<<"No records available \n";
        return;
    }
    else
    { 
        node *temp=head;
        while(temp!=nullptr)
        {
            if(temp->birth_date==key)
            {
                cout<<"NAME\tBIRTHDAY\n";
                cout<<temp->name<<"\t"<<temp->birth_date<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"No such record available ";
        }
    }
}
void linkedlist :: display()
{
    node *temp;
    temp=head;
    if(head==NULL)
    {
        cout<<"Nothing to display ";
        return;
    }
    else
    {
        cout<<"NAME\tBIRTHDAY\n";
        while(temp!=nullptr)
        {
            cout<<temp->name<<"\t"<<temp->birth_date<<"\n";
            temp=temp->next;
        }
    }
}
int main()
{
    //node *head;
    //head=NULL;
    linkedlist ll;
    string name;
    int birth_date,ch,op,key,del_date;
    do
    {
        cout<<"1.Insert Record\n2.Delete Record\n3.Search Record\n4.Display Record\n5.Exit\n";
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1 :
                    cout<<"Enter name : ";
                    cin>>name;
                    cout<<"Enter birth date : ";
                    cin>>birth_date;
                    ll.insert(name,birth_date);
                    break;
                    
            case 2 :
                   cout<<"Enter the birthday date whose record you want to delete :";
                   cin>>del_date;
                   ll.dele(del_date);
                   break;
                   
            case 3 :
                    cout<<"Enter the birthdate of which you want to search:";
                    cin>>key;
                    ll.search(key);
                    break;
           
            case 4 :
                    ll.display();
                    break;
                    
             case 5 : 
                    exit(0);
                    break;
                    
            default :
                    cout<<"Enter valid choice!!!!!!!!";
                    break ;
        }
        cout<<"\nDo you want to continue ..?? (1=YES,2=NO) : ";
        cin>>op;
    }while(op==1);
    return 0;
}
