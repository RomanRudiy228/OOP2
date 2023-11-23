#include <iostream>
#include <string>
using namespace std;


class SHIP
{
    string name;   //назва
    int tonnage;   //тонажність
    string type;   //тип

public:
    SHIP() {} //Конструктор без параметрвів
    SHIP(string valueN, int valueA, string valueW) //Конструктор з параметрами
    {
        name = valueN;
        tonnage = valueA;
        type = valueW;
    }
    ~SHIP() {
        cout << "Desructor is called " << name << endl;
    } //Деструктор
    SHIP(const  SHIP&); // конструктор копіювання

    string GetName() const; // селектори
    int GetTonnage() const;
    string GetType() const;

    void SetName(string); // модифікатори
    void SetTonnage(int);
    void SetType(string);
    void Set(string, int, string);

    //Метод toString() для одержання строкового представлення стану об’єктів.
    string toString() const {
        return name + to_string(tonnage) + "t" +  type ;
    }

    //Оголошуємо вказівник на метод класу SHIP
    static void (SHIP::* printName)() const;

    void Print()
    {
        cout << "Name  = " << name << "\nTonnage = " << tonnage << "\nType = " << type << "\n-----------------" << endl;
    }
};

int main()
{
    SHIP a("Aurora", 100000, "Kargo");
    a.Print();

    SHIP b("Titanik", 15, "Passenger's");
    b.Print();

    SHIP c("Victoria", 140000, "Special");
    c.Print();

    // Визначенння вхідного об'єкту 
    SHIP ship("Aurora", 100000, "Kargo");
    cout << ship.toString() << endl;

    // Визначення вхідного вказівника на об'єкт 
    SHIP* shipPtr = &ship;

    return 0;
}