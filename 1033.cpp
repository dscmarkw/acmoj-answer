#include <iostream>
using namespace std;
const int MAXN=11;
int det(int **m,int size);
int **A(int **m,int size,int pos);
int main(){
    int n;
	cin>>n;
	int **m;
    m=new int* [n];
    for(register int i=0;i<n;i++){
        m[i]=new int [n];
    }
	for(register int i=0;i<n;i++){
		for(register int j=0;j<n;j++){
			cin>>m[i][j];
		}
    }
    cout<<det(m,n)<<endl;
    return 0;
}
int det(int **m,int size){
    if(size==2){
        return m[0][0]*m[1][1]-m[0][1]*m[1][0];
    }
    if(size==1) return m[0][0];
    bool sig=true;
    int ans=0;
    for(register int i=0;i<size;i++){
        ans+=(sig?1:-1)*m[0][i]*det(A(m,size,i),size-1);
        sig=!sig;
    }
    return ans;
}
int **A(int **m,int size,int pos){
    int **ans=new int* [size-1];
    for(register int i=0;i<size;i++){
        ans[i]=new int [size-1];
    }
    for(register int i=1;i<size;i++){
        int k=0;
        for(register int j=0;j<size;j++){
            if(j==pos) continue;
            ans[i-1][k++]=m[i][j];
        }
    }
    return ans;
}