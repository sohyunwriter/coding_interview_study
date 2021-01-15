#include <bits/stdc++.h>

using namespace std;

long long operation(long long num1, long long num2, char op){
    if(op == '*') return num1 * num2;
    if(op == '-') return num1 - num2;
    if(op == '+') return num1 + num2;
    return -1;
}

long long calc_with_priority(vector<long long> num, vector<char> op,
	int pr_times, int pr_minus, int pr_plus){
	map<char, int> pr_map;
	stack<long long> num_stk;
	stack<char> op_stk;
	int len = op.size();

	pr_map.insert(make_pair('*', pr_times));
	pr_map.insert(make_pair('-', pr_minus));
	pr_map.insert(make_pair('+', pr_plus));

	for (int i = 0; i < len; i++){
		if (op_stk.empty()){
			num_stk.push(num[i]);
			op_stk.push(op[i]);
		}
		else{
			long long targ = num[i];
			if (!(pr_map[op_stk.top()] < pr_map[op[i]])){
				while (!op_stk.empty() && pr_map[op_stk.top()] >= pr_map[op[i]]){
					targ = operation(num_stk.top(), targ, op_stk.top());
					num_stk.pop();
					op_stk.pop();

				}
			}
			num_stk.push(targ);
			op_stk.push(op[i]);
		}
	}

	return llabs(num_stk.top());

}

long long solution(string expression) {
	long long answer = -1;
	int len = expression.size();
	vector<long long> num;
	vector<char> op;

	for (int i = 0; i < len; i++){
		for (int j = i; j <= len; j++){
			if (expression[j] < 48){
				num.emplace_back(atol(expression.substr(i, j - i).c_str()));
				op.emplace_back(expression[j]);
				i = j;
				break;
			}
			if (j == len){
				num.emplace_back(atol(expression.substr(i, j - i + 1).c_str()));
				i = j;
			}
		}
	}
	answer = max(answer, calc_with_priority(num, op, 1, 2, 3));
	answer = max(answer, calc_with_priority(num, op, 1, 3, 2));
	answer = max(answer, calc_with_priority(num, op, 2, 1, 3));
	answer = max(answer, calc_with_priority(num, op, 2, 3, 1));
	answer = max(answer, calc_with_priority(num, op, 3, 1, 2));
	answer = max(answer, calc_with_priority(num, op, 3, 2, 1));
	
	return answer;
}

int main(){
    string exp;
    cin >> exp;
    solution(exp);
}