#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)
int main(){
	int h,w;
	cin >> h >> w;
	rep(i,h)
	{
		rep(j,w){
		if(i == 0||i == h-1 || j == 0 || j ==w-1 )
			cout << "#";
		else
			cout << ".";
		}
		cout << endl;
	}
}
