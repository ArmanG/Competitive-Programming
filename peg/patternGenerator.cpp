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

int N, K;

void bitPatterns( string s, int ones ) {

	if (ones > K) {
		return;
	}

	if ( s.size() == N ){
		if ( ones==K ) {
			printf( "%s\n", s.c_str() );
		}
		return;
		// cout >> s;
	}

	bitPatterns( s+'1', ones+1 );
	bitPatterns( s+'0', ones );

}


int main() {

	scanf("%d %d", &N, &K);


	bitPatterns( "", 0 );

	

	return 0;


}