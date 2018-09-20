#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
# include <algorithm>
# include <math.h>
using namespace std;

#define OK 1
#define ERROR O
#define TRUE 1
#define FALSE 0

#define SIZE 10

typedef int ElemType;
typedef int Status;

Status swap(ElemType &a,ElemType &b);//交换位置
Status traverse(ElemType a[]);//遍历

Status BubbleSort(ElemType a[],int n);//冒泡排序
Status BubbleSort2(ElemType a[],int n);//冒泡排序优化1√   优化：增加一个开关，如果某次排序中没有交换位置，则排序完成
Status BubbleSort3(ElemType a[],int n);//冒泡排序优化2	 优化：在优化一下，如果在排序中后边若干位未排序，则后端已完成，只需从最后交换位置之前开始

Status SelectSort(ElemType a[],int n);//选择排序√

Status InsertSort(ElemType a[],int n);//直接插入排序
Status InsertSort2(ElemType a[],int n);//插入排序优化√
Status ShellSort(ElemType a[],int n);//希尔排序√
Status ShellSort2(ElemType a[],int n);//希尔排序优化√√

Status MergeSort(ElemType a[],int first,int last);//归并排序√√

Status QuickSort(ElemType a[],int low,int high);//快速排序√√

Status HeapSort(ElemType a[],int length);//堆排序√√

//计数排序（桶）
//std:sort
//qsort


ElemType a[SIZE];
/*ElemType b[SIZE];
ElemType c[SIZE];
ElemType d[SIZE];
ElemType e[SIZE];
ElemType f[SIZE]; 
ElemType g[SIZE];*/
ElemType h[SIZE];
ElemType z[SIZE];
ElemType a1[SIZE];
ElemType a2[SIZE];
ElemType a3[SIZE];


int comp(const void * A,const void *B)
{
	return (*(int *)A)- (*(int *)B);
}

int main(void)
{
	int ts[100];
	int te[100];

	
	srand(time(0));
	
	int i=0;
	
 	memset(a,0,SIZE);
/*	memset(b,0,SIZE);
	memset(c,0,SIZE);
	memset(d,0,SIZE);
	memset(e,0,SIZE);
	memset(f,0,SIZE); 
	memset(g,0,SIZE);*/
	memset(h,0,SIZE);
	memset(z,0,SIZE);
	memset(a1,0,SIZE);
	memset(a2,0,SIZE);
	memset(a3,0,SIZE);
	
	for(i=0;i<SIZE;i++)
	{
		a[i] = rand()%100+1;
		//b[i] = a[i];
		//c[i] = a[i];
		//d[i] = a[i];
		//e[i] = a[i];
		//f[i] = a[i];
		//g[i] = a[i];
		h[i] = a[i];
		z[i] = a[i];
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
	}
	
	//冒泡排序
	//--------------冒泡排序-------------------//
/*   	ts[0]=clock();
	BubbleSort(a,SIZE);
	te[0]=clock();
	printf("冒泡排序:\t%f毫秒\n", (double)(te[0]-ts[0]));   
	//--------------冒泡排序优化1----------------------//
	ts[1]=clock();
	BubbleSort2(b,SIZE);
	te[1]=clock();
	printf("冒泡排序优化1:\t%f毫秒\n", (double)(te[1]-ts[1]));
		//--------------冒泡排序优化2----------------------//
	ts[2]=clock();
	BubbleSort3(c,SIZE);
	te[2]=clock();
	printf("冒泡排序优化2:\t%f毫秒\n", (double)(te[2]-ts[2])); */
	//--------------------END-----------------------------//
	
	//选择排序
	//--------------------选择排序--------------//
 	/* ts[3]=clock();
	SelectSort(d,SIZE);
	te[3]=clock();
	printf("选择排序:\t%f毫秒\n", (double)(te[3]-ts[3]));  */
	//-------------------END-----------------------------//
	
	
	//插入排序
	//-------------------直接插入排序----------------//
/* 	ts[4]=clock();
	InsertSort(e,SIZE);
	te[4]=clock();
	printf("直接插入排序:\t%f毫秒\n", (double)(te[4]-ts[4]));
	//------------------插入排序优化-----------------//
	ts[5]=clock();
	InsertSort2(f,SIZE);
	te[5]=clock();
	printf("插入排序优化:\t%f毫秒\n", (double)(te[5]-ts[5])); */
	//-----------------希尔排序---------------------//
	/* ts[6]=clock();
	ShellSort(g,SIZE);
	te[6]=clock();
	printf("希尔排序:\t%f毫秒\n", (double)(te[6]-ts[6]));	*/
	//-----------------希尔排序优化-----------------//
	ts[7]=clock();
	ShellSort2(h,SIZE);
	te[7]=clock();	
	printf("希尔排序优化:\t%f毫秒\n", (double)(te[7]-ts[7])); 

	//--------------------END-----------------------------//
	
	
	//快速排序
	//------------------系统快排-------------------------//
	/* ts[8]=clock();
	qsort(z,SIZE,sizeof(z[0]),comp);
	te[8]=clock();	
	printf("系统快排:\t%f毫秒\n", (double)(te[8]-ts[8]));	*/
	//------------------------系统排序-------------------//
	ts[9] = clock();
	sort(a1,a1+SIZE);
	te[9] = clock();
	printf("系统排序:\t%f毫秒\n", (double)(te[9]-ts[9])); 
	//-------------------------自写快排-----------------//
	/* ts[11] = clock();
	QuickSort(a3,0,SIZE-1);
	te[11] = clock();
	printf("自写快排:\t%f毫秒\n", (double)(te[11]-ts[11]));	 */
	
	//----------------------------END-----------------------------//
	
	//归并排序
	//-------------------归并排序------------------------//
 	//traverse(a2);
 	ts[10] = clock();
	MergeSort(a2,0,SIZE-1);
	te[10] = clock();
	printf("归并排序:\t%f毫秒\n", (double)(te[10]-ts[10])); 
	//-------------------END-----------------------------//
	
	//堆排序
	//----------堆排序----------------------------------//
	ts[12] = clock();
	HeapSort(a3,SIZE);
	te[12] = clock();
	printf("堆排序   :\t%f毫秒\n", (double)(te[12]-ts[12]));
	//----------------END-----------------------------//

	
	
	
	
 	traverse(a3);
	/*printf("\n");
	traverse(c);  */
	
	
	printf("\n");
	

	return 0;
}

Status swap(ElemType &a,ElemType &b)
{
	ElemType t;
	t = a;
	a = b;
	b = t;
	
	return OK;
}

Status traverse(ElemType a[])
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",a[i]);
	}
	
	printf("\n");
	
	return OK;
}

Status ArrayCopy(ElemType a[],ElemType b[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		b[i] = a[i];
	}
	
	return OK;
}

//冒泡排序
Status BubbleSort(ElemType a[],int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)//每次从前（n-i）项中每次比较两项，将最大者沉底
		{
			if(a[j-1] > a[j])
				swap(a[j-1],a[j]);
		}
	}
	
	return OK;
}

//冒泡排序2
Status BubbleSort2(ElemType a[],int n)
{
	int i,j;
	int flag =FALSE;

	for(i=0;i<n;i++)
	{
		flag = FALSE;
		
		for(j=1;j<n-i;j++)
		{
			if(a[j-1] > a[j])
			{
				swap(a[j-1],a[j]);
				flag = TRUE;			
			}
		}
		
		if(!flag)
		{
			break;
		}
	}
	
	return OK;
}

//冒泡排序3
Status BubbleSort3(int a[], int n)
{
	int i,j;
	int flag = n;
	
	while(flag > 0)
	{
		i = flag;
		flag = 0;
		
		for(j=1;j<i;j++)
		{
			if(a[j-1] > a[j])
			{
				swap(a[j-1],a[j]);
				flag = j;
			}
		}
	}
	
	return OK;
} 

//选择排序
Status SelectSort(ElemType a[],int n)
{
	int i,j;
	int min;
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[min] > a[j])
				min = j;
		}
		
		swap(a[i],a[min]);
	}
	return OK;
}

//插入排序
Status InsertSort(ElemType a[],int n)
{
	int i,j,k;
	int t;
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[i]>a[j])
			{
				break;
			}
		}
		
		if(j != i -1)
		{
			t = a[i];
			for(k = i-1; k >j ;k--)
			{
				a[k+1] = a[k];
			}
			
			a[k+1] =t;
			
		}
	}
	
	return OK;
}

Status InsertSort2(ElemType a[],int n)
{
	int i,j;
	int temp;
	
	for(i=1;i<n;i++)
	{
		temp = a[i];
		
		if(a[i-1] > a[i])
		{
			for(j=i-1;j>=0 && a[j] > temp ;j--)
			{
				a[j+1] =a[j];
			}
			
			a[j+1] = temp;
		}
	}
	
	return OK;
}

Status ShellSort(ElemType a[],int n)
{
	int i,j,k,gap;
	int temp;
	
	for(gap = n/2;gap>0;gap /= 2)
	{
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<n;j += gap)
			{
				temp = a[j];
				k = j-gap;
				while(k >= 0 && a[k] > temp)
				{
					a[k+gap] =a[k];
					k -= gap;
				}
				a[k+gap] =temp;
			}
		}
	}
	
	return OK;
}

long long int Sege(int n)
{
	return (9*(long int)pow(4,n)-9*(long int)pow(2,n)+1);
}

Status ShellSort2(ElemType a[],int n)
{
	int j,gap;
	int k,temp;
	long long int Sedgewick[100];
	long long int cnt=2;
	Sedgewick[0] = 0;
	Sedgewick[1] = 1;
	while ( Sedgewick[cnt-1]<=n )
	{
		Sedgewick[cnt] = Sege(cnt);
		cnt++;
	}
	cnt -= 2;
	for(gap = Sedgewick[cnt]; gap>0; gap= Sedgewick[--cnt])
	{
		for(j = gap; j<n; j++)
		{
			if(a[j] < a[j - gap])
			{	
				temp = a[j];
				k = j -gap;
				while(k>= 0&& a[k] > temp)
				{
					a[k+gap] = a[k];
					k -= gap;
				}
				a[k+gap] = temp;
			}
		}
	}
	
	return OK;
} 

//-----------------------------------归并排序---------------------//

ElemType temp[SIZE];
Status MergeArray(ElemType a[],int first,int mid,int last)
{
	int i=first, m =mid;
	int j=mid+1, n =last;
	int k=0;
	while(i<=m && j<=last)
	{
		if(a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	
	while(i <= m)
	{
		temp[k++] = a[i++];
	}
	
	while(j<= n)
	{
		temp[k++] = a[j++];
	}
	
	for(i=0; i<k;i++)
	{
		a[first+i] =temp[i];
	}
	
	return OK;
}

Status MergeSort(ElemType a[],int first,int last)
{
	int mid;
	
	if(first <  last)
	{
		mid = (first + last)/2;
		MergeSort(a,first,mid);
		MergeSort(a,mid+1,last);
		MergeArray(a,first,mid,last);
	}
	
	return OK;
}

//-----------------END-----------------------------//

//---------------快排------------------------------//
int Partition(ElemType a[],int low,int high)
{
	int i = low;
	int j = high;
	int pivotkey = a[low];
	
	while(i < j)
	{
		while(i<j && a[j] >= pivotkey)//从右边往左寻找j比pivotkey小的填到左边
		j--;
		a[i] =a[j];
		
		while(i<j && a[i] < pivotkey)
		i++;
		a[j] = a[i];
	}
	
	a[i] = pivotkey;
	
	return i;
}

Status QuickSort(ElemType a[],int low,int high)
{
	int pivotloc;
	
	if(low < high)
	{
		int pivotloc = Partition(a,low,high);
		QuickSort(a,low,pivotloc-1);
		QuickSort(a,pivotloc + 1,high);
	}
	
	return OK;
}
//----------------------END-----------------------------//
Status HeapAdjust(ElemType a[],int s,int l)//数组，调整位置，总长度
{
	int lc = 2*s ;
	int rc = 2*s+1;
	int temp = s;
	
	if( s <= l/2) //如果是叶子节点就不调整
	{
		if(lc <= l && a[lc] > a[temp])
		{
			temp = lc;
		}
		
		if(rc <= l && a[rc] > a[temp])
		{
			temp =rc;
		}
		
		if( temp != s)
		{
			swap(a[s] , a[temp]);
			HeapAdjust(a,temp,l);
		}
	}
	
	return OK;
}//堆调整

Status HeapSort(ElemType a[],int length)
{
	int n =length/2;
	int i=1;
	
	for(i = n; i > 0;i--)
	{
		HeapAdjust(a,i,length);
	}//建立堆
	
	for(i = length -1; i> 0; i--)
	{
		swap(a[i],a[1]);
		HeapAdjust(a,1,i-1);
	}//排序
	
	return OK;
}
