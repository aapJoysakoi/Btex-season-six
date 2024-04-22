#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a string is a keyword
bool isKeyword(const string& str) {
    // List of keywords
    string keywords[] = {"if", "else", "while", "for", "int", "float", "char", "return"};
    for (const string& keyword : keywords) {
        if (str == keyword) {
            return true;
        }
    }
    return false;
}

// Function to check if a character is a digit
bool isDigit(char c) {
    return isdigit(c);
}

// Function to check if a character is a valid identifier character
bool isValidIdentifierChar(char c) {
    return isalpha(c) || isdigit(c) || c == '_';
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (isspace(c)) {
            if (!token.empty()) {
                cout << "Token: " << token << endl;
                token.clear();
            }
        } else if (isDigit(c)) {
            token += c;
        } else if (isValidIdentifierChar(c)) {
            token += c;
        } else {
            // Handle operators, separators, etc. as needed
            cout << "Unknown character: " << c << endl;
        }
    }
    if (!token.empty()) {
        cout << "Token: " << token << endl;
    }
}

int main() {
    string input;
    cout << "Enter input string: ";
    getline(cin, input);
    cout << "Tokens:" << endl;
    tokenize(input);
    return 0;
}
