/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 *
 * https://leetcode-cn.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (32.40%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 25.8K
 * Testcase Example:  '"112358"'
 *
 * 累加数是一个字符串，组成它的数字可以形成累加序列。
 * 
 * 一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
 * 
 * 给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
 * 
 * 说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 * 
 * 示例 1:
 * 
 * 输入: "112358"
 * 输出: true 
 * 解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * 示例 2:
 * 
 * 输入: "199100199"
 * 输出: true 
 * 解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 * 
 * 进阶:
 * 你如何处理一个溢出的过大的整数输入?
 * 
 */

// @lc code=start
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int i=0;
        for(int j=i+1;j<=num.size()-1;j++){
            for(int k=j+1;k<=num.size()-1;k++){
                if(dfs(num,i,j,k)) return true;
            }
        }
        return false;
    }

    bool dfs(string& s,int i,int j,int k){
        if((s[i]=='0'&&j-i>1)||(s[j]=='0'&&k-j>1)) return false;
        string a=s.substr(i,j-i);
        string b=s.substr(j,k-j);
        string sum=add(a,b);
        int n=sum.size();
        if(k+n-1>s.size()-1||sum!=s.substr(k,n)) return false;
        if(k+n-1==s.size()-1) return true;
        return dfs(s,j,k,k+n);    
    }

    string add(string& a,string& b){
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

