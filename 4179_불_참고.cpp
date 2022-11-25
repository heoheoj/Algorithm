#include <iostream>
#include <queue>
#define rep(i,x,n) for(int i=x;i<n;i++)
using namespace std;

const int INF=987654321;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
int fire[1005][1005]={0,}, person[1005][1005]={0,}; 
int R,C,start_i,start_j;
char arr[1005][1005]={0,};
int main(){
	cin.tie(0); 
	cout.tie(0);
	fill (&person[0][0],&person[0][0]+1005*1005,INF);
	fill (&fire[0][0],&fire[0][0]+1005*1005,INF);//***c++에서 배열 채우는 법 
	queue<pair<int, int> > q;
	cin >>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> arr[i][j];	
			if(arr[i][j]=='F'){
				fire[i][j]=1;
				q.push(make_pair(i,j));
			}
			if(arr[i][j]=='J'){
				start_i=i;
				start_j=j;
			}
		}
	}
	
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			//cout <<"nx,ny="<< nx <<","<< ny<< endl;
			if(0<=nx&& nx<C && 0<=ny && ny<R){
				if(fire[ny][nx]==INF&&arr[ny][nx]!='#'){
					fire[ny][nx]=fire[y][x]+1;
					q.push(make_pair(ny,nx));
				}
			}
		}
	}
	
	q.push(make_pair(start_i,start_j));
	person[start_i][start_j]=1;
	
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(0<=nx&& nx<C && 0<=ny && ny<R){
				if(person[ny][nx]==INF&& arr[ny][nx]!='#'){
					person[ny][nx]=person[y][x]+1;
					q.push(make_pair(ny,nx));
				}
			}
		}
	}
	
	/*	
	rep(i,0,R){
		rep(j,0,C){
			cout << fire[i][j] << " ";
		}
		cout <<endl;
	}
	cout <<endl;
	rep(i,0,R){
		rep(j,0,C){
			cout << person[i][j] << " ";
		}
		cout <<endl;
	}


	//cout <<endl;
	int _max=0;
	rep(i,0,R){
		rep(j,0,C){
			if(person[i][j]<fire[i][j]){
				_max=max(_max,person[i][j]);
			}
			
		}
	}

	int _max=0;
	for(int i=0;i<R;i+=R-1){
		for(int j=0;j<C;j++){
			if(person[i][j]<fire[i][j]){
				_max=max(_max,person[i][j]);
			}
	
		}
	}
	for(int i=1;i<R-1;i++){
		for(int j=0;j<C;j+=C-1){
			if(person[i][j]<fire[i][j]){
				_max=max(_max,person[i][j]);
			}
	
		}
	}	
	*/
	int _min=INF;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(i==0||i==R-1||j==0||j==C-1){ //***모서리만 접근하는 방법 
				if(person[i][j]<fire[i][j]) //fire가 주어지지 않는 경우도 있기때문에 배열 초기화를 INF로 해줘야한다. 
				//fire[i][j]!=INF 로 인해 반례가 발생한다.  
					_min=min(_min,person[i][j]); 
			}
		}
	}	
	
	if(_min!=INF)
		cout << _min;
	else 
		cout << "IMPOSSIBLE\n";


	return 0;
	
}
