#include <iostream>
#include <queue>
using namespace std;
/***
 * @Sanctorum003
***/
typedef struct node
{ //二叉树的数据结构
    int key;
    struct node *lchild;
    struct node *rchild;
} Node, *BiTree;

void PreTravserse(BiTree &BST)
{
    if (BST)
    {
        cout << BST->key << endl;
        PreTravserse(BST->lchild);
        PreTravserse(BST->rchild);
    }
}

void MidTraverse(BiTree &BST)
{
    if (BST)
    {
        MidTraverse(BST->lchild);
        cout << BST->key << endl;
        MidTraverse(BST->rchild);
    }
}

void PostTraverse(BiTree &BST)
{
    if(BST)
    {
        PostTraverse(BST->lchild);
        PostTraverse(BST->rchild);
        cout << BST->key << endl;
    }
}

void levelTraverse(BiTree &BST)
{
    queue<BiTree> que;
    BiTree temp;

    if (!BST)
        return;

    que.push(BST);
    while (que.size() != 0)
    {
        temp = que.front();
        que.pop();
        cout << temp->key << endl;
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

BiTree Insert(BiTree &BST, int data)//(BiTree BST,...)则只是创建副本指针，对于BST的操作不会改变tree，所以最后不会创建树
{
    if (BST == NULL)
    {
        BST = new Node(); /*(BST)malloc(sizeof(Node));*/
        BST->key = data;
        BST->lchild = NULL;
        BST->rchild = NULL;
    }
    else if (data < BST->key)
    {
        BST->lchild = Insert(BST->lchild, data);
    }
    else if (data > BST->key)
    {
        BST->rchild = Insert(BST->rchild, data);
    }

    return BST;
}

BiTree Findmin(BiTree BST)
{
    BiTree temp = BST;
    while(BST->lchild)
    {
        BST = BST->lchild; 
        temp = BST;
    }
    return BST;
}

BiTree Findmax(BiTree BST)
{
    BiTree temp = BST;
    while(BST->rchild)
    {
        BST = BST->rchild; 
        temp = BST;
    }
    return BST;
}

BiTree FindNode(BiTree BST,int data)
{
    while(1)
    {
        if(BST == NULL) return BST;

        if(BST->key == data)
        {
            return BST;
        }
        else if(BST->key > data)
        {
            BST = BST->lchild;
        }
        else
        {
            BST = BST->rchild;
        }
    }
    return BST;
}

BiTree DeleteNode(BiTree BST,int data)
{
    BiTree  temp;
    if(!BST) cout<<"cannot find the element";
    else
    {
        if(BST->key > data)
        {
            BST->lchild = DeleteNode(BST->lchild,data);
        }
        else if(BST->key < data)
        {
            BST->rchild = DeleteNode(BST->rchild,data);
        }
        else
        {
            if(BST->rchild && BST->lchild)
            {
                temp = Findmin(BST->rchild);
                BST->key = temp->key;
                BST->rchild = DeleteNode(BST->rchild,BST->key);
            }
            else
            {
                if(!BST->lchild)
                {
                    BST = BST->rchild;
                }
                else
                {
                    BST = BST->lchild;
                }
            }
        }
    }

    return BST;
}


int main(void)
{
    BiTree tree = NULL;
    Insert(tree, 3);
    Insert(tree, 1);
    Insert(tree, 2);
    Insert(tree, 4);
    tree = DeleteNode(tree,6);
    // levelTraverse(tree);
    // cout<<endl;
    // PreTravserse(tree);
    cout<<endl;
    MidTraverse(tree);
    // cout<<endl;
    // PostTraverse(tree);
    cout<<endl;
    
    return 0;
}