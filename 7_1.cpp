#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

int main()
{
    string my_string, lower_text_string;

    cout << "Enter your content: ";
    getline(cin, my_string);

    for (char ch : my_string)
    {
        if (isalnum(ch) || isspace(ch))
        {
            lower_text_string += tolower(ch);
        }
    }

    cout << "------for original string------" << endl;
    stringstream obj(my_string);
    map<string, int> freq;

    string buf;
    while (obj >> buf)
    {
        freq[buf]++;
    }

    cout << "Repeated words are :-" << endl;
    for (auto &it : freq)
    {
        if (it.second > 1)
        {
            cout << it.first << ": " << it.second << endl;
        }
    }

    cout << "------without including caps------" << endl;

    stringstream obj_lower(lower_text_string);
    freq.clear();
    while (obj_lower >> buf)
    {
        freq[buf]++;
    }

    cout << "Repeated words are :-" << endl;
    for (auto &it : freq)
    {
        if (it.second > 1)
        {
            cout << it.first << ": " << it.second << endl;
        }
    }
    cout << "This program is made by 24CE030 - DHARM." << endl;

    return 0;
}
