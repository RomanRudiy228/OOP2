#include <iostream>
#include <stdexcept>

// Власний виняток для шаблону
class TemplateException : public std::exception 
{
public:
    const char* what() const noexcept override 
    {
        return "TemplateException: Custom exception for the template class.";
    }
};

// Клас, який буде використовуватися як параметр шаблону
class MyClass 
{
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // Перевантажена операція віднімання
    MyClass operator-(const MyClass& other) 
    {
        return MyClass(value - other.value);
    }

    // Перевантажена операція індексування
    int operator[](int index) 
    {
        if (index == 0)
            return value;
        else
            throw TemplateException();
    }

    // Перевантажена операція int()
    operator int() const 
    {
        return value;
    }
};

// Шаблон класу
template <typename T>
class MyTemplate 
{
private:
    T* data;

public:
    MyTemplate() : data(nullptr) {}

    MyTemplate(const T& value) 
    {
        data = new T(value);
    }

    // Конструктор копіювання
    MyTemplate(const MyTemplate& other) 
    {
        if (other.data != nullptr)
            data = new T(*other.data);
        else
            data = nullptr;
    }

    // Деструктор
    ~MyTemplate() 
    {
        delete data;
    }

    // Перевантажена операція присвоювання
    MyTemplate& operator=(const MyTemplate& other) 
    {
        if (this != &other) 
        {
            delete data;
            if (other.data != nullptr)
                data = new T(*other.data);
            else
                data = nullptr;
        }
        return *this;
    }

    // Перевантажена операція ()
    T operator()() const 
    {
        if (data != nullptr)
            return *data;
        else
            throw TemplateException();
    }

    // Перевантажена операція --
    MyTemplate& operator--() 
    {
        if (data != nullptr)
            --(*data);
        else
            throw TemplateException();
        return *this;
    }

    // Перевантажена операція []
    T operator[](int index) const 
    {
        if (data != nullptr)
            return (*data)[index];
        else
            throw TemplateException();
    }
};

int main() 
{
    try 
    {
        // Тестування шаблону для стандартних типів даних (int)
        MyTemplate<int> myInt(10);
        std::cout << "Value: " << myInt() << std::endl;
        myInt = 20;
        std::cout << "Value: " << myInt() << std::endl;
        --myInt;
        std::cout << "Value: " << myInt() << std::endl;
        std::cout << "Index 0: " << myInt[0] << std::endl;

        // Тестування шаблону для типу MyClass
        MyTemplate<MyClass> myClass(MyClass(5));
        std::cout << "Value: " << myClass().operator int() << std::endl;
        --myClass;
        std::cout << "Value: " << myClass().operator int() << std::endl;
        std::cout << "Index 0: " << myClass()[0] << std::endl;
    }
    catch (const TemplateException& ex) 
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
