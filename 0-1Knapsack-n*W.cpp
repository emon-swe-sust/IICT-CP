#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int>& weight, vector<int>& profit, 
             int index, vector<vector<int>>& memo) {
  
    if (index < 0)
        return 0;

    if (memo[index][W] != -1)
        return memo[index][W];

    if (weight[index] > W) {        
        memo[index][W] = knapSack(W, weight, profit, index - 1, memo);
    } else {
        memo[index][W] = max(profit[index] + 
                             knapSack(W - weight[index], weight, profit, index - 1, memo),
                             knapSack(W, weight, profit, index - 1, memo));
    }

    return memo[index][W];
}

int main() {
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;
    int n = weight.size();
    vector<vector<int>> memo(n, vector<int>(W + 1, -1));

    int ans = knapSack(W, weight, profit, n-1, memo);
    cout << ans << endl;
    return 0;
}