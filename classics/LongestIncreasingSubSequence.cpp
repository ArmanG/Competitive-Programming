#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 5001

vector<int> S(MAX,1);
vector<int> seq;
int n;

int LIS() {
    
	for ( int i=1; i<n; i++ ) {
		for ( int j=0;j<i; j++ ) {
			if ( seq[j] < seq[i] && S[j] >= S[i] ) {
				S[i]=S[j]+1;
			}
		}
	}
	
	int max=0;
	for ( int i=0; i<MAX; i++ ) {
		if ( S[i] > max ) {
			max=S[i];
		}
	}
	
	return max;
}

int main ( void ) {

	scanf("%d", &n);
	for ( int i=0; i<n; i++ ) {
		int ni;
		scanf("%d", &ni);
		seq.push_back(ni);
	}

	int ans = LIS();
	printf("%d\n", ans);
	return 0;
	
}
