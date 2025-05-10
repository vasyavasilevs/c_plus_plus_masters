#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    const int rows = 10;
    std::vector<std::vector<int>> pascal(rows);

    for (int i = 0; i < rows; ++i) {
        pascal[i].resize(i + 1);
        pascal[i][0] = pascal[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        std::cout << std::string((rows - i - 1) * 2, ' ');
        for (int val : pascal[i]) {
            std::cout << std::setw(4) << val;
        }
        std::cout << '\n';
    }

    return 0;
}
