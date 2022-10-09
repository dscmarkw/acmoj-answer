#include <iostream>
using namespace std;
char ans[650];
char* add_two_string(char *p, char *q);
int main(){
    int i,j;
    cin>>i>>j;
    char str1[650];
    char str2[650];
    cin>>str1>>str2;
    if(i>=j) cout<<add_two_string(str1,str2)<<endl;
    else cout<<add_two_string(str2,str1)<<endl;//保证p比q长或者一样长
    return 0;
}
char* add_two_string(char *p, char *q){
    bool k=0;
    int add[650]={0};
    int i,j;
    for(i=0;q[i]!='\0';i++){
        add[i]=(p[i]-'0')+(q[i]-'0')+k;
        if(add[i]>=10){
            k=1;
            add[i]-=10;
        }
        else k=0;
    }
    for(;p[i]!='\0';i++){
        add[i]=(p[i]-'0')+k;
        if(add[i]>=10){
            k=1;
            add[i]-=10;
        }
        else k=0;
    }
    if(k){
        add[i++]=1;
        add[i]=-1;
    }
    else add[i]=-1;
    for(j=0;j<i;j++){
        ans[j]=add[j]+'0';
    }
    ans[i]='\0';
    return ans;
}