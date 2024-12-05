/*Tere are N stones numbered 1,2,3,....N for each each i (1<=i<=N), the heights of stones i is hi;
There is a frog who is currently on stone 1 . He will repeat the following actions some number of times to reach Stones N;
  if the frog is currently on stone i. jump to one of the following : Stone i+1 ,i+2,...i+k. Hence, a cost of |hi-hj| is incurred ,where j is the
  stone to land on.
  Find the minimum possible total cost incurred before the frog reaches the Stone N.*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int ftb(vector<int> height , int idx, int k){
    if(idx==height.size()-1) return 0;
    int ans = INT16_MAX;
    if(dp[idx] != -1 ) return dp[idx];
    for(int j=1;j<=k;j++){
        if(idx +j < height.size()){
            ans =min(ans,abs(height[idx] - height[idx+j]) + ftb(height,idx+j,k));
        }
    }
    return dp[idx] = ans;
}

int main(){
    int n,k;
    cout<<"Enter ele"<<endl;
    cin>>n>>k;
    dp.clear();
    dp.resize(10005,-1);
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<<ftb(heights,0,k);
    return 0;
}