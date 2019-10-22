
#pragma region 449_���л��ͷ����л�����������
/*
���л��ǽ����ݽṹ�����ת��Ϊһϵ��λ�Ĺ��̣��Ա������Դ洢���ļ����ڴ滺�����У�
��ͨ������������·���䣬�Ա��Ժ���ͬһ������һ��������������ؽ���
���һ���㷨�����л��ͷ����л������������� �����л�/�����л��㷨�Ĺ�����ʽû�����ơ�
��ֻ��ȷ�������������������л�Ϊ�ַ��������ҿ��Խ����ַ��������л�Ϊ����Ķ�����������
������ַ���Ӧ�����ܽ��ա�
ע�⣺��Ҫʹ�����Ա/ȫ��/��̬�������洢״̬�� ������л��ͷ����л��㷨Ӧ������״̬�ġ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/serialize-and-deserialize-bst
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	// Runtime: 32 ms, faster than 61.08% of C++ online submissions for Serialize and Deserialize BST.
	// Memory Usage : 26.6 MB, less than 26.92 % of C++ online submissions for Serializeand Deserialize BST.
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		foreSerialize(root, res);
		return res;
	}

	// ǰ����� ���л�
	void foreSerialize(TreeNode* root, string& res)
	{
		if (root == NULL)
		{
			res += "#_";
			return;
		}
		res += to_string(root->val) + "_";
		foreSerialize(root->left, res);
		foreSerialize(root->right, res);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> list = split(data, '_');
		int index = 0;
		TreeNode* res = ForeDeserizlize(list, index);
		return res;
	}

	TreeNode* ForeDeserizlize(vector<string>& str, int& index)
	{
		if (str[index] == "#")
		{
			++index;
			return NULL;
		}
		TreeNode* root = new TreeNode(stoi(str[index++]));
		root->left = ForeDeserizlize(str, index);
		root->right = ForeDeserizlize(str, index);
		return root;
	}

	vector<string> split(const string& str, char delim) {
		vector<string> list;
		int begin = 0;
		while (begin < str.size())
		{
			int sIndex = str.find(delim, begin);
			if (sIndex != str.npos)
			{
				list.push_back(str.substr(begin, sIndex - begin));
				begin = sIndex + 1;
			}
			else
			{
				list.push_back(str.substr(begin));
				break;
			}
		}

		return list;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#pragma endregion
