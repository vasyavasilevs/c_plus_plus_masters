#include <iostream>
#include <string>
#include <cctype> 

void convertToProperCase(std::string& text) {
    bool inWord = false; 

    for (char& c : text) {
        if (std::isalpha(c)) { 
            if (!inWord) {
                c = std::toupper(c); 
                inWord = true;
            } else {
                c = std::tolower(c); 
            }
        } else {
            inWord = false; 
        }
    }
}

int main() {
    std::string text = "heLLo, woRLD!";
    convertToProperCase(text);
    std::cout << text << std::endl; 
    return 0;
}
