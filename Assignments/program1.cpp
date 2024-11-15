#include<iostream>
using namespace std;

class Student
{
  private :
           char name[10];
           int rollno;
           int m1,m2,m3;
           
  public :
          void read();
          void dis();
};

int main()
{ 
   Student obj1, obj2, obj3 ;
   
   obj1.read();
   obj2.read();
   obj1.dis();
   obj2.dis();
}

void Student::read()

{
  cout<<"Enter the Student Name :";
  cin>>name;
  cout<<"Enter the Student Roll No :";
  cin>>rollno;
  cout<<"Enter Marks Of 3 Subjects :";
  cin>>m1>>m2>>m3;
}

void Student::dis()
{
   cout<<"\nName is "<<name;
   cout<<"\nRoll No is "<<rollno;
   cout<<"\nMarks are "<<m1<<m2<<m3;
}
  
/*
Enter the Student Name :Sakshi
Enter the Student Roll No :31
Enter Marks Of 3 Subjects :97
78
90
Enter the Student Name :Pranjal
Enter the Student Roll No :49
Enter Marks Of 3 Subjects :90
98
99

Name is Sakshi
Roll No is 31
Marks are 977890
Name is Pranjal
Roll No is 49
Marks are 909899
*/
  
