#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<int> best( 101, -1 );
vector<int> best_length(101, -1);
vector<string> names;
vector<int> times;
int m , n, timer;
string word;

vector<string> final_names();

void printnames(int k)
{
    if (k <= 0) return;
    int cur_length = best_length[k];
    printnames(k-cur_length);
    string stringer = "";
    for (int i = k - cur_length + 1; i <= k;i++)
        stringer += names[i] + " ";
    stringer.erase(stringer.size() - 1);
    cout << stringer << endl;
}

int max_time(int i, int j)
{
    int maxim = times[i];
    for(i = i + 1;i <= j;i++)
        if ( times[i] > maxim )
            maxim = times[i];
    return maxim;
}

int getbest(int k)
{
    if (k < 0) return 9999999;
    if (best[k] != -1) return best[k];

    int best_cost = 9999999;
    int best_length = 9999999;

    for (int length = 1; length <= m; length++)
    {
        int left = k - length + 1;
        int cost = max_time(left, k) + getbest(left-1);
        if (cost < best_cost){
            best_cost = cost;
            best_length = length;
        }
    }

    best_length[k] = best_length;
    best[k] = best_cost;
    return best_cost;
}

int main()
{

    //ifstream in ("test.txt");

    cin >> m >> n;
    names.push_back("none");
    times.push_back(654654654);

    for (int i = 0 ; i < n;i++)
    {
        cin >> word >> timer;
        names.push_back(word);
        times.push_back(timer);
    }

    best[1] = times[1];
    best[0] = 0;
    best_length[1] = 1;

    cout << "Total Time: " << getbest(n) << endl;
    printnames(n);
    return 0;
}

/*
Let best[k] represent the best way of sending the first k people across the bridge.
 all the possible ways to form the final group of people that ends at exactly index k.
For example if M=2, then the last group can be formed in only 2 ways: either person[k] goes alone,
or { person[k-1], person[k] } form a group of 2 and then you have a sub-problem of finding 
the best way to send the first k-2 people.

m = 2
 (8  5)  (3)
*/
 