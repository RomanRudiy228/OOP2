
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;



int main()
{
    ifstream file;
    ofstream file_o;
    file.open("input.txt");
    if (!file) return -1;
    char sym;
    for (int i = 0; i < sym; i++) {
        file >> i;
    }
    file.close();

    char tab[1024];
    gets_s(tab);
    cout << tab;
    int counter = 0;
    int i = 0;
    for (size_t i = 0; i < 1024; i++)
    {
        if (tab[i] >= 48 && tab[i] <= 57 && tab[i - 1] == ' ')
            counter++;
    }
    cout << counter << "\n";

    file_o.open("output.txt");
    if (!file) return -1;
    file_o << counter;
    file_o.close();
}


