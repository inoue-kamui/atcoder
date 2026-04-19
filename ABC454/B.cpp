#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> clothes(m,0);
    bool flag = true;
    rep(i,n){
        int f;
        cin >>f;
        clothes[f-1]++;
    }
    rep(i,n){
        if (clothes[i] >= 2)
            flag =false;
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


        flag = true;
        rep(i,n){
            if (clothes[i] == 0)
                flag =false;
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
}
