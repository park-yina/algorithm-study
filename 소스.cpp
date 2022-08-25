#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10005
int dp[MAX][2];//������� �̰ų� ��� ������ �ƴϰų��� ����� �� �ۿ� ���� ����
vector<vector<int>>v;
int n, a, b;//������ ���ڿ� ���� ������ index�� ǥ���ϱ� ���� ����
int citi[MAX];
bool visit[MAX];
void dfs(int cur) {
	if (visit[cur])return;//�̹� �湮�� ���̸� �ٽ� �湮�� �� �ʿ䰡 ����
	dp[cur][0] = 0;//��� ������ ������ ���� �ֹ��� ���� ����ؾ� �ϱ� ������ �� ��� ������ �ֹ��� ���ڸ� 0���� ����
	dp[cur][1] = citi[cur];
	visit[cur] = true;
	for (int next:v[cur]) {
		if (visit[next])continue;
		dfs(next);
		dp[cur][0] = dp[cur][0] + max(dp[next][0], dp[next][1]);//�Ϲ� ������ ������������ ��� ������ �����ؾ��ϱ� ����
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