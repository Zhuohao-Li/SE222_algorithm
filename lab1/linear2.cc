#include<iostream>
//#include<algorithm>
using namespace std;
int select(int a[],int l,int r,int k);
int med_select(int a[], int l,int r);
int position(int a[],int l,int r,int m);
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<select(a,0,9,0)<<endl;
	return 0;
 } 
 int select(int a[],int l,int r,int k)
{
	if(l<r)
	{
		if(r-l+1<=5)
		{
			
			int *arr = new int[r-l+1];
			for(int i = 0 ;i < r-l+1 ; i ++)
			{
				arr[i] = a[l+i];
			}
			sort(arr,arr+r-l+1);
			return arr[k-l];
		}
		else
		{
			int m = med_select(a,l,r);
			int p = position(a,l,r,m);
			if(p == k)
				return a[p];
			else if(p>k)
				return select(a,l,p-1,k);
			else if(p<k)
				return select(a,p+1,r,k);
		}
	}
	else
	{
		return a[l];
	}
}
int med_select(int a[], int l,int r)
{
		int size = r-l+1;  
		int median_num = size/5; 
		int **arr = new int *[median_num+1];
		for(int i = 0 ;i < median_num+1 ; i++)
			arr[i] = new int[5+1];
		int *median = new int[median_num];
		int jishu = 1;
		for(int i = 1 ; i < median_num+1; i++)
		{
			for(int j = 1 ; j < 5+1 ;j++)
			{	
				arr[i][j] = a[jishu++];
			}
			median[i] = select(arr[i],1,5,3); 
		}
		return select(median,1,median_num,median_num/2);
}

int position(int a[],int l,int r,int m)
{
	int x;    //x记录位置 
	
	for(int i = l ; i <= r ; i++)
	{
		if(a[i] == m)
		{
			x = i;
			break;
		}
	}
	
	int t = a[l];
	a[l] = a[x];
	a[x] = t; 
	
	int i = l,j = r;
	cout<<endl;
	while(i < j)
	{
		while(i<j && a[j] > m)
			j--;
		if(i<j)
		{
			a[i++] = a[j];
		} 	
		while(i<j && a[i] <= m)
			i++;
		if(i<j)
		{
			a[j--] = a[i];
		} 
			
	}
	a[i] = m;
	return i;
}


