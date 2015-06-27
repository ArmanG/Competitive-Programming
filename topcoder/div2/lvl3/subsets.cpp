#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
Problem Statement: http://community.topcoder.com/stat?c=problem_statement&pm=10554
1,1,1,1,1,2,3,4,2,2,2
1: 5
2: 4
3: 1
4: 1 
*/

int TEST[1001]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,     0};

vector<int> numbers;
int freq[1001];
int n, sum;
int total;


void backtrack( int currSum, int currProd, int currIndex ) {

	if ( currProd-currSum>1000 ) return;
	if ( currIndex==numbers.size() ){
		if ( currSum>currProd ) total++;
		return;
	}
	else {
	
		int currVal=numbers[currIndex];
		int currFreq=freq[currVal];
		int localSum=0;
		int localProd=1;

		for ( int i=0; i<=currFreq; i++ ) {
			backtrack( currSum+localSum, currProd*localProd, currIndex+1 );
			localSum+=currVal;
			localProd*=currVal;
		}
	}
	
}

int main() {

	set<int> unique;
	for ( int i=0; i<1000; i++ ){
		int val = TEST[i];
		if ( val==0 ) break;
		freq[val]++;
		unique.insert( val );
	}

	vector<int> tmp( unique.begin(), unique.end() );
	numbers=tmp;

	backtrack(0, 1, 0);
	printf("%d\n",total);

	return 0;
}
