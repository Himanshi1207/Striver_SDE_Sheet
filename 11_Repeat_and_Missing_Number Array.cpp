#include<bits/stdc++.h>
using namespace std;
vector<int> repeatedNumber(const vector<int> &arr) {
    int n=arr.size();
    int xr=0;
	for(int i=0;i<n;i++){
		xr=xr^arr[i];
		xr=xr^(i+1);
	}
	int setbit=0;
	while(1){
		if((xr&(1<<setbit))!=0)
		break;
		setbit++;
	}
	int zero=0, one=0;
	for(int i=0;i<n;i++){
		if((arr[i]&(1<<setbit))!=0){
			one^=arr[i];
		}
		else{
			zero^=arr[i];
		}
	}
	for(int i=0;i<n;i++){
		if(((i+1)&(1<<setbit))!=0){
			one^=(i+1);
		}
		else{
			zero^=(i+1);
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i]==zero) cnt++;
	}
	if(cnt==2) return {zero, one};
	return {one, zero};

}
