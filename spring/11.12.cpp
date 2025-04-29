#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator> 

int main() {
    std::vector<int> v = {1, 2, 3, 4, 2, 5, 2, 6};

    int twos = std::count(v.begin(), v.end(), 2);
    std::cout << "Count of 2s: " << twos << '\n';

    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {1, 2, 0, 4};
    auto [it1, it2] = std::mismatch(a.begin(), a.end(), b.begin());
    if (it1 != a.end())
        std::cout << "First mismatch: " << *it1 << " vs " << *it2 << '\n';

    std::vector<int> c = {7, 8, 9};
    std::vector<int> d = {7, 8, 9};
    std::cout << "c == d? " << (std::equal(c.begin(), c.end(), d.begin()) ? "Yes" : "No") << '\n';

    std::vector<int> pattern = {2, 5};
    auto it = std::search(v.begin(), v.end(), pattern.begin(), pattern.end());
    if (it != v.end())
        std::cout << "Pattern found at index: " << std::distance(v.begin(), it) << '\n';

    std::replace(v.begin(), v.end(), 2, 99);
    std::cout << "After replace: ";
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';

    auto new_end = std::remove(v.begin(), v.end(), 99);
    v.erase(new_end, v.end()); // Physical removing
    std::cout << "After remove: ";
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> e = {1, 1, 2, 2, 2, 3, 3, 4};
    auto unique_end = std::unique(e.begin(), e.end());
    e.erase(unique_end, e.end());
    std::cout << "After unique: ";
    for (int x : e) std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> f = {1, 2, 3, 4, 5};
    std::rotate(f.begin(), f.begin() + 2, f.end()); // cyclic: 3 4 5 1 2
    std::cout << "After rotate: ";
    for (int x : f) std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> g = {1, 4, 5, 2, 3, 6};
    auto part_it = std::partition(g.begin(), g.end(), [](int x) { return x % 2 == 0; });
    std::cout << "After partition (evens first): ";
    for (int x : g) std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> h = {5, 1, 4, 2, 3};
    std::nth_element(h.begin(), h.begin() + 2, h.end());
    std::cout << "After nth_element (3rd element): ";
    for (int x : h) std::cout << x << ' ';
    std::cout << '\n';
    std::cout << "3rd element (0-based): " << h[2] << '\n';

    return 0;
}
