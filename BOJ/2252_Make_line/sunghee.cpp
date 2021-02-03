#include <bits/stdc++.h>
using namespace std;

vector <int> tree[32005];
vector <int> stk;
int chkW[32005];

void dfs(int cur){
	chkW[cur] = 1;
	for (auto next : tree[cur]){
		if (!chkW[next])
			dfs(next);
	}
	stk.push_back(cur);
}

int main(){
	int v, e, i, a, b;
	cin >> v;
	cin >> e;
	for (i = 0; i < e; i++){
		cin >> a;
		cin >> b;
		tree[a].push_back(b);
	}
	for (i = 1; i <= v; i++){
		if (!chkW[i])
			dfs(i);
	}
	while (stk.size() != 0){
		cout << stk[stk.size() - 1] << " ";
		stk.pop_back();
	}
	return 0;
}