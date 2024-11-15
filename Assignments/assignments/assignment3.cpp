/*
Name : Prachi Mehetre
Class : SE B2
Roll no.: 47
PROBLEM STATEMENT :
String Operations: Write a menu driven C++ program with a class for 
String. Write functions 
1. To determine the frequency of occurrence of a particular character 
in the string.
2. Extract a new string from original string by accepting starting
position and length 
3. To accept any character and return the string with by removing all 
occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the 
string x. Note that w may not be of same size that of x
5. To check whether given string is palindrome or not */

#include<iostream>
#include<string.h>
using namespace std;

class function {
public:
    string word, r, n;
    char character, remove;
    int count = 0, i = 0, pos = 0, len = 0, flag = 0, length = 0, l;

public:
    void frequency() {
        character=0;
        cout << "Enter the string" << endl;
        cin >> word;
        cout << "Enter the character of which you have to determine the frequency in the string :";
        cin >> character;
        for (i = 0; i < word.length(); i++) {
            if (word[i] == character) {
                count++;
            }
        }
        cout << "Number of character " << character << " = " << count << endl;
    }

    void newstring() {
        cout << "Enter the string" << endl;
        cin >> word;
        cout << "Enter the starting position of the string" << endl;
        cin >> pos;
        cout << "Enter the length of the new string" << endl;
        cin >> len;

        for (i = pos /*- 1*/; i < len + pos /*- 1*/; i++) {
            cout << word[i];
        }
    }

    void replace() {
        int position;
        char str1[200], str2[200];
        int length = 0;
        int m = 0;
        cout << "Enter the string" << endl;
        cin >> word;
        cout << "Enter substring to replace: " << endl;
        cin >> str1;
        cout << "Enter new substring: " << endl;
        cin >> str2;

        while (str1[length] != '\0') {
            length++;
        }
        i = 0;
        int j = 0;
        int k = 0;
        m = 0; // Initialize m to 0
        while (word[i] != '\0') {
            if (word[i] == str1[j]) {
                position = i;
                while (str1[j] != '\0') {
                    if (str1[j] != word[position + k]) {
                        m = 1;
                    }
                    k++;
                    j++;
                }
                if (m == 0) {
                    int end_pos = position + length;
                    i = 0;
                    while (i < position) {
                        cout << word[i];
                        i++;
                    }
                    cout << str2;
                    while (word[end_pos] != '\0') {
                        cout << word[end_pos];
                        end_pos++;
                    }
                    break;
                }
            }
            i++;
        }
        if (m == 1) {
            cout << "String not found.";
        }
    }

    void removes() {
        cout << "Enter the string" << endl;
        cin >> word;
        cout << "Enter the character which you want to remove from the entered string :";
        cin >> remove;
        for (i = 0; i < word.length(); i++) {
            if (word[i] != remove) {
                cout << word[i];
            }
        }
        cout << endl;
    }

    void palindrome() {
        cout << "Enter the string :" << endl;
        cin >> word;
        flag=0;
        for (i = 0; i < word.length(); i++) 
		{
            if (word[i] != word[length - i - 1]) 
			{
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << word << " is a palindrome" << endl;
        } else {
            cout << word << " is not a palindrome" << endl;
        }
    }
};

int main() {
    int op, ch;
    function obj;

    do {
        cout << "1. To determine the  of occurrence of a particular character in the string." << endl
             << "2. Extract a new string from the original string by accepting starting position and length" << endl
             << "3. To accept any character and return the string with by removing all occurrences of a character accepted" << endl
             << "4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x" << endl
             << "5. To check whether the given string is palindrome or not" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                obj.frequency();
                break;

            case 2:
                obj.newstring();
                break;

            case 3:
                obj.removes();
                break;

            case 4:
                obj.replace();
                break;

            case 5:
                obj.palindrome();
                break;

            default:
                cout << "Entered the wrong choice";
                break;
        }
        cout << endl << "Do you want to continue? (if YES press 1)" << endl;
        cin >> op;
    } while (op == 1);
    return 0;
}
/*OUTPUT
1. To determine the  of occurrence of a particular character in the string.
2. Extract a new string from the original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x
5. To check whether the given string is palindrome or not
Enter your choice
1
Enter the string
sharda
Enter the character of which you have to determine the frequency in the string :a
Number of character a = 2

Do you want to continue? (if YES press 1)
1
1. To determine the  of occurrence of a particular character in the string.
2. Extract a new string from the original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x
5. To check whether the given string is palindrome or not
Enter your choice
2
Enter the string
rajlakshmi
Enter the starting position of the string
4
Enter the length of the string
7
lakshmi
Do you want to continue? (if YES press 1)
1
1. To determine the  of occurrence of a particular character in the string.
2. Extract a new string from the original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x
5. To check whether the given string is palindrome or not
Enter your choice
3
Enter the string
madam
Enter the character which you want to remove from the entered string :m
ada

Do you want to continue? (if YES press 1)
1
1. To determine the  of occurrence of a particular character in the string.
2. Extract a new string from the original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x
5. To check whether the given string is palindrome or not
Enter your choice
4
Enter the string
rajkanya
Enter substring to replace:
kanya
Enter new substring:
lakshmi
rajlakshmi
Do you want to continue? (if YES press 1)
1
1. To determine the  of occurrence of a particular character in the string.
2. Extract a new string from the original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x
5. To check whether the given string is palindrome or not
Enter your choice
5
Enter the string :
madam
madam is a palindrome

Do you want to continue? (if YES press 1)
1
1. To determine the  of occurrence of a particular character in the string.
2. Extract a new string from the original string by accepting starting position and length
3. To accept any character and return the string with by removing all occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of the same size as x
5. To check whether the given string is palindrome or not
Enter your choice
5
Enter the string :
panchi
panchi is not a palindrome

Do you want to continue? (if YES press 1)
2

--------------------------------
Process exited after 167.3 seconds with return value 0
Press any key to continue . . .*/
