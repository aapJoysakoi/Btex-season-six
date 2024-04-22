#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a string represents a valid floating-point number
bool isFloat(const string& str) {
    bool hasDecimal = false;
    bool hasDigits = false;
    bool hasExponent = false;
    for (char c : str) {
        if (isdigit(c)) {
            hasDigits = true;
        } else if (c == '.') {
            if (hasDecimal || hasExponent) {
                return false; // More than one decimal point or already found in the exponent part
            }
            hasDecimal = true;
        } else if (c == 'e' || c == 'E') {
            if (!hasDigits || hasExponent) {
                return false; // Exponent encountered without any digits or more than one exponent part
            }
            hasExponent = true;
            hasDigits = false; // Resetting hasDigits flag for the exponent part
        } else if (c == '+' || c == '-') {
            if (str.empty() || str.back() != 'e' && str.back() != 'E') {
                return false; // Sign encountered in invalid position
            }
        } else {
            return false; // Invalid character
        }
    }
    return hasDigits; // At least one digit must be present
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (isspace(c)) {
            if (!token.empty()) {
                if (isFloat(token)) {
                    cout << "Token: " << token << endl;
                } else {
                    cout << "Invalid token: " << token << endl;
                }
                token.clear();
            }
        } else {
            token += c;
        }
    }
    if (!token.empty()) {
        if (isFloat(token)) {
            cout << "Token: " << token << endl;
        } else {
            cout << "Invalid token: " << token << endl;
        }
    }
}

int main() {
    string input;
    cout << "Enter input string: ";
    getline(cin, input);
    cout << "Floating-point numbers in the input:" << endl;
    tokenize(input);
    return 0;
}
