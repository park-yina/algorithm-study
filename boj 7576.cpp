#include<iostream>
#include<queue>//큐를 사용하여 bfs를 채워준다.
#include<algorithm>
#include<utility>
#include<string>
using namespace std;
int a[1001][1001];//토마토를 표현
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int n, m;
int visit[1001][1001];

void bfs() {
	queue<pair<int,int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				q.push({ i,j });
			}
			if (a[i][j] == 0) {
				visit[i][j] = -1;
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (visit[nx][ny] >= 0)continue;
			q.push({ nx,ny });
			visit[nx][ny] = visit[cur.first][cur.second] + 1;
		}
	}
}
int cal() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == -1)return -1;
			res = max(res, visit[i][j]);
		}
	}
	return res;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	bfs();
	cout << cal();
	return 0;
}
