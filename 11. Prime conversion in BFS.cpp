// Convert two 4 digit prime number in minimum ways where
// in one step you can only change 1 digit
// Problem Link: https://www.spoj.com/MAIN10/problems/PPATH/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int mx = 1e5+1;
vector<int>primes;
int isVisited[mx], dist[mx];
vector<int> graph[mx];

void BFS(int source) {
	isVisited[source] = 1;
	dist[source] = 0;
	queue<int> q;
	q.push(source);
	
	while(!q.empty()) {
		int current = q.front();
		q.pop();
		
		for(int child: graph[current]) {
			if(isVisited[child] == 0) {
				dist[child] = dist[current]+1;
				isVisited[child] = 1;
				q.push(child);
			}
		}
	}
}

void testCase() {
	int a, b; cin >> a >> b;
	
	for(int i=1000; i<=9999; i++) dist[i]=-1, isVisited[i]=0;
	
	BFS(a);
	
	if(dist[b]==-1) cout << "Impossible\n";
	else cout << dist[b] << endl;
}

bool isValid(int a, int b) {
	int cnt = 0;
	while(a>0) {
		if(a%10 != b%10) cnt++;
		
		a/=10; b/=10;
	}
	
	if(cnt == 1) return true;
	return false;
}

void buildGraph() {
	for(int i=0; i<primes.size(); i++)
		for(int j=i+1; j<primes.size(); j++)
			if(isValid(primes[i], primes[j])) {
				graph[primes[i]].push_back(primes[j]);
				graph[primes[j]].push_back(primes[i]);
			}
}

bool isPrime(int n) {
	for(int i=2; i*i<=n; i++)
		if(n%i==0) return false;
	
	return true;
}

void primeFinder() {
	for(int i=1001; i<=9999; i++)
		if(isPrime(i)) primes.push_back(i);
}

int main() {
	primeFinder();
	
	buildGraph();
	
	int t; cin >> t;
	while(t--) testCase();
}
