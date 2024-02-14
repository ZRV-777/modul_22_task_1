#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void insert_in_map(map<string, string> &myMap, string phone_number, string last_name)
{
    cout << "Input phone number: ";
    cin >> phone_number;
    cout << "Input last name: ";
    cin >> last_name;
    myMap.insert(make_pair(phone_number, last_name));
}

void find_last_name(map<string, string> &myMap, string phone_number)
{
    cout << "Input phone number: ";
    cin >> phone_number;
    map<string, string>::iterator it_phone = myMap.find(phone_number);
    if (it_phone != myMap.end())
    {
        cout << "Last name: " << it_phone->second << endl;
    }
}

void find_phone_number(map<string, string> &myMap, string last_name)
{
    cout << "Input last name: ";
    cin >> last_name;

    string target = last_name;
    vector<string> counter;

    for (auto it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second == target)
        {
            counter.push_back(it->first);
        }
    }

    for (const auto &counter: counter)
    {
        cout << "Phone number: ";
        cout << counter << " ";
    }
}

int main()
{
    map<string, string> phone_book;
    string phone_number;
    string last_name;
    string command;

    cout << "Input command (add, name, phone): ";
    cin >> command;

    while (command != "exit")
    {
        if (command == "add")
        {
            insert_in_map(phone_book, phone_number, last_name);
            cout << endl << "Input command (add, name, phone or exit): ";
            cin >> command;
        }
        else if (command == "name")
        {
            find_last_name(phone_book, phone_number);
            cout << endl << "Input command (add, name, phone): ";
            cin >> command;
        }
        else if (command == "phone")
        {
            find_phone_number(phone_book, last_name);
            cout << endl << "Input command (add, name, phone): ";
            cin >> command;
        }
        else
        {
            cerr << "Uknown command";
            cout << endl << "Input command (add, name, phone): ";
            cin >> command;
        }
    }
}