#include <bits/stdc++.h>
using namespace std;

int lps(const string& s, int lo, int hi) {
    if (lo == hi) return 1;
    if (s[lo] == s[hi] && lo + 1 == hi) return 2;
    if (s[lo] == s[hi]) return lps(s, lo + 1, hi - 1) + 2;
    return max(lps(s, lo, hi - 1), lps(s, lo + 1, hi));
}

int main() {
    string s = "NIDHI";
    int n = s.size();
    cout << lps(s, 0, n - 1);
    return 0;
}
