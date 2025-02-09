#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using  namespace std;
#define int long long

int n, m, k, s;
int sd[100001][101];
//sd[i][j]: Shortest distance of town i to product j.
int a[100001] {0};
vector<int>gr[100001];

void Solve() {

	memset(sd, -1, sizeof(sd));
	queue<int>q;

	for (int product = 1; product <= k; product++) {

		/*
			Ye Product Kaunse Kaunse town me banaya jata hain.
			and distance of that town to current product is zero.
		*/

		for (int i = 1; i <= n; i++) {
			if (a[i] == product) {
				sd[i][product] = 0;
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto child : gr[node]) {
				if (sd[child][product] == -1) {
					q.push(child);
					sd[child][product] = sd[node][product] + 1;
				}
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		sort(sd[i] + 1, sd[i] + k + 1);

		int ans = 0;

		for (int j = 1; j <= s; j++) {
			ans += sd[i][j];
		}

		cout << ans << " ";
	}

	cout << endl;

}

int32_t main() {
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	Solve();

}