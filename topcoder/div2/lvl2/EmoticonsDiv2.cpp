#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;

/*
You can only do two different operations:
--Copy all the emoticons you currently have into the clipboard.
--Paste all emoticons from the clipboard.

Each operation takes precisely one second.
Copying replaces the old content of the clipboard.
Pasting does not empty the clipboard. Note
that you are not allowed to copy just a part of
the emoticons you already have.

getBest( chat, clip ) == absolute best way to get to the tqrget from cur state
	op1 --> 1+getBEst( (chat, chat) )
	op2 --> 1+getBest( chat+clip, clip )
*/

#define MAX 10001

int T;
vector< vector<int> > memo(MAX, vector<int>(MAX,-1));

int getBest( int chat, int clip ) {
	
	if ( chat == T ) return 0;
	if( chat > T ) return 9999999;
	if ( memo[chat][clip] != -1 ) return memo[chat][clip];
	
	int op1 = 999999;
	if ( chat != clip) op1 = 1+getBest( chat, chat );
	
	int op2 = 1+getBest( chat+clip, clip );
	
	int ans = min(op1, op2);
	memo[chat][clip] = ans;
	return memo[chat][clip]
					  ;
}

int main() {
	T=1000;
	int ans =1+getBest(1,1);
	printf("%d\n", ans);
	return 0;
}
