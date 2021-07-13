// Segment Tree Array
// To find the min, max, sum of range
// question link -> https://leetcode.com/problems/range-sum-query-mutable/

#include <bits/stdc++.h>

using namespace std;

class NumArray
{
public:
    vector<int> st, nums;
    int len;

    //  to build the segment tree
    int build(int i, int l, int r)
    {
        if (l == r)
        {
            st[i] = nums[l];
            return st[i];
        }
        int mid = (l + r) / 2;
        st[i] = build((2 * i) + 1, l, mid) + build((2 * i) + 2, mid + 1, r);
        return st[i];
    }

    //  to find sum of range to chagne to min return min b/w left and right and INT_MAX insted of 0
    int findSum(int i, int l, int r, int tl, int tr)
    {
        if (l >= tl && r <= tr)
        {
            return st[i];
        }
        if (tr < l || tl > r)
        {
            return 0;
        }
        int mid = (l + r) / 2;
        return findSum((2 * i) + 1, l, mid, tl, tr) + findSum((2 * i) + 2, mid + 1, r, tl, tr);
    }

    //  to find sum of range to chagne to min return min b/w left and right
    int updateST(int i, int l, int r, int targetIndex, int value)
    {
        if (targetIndex < l || targetIndex > r)
        {
            return st[i];
        }
        if (l == r)
        {
            if (l == targetIndex)
                st[i] = value;
            return st[i];
        }
        st[i] += value;
        int mid = (l + r) / 2;
        st[i] = updateST((2 * i) + 1, l, mid, targetIndex, value) + updateST((2 * i) + 2, mid + 1, r, targetIndex, value);
        return st[i];
    }

    NumArray(vector<int> &n)
    {
        len = n.size();
        nums = n;
        //      finding the length of vector needed for the segment tree => 2*(min pow of 2>=len) - 1
        int p = 1;
        while (pow(2, p) < len)
            p++;
        st.resize((2 * pow(2, p)) - 1, INT_MIN);
        build(0, 0, len - 1);
    }

    void update(int index, int val)
    {
        updateST(0, 0, len - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return findSum(0, 0, len - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */