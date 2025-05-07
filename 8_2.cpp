#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void to_lowercase(string& word) {
    for (char& ch : word) {
        ch = tolower(ch);
    }
}

void clean_word(string& word) {
    word.erase(remove_if(word.begin(), word.end(),
               [](char c) { return ispunct(c); }),
               word.end());
}

int main() {
    string sentence;
    map<string, int> word_frequency;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    istringstream stream(sentence);
    string word;

    while (stream >> word) {
        clean_word(word);
        to_lowercase(word);
        if (!word.empty()) {
            ++word_frequency[word];
        }
    }

    cout << "\nWord Frequency Distribution:\n";
    for (auto it = word_frequency.begin(); it != word_frequency.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }

    cout << "This program is made by 24CE030 - DHARM." << endl;
    return 0;
}
