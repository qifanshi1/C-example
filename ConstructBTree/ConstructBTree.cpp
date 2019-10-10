#include<vector>
using namespace std;
extern  int a=0;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	TreeNode* ConstructBTree(const vector<int>& pre, int pre_begin, int pre_end,
		const vector<int>& vin, int vin_begin, int vin_end)
	{
		TreeNode* root = new TreeNode(pre[pre_begin]);
		if (pre_begin == pre_end)
		{
			if (vin_begin == vin_end)
			{
				return root;
			}
			else
				return NULL;
		}
		int i = vin_begin;
		for (; i <= vin_end; i++)
		{
			if (vin[i] == root->val)
				break;
		}
		int length1 = i - vin_begin;
		int length2 = vin_end - i;
		if (length1 > 0)
		{
			root->left = ConstructBTree(pre, pre_begin + 1, pre_begin + length1,
				vin, vin_begin, vin_begin + length1 - 1);
		}
		if (length2 > 0)
		{
			root->right = ConstructBTree(pre, pre_begin + length1 + 1, pre_begin + length1 + length2,
				vin, vin_begin + length1 + 1, vin_begin + length1 + length2);
		}
		return root;

	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty() || pre.size() != vin.size())
			return NULL;
		return ConstructBTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);

	}
};
int main()
{
	
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	Solution solution;
	TreeNode* root = solution.reConstructBinaryTree(pre, vin);
	//throw new exception("queue is empty!");
	system("pause");
	return 0;
}