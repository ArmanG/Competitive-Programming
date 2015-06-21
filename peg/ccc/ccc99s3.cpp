#include <stdio.h>
#include <string.h>
FILE *in,*out;

int r,n;
int p3[10]={ 1,3,9,27,81,243,729 };
char matrix[800][800];

void fill( int left, int right, int top, int bottom, int level ){

	if ( level==0 )
	 return;

	printf( "%d %d %d %d lev=%d\n", left,right,top,bottom,level );

	int xx=(right-left)/3;
	int yy=(top-bottom)/3;
	int x,y;

	// middle
	for ( y=bottom+yy; y<bottom+2*yy; y++ )
	 for ( x=left+xx; x<left+2*xx; x++ )
	  matrix[y][x]=' ';
	// other parts

	// top
	for ( x=left; x<right; x+=xx )
	 fill( x,x+xx,top,top-yy,level-1 );
	// bottom
	for ( x=left; x<right; x+=xx )
	 fill( x,x+xx,top-2*yy,top-3*yy,level-1 );

	x=left;
	fill( x,x+xx,top-yy,top-2*yy,level-1 );
	fill( x+2*xx,x+3*xx,top-yy,top-2*yy,level-1 );

}

void main( void ){
in=fopen( "fractal.in", "r" );
out=fopen( "fractal.out", "w" );

fscanf( in, "%d%d", &r, &n );

memset( matrix, 0, sizeof(matrix) );

int i,j;
for ( i=p3[r]-1; i>=0; i-- )
 for ( j=0; j<p3[r]; j++ )
  matrix[i][j]='*';

fill( 0,p3[3],p3[r],0, n );

for ( i=p3[r]-1; i>=0; fputc('\n',out),i-- )
 for ( j=0; j<p3[r]; j++ )
	 fputc( matrix[i][j],out );

}
