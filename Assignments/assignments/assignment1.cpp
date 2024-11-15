/*
Name : Prachi Mehetre
Class : SE B2
Roll no.: 47
PROBLEM STATEMENT :
Set operations: Write a menu driven C++ program to store sets for 
students' names participating in different events in Equinox such as Coding 
contest, Project competition, Paper Presentation, MasterMind etc.
1. Find out participants who have participated in Coding and Project 
both
2. Find out participants who have participated in Coding or Project 
competition or both or Mastermind
3. Find out participants who have participated in Coding but not in 
Master mind 
Find out participants who have participated in all events*/
#include<iostream>
using namespace std;
class event{
   public :
         char name[20];
         int code=0,project=0,paper=0,master_mind=0;
         int ev,op;

   public :
          void getdata()
          {
               cout<< "Enter name of the students"<<endl;
               cin >> name;
               cout<< "Enter Event in which he/she is interested"<<endl;
               cout<< "Press 1 for CODING COMPETITION"<<endl<<"Press 2 for PROJECT COMPETITION"<<endl<<"Press 3 for PAPER PRESENTATION"<<endl<<"Press 4 for MASTER MIND"<<endl;
               
               do {
                      cin >> ev;
                      if(ev==1)
                      {
                           code=1;
                      }
                      else if(ev==2)
                      {
                           project=1;
                      }
                      else if(ev==3)
                      {
                           paper=1;
                      }
                      else if(ev==4)
                      {
                           master_mind=1;
                      }
                      else
                      {
                           cout<<"Wrong choice entered.";
                      }
                      cout<<"Do you want to continue with any other event (if YES press 1)";
                      cin>>op;
                  }while(op==1);    
           }  
           
           void putdata()
           {
               
                if(code==1 && project==0 && paper==0 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"CODING"<<endl;
                }
                if(code==0 && project==1 && paper==0 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"PROJECT COMPETITION"<<endl;
                }
                if(code==0 && project==0 && paper==1 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"PAPER PRESENTATION"<<endl;
                }
                if(code==0 && project==0 && paper==0 && master_mind==1)
                {
                      cout<<name<<"\t"<<"\t"<<"MASTER MIND"<<endl;
                }
                if(code==1 && project==1 && paper==0 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"CODING,PROJECT COMPETITION"<<endl;
                }
                if(code==1 && project==1 && paper==1 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"CODING,PROJECT COMPETITION,PAPER PRESENTATION"<<endl;
                }
                if(code==1 && project==1 && paper==1 && master_mind==1)
                {
                      cout<<name<<"\t"<<"CODING,PROJECT COMPETITION,PAPER PRESENTATION,MASTER MIND"<<endl;
                }
                if(code==1 && project==0 && paper==1 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"CODING,PAPER PRESENTATION"<<"\n";
                }
                if(code==1 && project==0 && paper==0 && master_mind==1)
                {
                      cout<<name<<"\t"<<"\t"<<"CODING,MASTER MIND"<<endl;
                }
                if(code==0 && project==1 && paper==1 && master_mind==0)
                {
                      cout<<name<<"\t"<<"\t"<<"PROJECT COMPETITION,PAPER PRESENTATION"<<"\n";
                }
                if(code==0 && project==1 && paper==0 && master_mind==1)
                {
                      cout<<name<<"\t"<<"\t"<<"PROJECT COMPETITION,MASTER MIND"<<endl;
                }    
           }
};

int main()
{
   int option ,n,i;
   event e[n];
   cout << "Enter No. of students"<<endl;
   cin >> n;
   
   do{
        char ch;
        cout<<"a.To store the data ,b.To display data <<endl"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
              case 'a' :
                      cout<<endl<<"Enter details of student "<<i+1<<" : "<<endl;
                      for(i=0;i<n;i++)
                      {
                            e[i].getdata();
                      }
                      break;
                     
               
           
               case 'b' :
                       cout<<"NAME"<<"\t"<<"\t"<<"EVENT"<<endl;
                       for(i=0;i<n;i++)
                       {
                            e[i].putdata();
                       }
                       break;  
              default :
                      cout<<"Enter Valid Choice"<<endl;
                      break;
         }
         cout<<"Do you want to continue(1-Yes & 2-No)"<<endl;
         cin>>option;
      }while(option==1);
}
           
                     
                     
       
/*
OUTPUT
(base) unix@unix-HP-280-G4-MT-Business-PC:~$ cd COM-SE-B2_40
(base) unix@unix-HP-280-G4-MT-Business-PC:~/COM-SE-B2_40$ g++ assign1.cpp
(base) unix@unix-HP-280-G4-MT-Business-PC:~/COM-SE-B2_40$ ./a.out
Enter No. of students
2
a.To store the data ,b.To display data <<endl
Enter your choice
a

Enter details of student 1 :
Enter name of the students
prachi
Enter Event in which he/she is interested
Press 1 for CODING COMPETITION
Press 2 for PROJECT COMPETITION
Press 3 for PAPER PRESENTATION
Press 4 for MASTER MIND
1
Do you want to continue with any other event (if YES press 1)1
2
Do you want to continue with any other event (if YES press 1)1
3
Do you want to continue with any other event (if YES press 1)1
4
Do you want to continue with any other event (if YES press 1)2
Enter name of the students
mrunal
Enter Event in which he/she is interested
Press 1 for CODING COMPETITION
Press 2 for PROJECT COMPETITION
Press 3 for PAPER PRESENTATION
Press 4 for MASTER MIND
1
Do you want to continue with any other event (if YES press 1)1
3
Do you want to continue with any other event (if YES press 1)2
Do you want to continue(1-Yes & 2-No)
1
a.To store the data ,b.To display data <<endl
Enter your choice
b
NAME EVENT
prachi CODING,PROJECT COMPETITION,PAPER PRESENTATION,MASTER MIND
mrunal CODING,PAPER PRESENTATION
Do you want to continue(1-Yes & 2-No)
2
(base) unix@unix-HP-280-G4-MT-Business-PC:~/COM-SE-B2_40
 
  */ 
