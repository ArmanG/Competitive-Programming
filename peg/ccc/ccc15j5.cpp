#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
using namespace std;

/*

curPart = [ i, ?, ?, ?, ... ]
len( curPart ) = k
sum( curPart ) = n

ways( n, k, minVal ) =
	total=0
	for i = minVal to n
		total+= ways( n-i, k-1, i )

ways(8,4,1)
	total+= ways(7,3,1) --> ways(6,2,1) + ways(5,2,2) + ways(4,2,3)
			ways(6,3,2) --> ways(4,2,2) + ways(3,2,3)
			ways(5,3,3) --> ways(2,2,3)

- - |- - -| - - -
| |

*/

#define MAX 250

vector<int> dim1( MAX,-1 );
vector< vector<int> > dim2( MAX, dim1 );
vector< vector< vector<int> > > memo( MAX, dim2 );


int recurse( int n, int k, int minVal ) {

	if ( n==0 && k==0 ) return 1;
	if (n<0 || k<0 ) return 0;
	if ( minVal*k > n ) return 0;
	if ( memo[n][k][minVal] != -1 ) return memo[n][k][minVal];

	int total=0;
	for ( int i=minVal; i<=n; i++ ) {
		total += recurse( n-i, k-1, i );
	}

	memo[n][k][minVal] = total;
	return total;

}

int main() {
	int n, k;
	scanf("%d %d", &n, &k );
	int ans = recurse( n, k, 1);
	printf("%d\n", ans);
	return 0;
}
