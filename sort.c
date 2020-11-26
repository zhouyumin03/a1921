#include"sort.h"                                                                           
#include<stdio.h>
#define N 20

void bubble(int a[],int n)

{
	int i, j,t;
	for(i=1;i< n;i++)
	{for (j=0;j<n-i;j++)
		{

			if (a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}


void Bubble(int a[], int n)
{int i, num;
	srand(time(0));                                                                      
	for (i=0; i<N;i++)
		a[i] = rand () %100;
	printf("初始数据为：");

	for (i = 0;i<N;i++)
		printf("%d ",a[i]);
	printf("\n");
	num = N;
	bubble(a, num);
	printf("排序后数据：");
	for (i = 0;i<N;i++)
		printf("%d ",a[i]);
	printf("%d ",N);
	printf("\n");
	return;
}

void insertSort(int a[], int n ){
	int i,j,t;
	for (i=1; i<n; i++){
		t=a[i];
		j = i-1;
		while (j>=0 && a[j]>t){
			a[j+1] = a[j];
			j--;                                                                                                                            
		}
		a[j+1] = t;
	}
}

void Insert(int a[], int n )
{
	int  i;
	srand(time(0));
	for (i=0; i<N; i++)
		a[i] = rand() % 100;
	printf("初始数据为：");
	for (i=0; i<N; i++)
		printf("%d ",a[i]);
	printf("\n");
	insertSort(a, N);
	printf("排序后数据：");
	for (i=0; i<N; i++)
		for (i=0; i<N; i++)
			printf("%d ", a[i]);

	printf("\n");
	return ;
}

void select1(int a[], int n){
	int i, j, k, m;
	for (i=0; i<n-1; i++){
		m = a[i];
		k = i;
		for (j=i+1; j<n; j++)
			if (a[j] < m){
				m=a[j];
				k=j;

			}
		a[k] = a[i];
		a[i] = m;
	}
}


void Select(int a[], int n )
{
	int  i;
	srand(time(0));
	for (i=0; i<N; i++)
		a[i] = rand() % 100;
	printf("初始数据为：");
	for (i=0; i<N; i++)
		printf("%d ",a[i]);
	printf("\n");
	select1(a, N);
	printf("排序后数据：");
	for (i=0; i<N; i++)
		printf("%d ", a[i]);

	printf("\n");
	return ;
}

//分区
int Partition(int a[], int low, int high)
{
	int x = a[low];
	while (low < high)
	{
		while (low<high && a[high]>=x) high--;
		if (low <high)
		{
			a[low] = a[high];
			low++;
		}
		while (low<high && a[low]<=x) low++;
		if (low < high)
		{
			a[high] = a[low];
			high--;
		}
	}
	a[low] = x;
	return low;
}                                                                                          

//将区间[low...high]的元素进行快排
void QSort(int a[], int low, int high){
	if(low < high){
		int mid = Partition(a, low, high);
		QSort(a, low, mid-1);
		QSort(a, mid+1, high);

	}
}

//快排
void QuickSort(int a[], int n){
	QSort(a, 0, n-1);
}

//输出
void Quick(int a[], int n )
{
	int  i;
	srand(time(0));
	for (i=0; i<N; i++)
		a[i] = rand() % 100;
	printf("初始数据为：");
	for (i=0; i<N; i++)
		printf("%d ",a[i]);
	printf("\n");                                                                          
	QuickSort(a, N);
	printf("排序后数据：");
	for (i=0; i<N; i++)
		printf("%d ", a[i]);

	printf("\n");
	return ;
}
