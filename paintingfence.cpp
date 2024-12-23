#include <iostream>
using namespace std;

int countWays(int n, int k) {
    if (n == 1)
        return k;

    int same = k;
    int diff = k * (k - 1);
    int total = same + diff;

    for (int i = 3; i <= n; i++) {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }

    return total;
}

int main() {
    int n = 3, k = 2;
    cout << countWays(n, k);
    return 0;
}
