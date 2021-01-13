#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;

        int left = 0;
        deque<int> dq;
        for (int right = 0; right < nums.size(); right++) {
            while (dq.size() > 0 && dq.back() < nums.at(right)) {
                dq.pop_back();
            }
            dq.push_back(nums.at(right));
            if (right - left == k - 1) {
                v.push_back(dq.front());
                if (dq.front() == nums.at(left)) {
                    dq.pop_front();
                }
                left++;
            }
        }

        return v;
    }
};

int main() {
    vector<int> nums1 = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k1 = 3;
    vector<int> ans1 = Solution::maxSlidingWindow(nums1, k1); // [3,3,5,5,6,7]
    for (int i = 0; i < ans1.size(); i++)
        cout << ans1[i] << " ";
    cout << "\n";

    vector<int> nums2 = { 1 };
    int k2 = 1;
    vector<int> ans2 = Solution::maxSlidingWindow(nums2, k2); // [1]
    for (int i = 0; i < ans2.size(); i++)
        cout << ans2[i] << " ";
    cout << "\n";

    vector<int> nums3 = { 1, -1 };
    int k3 = 1;
    vector<int> ans3 = Solution::maxSlidingWindow(nums3, k3); // [1,-1]
    for (int i = 0; i < ans3.size(); i++)
        cout << ans3[i] << " ";
    cout << "\n";

    vector<int> nums4 = { 9, 11 };
    int k4 = 2;
    vector<int> ans4 = Solution::maxSlidingWindow(nums4, k4); // [11]
    for (int i = 0; i < ans4.size(); i++)
        cout << ans4[i] << " ";
    cout << "\n";

    vector<int> nums5 = { 4, -2 };
    int k5 = 2;
    vector<int> ans5 = Solution::maxSlidingWindow(nums5, k5); // [4]
    for (int i = 0; i < ans5.size(); i++)
        cout << ans5[i] << " ";
    cout << "\n";

    vector<int> nums6 = { 1, 3, 1, 2, 0, 5 };
    int k6 = 3;
    vector<int> ans6 = Solution::maxSlidingWindow(nums6, k6); // [3, 3, 2, 5]
    for (int i = 0; i < ans6.size(); i++) 
        cout << ans6[i] << " ";
    cout << "\n";

    return 0;
}
