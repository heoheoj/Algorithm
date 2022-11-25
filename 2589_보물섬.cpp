#include<iostream>
#include<queue>
#include<cstring>
#define rep(i,start,end) for(int i=start;i<end;i++)
using namespace std;

queue <pair<int ,int> > land;
queue <pair<int ,int> > q;
int w,h,mx=0;
char arr[55][55];
int visited[55][55], dy[4]={-1, 0, 1, 0},dx[4]={0, 1, 0, -1};
void bfs(int _i,int _j){
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		//if(visited[ny][nx]==1)
		//	continue;
		//visited[ny][nx]=1;
		rep(i,0,4){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny>=0&& ny<h && nx>=0 && nx<w){
				if(arr[ny][nx]=='L' && visited[ny][nx]==0){
					q.push({ny,nx});
					visited[ny][nx]=visited[y][x]+1;
					mx=max(mx,visited[ny][nx]);
				}
			}
		}
	}
}
int main(void){
	cin >> h >> w;
	
	rep(i,0,h){
		rep(j,0,w){
			cin >> arr[i][j];
			
		}
	}


	rep(i,0,h){
		rep(j,0,w){
			if(arr[i][j]=='L'){
				q=queue <pair<int ,int> >();
				memset(visited,0,sizeof(visited));
				q.push({i,j});
				visited[i][j]=1;
				bfs(i,j);
			}
				
		}
	}
	cout << mx-1;
	return 0;
}
