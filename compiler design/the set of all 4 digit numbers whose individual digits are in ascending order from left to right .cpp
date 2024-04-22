#include <iostream>
#include <string>

using namespace std;

// Function to check if the digits of a number are in ascending order
bool digitsAscending(int number) {
    int lastDigit = number % 10;
    number /= 10;
    while (number > 0) {
        int currentDigit = number % 10;
        if (currentDigit >= lastDigit) {
            return false;
        }
        lastDigit = currentDigit;
        number /= 10;
    }
    return true;
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (isdigit(c)) {
            token += c;
            if (token.size() == 4) {
                int num = stoi(token);
                if (digitsAscending(num)) {
                    cout << "Token: " << token << endl;
                } else {
                    cout << "Invalid token: " << token << endl;
                }
                token.clear();
            }
        } else {
            token.clear();
        }
    }
}

int main() {
    string input;
    cout << "Enter input string: ";
    getline(cin, input);
    cout << "Tokens representing 4-digit numbers with ascending digits:" << endl;
    tokenize(input);
    return 0;
}
