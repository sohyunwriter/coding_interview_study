#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int T, a, b;
    cin >> T;
    while(T--){
        int N, M, ans = 0;
        cin >> N >> M;
        set<int> book[1010];
        vector<int> stu[1010];

        for(int i = 0; i < M; i++){
            cin >> a >> b;
            for(int j = a; j <= b; j++){
               book[j].insert(i);
               stu[i].emplace_back(j);
            }
        }

        while(1){
            int minIdx, minSize = 99999;
            for(int i = 1; i <= N; i++){
                if(book[i].size() && (book[i].size() < minSize)){
                    minIdx = i;
                    minSize = book[i].size();
                }
            }
            if(minSize == 99999) break;

            int stuNum = *book[minIdx].begin();
            for(set<int>::iterator it = book[minIdx].begin(); it != book[minIdx].end(); it++){
                stuNum = stu[stuNum].size() > stu[*it].size() ? *it : stuNum;
            }
            
            for(int n : stu[stuNum])
                book[n].erase(stuNum);
            stu[stuNum].clear();
            book[minIdx].clear();
            ++ans;
        }

        cout << ans << "\n";
    }


}