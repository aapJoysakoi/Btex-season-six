#include <iostream>
#include <string>

using namespace std;

// Function to check if the 10th symbol from the right end is '1'
bool hasOneAt10thFromRight(const string& str) {
    if (str.size() < 10) {
        return false; // If string length is less than 10, it doesn't satisfy the condition
    }
    return str[str.size() - 10] == '1';
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (c == '0' || c == '1') {
            token += c;
        } else {
            if (!token.empty()) {
                if (hasOneAt10thFromRight(token)) {
                    cout << "Token: " << token << endl;
                } else {
                    cout << "Invalid token: " << token << endl;
                }
                token.clear();
            }
        }
    }
    if (!token.empty()) {
        if (hasOneAt10thFromRight(token)) {
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
    cout << "Tokens where the 10th symbol from the right end is '1':" << endl;
    tokenize(input);
    return 0;
}
