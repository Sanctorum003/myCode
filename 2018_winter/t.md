# 最长子序列系列问题

### 这篇文章主要对这两天对LCS，以及其相关问题的学习做一个记录

## 1、LCS——最长公共子序列

### **注意**: 字串是连续的，而子序列只要相对位置一样，并不需要连续。

    问题描述： 给两个字符串a,b，求出这两个字符串的相同子序列的最大长度。

    解决方法： dp[i][j]保存了“字串a的前i个字串” 与 “字串b的前j个字串” 相同子序列的最大长度
    
    这个状态公式很简单：

    在决定dp[i][j]，就是a的前i个字符和b的前j个字符的最大公共子序列时：
    
        1.如果当前a[i]和b[j]相同的话，当前字符肯定在公共子序列中，所以是a的前i-1个和b的前j-1个的最大公共长度加上当前的1.
        如果a[i]和b[i]不相同的话，那当前字符肯定不再公共子序列中，那么当前的dp[i][j]就“由a的前i-1个字符与b的前j个字符的最大公共子序列”与“a的前i个字符与b的前j-1个字符的最大公共子序列” 来决定，因为a[i] b[j]不相等啊！ 
        
        所以就得到了上面的公式。

        
代码实现：
```
# include <iostream>
# include <cstring>
using namespace std;

int dp[20000][20000];  

int main(void){
	string a,b;
	while(cin>>a>>b){
		memset(dp,0,sizeof(dp));
		for ( int i=1; i<=a.size(); ++i ){
			for ( int j=1; j<=b.size(); ++j ){
				if ( a[i-1]==b[j-1] ){
					dp[i][j] = dp[i-1][j-1] +1 ;
				}else{
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		cout<<dp[a.size()][b.size()]<<endl;
	}
	return 0;
} 
```

##1.2 LCS的包装题目： 回文字串

[传送门][2]

    题目描述： 给一个字符串a，问至少添加多少个字符，能使这个字串变成回文字符串。
    
    解决方法：把字符串给翻转一下得到b，然后求a和b的LCS，最后len(a)-dp[len(a)][len(b)] 就是答案。 
    
    为什么呢？ 因为假设原本a就是个回文串，那么求出的dp[n][n]（n是字串长度）应该就是n，因为是回文串嘛。。 如果有一个字符没匹配到的话(也就是加一个字符就变成回文串)，那么dp[n][n]就是n-1， 因为那一个没匹配到的肯定是自己落单的，因此再给这个字串加上这些“落单”的字符们的个数，它就肯定变成回文串了。 因此len(a)-dp[len(a)][len(b)] 就是答案。 
    
代码：
```
# include <iostream>
# include <cstring>
using namespace std;

int dp[1003][1003];

int main(void){
	int n,l,r;
	char c;cin>>n;
	while( n-- ){
		memset(dp,0,sizeof(dp));
		string a;
		cin>>a;
		string b=a;
		l=0;r=a.size()-1;
		while( l<r ) swap(b[l++],b[r--]);
		for ( int i=1; i<=a.size(); ++i )
			for ( int j=1; j<=b.size(); ++j ){
				if ( a[i-1]==b[j-1] )
					dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		int l = a.size();
		cout<<l-dp[l][l]<<endl;
	}
	return 0;
}         
```

## 二、最长递增子序列
    
[传送门][3]
    
    问题描述：给一个序列，求出序列中最长的递增子序列。
    
    解决方法：arr[i]保存了 长度为i的序列的最后一个元素的值。每当收录进来一个值e：
    1.如果e比arr[len]大： (len是当前最大长度)
        len ← len + 1
        arr[len] = e 
    2.如果e比arr[len]小: 
        去arr中找到第一个满足e < arr[j]的值，位置为j (暴力N,二分logN) 
        arr[j] = e 
    
代码：
```
# include <iostream>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if ( !nums.size() ) return 0;
        int l,r,mid,j,arr[nums.size()+1],len=0;
        arr[0] = nums[0];
        for ( int i=1; i<=nums.size()-1; ++i ){
            if ( nums[i]>arr[len] ){
                arr[++len] = nums[i];
            }else{
                //O(NlogN)
                l = 0;
                r = len;
                while( l<=r ){
                    mid = (l+r)/2;
                    if ( arr[mid]>nums[i] ) r = mid-1;
                    else if ( arr[mid]<nums[i] ) l = mid+1;
                    else {
                        l = mid;
                        break;
                    }
                }
                arr[l] = nums[i];
                /*  O(N^2)
                for ( int j=0; j<=len; ++j ){
                    if ( arr[j]>=nums[i] ){
                        arr[j] = nums[i];
                        break;
                    }
                }*/
            }
        }
        return len+1;
    }
};
```
    
## 三、最长子序列个数

[传送门][4]
    
    题目描述： 给一个序列nums，求出最长子序列的个数
    
    解决方法： len[i]保存了nums[i]为结尾的最大长度，cnt[i]保存了以nums[i]为结尾的最大长度的个数。
    
    当第i个位置得到了一个新的值 e (=nums[i])：
        
        for ( 遍历i之前的每一个位置j ):
            if ( nums[j] < e ):  //此时以e结尾的最大值可能会更新
                if ( len[i] < len[j]+1 ):  //如果更新了的话
                    len[i] = len[j]+1
                    cnt[i] = cnt[j]     //因为更新时受第j个元素的影响，所以以nums[i]为结尾的个数就等于cnt[j]
                else if ( len[i] == len[j]+1 )：//说明长度为len[i]时 还可以加上len[j]给的个数
                    cnt[i] += cnt[j]
                    
            
                
C++代码：
```
# include <cstring>
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if ( !nums.size() ) return 0;
        //记录长度为n的个数
        int dp[nums.size()+1];  // 以nums[i]为结尾的最大长度
        int counter[nums.size()+1];  //以nums[i]为结尾的最大长度个数
        int len=1,maxv=1;
        for ( int i=0; i<=nums.size(); ++i )
            dp[i]=counter[i]=1;
        for ( int i=1; i<nums.size(); ++i ){ //放入第i个元素
            for ( int j=0; j<i; ++j ){
                if ( nums[i]>nums[j] ){  //当前值更大， 可以更新
                    if ( dp[i]<dp[j]+1 ){
                        dp[i] = dp[j]+1;  
                        counter[i] = counter[j];
                    }else if ( dp[i]==dp[j]+1 ) counter[i] += counter[j];
                }
            }
            if ( dp[i]>maxv ) maxv = dp[i];  //这句要放在外面，放在里面的话只有更新的时候会执行。但 5 5 5 5 这种情况就挂了
        }
        int ans=0;
        for ( int i=0; i<nums.size(); ++i )
            if ( maxv==dp[i] ) ans+=counter[i];
        return ans;
    }
};
```

------------
2018/2/23更新

[传送门][5]

## 四、最长连续公共子序列

    问题：和LCS的差不多，只不过LCS是相对位置一样，而在这个问题里，子序列必须是连续的。
    例如：
        A: [1,2,3,2,1,1]
        B: [3,2,1,4,1,7]
        Output: 3
    而对于LCS，output就是4
    
    思路：
        和LCS的思路几乎一样，只是在当a[i]!=b[j]的时候，处理办法不同，因为要求是连续的，所以当a[i]!=b[j]的时候，我们不能在让dp[i][j] 取 dp[i-1][j]或是dp[i][j-1]的最大值，而是直接赋为0， 因为断开了。。（再次强调，这里要求连续！！） 所以dp[i][j]将不再表示“a的前i个子符”和“b的前j个字符”的公共子串，而变成了 “ 如果在 ‘a的第i个字符’和在‘b的第j个字符’正好是连续公共子串的结尾，那么此时所表示的公共连续子串长度 ”。 （有点绕，慢慢品，很好理解。。）
        
        因此，我们就需要在这个过程中去用一个max变量来获取最大公共连续长度！
        
下面是代码：

```
class Solution {
public:
    int dp[1001][1001]={0};
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        for ( int i=1; i<=A.size(); ++i ){
            for ( int j=1; j<=B.size(); ++j ){
                if ( A[i-1]==B[j-1] ) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 0;
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
}; 
```