//https://leetcode.com/problems/decode-ways/description/
/*You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int str_int(string s){
        if(s.size()==1) return s[0]-'0';
        return (s[0]-'0')*10 + (s[1]-'0');
    }
    int f(string str, int idx){
        if(str[idx]=='0') return 0;
        if(idx>=str.size()) return 0;
        if(idx==str.size()-1){
            if(str[idx]=='0') return 0;
            else {
                return 1;
            }
        }
        if(idx==str.size()-2){
        bool can_form_2_digits = str_int(str.substr(idx,2))<=26;
        return can_form_2_digits + f(str,idx+1);
        }

        if(dp[idx]!=-1) return dp[idx];

        bool can_form_2_digits = str_int(str.substr(idx,2))<=26;
        return dp[idx] = f(str,idx+1) + ((can_form_2_digits) ? f(str,idx+2):0);
    }
    int numDecodings(string s) {
        dp.clear();
        dp.resize(105,-1);
        return f(s,0);
    }
};