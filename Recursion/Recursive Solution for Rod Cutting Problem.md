### **PROBLEM STATEMENT**
You are given a rod of length N and an array prices[] where prices[i] represents the price of a rod of length i+1. Your task is to determine the maximum profit you can achieve by cutting the rod into smaller lengths and selling the pieces.

Write a recursive function maxProfit(int n, int[] prices) to calculate the maximum profit.

Input: N = 8
prices = [1, 5, 8, 9, 10, 17, 17, 20]

Output: 22

### **Recursive Solution for Rod Cutting Problem**

The problem can be solved using **recursion** by trying all possible ways to cut the rod and choosing the one that gives the maximum profit.

---

### **Approach**
1. We have a rod of length `N`, and we can cut it into different lengths.
2. For each possible cut at length `i`, we:
   - Take the profit `prices[i-1]` (since index `i-1` stores the price for length `i`).
   - Recursively compute the **maximum profit** for the remaining rod of length `N - i`.
   - Return the maximum of all possible cuts.

### **Recursive Formula**
\[
\text{maxProfit}(N) = \max_{i=1}^{N} \left( \text{prices}[i-1] + \text{maxProfit}(N - i) \right)
\]
where:
- `prices[i-1]` is the price of the piece of length `i`.
- `maxProfit(N - i)` is the best profit achievable for the remaining rod of length `N - i`.

---

### **Recursive Code in C++**
```cpp
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
```

---

### **Time Complexity Analysis**
- The function computes `maxProfit(n)` recursively for all values `1` to `N`, leading to an **exponential time complexity** of **O(2^N)**.
- **Overlapping subproblems** cause redundant calculations, making it inefficient for large `N`.

---

### **Optimized Approach: Dynamic Programming (Memoization)**
To improve efficiency, **store previously computed results** to avoid redundant calculations (Top-Down DP).

Would you like me to provide the **optimized DP solution**? 🚀