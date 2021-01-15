#include <bits/stdc++.h>

using namespace std;
int N, K;
int bro_pos[500500];
int even[500500];
int odd[500500];
int min_meet, max_time, chk;
queue<pair<int, int>> q_visit;

int main(){
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	min_meet = 9999999;
	int k = K;

	memset(bro_pos, -1, sizeof(bro_pos));
	for (max_time = 0; max_time < 1010; max_time++){
		if (k + max_time > 500000) break;
		bro_pos[k += max_time] = max_time;
	}
	fill(odd, odd + 500500, 9999999);
	fill(even, even + 500500, 9999999);
	int now = N, cnt = 0;
	q_visit.push(make_pair(now, cnt));

	while (!q_visit.empty()){
		now = q_visit.front().first;
		cnt = q_visit.front().second;
		q_visit.pop();
		if (cnt >= min_meet || cnt >= max_time || now > 500000 || now < 0) continue;
		if (cnt % 2){
			if (odd[now] <= cnt) continue;
			odd[now] = cnt;
		}
		else{
			if (even[now] <= cnt) continue;
			even[now] = cnt;
		}
		if (bro_pos[now] != -1){
			if ((bro_pos[now] % 2 == cnt % 2) && bro_pos[now] >= cnt && bro_pos[now] < min_meet){
				min_meet = bro_pos[now];
			}
		}
		q_visit.push(make_pair(now * 2, cnt + 1));
		q_visit.push(make_pair(now - 1, cnt + 1));
		q_visit.push(make_pair(now + 1, cnt + 1));
	}

	cout << (min_meet == 9999999 ? -1 : min_meet);

}