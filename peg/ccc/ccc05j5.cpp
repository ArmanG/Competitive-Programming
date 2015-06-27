#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isAWord( string word );
bool isMonkeyWord( string word );

/*
<monkey-word> ::= <a-word> | <a-word> "N" <monkey-word> 
<a-word> ::= A | "B" <monkey-word> "S" 
*/


bool isAWord( string word ){

	if ( word.size()==0) return false; 
	if ( word=="A" ) return true;
	if ( word.at(0)=='B' && word.at(word.size()-1)=='S' ) return isMonkeyWord( word.substr( 1, word.size()-2 ) );
	return false;
	
}


bool isMonkeyWord( string word ) {

	if ( word.size()==0) return false; 
	if ( isAWord( word ) ) return true;

// 0123456
// BANANAS	
	for ( int i=0; i<word.size(); i++ ) {
		if ( word[i]=='N' ) {
			if ( isAWord(word.substr(0, i)) && isMonkeyWord( word.substr( i+1))) return true;
		}
	}
	return false;

}


int main() {

	string word;
	while(1) {
		cin >> word;
		if ( word=="X" ) break;
		( isMonkeyWord( word ) ) ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}
