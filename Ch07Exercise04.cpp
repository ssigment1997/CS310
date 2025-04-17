#include <iostream>     
#include <string>       
#include <algorithm>    // for remove_if
#include <cctype>       // for tolower

using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);  // Handle uppercase vowels
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str; // Use `getline(cin, str);` if you want to input spaces

    str.erase(remove_if(str.begin(), str.end(), isVowel), str.end());

    cout << "The new string without vowels is: " << str << endl;

    return 0;
}


