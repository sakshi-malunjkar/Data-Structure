#include <iostream>
#include <cmath>
using namespace std;

struct PolynomialTerm
 {
    int exp;
    float coef;
};

class Polynomial
{
private:
    PolynomialTerm poly[30];
    int total_terms;

public:

    void readPoly();
    void disPoly();
    double evaluatePoly(double value);
    Polynomial add_poly(const Polynomial& b) const;
};

void Polynomial::readPoly() 
{
    cout << "Read the polynomial\n";
    cout << "Enter total number of terms: ";
    cin >> total_terms;
    for (int i = 0; i < total_terms; i++) 
    {
        cout << "Enter exponent of term " << i + 1 << ": ";
        cin >> poly[i].exp;

        cout << "Enter coefficient of term " << i + 1 << ": ";
        cin >> poly[i].coef;
    }
}

void Polynomial::disPoly()
 {
    cout << "Polynomial is: ";
    for (int i = 0; i < total_terms; i++) 
    {
        cout << poly[i].coef << "x^" << poly[i].exp;
        if (i < total_terms - 1) 
        {
            cout << " + ";
        }
    }
    cout << endl;
}

double Polynomial::evaluatePoly(double value)
 {
    double result = 0;
    for (int i = 0; i < total_terms; i++) 
    {
        result += poly[i].coef * pow(value, poly[i].exp);
    }
    return result;
}

Polynomial Polynomial::add_poly(const Polynomial& b) const 
{
    int i = 0, j = 0, k = 0;
    Polynomial c;

    while (i < total_terms && j < b.total_terms) 
    {
        if (poly[i].exp == b.poly[j].exp) 
        {
            c.poly[k].coef = poly[i].coef + b.poly[j].coef;
            c.poly[k].exp = poly[i].exp;
            i++;
            j++;
        } else if (poly[i].exp > b.poly[j].exp)
         {
            c.poly[k].coef = poly[i].coef;
            c.poly[k].exp = poly[i].exp;
            i++;
        } else
         {
            c.poly[k].coef = b.poly[j].coef;
            c.poly[k].exp = b.poly[j].exp;
            j++;
        }
        k++;
    }

    while (i < total_terms)
     {
        c.poly[k].coef = poly[i].coef;
        c.poly[k].exp = poly[i].exp;
        i++;
        k++;
    }

    while (j < b.total_terms)
     {
        c.poly[k].coef = b.poly[j].coef;
        c.poly[k].exp = b.poly[j].exp;
        j++;
        k++;
    }

    c.total_terms = k;
    return c;
}

int main() 
{
    Polynomial a, b;

    a.readPoly();
    a.disPoly();
    b.readPoly();
    b.disPoly();

    Polynomial c = a.add_poly(b); 
    cout << "The result of adding the polynomials: ";
    c.disPoly(); 

    double value;
    cout << "Enter the value of X to evaluate polynomial1: ";
    cin >> value;

    double result = a.evaluatePoly(value);
    cout << "The result of the polynomial evaluation is: " << result << endl;

    return 0;
}