#include<bits/stdc++.h>
using namespace std;

struct tt {
	int first,second,index;
	
};

bool comp(const tt & n1,const tt & n2){
		if(n1.first == n2.first){
			if(n1.second==n2.second)
			{
				return n1.index>n2.index;
			}
			else 
				return n1.second<n2.second;
		}
		else
			return n1.first<n2.first;
	}


#define maxn (int)(1<<20)
int SA[maxn];
string str; //1 based indexed 
int p[20][maxn];
int N;
tt L[maxn];
int pow2[20];

void createSuffixArray(){

L[0].first=L[0].second=L[0].index=-7;
if(N==1){
	p[0][1]=1;
}
else{
	for(int i=1;i<=N;i++){
		p[0][i] = str[i]-'a'; 
	}
}

for(int k=0;k<=20;k++)
	pow2[k]= 1<<k;

int k=1;
while(pow2[k-1]<N){
	for(int j=1;j<=N;j++){
		L[j].index=j;
		L[j].first=p[k-1][j];
		L[j].second= ( (j+pow2[k-1]) <= N ? p[k-1][j+pow2[k-1]] :-1);
	}
/*	for(int i=0;i<=N;i++){
		cout<<"L["<<i<<"]"<<' '<<L[i].first<<" "<<L[i].second<<' '<<L[i].index<<'\n';
	}
*/
	sort(L,L+N+1,comp);
/*	for(int i=0;i<=N;i++){
		cout<<"L["<<i<<"]"<<' '<<L[i].first<<" "<<L[i].second<<' '<<L[i].index<<'\n';
	}
*/	
	for(int j=1;j<=N;j++){
		p[k][L[j].index] = ( ( ( j>1 && (L[j].first == L[j-1].first) ) && 
			(L[j].second==L[j-1].second) ) 
			? p[k][L[j-1].index] :
			 j );
	}
 ++k;
}
int step=k-1;
//cout<<"step"<<step;
for(int i=1;i<=N;i++){
	SA [ p[step][i] ] =i;
}
/*
for(int k=0;k<=step;k++){
	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;j++)
			cout<<str[j];
		    cout<<':';
		    cout<<p[k][i]<<" ";
	}
	cout<<'\n';
}
*/

}

int main(){
	string s;
	cin>>s;
	N=s.length();
	str ="a"+s;
	cout<<str<<'\n';

	createSuffixArray();
/*
	for(int i=1;i<=N;i++){
		cout<<SA[i]<<" ";
	}
*/
	
}

