#include<iostream>
using namespace std;

class str
{
  private :
  int str1,str2;
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
    cout<<"Enter the string : ";
    cin>>name;
    
    for(int i=0;name[i]!='\0';i++)
    {
      count++;
     }
     
     cout<<"Total Length : ";
     cout<<count;
     
}
/*
Enter the string : Sakshi
Total Length : 6
*/
 
 
 
