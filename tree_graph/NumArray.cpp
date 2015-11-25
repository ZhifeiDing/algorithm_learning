#include "leetcode.hpp"

/*
 * Given an integer array nums, find the sum of the elements between 
 * indices i and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element 
 * at index i to val.
 * Example:
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function 
 * is distributed evenly.
 */

/*
 * segment tree solution
 */

struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};
class NumArray {
    SegmentTreeNode* root;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }

    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            diff = modifyTree(i,val,root->right);
        } else {
            diff = modifyTree(i,val,root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
};

/*
 * You can do
 * 
 * O(1) update, O(N) sumRange
 * O(N) update, O(1) sumRange
 * O(NlogN) update, O(NlogN) sumRange
 * Since here, the update and sumRange operations are distributed evenly, 
 * option 3 is more appropriate. Basically, we can use a segment tree to 
 * achieve that. For this speical case, we can use a simplified version: 
 * binary indexed tree (BIT), in which a linear array BITSum is used and 
 * the "pointers" can be calculted directly as array indices. BITSum[i] 
 * is the sum of num[i-x+1::i] (note i starts from 1), where x is the value 
 * respresented by the rightmost "1" bit of i (e.g. i=5 =>x=1; i=4=>x=4). 
 * x can be calculated as x = i - i &-i (i &-i reset the rightmost "1" bit to 0). 
 * More details can be found online.
 */
class NumArray_BIT {
private:   
    int nSize;
    vector<int> BITsum; // BIT sum array
    vector<int> num; // original nums array

    int getSum(int i)
    {
        if(i<=0 || i>nSize) return 0;
        int res=BITsum[i];
        while( (i -= i & -i) > 0 )
            res +=BITsum[i];
        return res;
    }
public:
    NumArray_BIT(vector<int> &nums) {
        nSize = nums.size();
        num = BITsum = vector<int>(nSize+1, 0);
        for(int i=0;i<nSize; ++i)
            update(i, nums[i]);
    }

    void update(int i, int val) {
        int delta = val - num[++i];
        for(num[i] = val;i<=nSize;i += i & -i)
            BITsum[i] +=delta;
    }

    int sumRange(int i, int j) {
        return (i>j || i<0 || j>=nSize)? 0: i==j?num[i+1]:( getSum(j+1) - getSum(i) );
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
