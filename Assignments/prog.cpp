#include<iostream>
using namespace std;

class Array 
{
  private:
         int maxsize ;
         int A[20];
         int size;
         
  
  public:
       Array()
       {
         maxsize=20;
         size=0;
        }
        
        
    void read_Array();
    void display();
   
   
   
 };
 int main ()
{
    Array obj1;
    
    obj1.read_Array();
    obj1.display();
    
}
 
 void Array::read_Array()
 {
   int i,n;
   cout<<"Enter the size of array";
   cin>>n;
   
   if(n>maxsize)
   {
    cout<<"Array of this size cannot be created";
    cout<<"Maximum size is " <<maxsize;
    return;
   }
   
   else 
   {
    for(i=0;i<n;i++)
    {
     cin>>A[i];
     }
     
     size = n;
    }
}


void Array::display()
{
int i;
  for(i=0;i<size;i++)
  {
    cout<<A[i]<<"\t";
    
   }
   cout<<endl;
}
   


