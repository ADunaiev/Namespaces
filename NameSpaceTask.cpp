#include <iostream>
#include <conio.h>
using namespace std;

namespace fraction {
    class Fraction
    {
    private:
        int numerator;
        int denominator;

    public:
        const int* getNumerator()
        {
            return &numerator;
        }
        void setNumerator(int frac_numenator)
        {
            numerator = frac_numenator;
        }
        const int* getDenominator()
        {
            return &denominator;
        }
        void setDenominator(int frac_denominator)
        {
            denominator = frac_denominator;
        }
        Fraction Sum(Fraction a, Fraction b);
        Fraction Subtraction(Fraction a, Fraction b);
        Fraction Multiplication(Fraction a, Fraction b);
        Fraction Division(Fraction a, Fraction b);
        void print();
        void FracOperationPrint(Fraction a, char oper, Fraction b);
        Fraction& operator++();
        Fraction& operator--();
        Fraction& operator++(int);
        Fraction& operator--(int);
    };

    void Fraction::print()
    {
        cout << numerator << "/" << denominator << endl;
    }
    void Fraction::FracOperationPrint(Fraction a, char oper, Fraction b)
    {
        Fraction c;
        a.print();
        cout << " " << oper << " ";
        b.print();
        cout << " equal ";

        switch (oper) {
        case '+':
            c = c.Sum(a, b);
            c.print();
            break;

        case '-':
            c = c.Subtraction(a, b);
            c.print();
            break;

        case '*':
            c = c.Multiplication(a, b);
            c.print();
            break;

        case '/':
            c = c.Division(a, b);
            c.print();
            break;

        default:
            cout << "Absent operation!" << endl;


        }

        cout << endl;
    }
    Fraction Fraction::Sum(Fraction a, Fraction b)
    {
        Fraction c;
        c.denominator = a.denominator * b.denominator;
        c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;

        return c;
    }
    Fraction Fraction::Subtraction(Fraction a, Fraction b)
    {
        Fraction c;
        c.denominator = a.denominator * b.denominator;
        c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;

        return c;
    }
    Fraction Fraction::Multiplication(Fraction a, Fraction b)
    {
        Fraction c;
        c.denominator = a.denominator * b.denominator;
        c.numerator = a.numerator * b.numerator;

        return c;
    }
    Fraction Fraction::Division(Fraction a, Fraction b)
    {
        Fraction c;
        c.denominator = a.denominator * b.numerator;
        c.numerator = a.numerator * b.denominator;

        return c;
    }
    Fraction& Fraction::operator++()
    {
        ++numerator;
        ++denominator;
        return *this;
    }
    Fraction& Fraction::operator--()
    {
        --numerator;
        --denominator;
        return *this;
    }
    Fraction& Fraction::operator++(int)
    {
        Fraction temp;
        temp.setNumerator(numerator);
        temp.setDenominator(denominator);

        ++(*this);
        return temp;
    }
    Fraction& Fraction::operator--(int)
    {
        Fraction temp;
        temp.setNumerator(numerator);
        temp.setDenominator(denominator);

        --(*this);
        return temp;
    }
}

int main()
{
    fraction::Fraction Frac1;
    Frac1.setNumerator(2);
    Frac1.setDenominator(3);
    cout << "Frac1 = ";
    Frac1.print();

    fraction::Fraction Frac2;
    Frac2.setNumerator(3);
    Frac2.setDenominator(4);
    cout << "Frac2 = ";
    Frac2.print();

    ++Frac1;
    cout << "Frac1 = ";
    Frac1.print();

    --Frac1;
    cout << "Frac1 = ";
    Frac1.print();

    Frac1++;
    cout << "Frac1 = ";
    Frac1.print();

    Frac1--;
    cout << "Frac1 = ";
    Frac1.print();

    return 0;
}
