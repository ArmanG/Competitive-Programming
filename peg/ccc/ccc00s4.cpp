#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
t=10
clubs={1,5,6}

6,1,1,1,1
5+5

// best(d) = best way to get to exactly d
case 1:  1+best( 100-5 )
case 2: 1+best( 100-10 )
case 2: 1+best( 100-80 )

base:
best(0)=0
best( x ) = -inf  if x<0

100 
3 
33 
66 
1 
Sample Output

Roberta wins in 3 strokes. 
*/

#define MAX 5280+1

//int best[MAX];
vector<int> best( MAX, -1 );
vector<int> clubs;

int getbest( int d ){
	if ( d<0 ) return 89999999;
	if ( best[d] != -1 )
		return best[d];

	int optimum=9999999;
	for ( int i=0; i<clubs.size(); i++ ){
		int cur_club=clubs[i];
		// case 1:  1+best( 100-5 )
		int cur_strokes=1+getbest( d-cur_club );
		if ( cur_strokes < optimum )
			optimum=cur_strokes;
	}
	
	best[d]=optimum;
	return best[d];
}

int main(void) {
	int n,d;
	scanf( "%d %d", &d, &n );
	while (n--) {
		int temp;
		scanf( "%d", &temp);
		clubs.push_back( temp );
	}

	best[0]=0;
	int ans=getbest( d );

	if (ans > d) {
		printf("Roberta acknowledges defeat.");
	}
	else {
		printf( "Roberta wins in %d strokes.\n", ans );
	}

	return 0;
}
