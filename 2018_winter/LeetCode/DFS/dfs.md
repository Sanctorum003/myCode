> 101.Symmetric Tree
```cpp
(r1->val == r2->val) && isSymmetric(r1->right,r2->left) && isSymmetric(r1->left,r2->right);
//判断树是否对称，关键是 每对节点 左孩子==有孩子 右孩子==左孩子
```

> 108
```cpp
TreeNode* sortedArrayToBST(vector<int>& nums,int low,int high)
//vector<T> 不方便subvector 可以重载带边界的
//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。 实际上就是求折半查找判定树
```

> *257
```cpp
//非递归后续遍历太烦了，不好实现
//c++ string之间连接 用 **+**
```

