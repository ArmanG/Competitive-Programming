#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/*
paths( r, c ) = paths( r-1, c ) + paths( r, c-1 )
base:
if c = 0, paths( r, c ) = 1
if r = 0, paths( r, c ) = 1

r=2, c=3

0 1 1
c 1 2

*/

#define MAX 25

vector< vector<int> > ans(MAX, vector<int>(MAX, -1));

int paths (int r, int c) { 
    
    if ( ans[r][c]!=-1 ) return ans[r][c];
    if ( r==0 ) return paths( r, c-1 );
    if ( c==0 ) return paths( r-1,c );
    
    ans[r][c]=paths( r-1, c ) + paths( r, c-1 );
    return ans[r][c];
       
}


int main () {
    
    int r, c, k, cr, cc;
    
    ans[0][0]=1;
    
    scanf( "%d%d", &r, &c );
    
    scanf( "%d", &k );
    for( int i=0; i<k; i++ ) {
        scanf( "%d%d", &cr, &cc );
        ans[cr-1][cc-1] = 0;
    }
    
    int a=paths( r-1, c-1 );
    printf("%d", a);
    
    return 0;
}
