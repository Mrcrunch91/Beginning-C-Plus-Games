/*
 * Scrabble.cpp
 *
 *  Created on: Oct 5, 2019
 *      Author: natedogg
 */

#include "Scrabble.h"
#include "unordered_map"

using namespace std;

string replaceDots(const string &theString);
vector<int> twoSum(vector<int> &nums, int target);
int numberOfSteps(int num);
int factorial(int num);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int main() {

	vector<int> vi = { 0, 4, 0, 3 };

	vector<int> v = twoSum(vi, 0);

	TreeNode* theR = new TreeNode(7);
	theR->val = 0;
	theR->left = NULL;
	theR->right = NULL;

	for (uint i = 0; i < v.size(); i++) {
		//cout << v[i] << "";
	}

	cout << theR << "";
	return 0;
}

int rangeSumBST(TreeNode* root, int L, int R) {
		if((root->val < L) | (root->val > R)){
			return root->val;
		}else if(root->val == 0){
			return 0;
		}

		return rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
}

int factorial(int num){

	if(num == 1) return num;
	if(num == 0) return 1;


	return num * factorial(num -1) * factorial(num -2);
}

//if you divide by two and the result is even, return result, else subtract one and return
int numberOfSteps(int num) {
	int step = 0;

	do {
		step++;

		if ((num % 2) == 0) {
			 num /= 2;
		} else{
		 num -= 1;
		}
	}while (num > 0);

	return step;
}

string replaceDots(const string &theString) {

	string hold;

	for (uint i = 0; i < theString.size(); i++) {

		char a = theString[i];

		if (a == '.') {
			hold += "[.]";
		} else {
			hold += a;
		}
	}

	return hold;
}

vector<int> twoSum(vector<int> &nums, int target) {

	//New method, create a hash table and add all the values.
	//Iterate through the list from low to high, and subtract the value from the target
	//Then search hash for complementary value, then return position of the value in hash
	vector<int> hold;

	unordered_map<int, size_t> umap;

	for (int i = 0; i < int(nums.size()); i++) {

		int a = nums[i];

		if (umap.count(target - a)) {
			hold.push_back(umap[target - a]);
			hold.push_back(i);
		} else {
			umap.insert( { a, i });
		}

	}

	return hold;
}
;

