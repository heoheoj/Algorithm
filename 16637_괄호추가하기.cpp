#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#define rep(i,start,end) for(int i=start ; i<end ; i++)
using namespace std;

vector <int> num;
vector <char> opt;
int n,_max=-987654321;
//char c;

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
//???	char c[20];
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); //?????
    cout.tie(NULL);  
    
	string c;
	cin >> n;
	cin >> c; //입력 받는 것 문자열로 말고 하나씩은? 
	rep(i,0,n){
		
		if(i%2==0) // 0,2,
			num.push_back(c[i]-'0'); //문자를 정수로 변환
		else
			opt.push_back(c[i]); 
			
	//	cout<< c[i]-'0'<<" ";
	}
	//cout <<endl;cout <<endl;
	//rep(i,0,num.size())
	//	cout << num[i]<<" ";
//	cout <<endl;
	fun(0,num[0]);
	cout << _max;
} 
