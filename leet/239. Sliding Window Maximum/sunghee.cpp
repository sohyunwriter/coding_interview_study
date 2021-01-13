#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int vec_size = nums.size();
		vector<int> output;
		multiset<int> m_set;

		for (int i = 0; i < k; i++){
			m_set.insert(nums[i]);
		}
		output.emplace_back(*(--m_set.end()));

		for (int i = 0; i < vec_size - k; i++){
			m_set.erase(m_set.find(nums[i]));
			m_set.insert(nums[i + k]);
			output.emplace_back(*(--m_set.end()));
		}

		return output;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    Solution sol;
    vector<int> inp; int k, n;
    int tmp;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        inp.push_back(tmp);
    }

    sol.maxSlidingWindow(inp, k);
}