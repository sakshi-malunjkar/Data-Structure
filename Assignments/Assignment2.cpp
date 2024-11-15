#include <iostream>
using namespace std;

class str 
{
private:
    char name[100];
    char name1[100];

public:
    void read1();
    void read2();
    void dis1();
    void dis2();
    void len1();
    void len2();
    void fre1();
    void fre2();
    void menu();
    void concat();
   // void compare();
    void skip();
    void absubs();
    void palindrome();
};

int main() {
    str obj;
    obj.menu();
    return 0;
}

void str::read1() {
    cout << "Enter the string1: ";
    cin>>name ;
}

void str::read2() {
    cout << "Enter the string2: ";
    cin>>(name1);
}

void str::dis1()
 {
    cout << "String1: " << name << endl;
}

void str::dis2() 
{
    cout << "String2: " << name1 << endl;
}

void str::len1()
 {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
     {
        count++;
    }
    cout << "Length of String1: " << count << endl;
}

void str::len2() 
{
    int count = 0;
    for (int j = 0; name1[j] != '\0'; j++) 
    {
        count++;
    }
    cout << "Length of String2: " << count << endl;
}

void str::fre1() 
{
    int count = 0;
    char a;
    cout << "Enter the character whose frequency needs to be checked in String1: ";
    cin >> a;

    for (int i = 0; name[i] != '\0'; i++) 
    {
        if (name[i] == a) 
        {
            count++;
        }
    }
    cout << "Frequency of '" << a << "' in String1: " << count << endl;
}

void str::fre2() 
{
    int count = 0;
    char b;
    cout << "Enter the character whose frequency needs to be checked in String2: ";
    cin >> b;

    for (int j = 0; name1[j] != '\0'; j++)
     {
        if (name1[j] == b) {
            count++;
        }
    }
    cout << "Frequency of '" << b << "' in String2: " << count << endl;
}

void str::concat()
{
 int i=0;
 int j=0;
 while (name[i]!='\0')
 i++;
 cout<<name;
 for(j=0;name1[j]!='\0';j++)
 {
   name[i]==name1[j];
   name[i]='\0';
 }
 cout<<name1;
 }
/* 
void str::compare()
{
  int i=0;
  int j=0;
  while(name[i]!='\0')
  {
   if(name[i]>name1[j])
   return(1); i++;
        }
   if(name[i]<name1[j])
   return(-1);
  i++;
  }
  return(0);
 }*/

void str::absubs()
{
int r;
int l;
int i=0;
cout<<"Enter the Starting Position : ";
cin>>r;
cout<<"Enter the Length : ";
cin>>l;
for(i=(r-1);i<r-1+l;i++)
{
cout<<name[i];
}
cout<<endl;
}
 
void str::skip()
{
int i=0;
int j=0;
int a;
char n;

cout<<"Enter the String who character needs to be skipped(1 for String1 and 0 for String2) : ";
cin>>a;
 if(a==1)
 {
 cout<<"Enter the character who needs to be skipped : ";
 cin>>n;
 
 while(name[i]!='\0')
 {
   if(name[i]!=n)
   {
     cout<<name[i];
   }
   i++;
 }
}
else if(a==0)
{
cout<<"Enter the character who needs to be skipped :";
cin>>n;
while(name1[j]!='\0')
{
 if(name1[j]!=n)
 {
   cout<<name1[j];
 }
   j++;
    
} } 
else
cout<<"Enter valid Choice ";
cout<<endl;
}
void str::palindrome()
{
int j=0,i=0;
int count=0;
char palindrome[100];
while(name[i]!='\0')
{
 count++;
 i++;
}

for(i=(count-1);i>=0;i--)
{
  palindrome[j]!=name[i];
  j++;
} 
int flag=0;
while(i<count)
{
 if(palindrome[i]!=name[i])
 {
   flag =1; 
  }
  i++;
}
if(flag==1)
{
 cout<<name<<"is not a Palindrome ";
 }
 else
 cout<<name<<"is a Palindrome ";
 cout<<endl;
 }
void str::menu() 
{
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Enter String1" << endl;
        cout << "2. Enter String2" << endl;
        cout << "3. Display String1" << endl;
        cout << "4. Display String2" << endl;
        cout << "5. Length of String1" << endl;
        cout << "6. Length of String2" << endl;
        cout << "7. Frequency of character in String1" << endl;
        cout << "8. Frequency of character in String2" << endl;
        cout << "9. Concatenation"<<endl;
        //cout << "10. Compare"<<endl;
        cout << "10.Skip the letter in String "<<endl;
        cout << "11.Abstract Substring "<<endl;
        cout << "12.Palindrome "<<endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
            case 5:
                len1();
                break;
            case 6:
                len2();
                break;
            case 7:
                fre1();
                break;
            case 8:
                fre2();
                break;
            case 9 : 
                    concat();
                    break;
            //case 10: 
                     //compare();
                    //break;
            case 10  :
                     skip();
                     break;
            case 11 : 
                      absubs();
                      break;   
            case 12: 
                    palindrome();
                    break;      
            case 13:
                cout << "Exiting the menu" << endl;
                break;
            default:
                cout << "Invalid choice!!!" << endl;
                break;
        }
    } while (choice != 13);
}


