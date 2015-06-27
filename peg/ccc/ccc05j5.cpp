#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
bool isAWord( string word );
bool isMonkeyWord( string word );

int offset = 0;
/*
<monkey-word> ::= <a-word> | <a-word> "N" <monkey-word> 
<a-word> ::= A | "B" <monkey-word> "S" 
*/

bool isAWord( string word ){

	if ( word.size()==0) return false; 

	if ( word=="A" ) return true;

	if ( word.at(0)=='B' && word.at(word.size()-1)=='S' ){
		return isMonkeyWord( word.substr( 1, word.size()-2 ) );
	}
	
	return false;
	
}

bool isMonkeyWord( string word ) {

	if ( word.size()==0) return false; 

	int lastIndex = word.size()-1;

	if ( isAWord( word ) ) return true;

/*
	int nIndex = word.find("N");

	if ( nIndex!=string::npos && nIndex!=lastIndex  && nIndex!=0 ) {
		return isAWord( word.substr( 0, nIndex ) ) && isMonkeyWord( word.substr( nIndex+1, lastIndex-nIndex-1 ) );
	}
*/

// 0123456
// BANANAS	
	for ( int i=0; i<word.size(); i++ ) {
		if ( word[i]=='N' ) {
			if ( isAWord(word.substr(0, i)) && isMonkeyWord( word.substr( i+1))) {
				return true;
			}
		}
	}
	return false;

}




int main() {

	string word;

	while(1) {
		cin >> word;
		if ( word=="X" ) {
			break;
		}
	
		if ( isMonkeyWord(word) ) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;

}
