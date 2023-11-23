#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Train 
{
    string number;
    string destination;
    string departureTime;
};

// Функція для виведення всього списку поїздів
void printAllTrains(const vector<Train>& trains) 
{
    if (trains.empty()) 
    {
        cout << "There is no information about trains." << endl;
        return;
    }

    cout << "All train list:" << endl;
    for (const Train& train : trains) 
    {
        cout << "Train number: " << train.number << endl;
        cout << "Station of destination: " << train.destination << endl;
        cout << "Departure time: " << train.departureTime << endl;
        cout << endl;
    }
}

// Функція для виведення даних про конкретний поїзд за номером
void printTrainByNumber(const vector<Train>& trains, const string& trainNumber) 
{
    bool trainFound = false;
    for (const Train& train : trains) 
    {
        if (train.number == trainNumber) 
        {
            cout << "Information about train with number " << trainNumber << ":" << endl;
            cout << "Destination station: " << train.destination << endl;
            cout << "Departure time: " << train.departureTime << endl;
            cout << endl;
            trainFound = true;
            break;
        }
    }

    if (!trainFound) 
    {
        cout << "Train with numer " << trainNumber << " not found." << endl;
    }
}

// Функція для виведення даних про поїзди, що прямують до певної станції призначення
void printTrainsByDestination(const vector<Train>& trains, const string& destination) 
{
    bool trainsFound = false;
    for (const Train& train : trains) 
    {
        if (train.destination == destination) 
        {
            cout << "A train heading to the station " << destination << ":" << endl;
            cout << "Train number: " << train.number << endl;
            cout << "Departure time: " << train.departureTime << endl;
            cout << endl;
            trainsFound = true;
        }
    }

    if (!trainsFound) 
    {
        cout << "A train heading to the station " << destination << ", not found." << endl;
    }
}

int main() 
{
    vector<Train> trains;

    int choice;
    while (true) 
    {
        cout << "Menu:" << endl;
        cout << "1. Add train" << endl;
        cout << "2. Display all list of trains" << endl;
        cout << "3. Find a train by number" << endl;
        cout << "4. Find trains by destination station" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            Train train;
            cout << "Enter the train number: ";
            cin >> train.number;
            cout << "Enter destination station: ";
            cin >> train.destination;
            cout << "Enter the time of departure: ";
            cin >> train.departureTime;

            trains.push_back(train);

            cout << "Train successfully added!" << endl;
        }
        else if (choice == 2) 
        {
            printAllTrains(trains);
        }
        else if (choice == 3) 
        {
            string trainNumber;
            cout << "Enter the train number: ";
            cin >> trainNumber;

            printTrainByNumber(trains, trainNumber);
        }
        else if (choice == 4) 
        {
            string destination;
            cout << "Enter destination station: ";
            cin >> destination;

            printTrainsByDestination(trains, destination);
        }
        else if (choice == 5) 
        {
            break;
        }
        else 
        {
            cout << "Wrong choice. Try again." << endl;
        }

        cout << endl;
    }

    return 0;
}