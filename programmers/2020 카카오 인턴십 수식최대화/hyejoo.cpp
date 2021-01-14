#include <string> 
#include <vector> 
#include <algorithm> 
#include <iostream> 

using namespace std; 

long long calculation(long long oprand1, long long oprand2, char op) {
    switch(op) { 
    case '+': 
        return oprand1 + oprand2;
    case '-': 
        return oprand1 - oprand2;
    case '*':
        return oprand1 * oprand2;
    } 
} 

long long solution(string expression) { 
    long long answer = 0;

    vector<char> ops; 
    vector<long long> nums; 
    
    int idx = 0; 
    for (int i = 0; i < expression.size(); i++) { 
        if (!isdigit(expression[i])) { 
            ops.push_back(expression[i]); 
            nums.push_back(stoi(expression.substr(idx, i - idx))); 
            idx = i + 1; 
        } 
    } 
    nums.push_back(stoi(expression.substr(idx))); 
    
    vector<char> order = { '+','-', '*' };
    int oper_len = ops.size(); 
    vector<char> temp_ops; 
    vector<long long> temp_nums; 
    int temp_len; 
    
    do { 
        temp_ops = ops; 
        temp_nums = nums;
        temp_len = oper_len; 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < temp_len; j++) { 
                if (temp_ops[j] == order[i]) { 
                    temp_nums[j] = calculation(temp_nums[j], temp_nums[j + 1], temp_ops[j]); 
                    temp_nums.erase(temp_nums.begin() + j + 1); 
                    temp_ops.erase(temp_ops.begin() + j); 
                    temp_len--; 
                    j--; 
                }
            }
        }
        if (answer < abs(temp_nums[0])) 
            answer = abs(temp_nums[0]); 
    }
    
    while (next_permutation(order.begin(), order.end())); 
    return answer;
}

int main() {
    string expression1 = "100-200*300-500+20";
    cout << solution(expression1) << endl; // 60420

    string expression2 = "50*6-3*2";
    cout << solution(expression2) << endl; // 300

    return 0;
}
