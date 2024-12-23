#include <iostream>
using namespace std;

int countFriendsPairings(int n) {
    if (n <= 2)
        return n;

    int a = 1, b = 2, c;
    for (int i = 3; i <= n; i++) {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int n = 3;
    cout << countFriendsPairings(n);
    return 0;
}
