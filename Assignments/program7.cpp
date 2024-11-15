#include<iostream>
using namespace std;

class str
{
  private :
  char name[25];
  
  public : 
  void dis();
};

int main()
{
  str obj;
  obj.dis();
  
return 0;
}

void str::dis()
{

 int count=0;
 char a;
 cout<<"Enter the String : ";
 cin>>name;
 cout<<"Enter the char whose frequency needs to be checked : ";
 cin>>a;
 
 for(int i=0;name[i]!='\0';i++)
 {
    if(name[i]==a)
    {
    count++;
    }
  }
  
  cout<<"Total : ";
  cout<<count;
}  

/*
Enter the String : saaaakssaahi
Enter the char whose frequency needs to be checked : a
Total : 6
*/
   
    
 
 
 
 

  
  
