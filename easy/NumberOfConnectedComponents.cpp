#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'countIsolatedCommunicationGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY links
 *  2. INTEGER n
 */

void dfs(vector<vector<int>>&adj, vector<int>&visited, int idx){
    visited[idx] = 1;
    for(int i = 0; i < adj[idx].size(); i ++){
        if(visited[adj[idx][i]] == 0){
            dfs(adj, visited, adj[idx][i]);
        }
    }
}
int countIsolatedCommunicationGroups(vector<vector<int>> links, int n) {
   vector<int>visited(n, 0);
   vector<vector<int>>adj;
   for(int i = 0; i < n; i ++){
    adj.push_back(vector<int>());
   }
   for(int i = 0; i < links.size(); i ++){
    int src = links[i][0];
    int dest = links[i][1];
    adj[src].push_back(dest);
    adj[dest].push_back(src);
   }
   int count = 0;
   for(int i = 0; i < n; i ++){
    if(visited[i] == 0){
        count ++;
        dfs(adj, visited, i);
    }
   }
   return count;
}

int main()
{
    string links_rows_temp;
    getline(cin, links_rows_temp);

    int links_rows = stoi(ltrim(rtrim(links_rows_temp)));

    string links_columns_temp;
    getline(cin, links_columns_temp);

    int links_columns = stoi(ltrim(rtrim(links_columns_temp)));

    vector<vector<int>> links(links_rows);

    for (int i = 0; i < links_rows; i++) {
        links[i].resize(links_columns);

        string links_row_temp_temp;
        getline(cin, links_row_temp_temp);

        vector<string> links_row_temp = split(rtrim(links_row_temp_temp));

        for (int j = 0; j < links_columns; j++) {
            int links_row_item = stoi(links_row_temp[j]);

            links[i][j] = links_row_item;
        }
    }

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = countIsolatedCommunicationGroups(links, n);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
