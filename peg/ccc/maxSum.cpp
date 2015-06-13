#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
// best(k) = MAX(  a[k] + best(k-2), best(k-1)  )
case 1:  take index k --> a[k] + best(k-2)
case 2: DONT take k --> best(k-1)
For example, for the array 

   0 1 2 3 4
a= 4 5 6 9 10:

b(4) --> b(3), b(2)

4 6 10 is valid, while 5 9 10 is invalid since 9 and 10 are next to each other.
4 6 10 happens to be the optimal sum in this case, so 20 is the answer.
*/

#define MAX 100000

//int best[MAX];
vector<int> best( MAX, -1 );
int a[MAX];

int getbest( int k ){
	if ( k<0 ) return 0;
	if ( best[k] != -1 )
		return best[k];

	best[k]=max( a[k] + getbest(k-2), getbest(k-1) );
	return best[k];
}

int main(void) {
	int n;
	scanf( "%d", &n );
	for(int i = 0; i < n; i++) {
		scanf( "%d", &a[i] );
	}

	int ans=getbest( n-1 );
	printf( "%d\n", ans );

	return 0;
}
