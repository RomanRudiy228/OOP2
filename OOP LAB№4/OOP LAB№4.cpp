#include <iostream>
#include <vector>
using namespace std;

class TObject 
{
public:
    virtual void printInfo() = 0; // Чисто віртуальна функція
};

class Subdivision : public TObject 
{
protected:
    string name;

public:
    Subdivision(const string& name) : name(name) {}

    void printInfo() override 
    {
        cout << "Subdivision: " << name << endl;
    }
};

class Ship : public TObject 
{
protected:
    static int counter; // Статичне поле - лічильник об'єктів
    int waterDisplacement; // Водотоннажність

public:
    Ship(int waterDisplacement) : waterDisplacement(waterDisplacement) 
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

    void printInfo() override 
    {
        cout << "Water displacement: " << waterDisplacement << endl;
    }
};

int Ship::counter = 0; // Ініціалізуємо статичне поле

class Steamship : public Ship 
{
public:
    Steamship(int waterDisplacement) : Ship(waterDisplacement)
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
    Sailboat(int waterDisplacement) : Ship(waterDisplacement) 
    {
        cout << "Create sailboat" << endl;
    }

    ~Sailboat() {
        cout << "Deleted sailboat" << endl;
    }

    int getWaterDisplacement() const 
    {
        return waterDisplacement;
    }
};

class Corvette : public Ship 
{
public:
    Corvette(int waterDisplacement) : Ship(waterDisplacement) 
    {
        cout << "Create corvette" << endl;
    }

    ~Corvette() 
    {
        cout << "Deleted corvette" << endl;
    }
};

int calculateAverageWaterDisplacement(vector<Ship*>& ships) 
{
    int totalWaterDisplacement = 0;
    int sailboatCount = 0;

    for (auto ship : ships) 
    {
        Sailboat* sailboat = dynamic_cast<Sailboat*>(ship);
        if (sailboat) 
        {
            totalWaterDisplacement += sailboat->getWaterDisplacement();
            sailboatCount++;
        }
    }

    if (sailboatCount > 0) 
    {
        return totalWaterDisplacement / sailboatCount;
    }
    class Sailboat : public Ship 
    {
public:
    Sailboat(int waterDisplacement) : Ship(waterDisplacement) 
    {
        cout << "Create sailboat" << endl;
    }

    ~Sailboat() 
    {
        cout << "Deleted sailboat" << endl;
    }

    int getWaterDisplacement() const 
    {
        return waterDisplacement;
    }
};

    if (sailboatCount > 0) 
    {
        return totalWaterDisplacement / sailboatCount;
    }

    return 0;
}

int main() 
{
    vector<Ship*> collection; // Колекція об'єктів
    collection.push_back(new Steamship(1000)); // Додаємо пароплав в колекцію
    collection.push_back(new Sailboat(500)); // Додаємо вітрильник в колекцію
    collection.push_back(new Corvette(1500)); // Додаємо корвет в колекцію

    Ship::viewCollection(); // Викликаємо статичний метод для перегляду колекції

    int averageWaterDisplacement = calculateAverageWaterDisplacement(collection);
    cout << "Average water displacement of sailboats: " << averageWaterDisplacement << endl;

    // Знищуємо об'єкти
    for (auto ship : collection) 
    {
        delete ship;
    }

    Ship::viewCollection(); // Викликаємо статичний метод для перегляду колекції

    return 0;
}