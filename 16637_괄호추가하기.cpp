#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#define rep(i,start,end) for(int i=start ; i<end ; i++)
using namespace std;

vector <int> num;
vector <char> opt;
int n,_max=-987654321;

int oper(int a,int b, char c){
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
}
void fun(int idx,int _num){
	if(idx==num.size()-1){
		_max=max(_max,_num);
		return; 
	}	
	
	fun(idx+1,oper(_num,num[idx+1],opt[idx]));
	
	if(idx+2 <= num.size()-1){
		int temp = oper(num[idx+1],num[idx+2],opt[idx+1]);
		fun(idx+2,oper(_num,temp,opt[idx]));
	}
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);  
    
	string c;
	cin >> n;
	cin >> c; 
	rep(i,0,n){
		
		if(i%2==0) 
			num.push_back(c[i]-'0'); //문자를 정수로 변환
		else
			opt.push_back(c[i]); 
			
	
	}
	fun(0,num[0]);
	cout << _max;
} 
