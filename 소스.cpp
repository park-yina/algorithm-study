#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321
#define MAX 10001
using namespace std;
int t, n, d, c;//테스트 케이스,컴개수,의존성개수,해킹인덱스
int dp[MAX];
void daik(vector<pair<int, int>>edge[]) {
	dp[c] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,c });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dis = pq.top().first;
		pq.pop();
		if (dp[cur] < dis)
			continue;
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int ndis = dis + edge[cur][i].second;
			if (ndis < dp[next]) {
				dp[next] = ndis;
				pq.push({ ndis,next });
			}
		}
	}
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] != INF) {
			cnt++;
			ans = max(ans, dp[i]);
		}
	}
	cout << cnt << " " << ans << "\n";
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		vector<pair<int, int>>edge[MAX];
		cin >> n >> d >> c;
		int a, b, s;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			edge[b].push_back({ a,s });
		}
		fill_n(dp, MAX, INF);
		daik(edge);
	}
	return 0;
}