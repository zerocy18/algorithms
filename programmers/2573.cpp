#pragma warning(disable:4996)
#include<stdio.h>
#include <queue>
#define P pair<int, int>
using namespace std;

int N, M;
int area[300][300];
bool visit[300][300];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &area[i][j]);
		}
	}
}

bool edgeSea(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (area[nx][ny] > 0) {
				return true;
			}
		}
	}
	return false;
}

void melting(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (area[nx][ny] > 0) {
				area[nx][ny]--;
			}
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			if (!visit[nx][ny] && area[nx][ny] > 0) {
				dfs(nx, ny);
			}
		}
	}
}

void setVisit() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visit[i][j] = false;
}

int main() {
	int answer = 0;
	input();
	while (true) {
		queue<P> q;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (area[i][j] == 0 && edgeSea(i, j)) {
					q.push(P(i, j));
				}
			}
		}
		while (!q.empty()) {
			P cur = q.front();
			q.pop();
			melting(cur.first, cur.second);
		}
		//이어져있는지 확인(dfs)
		int cnt = 0;
		setVisit();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (area[i][j] > 0 && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		answer++;
		if (cnt >= 2) {
			printf("%d\n", answer);
			break;
		}
		if (cnt == 0) {
			printf("0");
			break;
		}
	}
	return 0;	
}
