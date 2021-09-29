#include<bits/stdc++.h>
#include<string>
#include<iostream>
#define PI  3.141592653589793
#define endl "\n"
#define ll long long
#define INF 9000000000000000000
// #define max(a,b) (a>b?a:b)
// #define min(a,b) (a<b?a:b)
#define pb(a) push_back(a)
#define pop() pop_back()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// rep(i, 0, 10)  OUTPUT: 0 1 2 3 4 5 6 7 8 9 ;
using namespace std;

//---------- JEET SAVSANI ----------//

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int fact(int n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);

}

void reverse(int arr[], int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;  j--;
	}
}

bool issorted(vector<int> arr)
{
	for(int i=0;i<arr.size()-1;i++)
	{
		if(arr[i]>arr[i+1])
			return false;
	}
	return true;
}

void rotate(vector<int> arr,int l,int r)
{
	int temp=arr[l];

	for(int i=l;i<r;i++)
	{
		arr[i]=arr[i+1];
	}
	arr[r]=temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
#endif
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin>>n;

		vector<int> arr(n);
		vector<pair<int,int>> ans;

		for(auto &it:arr) 
			cin>>it;

		while(!issorted(arr))
		{
			int i=0;
			while(i<n)
			{
				int temp=arr[i];
				int j=i;
				while(j<n && arr[j+1]<=temp)
					j++;

				if(j>i)
				{
					rotate(arr,i,j);
					ans.push_back({i+1,j+1});
					break;
				}
				i++;
			}
		}

		// for(int i=0;i<n;i++)
		// 	cout<<arr[i]<<" ";

		// cout<<endl;

		cout<<ans.size()<<endl;

		for(auto it:ans)
			cout<<it.first<<" "<<it.second<<" "<<"1"<<endl;
	}
	
	return 0;
}