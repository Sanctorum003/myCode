#include <iostream>
#include <vector>
using namespace std;
/*
叶子节点与外表节点不同
叶子节点指向外部节点
外部节点指向NULL
*/
#define ORDER 3

typedef struct node
{
	struct node *parent;//父亲节点
	vector<int> key;
	vector<struct node *> children;
	node()//构造函数
	{
		parent = NULL; children.insert(children.end(), NULL);
	}
}Node, *BTree;//b树数据结构

typedef struct RNode
{
	Node *node;//b树节点
	int rank;//节点中的顺位
	RNode(Node *node = NULL, int rank = 0)
	{//构造函数
		this->node = node;
		this->rank = rank;
	}
}RNode; //查找返回节点数据结构

BTree _hot;//全局变量，指向外部节点的**父母**引用
int _size;//关键码总数
int _order = ORDER;//阶数(ORDER条分支，ORDER-1个节点)
BTree _root;//记录根节点
int _p_num = 0; //查询节点父节点刚好大于待查询节点的位置

int ser_pos(BTree bt, int data)
{//查找插入的位置
	int len = bt->key.size();
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		if (bt->key[i] > data)   break;
	}

	return i;//返回应插入的位置
}

RNode search(BTree bt, int data)//返回结构体RNode
{
	while (bt)
	{//bt不为外部节点时查找
		int len = bt->key.size();
		int i = 0;
		for (i = 0; i < len; ++i)
		{
			if (bt->key[i] == data)
			{
				return *(new RNode(bt, i));
			}

			if (bt->key[i] > data)   break;
		}

		_p_num = i;//保存位置
		_hot = bt;//将叶子节点（非空）传递给_hot，以备后用。
		bt = bt->children[i];
	}

	return NULL;//查询失败，返回空
}

BTree rootIsNull(BTree fa)
{//是否是根节点
	if (fa == NULL)
	{
		fa = new Node();
		_root = fa;//更新根节点
		return fa;
	}//如果是根节点，创建新节点

	return fa;
}

void solveOverflow(BTree bt)
{
	int len = bt->children.size();//分支条数
	int num = bt->key.size();//节点个数
	if (len <= _order) { //未发生溢出
						 //cout << len << " ";
						 //cout << "no overflow" << endl;
		return;//直接返回
	}

	//发生上溢
	//cout << "overflow" << endl;
	int mid = num / 2;//数值中位数
	BTree fa = bt->parent;
	fa = rootIsNull(fa);//判断根节点是否上溢

	int fa_cnt = ser_pos(fa, bt->key[mid]);//需找插入点
	fa->key.insert(fa->key.begin() + fa_cnt, bt->key[mid]);//插入新节点
	fa->children.insert(fa->children.begin() + fa_cnt + 1, NULL);//插入新分支

	fa->children[fa_cnt] = new Node();
	for (int i = 0; i <mid; ++i)//拷贝左半边
	{
		fa->children[fa_cnt]->key.push_back(bt->key[i]);//左分支拷贝数值
		fa->children[fa_cnt]->children.push_back(bt->children[i + 1]);//左分支拷贝指针(除第0个)
	}
	fa->children[fa_cnt]->children[0] = bt->children[0];//拷贝0分支指针
	fa->children[fa_cnt]->parent = fa;//左分支父亲节点为fa

	fa->children[fa_cnt + 1] = new Node();
	for (int i = mid + 1; i <num; ++i)//拷贝右半边
	{
		fa->children[fa_cnt + 1]->key.push_back(bt->key[i]);//右分支拷贝数值
		fa->children[fa_cnt + 1]->children.push_back(bt->children[i + 1]);//右分支拷贝指针(除第mid+1个)
	}
	fa->children[fa_cnt + 1]->children[0] = bt->children[mid + 1];//拷贝mid+1分支指针
	fa->children[fa_cnt + 1]->parent = fa;//左分支父亲节点为fa

	solveOverflow(fa);//递归检查父节点是否溢出

	for (int i = 0; i < fa->children.size(); ++i)
		if (fa->children[i] != NULL)//保证儿子节点存在
			for (int j = 0; j <fa->children[i]->children.size(); ++j)
				if (fa->children[i]->children[j] != NULL)//保证孙子节点存在
					fa->children[i]->children[j]->parent = fa->children[i];//分裂时更新孙子节点的指向，指向新儿子节点
}

void solveDownflow(BTree &bt)
{
	if (_root->key.size() == 0)	return; //合并时有可能根节点变空，直接返回
	if (bt->children.size() >= (_order + 1) / 2)
		return;//未发生下溢，直接返回

			   //发生下溢
			   //search(_root,bt->key[0]);//查询最小节点
			   // int r = _p_num;//通过上一步，得到(二叉)父节点位置
	BTree fa = bt->parent;//父亲节点
						  //if(fa == NULL) return;//父节点不存在 返回（错误）
						  // int i = 0;
						  // for(i = 0; i < fa->key.size();++i)
						  // {
						  // 	if(bt->key.size() == 0)
						  // 		break;//bt无key 返回0

						  // 	if(fa->key[i] > bt->key[0])
						  // 		break;
						  // }
						  // int r =i;
	int r = _p_num;
	BTree Lbro = NULL;
	BTree Rbro = NULL;
	if (r >= 1)//保证有左兄弟
		Lbro = fa->children[r - 1];//左兄弟
	if (r <= fa->children.size() - 2)//保证有右兄弟
		Rbro = fa->children[r + 1];//右兄弟
	if (Lbro && Lbro->children.size() > (_order + 1) / 2)
		//如果待调整节点的左兄弟存在且有多余节点
	{
		bt->key.insert(bt->key.begin(), fa->key[r - 1]);//将父亲插入待调整节点
		bt->children.insert(bt->children.begin(), Lbro->children[Lbro->children.size()-1]);//将左兄弟的最右分支复制过来
		if (bt->children[0])//如果复制过来的最左孩子存在
			bt->children[0]->parent = bt;//复制过来的孩子的父亲指向bt

		fa->key[r - 1] = Lbro->key[Lbro->key.size() - 1];//父亲的值改为左孩子的最大值

		Lbro->key.erase(Lbro->key.begin() + Lbro->key.size() - 1);//删除左孩子最大值
		Lbro->children.erase(Lbro->children.begin() + Lbro->children.size() - 1);//删除左孩子最右分支
	}
	else if (Rbro && Rbro->children.size() > (_order + 1) / 2)//此时的父亲为上一分支语句中父亲的右边一个
	{
		bt->key.insert(bt->key.end(), fa->key[r]);//将父亲插入待调整t节点
		bt->children.insert(bt->children.end(), Rbro->children[0]);//将右兄弟的最左分支复制过来
		if (bt->children[bt->children.size() - 1])//如果复制过来的最右孩子存在
			bt->children[bt->children.size() - 1]->parent = bt;//复制过来的孩子的父亲指向bt

		fa->key[r] = Rbro->key[0];//父亲的值改为右孩子的最小值

		Rbro->key.erase(Rbro->key.begin());//删除右孩子最小值
		Rbro->children.erase(Rbro->children.begin());//删除右孩子最左分支
	}
	else//无法从左右孩子获取节点
	{
		//去祸害父亲节点 删除fa->key[r]和fa->children[r+1],合并入fa->children[r]


		//未检测b_tree下降情况
		//当合并时未考虑是否存在左右兄弟，要分别考虑
		//明天写

		if (r == 0)//当bt为最左分支的时候，无左兄弟与右兄弟合并
		{
			//bt右边插入父亲
			bt->key.insert(bt->key.end(), fa->key[r]);
			bt->children.insert(bt->children.end(), Rbro->children[0]);//插入右孩子的最左分支

																	   //再插入右兄弟
			for (int i = 0; i< Rbro->key.size(); ++i)
			{
				bt->key.insert(bt->key.end(), Rbro->key[i]);
				bt->children.insert(bt->children.end(), Rbro->children[i + 1]);
			}

			//删除父亲及相关支路
			fa->key.erase(fa->key.begin() + r);
			fa->children.erase(fa->children.begin() + r + 1);

			//关联fa->children[r]与现在的bt
			fa->children[r] = bt;
		}
		else//否则必有左兄弟
		{
			//左兄弟插入父亲r-1
			Lbro->key.insert(Lbro->key.end(), fa->key[r - 1]);
			Lbro->children.insert(Lbro->children.end(), bt->children[0]);//插入bt的最左分支

			for (int i = 0; i < bt->key.size(); ++i)//再插入bt
			{
				Lbro->key.insert(Lbro->key.end(), bt->key[i]);
				Lbro->children.insert(Lbro->children.end(), bt->children[i + 1]);
			}

			//删除父亲及相关支路
			fa->key.erase(fa->key.begin() + r - 1);
			fa->children.erase(fa->children.begin() + r);

			//关联fa->children[r-1]与现在的bt ????
			fa->children[r - 1] = Lbro;
		}
	}

	solveDownflow(fa);//递归检查父亲节点是否下溢
}

bool insert(BTree &bt, int data)
{
	if (_size == 0)
	{//bt为空时，初始化
		bt = new Node();
		bt->key.push_back(data);
		bt->children.push_back(NULL);
		_size++;
		_root = bt;
		return true;
	}
	RNode rnode = search(bt, data);
	if (rnode.node) return false;//判读带插入数据是否已经存在
	int i = ser_pos(_hot, data);
	// cout << i << endl;
	_hot->key.insert(_hot->key.begin() + i, data);
	_hot->children.insert(_hot->children.begin() + i, NULL);
	_size++;
	solveOverflow(_hot);//检查是否上溢
	bt = _root;
}

bool deleteData(BTree &bt, int data)
{
	//待删除点不存在
	RNode rn = search(bt, data);
	if (!rn.node)	return false;

	//待删除点存在
	if (rn.node->children[0])//待删除点非叶子节点
	{
		BTree temp = rn.node->children[rn.rank + 1];//tmep为待删除点的右子树
		while (temp->children[0])//如果左孩子存在，一直向左
		{
			temp = temp->children[0];
		}//最终找到右子树的最小孩子

		rn.node->key[rn.rank] = temp->key[0];
		rn.node = temp;
		rn.rank = 0;//交换位置
	}//此时rn必定为叶子节点

	rn.node->key.erase(rn.node->key.begin() + rn.rank);//删除key节点
	rn.node->children.erase(rn.node->children.begin() + rn.rank + 1);//删除children节点

	solveDownflow(rn.node);//递归检查是否下溢

	if (_root->key.size() == 0)//如果根节点变空
	{
		_root = _root->children[0];//改变根节点
		_root->parent = NULL;//其父亲指向NULL
		bt = _root;//重新更改bt
	}
}

int main(void)
{
	BTree bt = NULL;
	for (int i = 1; i <11; ++i)
	{
		insert(bt, i);
	}

	deleteData(bt, 1);
	deleteData(bt, 5);
	deleteData(bt, 2);
	return 0;
}