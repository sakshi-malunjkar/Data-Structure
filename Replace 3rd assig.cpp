#include <iostream>
using namespace std;

class str {
private:
    char str1[100]; // Increased size for longer strings

public:
    void read();
    void dis();
    void ch();
    void replace();
};

void str::read() {
    cout << "Enter the String: ";
    cin >> str1; // This will read a single word (no spaces)
    cout << endl;
}

void str::dis() {
    cout << "String is: " << str1 << endl;
}

void str::ch() {
    char a;
    cout << "Enter the letter which needs to be skipped: ";
    cin >> a;
    int i = 0;
    cout << "String after removing '" << a << "': ";
    while (str1[i] != '\0') {
        if (str1[i] != a) {
            cout << str1[i];
        }
        i++;
    }
    cout << endl;
}

void str::replace() 
{
    char word[100]; // Original string
    char str2[50]; // Substring to find
    char str3[50];  // New substring
    cout << "Enter the original string: ";
    cin >> word; // This will read a single word (no spaces)
    cout << "Enter substring to replace: ";
    cin >> str2; // This will read a single word (no spaces)
    cout << "Enter new substring: ";
    cin >> str3; // This will read a single word (no spaces)

    int lenWord = 0, lenFind = 0, lenReplace = 0;

    // Calculate the length of word
    while (word[lenWord] != '\0') 
    {
        lenWord++;
    }

    // Calculate the length of str11
    while (str2[lenFind] != '\0') 
    {
        lenFind++;
    }

    // Calculate the length of str2
    while (str3[lenReplace] != '\0')
    {
        lenReplace++;
    }

    bool found = false;

    // Search for the substring str11 in word
    for (int i = 0; i <= lenWord - lenFind; i++)
    {
        int j;
        for (j = 0; j < lenFind; j++) 
        {
            if (word[i + j] != str2[j]) 
            {
                break;
            }
        }

        if (j == lenFind) 
        {
            found = true;
            // Output the part of the original string before the substring
            for (int k = 0; k < i; k++)
            {
                cout << word[k];
            }
            // Output the new substring
            cout << str3;
            // Output the part of the original string after the substring
            for (int k = i + lenFind; k < lenWord; k++) 
            {
                cout << word[k];
            }
            cout << endl;
            break; // Exit after replacing first occurrence
        }
    }

    if (!found) 
    {
        cout << "Substring not found." << endl;
    }
}

int main() {
    str obj;
    obj.read();
    obj.dis();
    obj.ch();
    obj.replace();
    return 0;
}
