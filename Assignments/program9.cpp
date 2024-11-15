#include<iostream>
using namespace std;
class matrix
{
  public :
         int A[10][10];
         int B[10][10];
         int r1,r2,c1,c2;
         int C[10][10];
         
  public:
           void menu();
           void read();
           void dis();
           void add();
           void sub();
           void sparce();
};
int main()
{
  matrix obj;
  /*obj.read();
  obj.dis();
  obj.add();
  obj.sub();*/
  obj.menu();
return 0;
}

void matrix::read()
{
 cout<<"Enter the No of rows and column for matrix1 \n";
 cin>>r1>>c1;
 cout<<"Enter the No of rows and column for matrix2\n";
 cin>>r2>>c2;
  cout<<"Enter the elements for matrix1\n";
  for(int i=0;i<r1;i++)
  {
   for(int j=0;j<c1;j++)
     {
       cin>>A[i][j];
     }
   }
  cout<<"Enter the elements for matrix2\n";
 for(int i=0;i<r2;i++)
  {
   for(int j=0;j<c2;j++)
     {
       cin>>B[i][j];
     }
   }
 }
void matrix::dis()
{
cout<<"Matrix A :\n";
for(int i=0;i<r1;i++)
  {
   for(int j=0;j<c1;j++)
     {

       cout<<A[i][j]<<"\t";
     }
     cout<<endl;
   }
   cout<<endl;
   
 cout<<"Matrix B : \n";  
 for(int i=0;i<r2;i++)
  {
   for(int j=0;j<c2;j++)
     {
       cout<<B[i][j]<<"\t";
     }
     cout<<endl;
   }
   cout<<endl;
}

void matrix::add()
{
int i=0,j=0;
  if((r1==r2)&&(c1==c2))
  {
  for(int i=0;i<r1;i++)
  {
   for(int j=0;j<c1;j++)
     {
       C[i][j] = A[i][j] + B[i][j];
      }
    }
   cout<<"Addition matrix is : \n";
   for(int i=0;i<r1;i++)
    {
   for(int j=0;j<c1;j++)
     {
    
      cout<<C[i][j]<<"\t";
      }
   cout<<endl;
   }
   }
   else
   cout<<"Addition can not take place!!";
   cout<<endl;
 }

void matrix::sub()
{
int i=0,j=0;
if((r1==r2)&&(c1==c2))
{
  for(int i=0;i<r1;i++)
  {
   for(int j=0;j<c1;j++)
     {
       C[i][j] = A[i][j] - B[i][j];
      }
    }
   cout<<"Subtraction matrix is : \n";
   for(int i=0;i<r1;i++)
    {
   for(int j=0;j<c1;j++)
     {
    
      cout<<C[i][j]<<"\t";
      }
   cout<<endl;
   }
   }
   else
   cout<<"Subraction can not take place!! ";
   cout<<endl;
 }

void matrix::sparce()
{
  cout<<"Sparce Matrix\n";
  cout<<"Row"<<"\t"<<"Column"<<"\t"<<"Value\n";
  cout<<c1;
 }

void matrix::menu()
{
   int choice ;
    do
    {
     cout<<"1.Read Matrix1 and Matrix2\n";
     cout<<"2.Display Matrix\n";
     cout<<"3.Addition of Matrix\n";
     cout<<"4.Subtraction of Matrix\n";
     cout<<"5.Sparce Matrix\n";
     cout<<"6.Exit\n";
     cout<<"Enter the Choice\n";
     cin>>choice;
     
     switch(choice)
     {
       case 1 : 
               read();
               break;
       case 2 : 
               dis();
               break;
       case 3 :
               add();
               break;
       case 4 : 
               sub();
               break;
       case 5 : 
               sparce();
               break;
       case 6 : 
                cout<<"Existing the Menu \n";
                break;
       default : 
                cout<<"Invalid Choice\n";
      }
     }while(choice!=6);
   }
                









 
 
 
 
 
