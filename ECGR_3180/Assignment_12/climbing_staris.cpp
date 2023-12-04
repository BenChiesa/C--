#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
        if(n<=2)
        return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
}

int main(){
    cout << climbStairs(0) << endl;
    cout << climbStairs(2) << endl;
    cout << climbStairs(5) << endl;
    cout << climbStairs(10) << endl;
}