#include <iostream>
#include <string>

using namespace std;

// Function to check if a string contains three consecutive '2's
bool hasThreeConsecutiveTwos(const string& str) {
    for (size_t i = 0; i < str.size() - 2; ++i) {
        if (str[i] == '2' && str[i + 1] == '2' && str[i + 2] == '2') {
            return true;
        }
    }
    return false;
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (c == '0' || c == '1' || c == '2') {
            token += c;
        } else {
            if (!token.empty()) {
                if (hasThreeConsecutiveTwos(token)) {
                    cout << "Token: " << token << endl;
                } else {
                    cout << "Invalid token: " << token << endl;
                }
                token.clear();
            }
        }
    }
    if (!token.empty()) {
        if (hasThreeConsecutiveTwos(token)) {
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
    cout << "Tokens containing three consecutive '2's:" << endl;
    tokenize(input);
    return 0;
}
