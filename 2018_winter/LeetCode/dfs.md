# 101.Symmetric Tree
```cpp
(r1->val == r2->val) && isSymmetric(r1->right,r2->left) && isSymmetric(r1->left,r2->right);
//判断树是否对称，关键是 每对节点 左孩子==有孩子 右孩子==左孩子
```

# 108
```cpp
TreeNode* sortedArrayToBST(vector<int>& nums,int low,int high)
//vector<T> 不方便subvector 可以重载带边界的
//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。 实际上就是求折半查找判定树
```
# 110 平衡二叉树
```cpp
//根据定义 平衡二叉树 所有子树的左右结点的高度差小于1
//先判断当前结点是否平衡在判断左子树和右子树是否平衡，依次递归
```

# 111 
>首先判空，若当前结点不存在，直接返回0。然后看若左子结点不存在，那么对右子结点调用递归函数，并加1返回。反之，若右子结点不存在，那么对左子结点调用递归函数，并加1返回。若左右子结点都存在，则分别对左右子结点调用递归函数，将二者中的较小值加1返回即可， 

# 200. 岛屿的个数
```cpp
vector<vector<int> > newOne(r, vector<int>(c, 0));
// r*c 且值为0
```

# *257
```cpp
//非递归后续遍历太烦了，不好实现
//c++ string之间连接 用 **+**
```

# 513. 找树左下角的值
> string转int 可以使用std::stoi/stol/stoll等等函数

# 515. 在每个树行中找最大值
> vector::clear //清空容器

