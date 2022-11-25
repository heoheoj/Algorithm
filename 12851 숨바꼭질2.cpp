#include<iostream>
#include<queue>
#define MAX 100005 // 크기 변경하기  
using namespace std;
int N, K, cnt = 0;
queue <int> q;
queue <int> temp;
int visited[MAX][2] = { 0, };
void bfs() {
	bool flag = false;
	int po=0;

	while (1) {
		if (q.empty()) { // 트리레벨이 높아질 때마다 이전 트리레벨에서 생성한 temp를 q에 복사 
			if (flag) {
				cout << visited[po][0]<< endl;
				cout << visited[po][1];
				return;
			}
			q = temp;
			temp = queue <int>();
		}

		int cur = q.front();
		q.pop();
	
	
	
		for(int next: {cur-1,cur+1,cur*2}){
			if(next <0 || next >MAX)
				continue;
			if (!visited[next][0]) { 
				visited[next][0] = visited[cur][0] + 1;
				visited[next][1]+=visited[cur][1];
				temp.push(next);
			}
			else if(visited[next][0] == visited[cur][0]+1) // 같은 레벨 노드인지 확인하는 조건 
				visited[next][1] += visited[cur][1];
			if(next==K && !flag ){ // po가 0 일때가 있어서  flag 를 정의 해줘야한다. 
				po = next;
				flag=true;
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin >> N >> K;
	if (N != K) {
		q.push(N);
		visited[N][0] = 0; 
		visited[N][1]=1;
		bfs();
	}
	else {
		cout << "0\n" << "1";
	}
	return 0;
} 

//7 0 반 례
