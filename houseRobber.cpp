/* You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have
 security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
 */

#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int f(int i, vector<int>& arr){
    if(i>=arr.size()) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] =  max(arr[i]+f(i+2,arr) , f(i+1,arr));
}
 
int rob(vector<int>& nums){
    dp.resize(nums.size()+10,-1);
    return f(0,nums);
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout<<rob(nums);
    return 0;
}