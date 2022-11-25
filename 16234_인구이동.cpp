#include<iostream>
#include<cstring> // memeset ��� 
#include<cmath> // abs ��� 
#include<queue>
#define rep(i,start,end) for(int i=start;i<end;i++)
using namespace std;

bool move_flag,flag;
int N,L,R,cnt,total_people;
int arr[55][55],visited[55][55],pass[55][55]={0,};
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
queue<pair<int,int> >q;
queue<pair<int,int> >_union;


void move_people(){
	int average= total_people/cnt;
	
	while(!_union.empty()){
		int y=_union.front().first;
		int x=_union.front().second;
		
	//	cout << "("<< y << "," << x <<")";
		
		pass[y][x]=1;
		_union.pop();
		arr[y][x]=average;
	}
	
//	cout <<average<<endl;
	flag=true;
}
void bfs(){
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		
		rep(i,0,4){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny>=0 && ny<N && nx>=0 && nx<N){
				if(visited[ny][nx]==0){
					int gap=abs(arr[y][x]-arr[ny][nx]);
					if(gap>=L && gap<=R){
						q.push({ny,nx});
						_union.push({ny,nx});
						visited[ny][nx]=1;
						total_people+=arr[ny][nx];
						move_flag=true;
						cnt++;
					}
				}
			}
		}
	//	if(move_flag) 
	//		cnt++;// ���ձ� ����  
	}
	if(move_flag){ //cnt>1 
		move_people();
	}
		
}
int main(void){
	int answer=0;
	cin >>N >>L >>R;
	rep(i,0,N){
		rep(j,0,N){
			cin >> arr[i][j];
		}
	}
	while(1){ //���� 4 ����   �ѹ� �� ���� answer++�ϰ� �ٽ� ���鼭 ���� �����ؾߵǴµ� �������� ��ó�� answer�� �ѹ��� ���� 
		flag=false;
		memset(pass,0,sizeof(pass));
		memset(visited,0,sizeof(visited));
		//q=queue<pair<int,int> >();
		
		
		rep(i,0,N){     //while������ �ؾߵɰͰ�����  ��� �� �� ���Ҵµ� move_flag�� false���� ���� 
			rep(j,0,N){
				if(pass[i][j]==1)
					continue;
				q = queue<pair<int, int> >();
			_union = queue<pair<int, int> >();
				total_people=0;
				move_flag=false;
				cnt=1;
				total_people+=arr[i][j];
				q.push({i,j});
				_union.push({i,j});
				visited[i][j]=1;
				bfs();
				//if(_union.size()==1)
				//	continue;
			}
		}
		if(flag)
					answer++;
		else
			break;
	}
	cout <<answer;
}
