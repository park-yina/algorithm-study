#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10005
int dp[MAX][2];//우수마을 이거나 우수 마을이 아니거나의 경우의 수 밖에 없기 때문
vector<vector<int>>v;
int n, a, b;//마을의 숫자와 인접 마을의 index를 표현하기 위한 변수
int citi[MAX];
bool visit[MAX];
void dfs(int cur) {
	if (visit[cur])return;//이미 방문한 곳이면 다시 방문을 할 필요가 없음
	dp[cur][0] = 0;//우수 마을일 때에만 마을 주민의 수를 계산해야 하기 때문에 비 우수 마을은 주민의 숫자를 0으로 설정
	dp[cur][1] = citi[cur];
	visit[cur] = true;
	for (int next:v[cur]) {
		if (visit[next])continue;
		dfs(next);
		dp[cur][0] = dp[cur][0] + max(dp[next][0], dp[next][1]);//일반 마을은 무조건적으로 우수 마을과 인접해야하기 때문
		dp[cur][1] = dp[cur][1] + dp[next][0];
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> citi[i];
	}
	v.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}