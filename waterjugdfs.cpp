#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
};

bool isValid(int x, int y, int a, int b) {
    return x >= 0 && x <= a && y >= 0 && y <= b;
}

bool dfs(int a, int b, int target, set<pair<int, int>> &visited, stack<State> &s) {
    if (target > max(a, b)) return false;

    while (!s.empty()) {
        State current = s.top();
        s.pop();

        int x = current.x;
        int y = current.y;

        if (x == target || y == target) return true;

        if (visited.find({x, y}) != visited.end()) continue;

        visited.insert({x, y});

        // Fill the first jug
        if (isValid(a, y, a, b)) s.push({a, y});

        // Fill the second jug
        if (isValid(x, b, a, b)) s.push({x, b});

        // Empty the first jug
        if (isValid(0, y, a, b)) s.push({0, y});

        // Empty the second jug
        if (isValid(x, 0, a, b)) s.push({x, 0});

        // Pour from first jug to second jug
        int pour = min(x, b - y);
        if (isValid(x - pour, y + pour, a, b)) s.push({x - pour, y + pour});

        // Pour from second jug to first jug
        pour = min(y, a - x);
        if (isValid(x + pour, y - pour, a, b)) s.push({x + pour, y - pour});
    }

    return false;
}

int main() {
    int a = 4, b = 3, target = 2;
    set<pair<int, int>> visited;
    stack<State> s;
    s.push({0, 0});

    if (dfs(a, b, target, visited, s)) {
        cout << "Solution is possible using DFS\n";
    } else {
        cout << "Solution is not possible\n";
    }
    return 0;
}
