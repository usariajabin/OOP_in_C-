#include<iostream>
using namespace std;

bool equivalent(int a[],int b[],int n){
	int shift=0;
	for(int c=0; c<n; c++){
		if (a[0]!=b[c]) shift+=1;
		else break;
	}	 

	for(int d=0; d<n; d++){ 
		if (a[d]!=b[(d+shift)%5]) return false;
		}
		return true;
}
int main(){
	int a[]={1,2,3,4,5};
	int b[]={3,4,5,1,2};
	
	bool testResult;
	testResult= equivalent(a,b,5);
	cout<< testResult<<endl;
	return 0;
}
