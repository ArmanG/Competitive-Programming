#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int boardSize;
int total;
vector<int> arrangement;

/* How many different ways can you fit n non-attacking queens on an nxn chessboard? */

bool isSafeSpot( int column, int k ) {
	for ( int i=0; i<k; i++ ) {
		if ( arrangement[i]==column || abs( arrangement[i]-column )==abs( i-k ) ) {
			return false;
		}
	}
	return true;
}

void placeQueens( int k ) {
	if ( k == boardSize ) {
		total++;
		return;
	} 
	for ( int i=0; i<boardSize; i++ ) {
		if ( isSafeSpot( i, k ) ) {
			arrangement[k]=i;
			placeQueens( k+1 );
			arrangement[k]=-1;
		}
	}
}

int main () {
	cin >> boardSize;
	arrangement.resize(baordSize);
	placeQueens(0);
	cout << total << endl;	
	return 0;
}
