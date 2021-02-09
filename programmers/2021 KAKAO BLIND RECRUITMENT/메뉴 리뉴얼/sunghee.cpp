#include <bits/stdc++.h>

using namespace std;
vector<int> orderbits;
vector<int> courses[11];
vector<int> cases;

void getAllCases(int now, int left, int cnt) {
    if (cnt < 0) {
        cases.emplace_back(now);
        return;
    }
    if (left < 0) return;
    getAllCases(now | (1 << left), left - 1, cnt - 1);
    getAllCases(now, left - 1, cnt);
}

int getBits(string order) {
    int bit = 0;
    int len = order.length();
    for (int i = 0; i < len; i++)
        bit |= (1 << (order[i] - 'A'));
    return bit;
}

string bitsToString(int bit) {
    char output[11] = { 0 };
    for (int i = 0; i < 26; i++) {
        if ((bit & (1 << i)) == (1 << i)) {
            output[strlen(output)] = 'A' + i;
        }
    }
    output[strlen(output)] = 0;
    return string(output);
}

void compAll(int courseNum) {
    map<int, int> counter;
    for (auto& cs : cases)
        for (auto& e : orderbits) {
            if ((e & cs) == cs) {
                if (counter.find(cs) == counter.end())
                    counter.insert(make_pair(cs, 1));
                else
                    counter[cs] += 1;
            }
        }
    vector<pair<int, int>> sorter;
    for (auto iter = counter.begin(); iter != counter.end(); ++iter)
        sorter.emplace_back(make_pair(iter->first, iter->second));

    sort(sorter.begin(), sorter.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
        });

    int def = sorter[0].second;
    for (auto& e : sorter) {
        if (e.second != def || e.second < 2) break;
        courses[courseNum].emplace_back(e.first);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto& e : orders) {
        int orderbit = getBits(e);
        orderbits.emplace_back(orderbit);
    }
    for (auto& e : course) {
        cases.clear();
        getAllCases(0, 26, e - 1);
        compAll(e);
        for (int& i : courses[e]) {
            answer.emplace_back(bitsToString(i));
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
