#include<iostream>
#include<queue>
#define rep(i,start,end) for(int i=start;i<end;i++)
using namespace std; 
int attack[6][3]={
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3} 
};

struct st {
	int a;
	int b;
	int c;
};

queue <st> q;
int visited[65][65][65];

void solve(){
	while(!q.empty()){
		int na=q.front().a;
		int nb=q.front().b;
		int nc=q.front().c;
		q.pop();
//		if(visited[na][nb][nc])
//			continue;
		if(visited[0][0][0])
			break; 
		
		rep(i,0,6){
			//방문한 곳을 메모제이션 하기위해 음수는 0으로 해준다. max를 사용해서
			int _a=max(0,na-attack[i][0]);
			int _b=max(0,nb-attack[i][1]);
			int _c=max(0,nc-attack[i][2]);
			if(visited[_a][_b][_c]==0){ //이미 이전에 방문한 케이스는 방문하지 않는다. 
				q.push({_a,_b,_c});
				visited[_a][_b][_c]=visited[na][nb][nc]+1; //메모제이션을 통해 트리의 레벨을 저장한다. 
			} 
		}
	}	
}
int main(void){
	int n;
	int arr[3]={0};
	cin >> n;
	rep(i,0,n){
		cin >> arr[i];
	}
	q.push({arr[0],arr[1],arr[2]});
	solve();
	cout << visited[0][0][0];
}
