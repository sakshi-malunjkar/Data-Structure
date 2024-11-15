#include<iostream>
using namespace std;

class comp
{   
private:
    int A[10], B[10], C[10], D[10];
    int a, b, c, d;
    
public:
    void read();
    void dis();
    void intersection();
    void diff();
    void uni();
    void all_events();
    void menu();
};

int main()
{
    comp obj;
    obj.menu();
    return 0;
}

void comp::read()
{
    cout << "Enter the number of students who participated in Coding contest: ";
    cin >> a;
    cout << "Enter the Roll No. of Coding Contest Students: ";
    for (int i = 0; i < a; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the number of students who participated in Project Competition: ";
    cin >> b;
    cout << "Enter the Roll No. of Project Competition Students: ";
    for (int j = 0; j < b; j++)
    {
        cin >> B[j];
    }

    cout << "Enter the number of students who participated in Paper Presentation: ";
    cin >> c;
    cout << "Enter the Roll No. of Paper Presentation Students: ";
    for (int k = 0; k < c; k++)
    {
        cin >> C[k];
    }

    cout << "Enter the number of students who participated in Mastermind: ";
    cin >> d;
    cout << "Enter the Roll No. of Mastermind Students: ";
    for (int l = 0; l < d; l++)
    {
        cin >> D[l];
    }
}

void comp::dis()
{
    cout << "Students Roll No who Participated in Coding Contest: ";
    for (int i = 0; i < a; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Students Roll No who Participated in Project Competition: ";
    for (int j = 0; j < b; j++)
    {
        cout << B[j] << " ";
    }
    cout << endl;

    cout << "Students Roll No who Participated in Paper Presentation: ";
    for (int k = 0; k < c; k++)
    {
        cout << C[k] << " ";
    }
    cout << endl;

    cout << "Students Roll No who Participated in Mastermind: ";
    for (int l = 0; l < d; l++)
    {
        cout << D[l] << " ";
    }
    cout << endl;
}

void comp::intersection()
{
    cout << "Students who have participated both in coding contest and project competition: ";
    int found = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (A[i] == B[j])
            {
                cout << A[i] << " ";
                found++;
                break; 
            }
        }
    }
    if (found == 0) cout << "None";
    cout << endl;
}

void comp::diff()
{
    cout << "Students who participated in coding but not in mastermind: ";
    int found;
    for (int i = 0; i < a; i++)
    {
        found = 0;
        for (int l = 0; l < d; l++)
        {
            if (A[i] == D[l])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

void comp::uni()
{
    int M[30]; 
    int s = 0;
    
    for (int i = 0; i < a; i++)
    {
        M[s++] = A[i];
    }
    for (int j = 0; j < b; j++)
    {
        bool found = false;
        for (int k = 0; k < s; k++)
        {
            if (B[j] == M[k])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            M[s++] = B[j];
        }
    }
    for (int l = 0; l < d; l++)
    {
        bool found = false;
        for (int k = 0; k < s; k++)
        {
            if (D[l] == M[k])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            M[s++] = D[l];
        }
    }

    cout << "Students who have participated in Coding or Project or both or Mastermind: ";
    for (int i = 0; i < s; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;
}

void comp::all_events()
{
    int all_events[10];
    int s = 0;

    for (int i = 0; i < a; i++)
    {
        bool in_all = true;

        for (int j=0;j<b;j++)
        {
            if (A[i]==B[j])
            {
                for (int k=0;k<c;k++)
                {
                    if (A[i]==C[k])
                    {
                        for (int l=0;l<d;l++)
                        {
                            if (A[i]==D[l])
                            {
                                all_events[s++] = A[i];
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }

    cout << "Students who participated in all events: ";
    for (int i = 0; i < s; i++)
    {
        cout << all_events[i] << " ";
    }
    if (s == 0) cout << "None";
    cout << endl;
}

void comp::menu()
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enter student data\n";
        cout << "2. Display student data\n";
        cout << "3. Find intersection (Coding and Project)\n";
        cout << "4. Find difference (Coding but not Mastermind)\n";
        cout << "5. Find union (Coding, Project, Mastermind)\n";
        cout << "6. Find students in all events\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                read();
                break;
            case 2:
                dis();
                break;
            case 3:
                intersection();
                break;
            case 4:
                diff();
                break;
            case 5:
                uni();
                break;
            case 6:
                all_events();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
        }
    } while (choice != 7);
}

/*1. Enter student data
2. Display student data
3. Find intersection (Coding and Project)
4. Find difference (Coding but not Mastermind)
5. Find union (Coding, Project, Mastermind)
6. Find students in all events
7. Exit
Enter your choice: 4
Students who participated in coding but not in mastermind: 41 62 

Menu:
1. Enter student data
2. Display student data
3. Find intersection (Coding and Project)
4. Find difference (Coding but not Mastermind)
5. Find union (Coding, Project, Mastermind)
6. Find students in all events
7. Exit
Enter your choice: 5
Students who have participated in Coding or Project or both or Mastermind: 31 41 62 85 59 69 

Menu:
1. Enter student data
2. Display student data
3. Find intersection (Coding and Project)
4. Find difference (Coding but not Mastermind)
5. Find union (Coding, Project, Mastermind)
6. Find students in all events
7. Exit
Enter your choice: 6
Students who participated in all events: None

Menu:
1. Enter student data
2. Display student data
3. Find intersection (Coding and Project)
4. Find difference (Coding but not Mastermind)
5. Find union (Coding, Project, Mastermind)
6. Find students in all events
7. Exit
*/


