#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n; i++)
int main(){
	int m,d;
	cin >> m >> d;
	if (m == d)
		{
			if(m == 3)
				cout << "Yes";
			else if(m == 5)
				cout << "Yes";
			else if(m == 7)
				cout << "Yes";
			else if(m == 9)
				cout << "Yes";
			else
				cout << "No";
			return(0);
		}
	else if (m == 1 && d ==7)
		cout << "Yes";
	else
		cout << "No";
}
