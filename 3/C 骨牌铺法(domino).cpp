#include<iostream>
using namespace std;
int main() {
	int a[10000],n;
	a[0]=1;
	a[1]=2;
	a[2]=4;
	cin>>n;
	for(int i=4; i<=n; ++i) {
		a[i-1]=a[i-2]+a[i-3]+a[i-4];
	}
	cout<<a[n-1];
	return 0;
}