#include<iostream>
using namespace std;

class node
{  
public :
   int data ;
   node*next;
};

class single_llist
{
  public:
         node*Head;
        node*create_node();
         void insert_begin();
         void display();
         void insert_last();
         void insert_pos();
         void delete_pos();
         void delete_first();
         //void delete_last();
         void search();
         
         void menu();
         single_llist()
         {
           Head = NULL;
         }
};

node*single_llist::create_node()
{
  node*temp,*s;
  temp = new node;
  int value;
  cout<<"Enter the value to be inserted ";
  cin>>value;
  if(temp==NULL)
  {
   cout<<"Memory not allocated "<<endl;
   return 0;
  }
   else
   {
     temp->data = value;
     temp->next = NULL;
     return temp;
   }
   
 }

void single_llist::insert_begin()
{
   node*temp,*p;
   temp = create_node();
   if(Head == NULL)
   {
      Head = temp;
      Head->next = NULL;
    }
    else 
    {
      p = Head;
      Head = temp;
      Head->next=p;
    }
    
    cout<<"Element inserted at begining "<<endl;
}

void single_llist::display()
{
  node*temp;
  if(Head == NULL)
  {
    cout<<"The list is Empty "<<endl;
    return;
  }
  temp = Head;
  cout<<"Elements of list are : "<<endl;
  while(temp!=NULL)
  {
   cout<<temp->data<<"->" ;
   temp = temp->next;
  }
  
  cout<<"NULL"<<endl;
}


void single_llist::insert_last()
{
  node*temp,*s;
  temp = create_node();
  s = Head;
  while(s->next!=NULL)
  {
    s = s->next;
  }
   temp->next = NULL;
   s->next = temp;
   cout<<"Element inserted at last "<<endl;
}

void single_llist::insert_pos()
{
 int value ,pos,counter=0;
 node*temp,*s,*ptr;
 temp = create_node();
 cout<<"Enter the position at which node to be inserted ";
 cin>>pos;
 int i ;
 s=Head;
 while(s!=NULL)
 {
  s=s->next;
  counter++;
 }
 
 if(pos==1)
 {
  if(Head ==NULL)
  {
     Head = temp;
     Head->next = NULL;
     }
  else 
      {
        ptr = Head;
        Head = temp;
        Head->next=ptr;
      }
    }
   else if ( pos>1 && pos<=counter)
   {
     s = Head;
     for(i=1;i<pos;i++)
     {
        ptr = s;
        s = s->next;
     }
     
     ptr->next = temp;
     temp->next = s;
   }
 else
   {
     cout<<"Position out of range "<<endl;
    }
}

void single_llist::delete_pos()
{
    int pos,i,counter=0;
    if(Head==NULL)
    {
    cout<<"List is Emptya"<<endl;
    return;
    }
    
    cout<<"Enter the position of value to be deleted : ";
    cin>>pos;
    node*s,*ptr;
    s=Head;
    if (pos==1)
    {
      Head = s->next;
     }
     
     else
        { 
          while(s!= NULL)
          {
             s= s->next;
             counter++;
           }
           
           if(pos>0 && pos<=counter)
           {
  		s = Head;
  		for(i=1;i<pos;i++)
  		  {
  		    ptr = s;
  		    s = s->next;
  		  }
  		  
  		  ptr->next = s->next ;
  		 }
  		 
  		 else
  		   {
  		     cout<<"Position out of range "<<endl;
  		    }
  		    
  		    free(s);
  		    cout<<"Element Deleted"<<endl;
  		 }
  }
  
void single_llist::delete_first() 
{
    if (Head == NULL)
     {
        cout << "List is empty" << endl;
        return;
    }

    node* s;
    s=Head;
    Head = s->next;
    delete s;
    cout << "First element deleted" << endl;
}

void single_llist::search()
{
  int value ,pos=0;
  int flag = 0;
  if(Head == NULL)
  {
    cout<<"List is Empty "<<endl;
    return ;
  }
  
  cout<<"Enter the value to Search : ";
  cin>>value;
  
  node*s;
  s=Head;
  while(s!=NULL)
  {
    pos++;
    if(s->data == value)
      {
         flag = 1;
         cout<<"Element "<<value<<" is found "<<pos<<endl;
       }
        s=s->next;
        }
        if(!flag)
           cout<<"Element "<<value<<"Not found in the list"<<endl;
}
  
	
int main()
{
  single_llist s1;
   /* s1.insert_begin();
    s1.insert_last();
    s1.insert_pos();
    s1.delete_pos();
    s1.delete_first();
    s1.search();
    s1.display();*/
    s1.menu();
    
    
    
 return 0;
}



void single_llist::menu()
{
   int choice ;
    do
    {
    
     cout<<"1.Insert node at begining\n";
     cout<<"2.Insert node at last\n";
     cout<<"3.Insert node according to position\n";
     cout<<"4.Delete node according to position\n";
     cout<<"5.Delete first node\n";
     cout<<"6.Search Value\n";
     cout<<"7.Exit\n";
     cin>>choice;
     
     switch(choice)
     {
       /*case 1 : 
               create_node();
               break;*/
       case 1 : 
               insert_begin();
               break;
       case 2:
               insert_last();
               break;
       case 3 : 
               insert_pos();
        	break;
       case 4 : 
               delete_pos();
               break;
               
       case 5 : 
       		delete_first();
       		break;
       case 6 :
               search();
              break;
       case 7 : 
                cout<<"Existing the Menu \n";
                break;
       default : 
                cout<<"Invalid Choice\n";
      }
		display();
     }while(choice!=7);
   }
            

    
