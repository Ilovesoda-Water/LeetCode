#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cmath>
using namespace std;
int lengthOfLongestSubstring(string s) {
    map<char,int> m;
    int start = 0;
    int max_len = 0;
    for (int i=0;i<s.length();i++){
        if (m.count(s[i]) == 0 || m.count(s[i])>0&&m[s[i]]<start){
            m[s[i]] = i;
            max_len = max(i-start+1, max_len);
        }
        else{
            start = m[s[i]] + 1;
            m.erase(s[i]);
            m[s[i]] = i;
        }
    }
    return max_len;
}

int main(){
    string s = "pwwkew";
    printf("%d\n", s.length());
    int max_len = lengthOfLongestSubstring(s);
    printf("%d\n", max_len);
    return 0;
}
