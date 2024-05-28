#include <iostream>
#include <regex>
#include <string>
#include <vector>
// Define a structure to hold the token information
struct Token {
    std::string type;
    std::string value;
};
// Token specifications
const std::vector<std::pair<std::string, std::regex>> tokenSpecs = {
    {"KEYWORD", std::regex(R"(\b(if|else|while|return|int|float|void)\b)")},
    {"OPERATOR", std::regex(R"(\+\+|--|==|!=|<=|>=|&&|\|\||[+\-*/=<>!])")}, // Includes ++, --, ==, !=, <=, >=, &&, ||
    {"NUMBER", std::regex(R"(\b\d+(\.\d*)?\b)")},
    {"SEMICOLON", std::regex(R"(;)")},
    {"PAREN", std::regex(R"([()])")},
    {"BRACE", std::regex(R"([{}])")},
    {"IDENTIFIER", std::regex(R"(\b[A-Za-z_]\w*\b)")},
    {"WHITESPACE", std::regex(R"(\s+)")}, // We will skip whitespace in the output
    {"UNKNOWN", std::regex(R"(.)")}  // Matches any other character
};
// Function to tokenize the input code
std::vector<Token> tokenize(const std::string &code) {
    std::vector<Token> tokens;
    size_t position = 0;
    while (position < code.length()) {
        bool matched = false;
        for (const auto &spec : tokenSpecs) {
            std::smatch match;
            std::string subCode = code.substr(position);
            if (std::regex_search(subCode, match, spec.second, std::regex_constants::match_continuous)) {
                std::string tokenValue = match.str(0);
                if (spec.first != "WHITESPACE") { // Skip whitespace tokens
                    tokens.push_back({spec.first, tokenValue});
                }
                position += tokenValue.length();
                matched = true;
                break;
            }
        }
        if (!matched) {
            // If no match was found, advance by one character to prevent infinite loop
            position++;
        }
    }
    return tokens;
}
  int main() {
    std::cout << "Enter a string to tokenize: ";
    std::string code;
    std::getline(std::cin, code);
    // Tokenize the user input
    std::vector<Token> tokens = tokenize(code);
    // Print the number of tokens and their types
    std::cout << "Number of tokens: " << tokens.size() << std::endl;
    for (const auto &token : tokens) {
        std::cout << "(" << token.type << ", " << token.value << ")" << std::endl;
    }
    return 0;
}
