#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int K, S[20];

void combination(int start, int r){
    if(!r){
        for(int &n : vec) cout << n << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < K - r + 1; i++){
        vec.emplace_back(S[i]);
        combination(i + 1, r - 1);
        vec.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    while(1){
        cin >> K;
        if(!K) break;

        for(int i = 0; i < K; i++)
            cin >> S[i];
        
        combination(0, 6);
        cout << "\n";
    }
}