#include <iostream>
#include <string>

using namespace std;

// Function to check if the sum of digits of a number equals 9
bool sumOfDigitsEquals9(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum == 9;
}

// Function to tokenize a given input string
void tokenize(const string& input) {
    string token;
    for (char c : input) {
        if (isdigit(c)) {
            token += c;
            if (token.size() == 4) {
                int num = stoi(token);
                if (sumOfDigitsEquals9(num)) {
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
    cout << "Tokens representing 4-digit numbers whose digits sum up to 9:" << endl;
    tokenize(input);
    return 0;
}
