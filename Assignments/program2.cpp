#include<iostream>
using namespace std;

class Student
{
  private :
           int a[10],i;
           
  public :
          void read();
          void dis();
};

int main()
{
  Student obj1;
  
  obj1.read();
  obj1.dis();
  
}

void Student::read()
{
  for(i=0;i<10;i++)
  {
    cout<<"Enter the Student Roll No : ";
    cin>>a[i];
  }
  
}

void Student::dis()
{
  for(i=0;i<10;i++)
  {
    cout<<a[i];
   }
}

/*Enter the Student Roll No : 1
Enter the Student Roll No : 2
Enter the Student Roll No : 3
Enter the Student Roll No : 4
Enter the Student Roll No : 5
Enter the Student Roll No : 6
Enter the Student Roll No : 7
Enter the Student Roll No : 8
Enter the Student Roll No : 9
Enter the Student Roll No : 10
12345678910
*/


