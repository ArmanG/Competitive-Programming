#include <cstdio>
#include <string>
#include <vector>

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
	}
	bitPatterns( s+'1', ones+1 );
	bitPatterns( s+'0', ones );
}

int main() {
	scanf("%d %d", &N, &K);
	bitPatterns( "", 0 );
	return 0;
}
