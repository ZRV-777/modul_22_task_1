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
    //map<int, vector<string>> counter;
    cout << "Input last name: ";
    cin >> last_name;
    map<string, string>::iterator it_lName = myMap.find(last_name);

/*   for (auto& it : myMap)
    {
      counter[it.second.size()].emplace_back(it.first);
    }

  for (auto& it : counter)
    {
      if (it.second.size() <= 1) continue;

      cout << "Phone number: ";
      for (auto& k:it.second)
        {
          if (&k != &it.second.front()) cout << " ";
          cout << k;
        }
    } */

    if (it_lName != myMap.end())
    {
        cout << "Phone number: " << it_lName->first << endl;
    }
}

int main()
{
    map<string, string> phone_book;
    string phone_number;
    string last_name;
    string command;

    cout << "Input command (add, Lname, phone): ";
    cin >> command;

    while (command != "exit")
    {
        if (command == "add")
        {
            insert_in_map(phone_book, phone_number, last_name);
            cout << endl << "Input command (add, Lname, phone or exit): ";
            cin >> command;
        }
        else if (command == "Lname")
        {
            find_last_name(phone_book, phone_number);
            cout << endl << "Input command (add, Lname, phone): ";
            cin >> command;
        }
        else if (command == "phone")
        {
            find_phone_number(phone_book, last_name);
            cout << endl << "Input command (add, Lname, phone): ";
            cin >> command;
        }
/*       else if (command == "show")
      {
        for (map<string, string>::iterator it = phone_book.begin();
            it != phone_book.end(); ++ it)
          {
            cout << it->first << " " << it->second << endl;
          }

        cout << endl << "Input command (add, lname, phone): ";
        cin >> command;
      } */
        else
        {
            cerr << "Uknown command";
            cout << endl << "Input command (add, Lname, phone): ";
            cin >> command;
        }
    }
}