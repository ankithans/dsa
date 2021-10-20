// https://atcoder.jp/contests/dp/tasks/dp_c

// 3
// 10 40 70
// 20 50 80
// 30 60 90

// 70+50+90 => 210 greedy works, but not always

// recursive
int f(int ind, int prev) {
    if(ind == 0) return 0;
    int maxi = INT_MIN;

    if(prev == 0) {
        int firstTask = a[ind] + f(ind+1, 1);
        int secondTask = b[ind] + f(ind+1, 2);
        int thirdTask = c[ind] + f(ind+1, 3);
        maxi = max(firstTask, max(secondTask, thirdTask));
    } else if(prev == 1) {
        int secondTask = b[ind] + f(ind+1, 2);
        int thirdTask = c[ind] + f(ind+1, 3);
        maxi = max(secondTask, thirdTask);
    } else if(prev == 2) {
        int firstTask = a[ind] + f(ind+1, 1);
        int thirdTask = c[ind] + f(ind+1, 3);
        maxi = max(firstTask, thirdTask);
    } else {
        int firstTask = a[ind] + f(ind+1, 1);
        int secondTask = b[ind] + f(ind+1, 2);
        maxi = max(firstTask, secondTask);
    }

    return maxi;
}

// dp[n+1][4]
// add it at two places ...

// iterative
dp[n][1] = 0;
dp[n][2] = 0;
dp[n][3] = 0;

for(int i = 0; i >= 0; i--) {
    dp[i][1] = max(dp[i+1][0], dp[i+1][2], dp[i+1][3]);
    dp[i][2] = max(dp[i+1][0], dp[i+1][1], dp[i+1][3]);
    dp[i][3] = max(dp[i+1][0], dp[i+1][1], dp[i+1][3]);
}

return max(dp[0][1], dp[0][2], dp[0][3]);