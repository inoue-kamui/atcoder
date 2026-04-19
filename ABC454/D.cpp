#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)



string func(string a)
{
    string s;
    rep(i,a.size())
    {
        s.push_back(a[i]);
        while(s.size() >= 4){
            int n = s.size();
            if(s[n-4]=='(' && s[n-3] == 'x' && s[n-2]=='x' && s[n-1] == ')')
                {
                    rep(j,4) s.pop_back();
                    rep(j,2) s.push_back('x');
                }
            else
                break;
        }
    }
    return s;
}


int main(){
    int t;
    cin >> t;
    string a,b;
    rep(i,t)
    {
        cin >> a >> b;
        cout << ((func(a) == func(b)) ? "Yes" :"No");
        cout << "\n";
    }
}
