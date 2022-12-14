#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n=0,t=0,k=0;
	cin>>n>>t>>k;
	priority_queue<int,vector<int>,greater<int>> q;
	for(register int i=0;i<n;i++){
		int a=0;
		cin>>a;
		q.push(a);
	}
	int sum=0;
	for(register int i=0;i<n;i++){
		int x=q.top();
		q.pop();
		sum+=x;
		if(sum>=k-t){
			double score=10+90*i/n;
			cout<<(int)score<<endl;
			return 0;
		}
	}
	cout<<100<<endl;
	return 0;
}