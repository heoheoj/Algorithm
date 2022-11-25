#include<stdio.h>
#include<iostream>
#include<vector> 
#include<cstdlib>
#define rep(i,start,end) for(int i=start;i<end;i++)
using namespace std;
const int MAX=987654321;
vector <pair<int,int> >home;
vector <pair<int,int> >chicken;
int arr[55][55];
int N,M,answer=MAX;

void distance(vector<pair<int,int> >v){
	int dis,dis_chicken,city_chicken=0;
	
	rep(i,0,home.size()){
		dis_chicken=MAX; //치킨거리 
		rep(j,0,M){
			dis= abs(home[i].first-v[j].first) + abs(home[i].second-v[j].second);
			dis_chicken=min(dis_chicken,dis);
		}
		city_chicken+=dis_chicken;
	}
	
	answer = min(city_chicken,answer);
}
void combi(int start,vector <pair<int,int> >v){
	if(v.size()==M){//M개의 치킨집을 선택
		distance(v);
		return; 
	}
	
	for(int i=start+1 ; i<chicken.size() ; i++){
		v.push_back(chicken[i]);
		combi(i,v);
		v.pop_back();
	}
	return;
}

int main(void){
	cin >>N >> M;
	rep(i,0,N){
		rep(j,0,N){
			cin >> arr[i][j];
			if(arr[i][j]==1)
				home.push_back({i,j});
			else if(arr[i][j]==2)
				chicken.push_back({i,j});
		}
	}
	
	vector <pair<int,int> > v;
	combi(-1,v);
	cout << answer;
	
}
