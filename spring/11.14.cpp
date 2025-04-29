#include <iostream>
#include <vector>
#include <numeric> 

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Sum: " << sum << '\n'; // 15

    std::vector<int> w = {10, 20, 30, 40, 50};
    int dot = std::inner_product(v.begin(), v.end(), w.begin(), 0);
    std::cout << "Inner product: " << dot << '\n'; // 1*10 + 2*20 + ... = 550

    std::vector<int> partial;
    std::partial_sum(v.begin(), v.end(), std::back_inserter(partial));
    std::cout << "Partial sums: ";
    for (int x : partial) std::cout << x << ' '; // 1 3 6 10 15
    std::cout << '\n';

    std::vector<int> diff;
    std::adjacent_difference(v.begin(), v.end(), std::back_inserter(diff));
    std::cout << "Adjacent differences: ";
    for (int x : diff) std::cout << x << ' '; // 1 (2-1) (3-2) (4-3) (5-4) : 1 1 1 1 1
    std::cout << '\n';

    return 0;
}
