#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

int road[500100][2];

bool check(int i) {
	if (i >= 0 && i <= 500000) {
		return true;
	}
	return false;
}
int main() {
	for (int i = 0; i < 500001; i++) {
		road[i][0] = -1;
		road[i][1] = -1;
	}

	int n, k;
	cin >> n >> k;
	
	int j = 0;
	
	if (n == k) {
		cout << 0 << endl;
		return 0;
	}
	
	queue<int>q;
	q.push(n);
	road[n][0] = 0;
	int cnt = 1;
	while (!q.empty()) {
		int len = q.size();
		
		while (len--) {
			int pos = q.front(); q.pop();
			if (check(pos - 1) && road[pos - 1][cnt % 2] == -1) {
				q.push(pos - 1);
				road[pos - 1][cnt % 2] = cnt;
			}
			if (check(pos + 1) && road[pos + 1][cnt % 2] == -1) {
				q.push(pos + 1);
				road[pos + 1][cnt % 2] = cnt;
			}
			if (check(pos * 2) && road[pos * 2][cnt % 2] == -1) {
				q.push(pos * 2);
				road[pos * 2][cnt % 2] = cnt;
			}
		}
		cnt++;
	}
	j = 0;
	int min = 5000000;

	for (; k <= 500000; k += ++j) {
		if (j >= road[k][j % 2] && min > j) {
			min = j;
		}
	}
	
	if (min == 5000000) {
		cout << -1;
	}
	else {
		cout << min;
	}
}
