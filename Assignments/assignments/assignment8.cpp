#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool isOperand(char ch) {
    return (isalpha(ch) || isdigit(ch));
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isOperand(ch))
            postfix += ch;
        else if (ch == '(')
            s.push(ch);
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        } else if (isOperator(ch)) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char &ch : infix) {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

string prefixToInfix(string prefix) {
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            string operand(1, prefix[i]);
            s.push(operand);
        } else if (isOperator(prefix[i])) {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            string result = "(" + operand1 + prefix[i] + operand2 + ")";
            s.push(result);
        }
    }

    return s.top();
}

string postfixToInfix(string postfix) {
    stack<string> s;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            string operand(1, ch);
            s.push(operand);
        } else if (isOperator(ch)) {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string result = "(" + operand1 + ch + operand2 + ")";
            s.push(result);
        }
    }

    return s.top();
}

string postfixToPrefix(string postfix) {
    stack<string> s;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            string operand(1, ch);
            s.push(operand);
        } else if (isOperator(ch)) {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string result = ch + operand1 + operand2;
            s.push(result);
        }
    }

    return s.top();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "Expression Conversion and Evaluation Menu:" << endl;
        cout << "1. Infix to Postfix" << endl;
        cout << "2. Infix to Prefix" << endl;
        cout << "3. Prefix to Infix" << endl;
        cout << "4. Postfix to Infix" << endl;
        cout << "5. Postfix to Prefix" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Infix Expression: ";
                cin >> expression;
                cout << "Postfix Expression: " << infixToPostfix(expression) << endl;
                break;

            case 2:
                cout << "Enter Infix Expression: ";
                cin >> expression;
                cout << "Prefix Expression: " << infixToPrefix(expression) << endl;
                break;

            case 3:
                cout << "Enter Prefix Expression: ";
                cin >> expression;
                cout << "Infix Expression: " << prefixToInfix(expression) << endl;
                break;

            case 4:
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                cout << "Infix Expression: " << postfixToInfix(expression) << endl;
                break;

            case 5:
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                cout << "Prefix Expression: " << postfixToPrefix(expression) << endl;
                break;

            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 6);

    return 0;
}

