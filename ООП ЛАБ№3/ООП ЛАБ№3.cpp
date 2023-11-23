#include <iostream>
#include <vector>
using namespace std;

class Ship 
{
protected:
    static int counter; // Статичне поле - лічильник об'єктів
public:
    Ship() 
    {
        counter++; // Збільшуємо лічильник при створенні об'єкту
    }
    virtual ~Ship() 
    {
        counter--; // Зменшуємо лічильник при знищенні об'єкту
    }
    static void viewCollection() 
    { 
       // Статичний метод для перегляду колекції
       cout << "Number of objects in collection: " << counter << endl;
    }
};

int Ship::counter = 0; // Ініціалізуємо статичне поле

class Steamship : public Ship 
{
public:
    Steamship() 
    {
       cout << "Create steamship" << endl;
    }
    ~Steamship() 
    {
       cout << "Deleted steamship" << endl;
    }
};

class Sailboat : public Ship 
{
public:
    Sailboat() 
    {
       cout << "Create sailboat" << endl;
    }
    ~Sailboat() 
    {
       cout << "Deleted sailboat" << endl;
    }
};

class Corvette : public Ship 
{
public:
    Corvette() 
    {
       cout << "Create corvette" << endl;
    }
    ~Corvette() 
    {
       cout << "Deleted corvette" << endl;
    }
};

int main() 
{
    vector<Ship*> collection; // Колекція об'єктів
    collection.push_back(new Steamship()); // Додаємо пароплав в колекцію
    collection.push_back(new Sailboat()); // Додаємо вітрильник в колекцію
    collection.push_back(new Corvette()); // Додаємо корвет в колекцію

    Ship::viewCollection(); // Викликаємо статичний метод для перегляду колекції

    // Знищуємо об'єкти
    for (auto ship : collection) 
    {
        delete ship;
    }

    Ship::viewCollection(); // Викликаємо статичний метод для перегляду колекції

    return 0;
}