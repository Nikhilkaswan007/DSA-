#include <iostream>
#include <vector>
using namespace std;

int maxProfit(int n, vector<int>& prices) {
    if (n == 0) return 0; // Base case: No rod left to cut

    int max_value = 0;
    
    // Try cutting the rod at every length i (1 to n)
    for (int i = 1; i <= n; i++) {
        int profit = prices[i - 1] + maxProfit(n - i, prices);
        max_value = max(max_value, profit);
    }

    return max_value;
}

int main() {
    int N = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    
    cout << "Maximum Profit: " << maxProfit(N, prices) << endl; // Output: 22
    return 0;
}
