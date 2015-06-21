#include <cstdio>
#include <string>
#include <vector>


/*
n=3
000
001
010
011
100
101
110
111

n=2
00
01
10
11

n=1
0
1

0 1 
00 01 10 11 
000 001 010 011 100 111
*/

using namespace std;


#define MAX 10000

vector< vector<int> > incoming(MAX, vector<int>() );
vector<int> memo( MAX, -1 );

int getWays(int k) {

	if (k == 1) {
		return 1;
	}
	if (memo[k] != -1) return memo[k];

	int total = 0;

	for (int i=0; i<incoming[k].size(); i++) {
		total += getWays(incoming[k][i]);
	}
	//printf("K: %d Total: %d\n", k, total);
	return memo[k]=total;
}

int main() {

	int n, n1, n2;

	n1 = -1;
	n2 = -1;
	scanf("%d", &n);
	while (n1) {
		scanf("%d %d", &n1, &n2);
		incoming[n2].push_back(n1);
	}
	
	int ans = getWays(n);

	printf("%d\n", ans);

	

	return 0;


}