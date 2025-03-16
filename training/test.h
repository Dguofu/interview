#pragma once
#include<vector>
#include<climits>
#include<iostream>
class list {
	
	struct  Node
	{
		int value;
		 Node* next;
		 Node(int v) {
			 value = v;
			 next = nullptr;
		 }

	};
	Node* L;
	Node* r;
public:
	list():L(nullptr),r(nullptr){}
	void append(int value) {
		Node* tmp = new Node(value);
		if (!L) {
			L = tmp;
			r = L;
			return;
		}
		r->next = tmp;
		r = r->next;
	}
	void print() {
		using namespace  std;
		Node* p = L;
		while (p) {
			cout << p->value << (p->next ? "->" :"");
			p = p->next;
		}
	}
	~list() {
		Node* p = L;
		
		while (p) {
			Node* back = p->next;
			delete p;
			p = back;
		}
	}
};
int min(int a,int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}
//线性动态规划题目
int min_coin_numbers(std::vector<int>& coins,int sum) {

	using namespace std;
	if (coins.empty() || sum < 0)return -1;
	vector<int> dp(sum + 1,INT_MAX-100);
	dp[0] = 0;
	for (int i = 0; i < sum; i++)
	{
		for (int coin : coins) {
			if (i + coin <= sum) {
				dp[i + coin] = min(dp[i + coin], dp[i] + 1);
			}
		}
	}

	return dp[sum];
}
int max_money(std::vector<int>& moneys) {
	using namespace std;
	if (moneys.empty())return 0;
	int n = moneys.size();
	if (n == 1)return moneys[0];
	vector<int> result(n+1, 0);
	result[1] = moneys[0];
	for (int i = 2; i <=n ; i++)
	{
		result[i] = max(result[i - 1], result[i - 2] + moneys[i-1]);

	}
	return result[n];
}
int min_multipy_numbers(std::vector<int>& juzhen) {
	using namespace std;
	int n = juzhen.size() - 1;
	vector<vector<int>> result(n, vector<int>(n, INT_MAX));
	for (int i = 0; i < n; i++)
	{
		result[i][i] = 0;
	}
	for (int len = 2; len <=n; len++)
	{
		for (int i = 0; i < n-len+1; i++)
		{
			int j = i + len - 1;
			for (int k = i; k < j; k++)
			{
				result[i][j] = min(result[i][j], result[i][k] + result[k + 1][j] + juzhen[i] * juzhen[k + 1] * juzhen[j + 1]);
			}
			
		}
	}
	return result[0][n - 1];
	
}
int knapsack(int W, std::vector<int>& weights, std::vector<int>& values, int n) {
	
	std::vector<int> dp(W + 1, 0);

	for (int i = 0; i < n; ++i) {
		for (int j = W; j >= weights[i]; --j) {
			dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
		}
	}

	return dp[W];  // 返回背包容量为 W 时的最大价值
}