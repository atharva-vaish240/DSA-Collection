
#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Create an array to store the count of distinct subsequences for each character in s2
    vector<int> prev(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = 1;

    // Iterate through s1 and s2 to calculate the counts
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) { // Iterate in reverse direction to avoid overwriting values prematurely
            if (s1[i - 1] == s2[j - 1]) {
                // If the characters match, we have two options:
                // 1. Match the current characters and add to the previous count (prev[j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
            // No need for an else statement since we can simply leave the previous count as is
        }
    }

    // The value at prev[m] contains the count of distinct subsequences
    return prev[m];
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}