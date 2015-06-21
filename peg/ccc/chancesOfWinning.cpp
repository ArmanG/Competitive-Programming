
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define TEAMS 5

int outcome[TEAMS][TEAMS];
int total =0;
int fav;

void recurse() {
    
    for ( int i=1; i<TEAMS; i++) {
        for ( int j=i+1; j<TEAMS; j++) {
            if ( outcome[i][j] == 0 ) {
                outcome[i][j]=1;
                recurse();

                outcome[i][j]=2;
                recurse();

                outcome[i][j]=-1;
                recurse();
                
                outcome[i][j]=0;
                
                return;
            }
        }
    }
    
    // base
    vector<int> points(TEAMS,0);
    
    for ( int i=1; i<TEAMS; i++) {
        for ( int j=i+1; j<TEAMS; j++) {
                if (outcome[i][j]==1) {
                    points[i]+=3;
                }
                if ( outcome[i][j]==-1 ) {
                    points[j]+=3;
                }
                if ( outcome[i][j] == 2 ) {
                    points[j]+=1;
                    points[i]+=1;
                }
        }
    }
    
    //printf("%d %d %d %d", points[1], points[2], points[3], points[4]);

    int favPoints = points[fav];
    sort(points.begin(), points.end());
    if (points[4] == favPoints && points[4] != points[3] ) {
        total ++;
        //printf("*******");
    }
    //puts("");
}

int main()
{

    int numGames, A, B, SA, SB;
    scanf("%d %d", &fav, &numGames);
    
    for ( int i=0; i<numGames; i++) {
        scanf("%d %d %d %d", &A, &B, &SA, &SB );
        if ( SA>SB ) {
            outcome[A][B]=1;
            //outcome[B][A]=-1;
        }
        if (SA<SB) {
            //outcome[B][A]=1;
            outcome[A][B]=-1;
        }
        if (SA == SB){
            outcome[A][B]=2;
           // outcome[B][A]=2;
        }
        
    }
    
    recurse();
    printf("%d\n", total);
    return 0;
}

/*

*/
 