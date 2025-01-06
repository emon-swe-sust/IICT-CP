#include <bits/stdc++.h>

void initial() {
    #ifndef LEETCODE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// Function to compare two integers
bool compareIntegers(int a, int b) {
    return a > b; // Change to '>' for descending order
}

int main() {
    initial();
    std::vector<int> numbers = {5, 2, 8, 3, 1};

    // Sorting the numbers using our comparison function
    std::sort(numbers.begin(), numbers.end(), compareIntegers);

    // Printing the sorted numbers
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}