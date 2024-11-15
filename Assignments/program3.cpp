#include<iostream>
using namespace std ;

class set
{
    private:
            int a[10];
            int b[10];
            int c[10];
            int i,j,k;
            int m,n;
    
    public: 
      	   void read();
      	   void dis();
      	   void intersection();
      	   
};

int main ()
{
    set obj1;
    
    obj1.read();
    obj1.intersection();
    
}

void set::read()
{
    cout<<"Enter the No. of elements : ";
     cin>>m;
 
   cout<<"Enter Array1 element ";
   
    for(i=0;i<m;i++)
    {
    cin>>a[i];
    }
    
    cout<<"Enter the No. of elements : ";
    cin>>n;
    cout<<"Enter Array2 element ";
  
    for(j=0;j<n;j++)
    {
      cin>>b[j];
    }
  
 }
 
 
  
  void set::intersection()
   {
     int count=0;
    
      for (i=0;i<m;i++)
       { 
         for(j=0;j<n;j++)
         { 
          if(a[i]==b[j])
          {
           c[k]=b[j];
           cout<<c[k];
           count++;
           
          }
         }
       }
        
      
          
     }   
     

/*Enter the No. of elements : 5
Enter Array1 element 1
2
3
4
5
Enter the No. of elements : 5
Enter Array2 element 1
2
8
9
3
123
*/
     
        
      
 
