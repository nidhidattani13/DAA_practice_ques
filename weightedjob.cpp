#include <bits/stdc++.h>
using namespace std;

struct Job {
    int start, end, profit;
};

bool compare(Job a, Job b) {
    return a.end < b.end;
}

int binarySearch(vector<Job>& jobs, int index) {
    int lo = 0, hi = index - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (jobs[mid].end <= jobs[index].start) {
            if (jobs[mid + 1].end <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int weightedJobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    
    int n = jobs.size();
    vector<int> dp(n);
    
    dp[0] = jobs[0].profit;
    
    for (int i = 1; i < n; i++) {
        int inclProfit = jobs[i].profit;
        int l = binarySearch(jobs, i);
        if (l != -1) {
            inclProfit += dp[l];
        }
        
        dp[i] = max(inclProfit, dp[i - 1]);
    }
    
    return dp[n - 1];
}

int main() {
    vector<Job> jobs = {{1, 3, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    cout << "Maximum Profit: " << weightedJobScheduling(jobs);
    return 0;
}
