#include<cmath>
#include<malloc.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include"smartPtr.h"
using namespace std;
long power(long base, long exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	long result = power(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;
	return result;
}
bool isFlower(int num)
{
	int sum = 0;
	int num1 = num;
	while (num1 > 0)
	{
		int temp = num1 % 10;
		sum += (temp*temp*temp);
		num1 /= 10;
	}
	if (sum == num)
		return true;
	else
		return false;
}
void FlowerNum(vector<int>& res)
{
	for (int i = 100; i <= 999; i++)
	{
		if (isFlower(i))
			res.push_back(i);
	}
}

vector<int> construct(int n, int m)
{
	vector<int> nums;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			nums.push_back(i);
		}
	}
	return nums;
}

void helper(vector<int> &vec, int start, int k, int times, vector<int> &tmpres,
	long& count)
{
	if (vec.size() - start < k)return;
	if (k == 0)
	{
		count++;
		return;
	}
		
	if (start == 0 || vec[start] != vec[start - 1])//当前元素前面没有出现过
	{
		//选择vec[start]
		tmpres.push_back(vec[start]);
		helper(vec, start + 1, k - 1, 1, tmpres,count);
		tmpres.pop_back();
		//不选择vec[start]
		helper(vec, start + 1, k, 1, tmpres,count);
	}
	else//当前元素前面出现过
	{
		if (tmpres.size() >= times && tmpres[tmpres.size() - times] == vec[start])
		{
			//只有当tmpres中包含times个vec[start]时，才选择vec[start]
			tmpres.push_back(vec[start]);
			helper(vec, start + 1, k - 1, times + 1, tmpres,count);
			tmpres.pop_back();
		}
		helper(vec, start + 1, k, times + 1, tmpres,count);
	}
}

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};
int getDepth(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	int left = getDepth(node->left);
	int right = getDepth(node->right);
	return max(right, left) + 1;
}
TreeNode* ConstructTree(vector<vector<int>> input)
{
	int len = input.size();
	vector<TreeNode*> vec_tree(len,nullptr);
	for (int i = 0; i < len; i++)
	{
		TreeNode* node = vec_tree[i];
		if (vec_tree[i] == nullptr)
		{
			node = new TreeNode(input[i][0]);
			vec_tree[i] = node;	
		}
		if (input[i][1] != -1)
		{
			TreeNode* left = vec_tree[input[i][1]];
			if (left == nullptr)
			{
				left = new TreeNode(input[input[i][1]][0]);
				vec_tree[input[i][1]] = left;
			}	
			node->left = left;
		}
		if (input[i][2] != -1)
		{
			TreeNode* right = vec_tree[input[i][2]];
			if (right == nullptr)
			{
				right = new TreeNode(input[input[i][2]][0]);
				vec_tree[input[i][2]] = right;
			}	
			node->right = right;
		}
	}
	TreeNode* res = nullptr;
	int depth = -1;
	for (int i = 0; i < vec_tree.size(); i++)
	{
		int dep = getDepth(vec_tree[i]);
		if (dep > depth)
		{
			depth = dep;
			res = vec_tree[i];
		}
	}
	return res;
}
void PreOrder(TreeNode* pNode)
{
	if (!pNode)
		return;
	cout << pNode->val << endl;
	PreOrder(pNode->left);
	PreOrder(pNode->right);
}
bool isAscend(TreeNode* node)
{
	if (!node || (!node->left && !node->right))
		return true;
	queue<TreeNode*> que;
	int pre_max_val = node->val;
	que.push(node);
	while (!que.empty())
	{
		int len = que.size();
		int cur_max_val = INT_MIN;
		while (len > 0)
		{
			TreeNode* temp = que.front();
			que.pop();
			len--;//一定要len--，否则循环不会跳出
			if (temp->left)
			{
				que.push(temp->left);
				if (temp->left->val < pre_max_val)
					return false;
				else if(temp->left->val>cur_max_val)
				{
					cur_max_val = temp->left->val;
				}
			}
			if (temp->right)
			{
				que.push(temp->right);
				if (temp->right->val < pre_max_val)
					return false;
				else if (temp->right->val > cur_max_val)
				{
					cur_max_val = temp->right->val;
				}
			}
		}
		pre_max_val = cur_max_val;
	}
	return true;
}
int main()
{
	vector<vector<int>> input = { {2,-1,-1},{1,5,3},{4,-1,6},{2,-1,-1},{3,0,2},
	{2,4,7},{7,-1,-1},{2,-1,-1} };

	TreeNode* pNode = ConstructTree(input);
	PreOrder(pNode);
	bool flag = isAscend(pNode);
	system("pause");
	return 0;
}