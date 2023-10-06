#include<iostream>
#include<string.h>
using namespace std;


struct iFly {
    virtual void Fly() = 0;
};

class Animal  // абстрактный класс !!
{
protected:
    char* name;
    int kg;
public:
    Animal() = default;
    Animal(const char* n, int k)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        kg = k;
    }
    void Print()
    {
        cout << "Name: " << name << "Kg: " << kg << endl;
    }
    virtual void Continent() = 0;
    virtual void Eat() = 0;
    virtual void Sound() = 0;

    ~Animal()
    {
        delete[] name;
    }
};

class Parrot : public Animal, public iFly {
    char* continent;

public:
    Parrot() = default;
    Parrot(const char* n, int kg, const char* cont) : Animal(n, kg)
    {
        continent = new char[strlen(cont) + 1];
        strcpy_s(continent, strlen(cont) + 1, cont);
    }

    virtual void Eat()
    {
        cout << "Попугаи едят семена\n";
    }
    virtual void Sound()
    {
        cout << "Попугаи издают какие то звуки\n";
    }
    virtual void Continent()
    {
        cout << "Попугаи живут везде. Даже в твоем доме)\n";
    }
    virtual void Fly() { cout << "Попугаи летают с помощью крыльев.\n"; };
    ~Parrot()
    {
        delete[] continent;
    }
};
class Plane : public iFly {
    string name;
public:
    Plane() = default;
    Plane(string n) { name = n; }

    virtual void Fly() {
        cout << "Самолет - воздушный транспорт\n";
    }
};
void main() {
    Parrot p("parrot1", 2, "America");
    p.Fly();
    Plane pl("Plane1");
    pl.Fly();
}