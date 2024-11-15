#include<iostream>
using namespace std;

class str
{
  private :
  char name[25];
  char name1[25];
  
  public : 
  void read1();
  void read2();
  void dis1();
  void dis2();
  void len1();
  void len2();
  void fre1();
  void fre2();
  void menu();
};

int main()
{
  str obj;
  /*
  obj.read1();
  obj.read2();
  obj.dis1();
  obj.dis2();
  obj.len1();
  obj.len2();
  obj.fre1();
  obj.fre2();
  */
   obj.menu();
 
return 0;
}
  
void str::read1()
{  
    
    cout<<"Enter the string1 : ";
    cin>>name;
}   

void str::read2()
{
 cout<<"Enter the string2 : ";
 cin>>name1;
}

void str::dis1()
{
 cout<<name1;
 cout<<endl;
}
void str::dis2()
{
 cout<<name1;
 cout<<endl;
}

void str::len1()
{
    int count=0;
    for(int i=0;name[i]!='\0';i++)
     {
      count++;
     }
     
      cout<<"Total Length : ";
      cout<<count;
      cout<<endl;
     }

void str::len2()
{
    int count=0;
    for(int j=0;name1[j]!='\0';j++)
     {
      count++;
     }
     
      cout<<"Total Length : ";
      cout<<count;
      cout<<endl;
}



void str::fre1()
{

 int count=0;
 char a;
 cout<<"Enter the char whose frequency needs to be checked : ";
 cin>>a;
 
 for(int i=0;name[i]!='\0';i++)
 {
    if(name[i]==a)
    {
    count++;
    }
  }
  if(count==0)
  {
      cout<<"Enter the String!!";
  }
  else
  {
  cout<<"Total : ";
  cout<<count;
  cout<<endl;
}  
}

void str::fre2()
 
 int count=0;
 char b;
 cout<<"Enter the char whose frequency needs to be checked : ";
 cin>>a;
 
 for(int j=0;name1[j]!='\0';j++)
 {
    if(name1[j]==b)
    {
    count++;
    }
  }
  if(count==0)
  {
      cout<<"Enter the String!!";
  }
  else
  {
  cout<<"Total : ";
  cout<<count;
  cout<<endl;
}  
}


void str::menu()
{
 cout<<"Menu :";
 cout<<endl;
 
 
 int choice;
 do
 {
  cout<<endl;
  cout<<"1.Enter the String \n";
  cout<<"2.Display String \n";
  cout<<"3.Total Length \n";
  cout<<"4.Frequency \n";
  cout<<"5.Exit\n";
  cout<<"Enter your Choice : ";
  
  cin>>choice;
  
  switch(choice)
  {
   case 1:
         read1();
         break;
   case 2:
         read2();
         break;
   case 3:
          dis1();
          break;
   case 4:
           dis2();
           break;
   case 5 :
           len1();
           break;
   case 6 :
           len2();
           break;
   case 7 : 
           fre1();
           break;
   case 8: 
     	   fre2();
     	   break;
   case 9 : 
           cout<<"Existing the menu ";
           break;
   default : cout<<"Invalid choice!!!";
             break;
   }
    
    }while(choice !=5);
    
  }


