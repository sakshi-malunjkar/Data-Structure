#include <iostream>
using namespace std;

class Set {
private:
    int a[100];
    int b[100];
    int c[200]; 
    int i, j, k;
    int m, n; 
    
public:
    void read();
    void dis(); 
    void intersection();
    void uni();
    void diff();
};

void Set::read() {
    cout << "Enter the number of elements in Array1 : ";
    cin >> m;
    if (m > 100) 
    {
        cout << "Error: Number of elements exceeds array size." << endl;
        return;
    }

    cout << "Enter Array1 elements: ";
    for (i = 0; i < m; i++) {
        cin >> a[i];
    }

    cout << "Enter the number of elements in Array2: ";
    cin >> n;
    if (n > 100)
     {
        cout << "Error: Number of elements exceeds array size." << endl;
        return;
     }

    cout << "Enter Array2 elements: ";
    for (j = 0; j < n; j++) 
    {
        cin >> b[j];
    }
}

void Set::intersection() 
{
    int count = 0;
    cout << "Intersection: ";
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (a[i] == b[j]) 
            {
                cout << a[i] << " ";
                count++;
            }
        }
    }
    if (count == 0)
     {
        cout << "No common elements";
    }
    cout << endl;
}

void Set::uni()
 {
    cout << "Union: ";
    k = 0; 
    for (i=0;i<m;i++)
    {
        c[k++] = a[i];
    }
    
  
    for (j=0; j<n;j++)
     {
        bool found = false;
        for (i=0;i<k;i++)
         {
            if (b[j] == c[i])
             {
                found = true;
                break;
             }
        }
        if (!found) 
        {
            c[k++] = b[j];
        }
    }
    
    
    for (i=0;i<k;i++) 
    {
        cout << c[i] << " ";
    }
    cout << endl;
}



  
    

    

int main() {
    Set obj1;
    
    obj1.read();
    obj1.intersection();
    obj1.uni();
    
    
    return 0;
}


/*
Enter the number of elements in Array1 (up to 10): 5
Enter Array1 elements: 1
2
3
4
5
Enter the number of elements in Array2 (up to 10): 5
Enter Array2 elements: 6
7
8
2
1
Intersection: 1 2 
Union: 1 2 3 4 5 6 7 8 
*/
