#include <iostream>
#include <list>

using namespace std;

/*
Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram
(параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle
(прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы. Для 
класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных
*/

class Figure
{
public:
    virtual void area() = 0;
};

class Parallelogram : public Figure
{
protected:
    int base;       //основание
    int height;     //высота
public:

    Parallelogram(int value_base, int value_height) :base(value_base), height(value_height) {}
    void area() override
    {
        cout << "The parallelogram area is " << base * height << endl;
    }
};

class Circle : public Figure
{
private:
    double radius;
    double P;
public:
    Circle(double value_radius) : radius(value_radius) {}
    void area() override
    {
        cout << "The area of the circle is " << 3.1415 * (radius * radius) << endl;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int value_base, int value_height) : Parallelogram(value_base, value_height) {}
    void area() override
    {
        cout << "The area of the triangle is " << base * height << endl;
    }
};

class Square : public Parallelogram
{
public:

    Square(int value_base, int value_height) : Parallelogram(value_base, value_height) {}

    void area() override
    {
        cout << "The square area is " << base * height << endl;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int value_base, int value_height) : Parallelogram(value_base, value_height) {}
    void area() override
    {
        cout << "The area of the rhombus is " << base * height << endl;
    }
};

/*Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
Обратить внимание на проблему «алмаз смерти». */

class Car
{
protected:
    string company, model; //поля для класса. стринг дает возможность писать большим колл-вом строк, а не с 1 символом.
public:
    Car()
    {
        company = "Doodge";
        model = "Demon";
    }
    Car(string xCompany, string vModel) : company(xCompany), model(vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    virtual ~Car() //virtual преопределить в любом наследнике.
    {
        cout << "\nДеструктор базового класса Car сработал!";  //деструктор базового класса.
    }
};

class PassengerCar : virtual public Car
{
public:

    PassengerCar()
    {
        company = "laFerrari";
        model = "Pick";
    }
    PassengerCar(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~PassengerCar()
    {
        cout << "\nДеструктор наследника PassengerCar сработал!"; //деструктор наследника.
    }
};

class Bus : virtual public Car
{
public:

    Bus()
    {
        company = "Renault";
        model = "Bus";
    }
    Bus(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~Bus()
    {
        cout << "\nДеструктор наследника Bus сработал!"; //деструктор наследника.
    }
};

class Minivan : public PassengerCar, public Bus //делаем сразу двойное присвоение.
{
public:
    Minivan()
    {
        company = "Audi";
        model = "eTron";
    }
    Minivan(string xCompany, string vModel) : Car(xCompany, vModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }

    ~Minivan()
    {
        cout << "\nДеструктор множественного наследника Minivan сработал!"; //деструктор множественного наследования.
    }
};


/*Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
*/
class Fraction 
{
protected:
    double numerator, denominator; 
public:
    Fraction() {}
    Fraction(double iNumerator, double iDenominator) : numerator(iNumerator), denominator(iDenominator)
    {
        if (denominator == 0) denominator = 0.00000001; 
    }
    friend Fraction operator+(const Fraction& d1, const Fraction& d2); 
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1); 

    double getNumerator() 
    {
        return numerator;
    }

    double getDenominator()
    {
        return denominator;
    }

    void Print()
    {
        cout << "Numerator:" << numerator << " denominator:" << denominator << endl;
    }

};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.numerator, d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2) 
{
    if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2) 
{
    if (d1 == d2) return false;
    else return true;
}

bool operator<(Fraction& d1, Fraction& d2) 
{
    if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator>(Fraction& d1, Fraction& d2) 
{
    if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2) 
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
    if (!(d1 < d2)) return true;
    else return false;
}

int main()
{
    setlocale(LC_ALL, "rus");
    //dz1


    //dz2
    {
        Car car;
        car.~Car();
        PassengerCar passengercar;
        passengercar.~PassengerCar();
        Bus bus;
        bus.~Bus();
        Minivan minivan;
        minivan.~Minivan();

    }

    {
        Fraction d1(6, 7);
        Fraction d2(3, 6);
        (d1 + d2).Print();
        (d1 - d2).Print();
        (d1 * d2).Print();
        (d1 / d2).Print();
        (-d1).Print();
        if (d1 == d2) cout << "\nFraction 1 == Fraction 2";
        if (d1 != d2) cout << "\nFraction 1 != Fraction 2";
        if (d1 > d2) cout << "\nFraction 1 > Fraction 2";
        if (d1 <= d2) cout << "\nFraction 1 <= Fraction 2";
        if (d1 < d2) cout << "\nFraction 1 < Fraction 2";
        if (d1 >= d2) cout << "\nFraction 1 >= Fraction 2";
    }
    return 0;
}