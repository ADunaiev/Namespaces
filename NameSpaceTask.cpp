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

namespace home_animals
{
    class Home_Animal
    {
    protected:
        std::string name;
        std::string Class;
        int legs;
        bool wings;
        int weight;
    public:
        Home_Animal();
        Home_Animal(std::string nameP, std::string ClassP, int legsP, bool wingsP, int weightP);
        std::string& get_name();
        std::string& get_class();
        int& get_legs();
        bool& get_wings();
        int& get_weight();
        void show() const;
    };

    Home_Animal::Home_Animal() : name{ "animal" }, legs{ 4 }, wings{ 0 }, weight{ 10 }{}
    Home_Animal::Home_Animal(std::string nameP, std::string ClassP, int legsP, bool wingsP, int weightP) :
        name{ nameP }, Class{ ClassP }, legs{ legsP }, wings{ wingsP }, weight{ weightP }{}

    std::string& Home_Animal::get_name()
    {
        return name;
    }
    std::string& Home_Animal::get_class()
    {
        return Class;
    }
    int& Home_Animal::get_legs()
    {
        return legs;
    }
    bool& Home_Animal::get_wings()
    {
        return wings;
    }
    int& Home_Animal::get_weight()
    {
        return weight;
    }
    void Home_Animal::show() const
    {
        std::cout << "Animal info" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Class: " << Class << std::endl;
        std::cout << "Legs: " << legs << std::endl;
        std::cout << "Wings: " << wings << std::endl;
        std::cout << "Weight: " << weight << std::endl;
        std::cout << std::endl;
    }

    class Dog : public Home_Animal
    {
    public:

        Dog(std::string c);
    };

    Dog::Dog(std::string c) { name = c; Class = "dog"; }

    class Cat : public Home_Animal
    {
    public:

        Cat(std::string c);
    };

    Cat::Cat(std::string c) { name = c; Class = "cat"; weight = 5; }

    class Parrot : public Home_Animal
    {
    public:

        Parrot(std::string c);
    };

    Parrot::Parrot(std::string c)
    {
        name = c; Class = "parrot"; weight = 1; wings = 1; legs = 2;
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

    cout << endl;

    home_animals::Dog Angel("Angel");
    Angel.show();

    home_animals::Cat Bazilio("Bazilio");
    Bazilio.show();

    home_animals::Parrot Govorun("Govorun");
    Govorun.show();

    return 0;
}
