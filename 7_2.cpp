#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
    ifstream file ("data.txt");
    if (!file) {
        cout << "Error: Cannot open file " << endl;
        return 1;
    }

    vector <string> lines;
    string line;
    int linecount=0 , wordcount=0 , charcount=0;

    while(getline(file,line))
    {
        lines.push_back(line);
        linecount++;

        charcount += line.length();

        stringstream ss(line);
        string word;
        while(ss >> word)
        {
            wordcount++;
        }
    }
    file.close();

    cout << "\n--- File Statistics ---" << endl;
    cout << "Lines      : " << linecount << endl;
    cout << "Words      : " << wordcount << endl;
    cout << "Characters : " << charcount << endl;

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}