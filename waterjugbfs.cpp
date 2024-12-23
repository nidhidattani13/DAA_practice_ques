#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
};

bool isValid(int x, int y, int a, int b) {
    return x >= 0 && x <= a && y >= 0 && y <= b;
}

bool bfs(int a, int b, int target) {
    if (target > max(a, b)) return false;

    set<pair<int, int>> visited;
    queue<State> q;

    q.push({0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;

        if (x == target || y == target) return true;

        // Fill the first jug
        if (isValid(a, y, a, b) && visited.find({a, y}) == visited.end()) {
            visited.insert({a, y});
            q.push({a, y});
        }

        // Fill the second jug
        if (isValid(x, b, a, b) && visited.find({x, b}) == visited.end()) {
            visited.insert({x, b});
            q.push({x, b});
        }

        // Empty the first jug
        if (isValid(0, y, a, b) && visited.find({0, y}) == visited.end()) {
            visited.insert({0, y});
            q.push({0, y});
        }

        // Empty the second jug
        if (isValid(x, 0, a, b) && visited.find({x, 0}) == visited.end()) {
            visited.insert({x, 0});
            q.push({x, 0});
        }

        // Pour from first jug to second jug
        int pour = min(x, b - y);
        if (isValid(x - pour, y + pour, a, b) && visited.find({x - pour, y + pour}) == visited.end()) {
            visited.insert({x - pour, y + pour});
            q.push({x - pour, y + pour});
        }

        // Pour from second jug to first jug
        pour = min(y, a - x);
        if (isValid(x + pour, y - pour, a, b) && visited.find({x + pour, y - pour}) == visited.end()) {
            visited.insert({x + pour, y - pour});
            q.push({x + pour, y - pour});
        }
    }

    return false;
}

int main() {
    int a = 4, b = 3, target = 2;
    if (bfs(a, b, target)) {
        cout << "Solution is possible using BFS\n";
    } else {
        cout << "Solution is not possible\n";
    }
    return 0;
}
