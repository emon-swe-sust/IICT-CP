#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistance(const string& str1, const string& str2) {
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {

            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min({dp[i][j - 1],     // Insert
                                    dp[i - 1][j],     // Remove
                                    dp[i - 1][j - 1]  // Replace
                                   });
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int distance = editDistance(str1, str2);
    cout << "Edit Distance: " << distance << endl;

    return 0;
}