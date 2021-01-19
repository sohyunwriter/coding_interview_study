#include <bits/stdc++.h>

using namespace std;
int V, E, K;
vector<pair<int, int>> vertex[20200];
bool visited[20200];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int dist[20200];
    cin >> V >> E >> K;

    fill(dist, dist+20200, INT_MAX);
    dist[K] = 0;
    
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vertex[u].emplace_back(make_pair(w, v));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, K));
    
    while(!q.empty()){
        pair<int, int> curr = q.top();
        q.pop();
        if(visited[curr.second]) continue;

        for(auto &p : vertex[curr.second]){
            int nx = p.second, w = p.first;
            if(dist[curr.second] + w < dist[nx]){
                dist[nx] = dist[curr.second] + w;
                q.push(make_pair(dist[nx], nx));
            }
        }
    }

    for(int i = 1; i <= V; i++){
        if(dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }

}