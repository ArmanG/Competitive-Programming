
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Let A and B be two sequences of non-empty strings:
A = (a1, a2, ..., an), B = (b1, b2, ..., bn).
Let m be a positive integer. Does there exist a sequence of integers
i1, i2, ..., ik such that m > k > 0 and ai1ai2...aik = bi1bi2...bik?

For example, if A = (a, abaaa, ab) and B = (aaa, ab, b), 
then the required sequence of integers is (2,1,1,3) 
giving abaaaaaab = abaaaaaab

2 --> abaaa , ab
1 --> abaaa+a , ab+aaa
1 --> abaaa+a+a , ab+aaa+aaa
3 --  abaaaaaab = abaaaaaab
*/

vector<string> a,b;
vector<int> ind(41);
int m;
bool found;

void recurse(string left, string right, int cur) {
	if (found) return;
	if ( cur==m) return;

	int len = min(left.size(), right.size());

	for ( int i=0; i<len; i++ ) {
		if (left[i] != right[i]) {
			return;
		}
	}

	if ( len > 0 && left == right ) {
		//printf("%s\n", left.c_str() );
		printf("%d\n", cur);

		for ( int j=0; j<cur; j++) {
			printf ("%d\n" , ind[j]+1);
		}
		found=true;
		return;
	}

	for ( int i=0; i<a.size(); i++ ) {
		ind[cur] =i;
		recurse(left+a[i], right+b[i], cur+1);

	}

}

int main()
{
	char temp[22];
	int n;
	scanf("%d %d", &m, &n);

	for (int i=0; i<n; i++){
		scanf("%s", temp);
		string foo = temp;
		a.push_back(foo);
	}

	for (int i=0; i<n; i++){
		scanf("%s", temp);
		string foo = temp;
		b.push_back(foo);
	}

	recurse("","",0);
	if (!found) printf("No solution.\n");


    return 0;
}

/*

*/
 