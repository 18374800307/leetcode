/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 *
 * https://leetcode-cn.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (64.41%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 17.1K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * 给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
 * 
 * 列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],2,[1,1]]
 * 输出: [1,1,2,1,1]
 * 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
 * 
 * 示例 2:
 * 
 * 输入: [1,[4,[6]]]
 * 输出: [1,4,6]
 * 解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
 * 
 * 
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include<vector>
#include<stack>
using namespace std;
class NestedIterator {
public:
    stack<NestedInteger> v;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for (vector<NestedInteger>::reverse_iterator it = nestedList.rbegin(); it != nestedList.rend();it++){
            v.push(*it);
        }
    }
    
    int next() {
        NestedInteger value = v.top();
        v.pop();
        return value.getInteger();
    }
    
    bool hasNext() {
        while(!v.empty()){
            NestedInteger value = v.top();

            if(value.isInteger()){
                return true;
            }
            v.pop();
            vector<NestedInteger> curList = value.getList();
            for(vector<NestedInteger>::reverse_iterator it = curList.rbegin(); it != curList.rend();it++){
                v.push(*it);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

