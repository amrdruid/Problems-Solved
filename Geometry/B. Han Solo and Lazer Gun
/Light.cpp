//http://codeforces.com/contest/514/problem/B
#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define all(v) (v).begin( ), (v).end( )
double pi = 3.1415926536;
const int oo = (int) 1e9;
const long long OO = numeric_limits<long long>::max();

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int f1[] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
int f2[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int shot[10001];
int main(){
ios_base::sync_with_stdio(false);
//cout.setf(ios::fixed);
//cin.tie(NULL);
//cout.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

	int n , x , y;
	cin >> n >> x >> y;

	vector<pair<int,int> > myvec(n);
	for(int i = 0 ; i < n ; i++){
		int a , b;
		cin >> a >> b;
		myvec[i] = make_pair(a,b);
	}

	int res = 0;
	for(int i = 0 ; i < sz(myvec) ; i++){
		int a = myvec[i].first;
		int b = myvec[i].second;

		if(!shot[i]){
			res++;
			shot[i] = 1;
			int deltaX = x - a;
			int deltaY = y - b;

			for(int j = 0 ; j < sz(myvec) ; j++){

				if(!shot[j]){
					int newDeltaX = x - myvec[j].first;
					int newDeltaY = y - myvec[j].second;
					if( (deltaX * newDeltaY) == (deltaY * newDeltaX)){
						shot[j] = 1;
					}
				}
			}
		}
	}

	cout << res;

	return 0;
}
