#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void insert_phone_to_lastname(map<string, string> &myMap, string phone_number, string last_name)
{
    myMap.insert(make_pair(phone_number, last_name));
}

void insert_lastname_to_phone(map<string, vector<string>> &myMap, string phone_number, string last_name)
{
    myMap[last_name].push_back(phone_number);
}

void find_last_name(map<string, string> &myMap)
{
    string phone_number;
    cout << "Input phone number: ";
    cin >> phone_number;
    map<string, string>::iterator it_phone = myMap.find(phone_number);
    if (it_phone != myMap.end())
    {
        cout << "Last name: " << it_phone->second << endl;
    }
}

void find_phone_numer(map<string, vector<string>> &myMap)
{
    string last_name;
    cout << "Input last name: ";
    cin >> last_name;

    map<string, vector<string>>::iterator it_last_name = myMap.find(last_name);
    if (it_last_name != myMap.end())
    {
        cout << "Phone numbers: ";
        for(int i = 0; i < it_last_name->second.size(); ++i)
        {
            cout << it_last_name->second[i] << " ";
        }
    }
}

int main()
{
    map<string, string> phone_to_lastname;
    map<string, vector<string>> lastname_to_phone;
    string phone_number;
    string last_name;
    string command;

    cout << "Input command (add, Lname, phone): ";
    cin >> command;

    while (command != "exit")
    {
        if (command == "add")
        {
            cout << "Enter phone number: ";
            cin >> phone_number;
            cout << "Enter last name: ";
            cin >> last_name;

            insert_phone_to_lastname(phone_to_lastname, phone_number, last_name);
            insert_lastname_to_phone(lastname_to_phone, phone_number, last_name);
            cout << endl << "Input command (add, Lname, phone or exit): ";
            cin >> command;
        }
        else if (command == "Lname")
        {
            find_last_name(phone_to_lastname);
            cout << endl << "Input command (add, Lname, phone): ";
            cin >> command;
        }
        else if (command == "phone")
        {
            find_phone_numer(lastname_to_phone);
            cout << endl << "Input command (add, Lname, phone): ";
            cin >> command;
        }
        else
        {
            cerr << "Uknown command";
            cout << endl << "Input command (add, Lname, phone): ";
            cin >> command;
        }
    }
}