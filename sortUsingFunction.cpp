#include <bits/stdc++.h>

bool compareIntegers(int a, int b) {
    return a > b;
}

int main() {
    std::vector<int> numbers = {5, 2, 8, 3, 1};

    std::sort(numbers.begin(), numbers.end(), compareIntegers);

    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
