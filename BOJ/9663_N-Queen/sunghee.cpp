#include <bits/stdc++.h>

using namespace std;
int chess_map[15][15];
int N;

void inline set_queen(int i, int j, int val) {
	for (int r = 0; r < N; r++) {
		chess_map[r][j] += val;
		if (i + r < N) {
			if (j + r < N)
				chess_map[i + r][j + r] += val;
			if (j - r >= 0)
				chess_map[i + r][j - r] += val;
		}
	}

	chess_map[i][j] -= val * 2;
}

int solution(int i, int j, int cnt) {
	if (!cnt) return 1;
	int output = 0;

	set_queen(i, j, 1);

	for (int r = 0; r < N; r++) {
		if (!chess_map[i + 1][r])
			output += solution(i + 1, r, cnt - 1);
	}

	set_queen(i, j, -1);
	return output;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += solution(0, i, N - 1);

	cout << ans;

}