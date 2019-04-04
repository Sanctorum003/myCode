# 14. 最长公共前缀
* string s = "" <=> s = NULL

# 709 转换成小写字母
* transform用法
```cpp
class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(),str.end(),str.begin(),::tolower);
        return str;
    }
};
```

# 929. 独特的电子邮件地址
* set的插入：set.insert(val);
* string的删除：string.erase(pos,len);

# 804. 唯一摩尔斯密码词
* string初始化：string a[] ={};