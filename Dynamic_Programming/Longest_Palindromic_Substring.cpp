#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int isPal[1000][1000];
string longestPalindrome(string s) {
    int l = s.length();
    int startIndex;
    int endIndex;
    for (int i=0;i<l;i++)
        isPal[i][i] = 1;
    for (int i=0;i<l-1;i++)
        if (s[i]==s[i+1])
        isPal[i][i+1] = 1;
    for (int i=0;i<l;i++)
    for (int j=i;j<l;j++){
        if (isPal[i][j]){
            startIndex = i;
            endIndex = j;
            while(startIndex-1>=0&&endIndex+1<l){
                if (s[startIndex-1]==s[endIndex+1]){
                    isPal[startIndex-1][endIndex+1] = 1;
                    startIndex--;
                    endIndex++;
                }
                else
                    break;
            }
        }
    }
    int max_l = 0;
    string pal = "";
    for (int i=0;i<l;i++){
        for (int j=0;j<l;j++)
            if (isPal[i][j]==1&&j-i+1>max_l){
                max_l = j-i+1;
                pal.assign(s, i, j-i+1);
            }
    }
    return pal;
}

int main(){
    string s = "abcda";
    string pal = longestPalindrome(s);
    cout<<pal;
    return 0;
}
