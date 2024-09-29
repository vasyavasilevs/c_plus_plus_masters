#include <iostream>

void classifySymbol(char c) {
    switch (c) {
        //decimal numbers
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            std::cout << c << " - decimal number\n" << std::endl;
            break;
        //arithmetic operators
        case '+': case '-': case '*': case '/':
            std::cout << c << " - arithmetic operator\n" << std::endl;
            break;
        //brackets
        case '(': case ')':
            std::cout << c << " - bracket\n" << std::endl;
            break;
        //other
        default:
            std::cout << c << " - other\n" << std::endl;
            break;
    }
}

int main() {
    std::string input;
    
    std::cout << "Enter a symbol (string of symbols): ";
    std::cin >> input;

    for (char c : input) {
        classifySymbol(c);
    }

    return EXIT_SUCCESS;
}
