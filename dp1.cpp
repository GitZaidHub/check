#include<iostream>
#include<vector>
using namespace std;

vector<int> dp; // dp-> array it will store the value of n that has been computed first
int fTopDown(int n){// this is approach is also called memoization
    if(n==0 || n==1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n]=fTopDown(n-1)+fTopDown(n-2);
}

int fbottomUp(int n){// tabulation smallest subproblem to top subproblem
    dp.resize(n+1,-1);
    dp[0]=0;
    dp[1] =1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fbottomUpO(int n){
    dp.resize(n+1,-1);
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n=7;
    dp.resize(n+1,-1);
    cout<<fTopDown(n)<<endl;
    cout<<fbottomUp(n)<<endl;
    cout<<fbottomUpO(n)<<endl;
    return 0;
}