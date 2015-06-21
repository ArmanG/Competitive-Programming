#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h> 
using namespace std;


/*

start at x,y 
get to x2,y2

try all possible moves from x,y
check if at x2,y2
recurse
keep track of number of moves

base cases:
out of range

*/

int minMoves = 1000000000;
bool visited[9][9];
int tx, ty;

void recurse(int x, int y, int currMoves) {

	if ( x>8 || y>8 || x<1 || y<1 ) return;

	if (visited[x][y] == true) return;

	if (currMoves > minMoves) return;

	//printf("x:%d, y:%d, currMoves:%d\n", x, y, currMoves);
	if (x==tx && y==ty) {
		if (currMoves < minMoves) {
			//printf("****currMoves:%d\n", currMoves);
			minMoves=currMoves;
		}
		return;
	}

	visited[x][y] =true;

	for(int dx=-2; dx<=2; dx++) {
		for(int dy=-2; dy<=2; dy++) {
			if (abs(dx)+abs(dy) == 3) {
				recurse(x+dx, y+dy, currMoves+1);
			}
		}
	}

	
	visited[x][y] =false;
}

int main() {

	int sx,sy;
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &tx, &ty);

	recurse(sx, sy, 0);

	printf("%d\n", minMoves);


}
