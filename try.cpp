#include<iostream>
using namespace std;

int str_to_int(string s){
    if(s.size()==1) return s[0]-'0';
    return (s[0] -'0')*10 +(s[1]-'0');
}

int f(string s , int idx){
    if(idx>=s.size()) return 0;
    if(idx==s.size()-1) {
        if(s[idx]=='0') return 0;
        else{
            return 1;
        }
    }
    if(idx==s.size()-2){
    bool can_form_2_digits = str_to_int(s.substr(idx,2))<=26;
    return can_form_2_digits +f(s,idx+1);
        
    }
    bool can_form_2_digits = str_to_int(s.substr(idx,2))<=26;
    return f(s,idx+1) + ((can_form_2_digits) ? f(s,idx+2) : 0);

}

int main(){
    cout<<str_to_int("125");
    return 0;
}