#include <iostream>
using namespace std;

class set {
private:
    int a[10];
    int b[10];
    int c[20];
    int i, j;
    int m, n;
    int k = 0;

public:
    void read();
    void dis();
    void diff();
    void dis1();
};

int main() {
    set obj1;

    obj1.read();
    obj1.dis();
    obj1.diff();
    obj1.dis1();

    return 0;
}

void set::read() {
    cout << "Enter the number of elements for Array1: ";
    cin >> m;

    cout << "Enter Array1 elements: ";
    for (i = 0; i < m; i++) {
        cin >> a[i];
    }

    cout << "Enter the number of elements for Array2: ";
    cin >> n;

    cout << "Enter Array2 elements: ";
    for (j = 0; j < n; j++) {
        cin >> b[j];
    }
}

void set::dis() {
    cout << "Array1 Elements are : ";
    for (i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Array2 Elements are : ";
    for (j = 0; j < n; j++) {
        cout << b[j] << " ";
    }
    cout << endl;
}

void set::diff() {
    for (i = 0; i < m; i++) {
        bool found = false;

        for (j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            c[k] = a[i];
            k++;
        }
    }
}

void set::dis1() {
    cout << "Difference elements : ";
    for (i = 0; i < k; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
}
/*
Enter the number of elements for Array1: 5
Enter Array1 elements: 1
2
3
4
5
Enter the number of elements for Array2: 5
Enter Array2 elements: 6
7
8
1
2
Array1 Elements are : 1 2 3 4 5 
Array2 Elements are : 6 7 8 1 2 
Difference elements : 3 4 5 
*/
        
