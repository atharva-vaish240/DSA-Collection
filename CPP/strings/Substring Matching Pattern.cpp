Problem : - 

You are given a string s and a pattern string p, where p contains exactly one '*' character.

The '*' in p can be replaced with any sequence of zero or more characters.

Return true if p can be made a substring of s, and false otherwise.

 

Example 1:

Input: s = "leetcode", p = "ee*e"

Output: true

Explanation:

By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.

Example 2:

Input: s = "car", p = "c*v"

Output: false

Explanation:

There is no substring matching the pattern.

Example 3:

Input: s = "luck", p = "u*"

Output: true

Explanation:

The substrings "u", "uc", and "uck" match the pattern.

 

Constraints:

1 <= s.length <= 50
1 <= p.length <= 50 
s contains only lowercase English letters.
p contains only lowercase English letters and exactly one '*'



Solution : - 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find('*');              // position of '*'
        string b = p.substr(0, x);        // prefix before '*'
        string e = p.substr(x + 1);       // suffix after '*'

        int i = s.find(b);                // find prefix in s
        int j = s.rfind(e);               // find suffix in s (from right)

        // check prefix found, suffix found, and prefix ends before suffix starts
        return i != -1 && j != -1 && i + b.size() <= j;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "leetcode";
    string p1 = "ee*e";
    cout << (sol.hasMatch(s1, p1) ? "true" : "false") << endl; // true

    // Example 2
    string s2 = "car";
    string p2 = "c*v";
    cout << (sol.hasMatch(s2, p2) ? "true" : "false") << endl; // false

    // Example 3
    string s3 = "luck";
    string p3 = "u*";
    cout << (sol.hasMatch(s3, p3) ? "true" : "false") << endl; // true

    return 0;
}



Complexity
Time complexity: O(m * n), where m is the length of string s and n is the length of string p
Space complexity:O(1)
