/*
    Name: [Benjamin Cherelus]
    
    Assignment Title: Remove Vowels from a String
*/

/*
    This program reads a string from the user and removes all vowels using
    the remove_if algorithm and a custom isVowel function.
*/

#include <iostream>
#include <string>
#include <algorithm>  // For remove_if
#include <cctype>     // For tolower

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch);  // Convert to lowercase for consistent comparison
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    string str;

    // Prompt user to enter a string (single word version)
    cout << "Enter a string: ";
    cin >> str;  // Use getline(cin, str) for full sentences

    // Remove vowels from the string using remove_if and erase
    str.erase(
        remove_if(str.begin(), str.end(), isVowel),  // Find vowels
        str.end()                                    // Erase them from the end of new string
    );

    // Output the resulting string without vowels
    cout << "The new string without vowels is: " << str << endl;

    return 0;
}


