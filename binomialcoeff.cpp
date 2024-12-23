#include <iostream>
using namespace std;

int nCr(int n, int r) {
    if (r > n) 
        return 0;
    if (r == 0 || r == n) 
        return 1;

    r = min(r, n - r);

    long long numerator = 1, denominator = 1;

    for (int i = 0; i < r; ++i) {
        numerator *= (n - i);
        denominator *= (i + 1);
    }

    return numerator / denominator;
}

int main() {
    cout << nCr(3, 2) << endl; 
    cout << nCr(2, 4) << endl; 
    cout << nCr(5, 0) << endl; 

    return 0;
}
