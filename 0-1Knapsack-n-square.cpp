#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int>& weight, vector<int>& profit, int n) {
  
    if (n == 0 || W == 0)
        return 0;

    if (weight[n - 1] > W)
        return knapSack(W, weight, profit, n - 1);

    return max(knapSack(W, weight, profit, n - 1), 
               profit[n - 1] + knapSack(W - weight[n - 1], weight, profit, n - 1));
}

int main() {
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;

    cout << knapSack(W, weight, profit, profit.size()) << endl;
    return 0;
}