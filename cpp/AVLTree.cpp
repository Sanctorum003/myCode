#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
    int key;
    struct node *lchild;
    struct node *rchild;
    int height;
} Node, *AVLtree;

void PreTravserse(AVLtree &avl)
{
    if (avl)
    {
        cout << avl->key << " ";
        PreTravserse(avl->lchild);
        PreTravserse(avl->rchild);
    }
}

void MidTraverse(AVLtree &avl)
{
    if (avl)
    {
        MidTraverse(avl->lchild);
        cout << avl->key << " ";
        MidTraverse(avl->rchild);
    }
}

void PostTraverse(AVLtree &avl)
{
    if (avl)
    {
        PostTraverse(avl->lchild);
        PostTraverse(avl->rchild);
        cout << avl->key << " ";
    }
}

void levelTraverse(AVLtree &avl)
{
    queue<AVLtree> que;
    AVLtree temp;

    if (!avl)
        return;

    que.push(avl);
    while (que.size() != 0)
    {
        temp = que.front();
        que.pop();
        cout << temp->key << " ";
        if (temp->lchild != NULL)
        {
            que.push(temp->lchild);
        }
        if (temp->rchild != NULL)
        {
            que.push(temp->rchild);
        }
    }
}

AVLtree Findmin(AVLtree avl)
{
    while(avl->lchild)
    {
        avl = avl->lchild; 
    }
    return avl;
}

AVLtree Findmax(AVLtree avl)
{
    while(avl->rchild)
    {
        avl = avl->rchild; 
    }
    return avl;
}


int getHeight(Node *tree)
{
    if (tree == NULL)
        return 0;
    return tree->height;
}

int maxh(Node *a, node *b)
{
    int ha = getHeight(a);
    int hb = getHeight(b);
    return ha > hb ? ha : hb;
}

AVLtree RR(Node *&aNode) //将bNode提起,左侧aNode下降
{
    Node *bNode = aNode->rchild;
    aNode->rchild = bNode->lchild;
    bNode->lchild = aNode;

    aNode->height = maxh(aNode->lchild, aNode->rchild) + 1;
    bNode->height = maxh(bNode->lchild, bNode->rchild) + 1;

    return bNode;
}

AVLtree LL(Node *&aNode) //将bNode提起,右侧aNode下降
{
    Node *bNode = aNode->lchild;
    aNode->lchild = bNode->rchild;
    bNode->rchild = aNode;

    aNode->height = maxh(aNode->lchild, aNode->rchild) + 1;
    bNode->height = maxh(bNode->lchild, bNode->rchild) + 1;
    return bNode;
}

AVLtree LR(Node *&aNode)
{
    aNode->lchild = RR(aNode->lchild);
    return LL(aNode);
}

AVLtree RL(Node *&aNode)
{
    aNode->rchild = LL(aNode->rchild);
    return RR(aNode);
}

AVLtree Insert(AVLtree AVL, int data)
{
    if (AVL == NULL) //空树则创建节点
    {
        AVL = new Node();
        AVL->lchild = NULL;
        AVL->rchild = NULL;
        AVL->key = data;
        AVL->height = 1;

        // cout<<"1"<<endl;
    }
    else
    {
        if (data < AVL->key)
        {
            // cout<<"2"<<AVL->key<<endl;
            AVL->lchild = Insert(AVL->lchild, data); //递归向左孩子插入
            int bala = getHeight(AVL->lchild) - getHeight(AVL->rchild);
            if (bala == 2) //是否需要旋转
            {
                if (data < AVL->lchild->key) //如果平衡破坏点在调整节点的左侧的左侧，进行LL旋转
                {
                    AVL = LL(AVL);
                }
                else
                {
                    AVL = LR(AVL);
                }
            }
        }
        else if (data > AVL->key)
        {
            AVL->rchild = Insert(AVL->rchild, data); //递归向右孩子插入
            //cout<<"2";
            int bala = getHeight(AVL->rchild) - getHeight(AVL->lchild);
            if (bala == 2)
            {
                if (data > AVL->rchild->key) //如果平衡破坏点在调整节点的右侧的右侧，进行RR旋转
                {
                    AVL = RR(AVL);
                }
                else
                {
                    AVL = RL(AVL);
                }
            }
        }
    }

    AVL->height = maxh(AVL->lchild, AVL->rchild) + 1;
    //cout<<"circul end"<<endl;
    return AVL;
}

AVLtree Delete(AVLtree AVL, int data)
{
    if(AVL == NULL) return AVL;
    else
    {
        if(data < AVL->key)
        {
            AVL->lchild = Delete(AVL->lchild,data);
        }
        else if(data > AVL->key)
        {
            AVL->rchild = Delete(AVL->rchild,data);
        }
        else
        {
            if(AVL->lchild && AVL->rchild)
            {
                AVLtree temp = Findmin(AVL->rchild);
                AVL->key = temp->key;
                AVL->rchild = Delete(AVL->rchild,AVL->key);
            }
            else
            {
                Node *temp = AVL;
                if(!AVL->lchild)
                {
                    AVL = AVL->rchild;
                }
                else
                {
                    AVL = AVL->lchild;
                }
                delete(temp);//清楚无用节点
            }
        }
    }

    if(AVL == NULL) return AVL;//如果删除的是叶子节点，直接返回

    int bala = getHeight(AVL->rchild) - getHeight(AVL->lchild);
    if (bala == 2)
    {
        if (getHeight(AVL->rchild->rchild) - getHeight(AVL->rchild->lchild) == 1)
        {
            AVL = RR(AVL);
        }
        else
        {
            AVL = RL(AVL);
        }
    }
    else if(bala == -2)
    {
        if (getHeight(AVL->lchild->lchild) - getHeight(AVL->lchild->rchild) == 1) 
        {
            AVL = LL(AVL);
        }
        else
        {
            AVL = LR(AVL);
        }
    }

    AVL->height = maxh(AVL->lchild, AVL->rchild) + 1;
    return AVL;
}

int main(void)
{
    AVLtree avl = NULL;
    int a[] = {3, 2, 1, 4, 5};
    for (int i = 0; i <= 15; ++i)
    {
        avl = Insert(avl, i);
    }


    avl = Delete(avl,0);
    avl = Delete(avl,3);
    avl = Delete(avl,6);
    avl = Delete(avl,10);
    avl = Delete(avl,15);    
    

    PreTravserse(avl);
    cout<<endl;
    MidTraverse(avl);
    cout<<endl;
    PostTraverse(avl);
    cout<<endl;
    levelTraverse(avl);

    return 0;
}