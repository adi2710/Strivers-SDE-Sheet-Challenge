#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int ans = 0, sign = 1;
    if(str[0] == '-')
        sign = -1;
    for(char ch : str)
    {
        if(isdigit(ch))
            ans = ans * 10 + ch - '0';
    }
    return ans * sign;
}