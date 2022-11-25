#include<iostream>
#include<queue>
#define MAX 100005 // ũ�� �����ϱ�  
using namespace std;
int N, K, cnt = 0;
queue <int> q;
queue <int> temp;
int visited[MAX][2] = { 0, };
void bfs() {
	bool flag = false;
	int po=0;

	while (1) {
		if (q.empty()) { // Ʈ�������� ������ ������ ���� Ʈ���������� ������ temp�� q�� ���� 
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
			else if(visited[next][0] == visited[cur][0]+1) // ���� ���� ������� Ȯ���ϴ� ���� 
				visited[next][1] += visited[cur][1];
			if(next==K && !flag ){ // po�� 0 �϶��� �־  flag �� ���� ������Ѵ�. 
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

//7 0 �� ��
