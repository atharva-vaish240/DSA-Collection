#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> output(n);
    vector<int> cnt(10, 0); 
    for (int i = 0; i < n; i++) 
        cnt[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) 
        cnt[i] += cnt[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int dig = (a[i] / exp) % 10;
        output[cnt[dig] - 1] = a[i];
        cnt[dig]--;
    }
    a = output; // copy back
}

void radixSort(vector<int> &a) {
    if (a.empty()) return;
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(a, exp);
}

void radixSortWithNegatives(vector<int> &a) {
    vector<int> neg, pos;
    for (int x : a) {
        if (x < 0) neg.push_back(-x); 
        else pos.push_back(x);
    }

    radixSort(pos);
    radixSort(neg);
    reverse(neg.begin(), neg.end()); 

    a.clear();
    for (int x : neg) a.push_back(-x);
    for (int x : pos) a.push_back(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    radixSortWithNegatives(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
}
