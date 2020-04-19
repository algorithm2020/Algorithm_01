#include <bits/stdc++.h>
using namespace std;
int visited[10000];
int solution(vector<vector<int>> routes) {
	int answer = 0;
    sort(routes.begin(),routes.end());
    int n=routes.size();
    memset(visited,0,sizeof(visited));
    for(int i=n-1;i>=0;i--){
        if(visited[i]==0) {
            visited[i]=1;
            answer++;
        }
        else continue;
        for(int j=i-1;j>=0;j--){
            if(routes[i][0]<=routes[j][1] && routes[i][0]>=routes[j][0] 
               && visited[j]==0) visited[j]=1;
        }
    }
	return answer;
}
