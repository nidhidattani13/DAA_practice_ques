#include <iostream>
using namespace std;

int findCatalan(int n) {
    if (n <= 1)
        return 1;

    int res = 0;
    for (int i = 0; i < n; i++)
        res += findCatalan(i) * findCatalan(n - i - 1);

    return res;
}

int main() {
    int n = 6;
    int res = findCatalan(n);
    cout << res;
    return 0;
}