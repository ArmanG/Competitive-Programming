#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> motel;
int dist[55] = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000, -1 };

int a,b;
int total=0;

/*
Determine if it is possible to complete the journey if:

the trucking company insists that the driver travels a minimum distance of A km per day,
the law sets a maximum distance of B km per day, and
each night, the driver must stay at an eligible motel (from the above list or the additional locations described below).
*/

void recurse( int lastMotel, int curMotel ) {
	int diff=motel[curMotel]-motel[lastMotel];
	if ( diff > b ) return;

	if ( curMotel == motel.size()-1 ){
		total++;
		//printf("*** Lst: %d, curr: %d\n", lastMotel, curMotel);
		return;
	}

	
	//printf("Lst: %d, curr: %d, diff %d\n", lastMotel, curMotel, diff);

	

	// stay at cur hotel
	if ( diff>=a )
		recurse( curMotel, curMotel+1 );

	// DONT stay

	recurse( lastMotel, curMotel+1 );
}


int main() {

	scanf("%d %d", &a, &b);
	int m,t;

	for ( t=0; dist[t]>=0; t++ )
		motel.push_back( dist[t] );

	scanf( "%d", &m );
	while ( m-- ){
		scanf( "%d", &t );
		motel.push_back(t);
	}

	sort( motel.begin(), motel.end() );
	
	recurse(0, 1);
	printf("%d\n", total);

	return 0;


}