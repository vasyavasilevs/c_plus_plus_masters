#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

template <typename InputIt, typename OutputIt, typename UnaryFunction, typename Predicate>
OutputIt transform_if(InputIt first, InputIt last, OutputIt dest,
                      UnaryFunction transform, Predicate pred) {
    return std::copy_if(first, last, dest,
        [&](const auto& val) {
            if (pred(val)) {
                *dest = transform(val);
                ++dest;
            }
            return false; 
        }
    );
}


int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    std::vector<int> result;

    auto is_not_even = [](int x) { return x % 2 != 0; };
    auto square = [](int x) { return x * x; };

    transform_if(v.begin(), v.end(), std::back_inserter(result), square, is_not_even);

    //1 9 25
    for (int x : result)
        std::cout << x << " ";

    return 0;
}

