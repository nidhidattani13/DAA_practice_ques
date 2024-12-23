#include <bits/stdc++.h>
using namespace std;

int minDiceThrows(int move[], int n) {
    vector<bool> visited(n + 1, false);
    visited[0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int currentPos = q.front().first;
        int throws = q.front().second;
        q.pop();

        if (currentPos == n - 1)
            return throws;

        for (int dice = 1; dice <= 6; dice++) {
            int nextPos = currentPos + dice;

            if (nextPos < n && !visited[nextPos]) {
                visited[nextPos] = true;

                if (move[nextPos] != -1) {
                    nextPos = move[nextPos];
                }

                q.push({nextPos, throws + 1});
            }
        }
    }

    return -1;
}

int main() {
    int n = 30;
    int move[n];
    for (int i = 0; i < n; i++) {
        move[i] = -1;
    }

    move[2] = 21;
    move[4] = 7;
    move[10] = 25;
    move[19] = 28;
    move[17] = 4;
    move[20] = 8;
    move[24] = 16;
    move[32] = 30;

    cout << minDiceThrows(move, n) << endl;

    return 0;
}
