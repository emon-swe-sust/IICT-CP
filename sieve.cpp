#include <iostream>
#include <vector>
using namespace std;

void simpleSieve(int limit) {
    vector<bool> mark(limit, true);
    for (int p = 2; p * p < limit; p++) {
        if (mark[p] == true) {
            for (int i = p * p; i < limit; i += p)
                mark[i] = false;
        }
    }

    for (int p = 2; p < limit; p++)
        if (mark[p] == true)
            cout << p << " ";
}

int main() {
    int limit = 100; 
    simpleSieve(limit);
    return 0;
}
