// Segment Tree Using structs and pointers
// To find the count of numbers in a range pass the sorted array to the constructor
// question link -> https://leetcode.com/problems/count-of-range-sum/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    struct SegmentTree
    {
        SegmentTree *left, *right;
        long min, max, count;

        // Constructor
        // nums is the sorted array, l and r point to the start and begining.
        SegmentTree(vector<long> &nums, long l, long r) : left(NULL), right(NULL)
        {
            if (l > r)
                return;
            if (l == r)
            {
                max = min = nums[l];
                count = 0;
            }
            else
            {
                max = nums[r];
                min = nums[l];
                count = 0;
                int mid = (l + r) / 2;
                if (mid >= l)
                    left = new SegmentTree(nums, l, mid);
                if (mid < r)
                    right = new SegmentTree(nums, mid + 1, r);
            }
        }

        // add element
        void add(long num)
        {
            if (num > max || num < min)
                return;
            count++;
            if (left)
                left->add(num);
            if (right)
                right->add(num);
        }

        // find count of element
        long find(long rMin, long rMax)
        {
            if (rMin > max || rMax < min)
                return 0;
            if (rMin <= min && rMax >= max)
                return count;
            long temp = 0;
            if (left)
                temp += left->find(rMin, rMax);
            if (right)
                temp += right->find(rMin, rMax);
            return temp;
        }
    };

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        set<long> s;
        long sum = 0, ans = 0, sm, lr;
        for (auto num : nums)
        {
            sum += num;
            s.insert(sum);
        }

        vector<long> temp;
        for (auto x : s)
            temp.push_back(x);

        // creating the tree
        SegmentTree *st = new SegmentTree(temp, 0, (int)temp.size() - 1);
        sum = 0;

        for (auto num : nums)
        {
            sum += num;
            if (sum >= lower && sum <= upper)
                ans++;
            sm = sum - lower;
            lr = sum - upper;

            ans += st->find(lr, sm);
            st->add(sum);
        }
        return ans;
    }
};