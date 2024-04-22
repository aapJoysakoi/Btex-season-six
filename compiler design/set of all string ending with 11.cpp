#include <iostream>
#include <string>

using namespace std;

// Function to check if a string ends with "11"
bool endsWith11(const string& str) {
    return str.size() >= 2 && str.substr(str.size() - 2) == "11";
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (c == '0' || c == '1') {
            token += c;
        } else {
            if (!token.empty()) {
                if (endsWith11(token)) {
                    cout << "Token: " << token << endl;
                } else {
                    cout << "Invalid token: " << token << endl;
                }
                token.clear();
            }
        }
    }
    if (!token.empty()) {
        if (endsWith11(token)) {
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
    cout << "Tokens ending with '11':" << endl;
    tokenize(input);
    return 0;
}
