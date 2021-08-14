/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minVal(int x, int y) { return (x < y) ? x : y; }

    // A utility function to get the
    // middle index from corner indexes.
    int getMid(int s, int e) { return s + (e - s) / 2; }

    /* A recursive function to get the
minimum value in a given range
of array indexes. The following
are parameters for this function.
 
    st --> Pointer to segment tree
    index --> Index of current node in the
           segment tree. Initially 0 is
           passed as root is always at index 0
    ss & se --> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[index]
    qs & qe --> Starting and ending indexes of query range */
    pair<int, int> RMQUtil(vector<pair<int, int>> st, int ss, int se, int qs, int qe, int index)
    {
        // If segment of this node is a part
        // of given range, then return
        // the min of the segment
        if (qs <= ss && qe >= se)
            return st[index];

        // If segment of this node
        // is outside the given range
        if (se < qs || ss > qe)
            return {INT_MAX, -1};

        // If a part of this segment
        // overlaps with the given range
        int mid = getMid(ss, se);
        return min(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
                   RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
    }

    // Return minimum of elements in range
    // from index qs (query start) to
    // qe (query end). It mainly uses RMQUtil()
    pair<int, int> RMQ(vector<pair<int, int>> st, int n, int qs, int qe)
    {
        // Check for erroneous input values
        // if (qs < 0 || qe > n - 1 || qs > qe)
        // {
        //     cout << "Invalid Input";
        //     return -1;
        // }

        return RMQUtil(st, 0, n - 1, qs, qe, 0);
    }

    // A recursive function that constructs
    // Segment Tree for array[ss..se].
    // si is index of current node in segment tree st
    pair<int, int> constructSTUtil(vector<int> arr, int ss, int se,
                                   vector<pair<int, int>> st, int si)
    {
        // If there is one element in array,
        // store it in current node of
        // segment tree and return
        if (ss == se)
        {
            st[si] = {arr[ss], ss};
            return {arr[ss], ss};
        }
        // If there are more than one elements,
        // then recur for left and right subtrees
        // and store the minimum of two values in this node
        int mid = getMid(ss, se);
        st[si] = min(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                     constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
        return st[si];
    }

    /* Function to construct segment tree
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
    vector<pair<int, int>> constructST(vector<int> arr, int n)
    {
        // Allocate memory for segment tree

        //Height of segment tree
        int x = (int)(ceil(log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        // int *st = new int[max_size];
        vector<pair<int, int>> st(max_size);

        // Fill the allocated memory st
        constructSTUtil(arr, 0, n - 1, st, 0);

        // Return the constructed segment tree
        return st;
    }

    void rec(vector<pair<int, int>> &ST, int l, int r, int &ans, int n)
    {
        if (l > r)
            return;
        auto mins = RMQ(ST, n, l, r);
        ans = max(ans, mins.first * (r - l + 1));
        // if (r == l)
        //     return;
        // else
        // {
        rec(ST, l, mins.second - 1, ans, n);
        rec(ST, mins.second + 1, r, ans, n);
        // }
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<pair<int, int>> st = constructST(heights, heights.size());
        int ans = INT_MIN;
        rec(st, 0, heights.size() - 1, ans, heights.size());
        return ans;
    }
};
// @lc code=end
