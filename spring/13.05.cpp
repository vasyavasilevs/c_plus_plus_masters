#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

bool isNotEmptyOrWhitespace(const std::string& line) {
    return !line.empty() && line.find_first_not_of(" \t\n\r\f\v") != std::string::npos;
}

int main() {
    std::string inputFileName, outputFileName;

    std::cout << "Input file name: ";
    std::getline(std::cin, inputFileName);
    
    std::cout << "Output file name: ";
    std::getline(std::cin, outputFileName);

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error when opening input file!" << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName); 
    if (!outputFile) {
        std::cerr << "Error when opening output file!" << std::endl;
        return 1;
    }

    std::string line;
    
    while (std::getline(inputFile, line)) {
        if (isNotEmptyOrWhitespace(line)) {
            outputFile << line << std::endl; 
        }
    }

    std::cout << "Done!" << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
