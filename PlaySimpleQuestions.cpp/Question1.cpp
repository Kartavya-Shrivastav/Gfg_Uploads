#include <bits/stdc++.h>
using namespace std;

/*
n m
[ [] [] [] [... m size]  ...n times]
q
[ [] [] []]l


Example Input:
5 5
{ [2 4 2 -1 -1]
  [2 4 1 1 -1]
  [3 9 8 1 -1]
  [3 9 8 -1 -1]
  [5 7 9 -1 -1]
}
2
{
  [2 4 -1 -1]
  [3 9 8 -1]
}

Example Output:
{2, 2}
*/


vector<int> bot(int N, int M, vector<vector<int>> &games, int Q, vector<vector<int>> &queries) {

    vector<int> ans;

    for(vector<int> &query: queries){
        int posSize = 0;
        for(int i: query) 
            if(i != -1) posSize++;

        query.resize(posSize);
    }

    for(vector<int> query: queries){
        int count = 0;
        for(vector<int> &game: games){
            if(search(query.begin(), query.end(), game.begin(), game.begin() + query.size()) != query.end()){
                count++;
            }
        }
        ans.push_back(count);
    }
    

    return ans;
}


int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> games = { {2, 4, 2, -1, -1},
                                  {2, 4, 1, 1, -1},
                                  {3, 9, 8, 1, -1},
                                  {3, 9, 8, -1, -1},
                                  {5, 7, 9, -1, -1} };

    int Q;
    cin >> Q;

    vector<vector<int>> queries = { {2, 4, -1, -1},
                                     {3, 9, 8, -1} };

    vector<int> result = bot(N, M, games, Q, queries);

    // for(int r: result){
    //     cout << r << " ";
    // }
    // cout << "\n";

    return 0;
}