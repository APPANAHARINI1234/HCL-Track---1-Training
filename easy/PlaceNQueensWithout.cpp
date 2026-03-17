#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'canPlaceSecurityCameras' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. 2D_INTEGER_ARRAY grid
 */
bool placed(vector<vector<int>>grid, int i1, int j1){
    for(int i = 0; i < grid.size(); i ++){
        if(grid[i][j1] == 2)
         return false;
    }
    for(int i = 0; i < grid.size(); i ++){
        if(grid[i1][i] == 2)
         return false;
    }
    int i = i1 - 1;
    int j = j1 - 1;
    while(i >= 0 && j >= 0){
        if(grid[i][j] == 2)
         return false;
         i --;
         j --;
    }
    i = i1 + 1;
    j = j1 + 1;
    while(i < grid.size() && j < grid[0].size()){
        if(grid[i][j] == 2)
         return false;
         i ++;
         j ++;
    }
    i = i1 - 1;
    j = j1 + 1;
    while(i >= 0 && j < grid[0].size()){
        if(grid[i][j] == 2)
         return false;
         i --;
         j ++;
    }
    i = i1 + 1;
    j = j1 - 1;
    while(j >= 0 && i < grid.size()){
        if(grid[i][j] == 2)
         return false;
         i ++;
         j --;
    }
    return true;
}
bool trycomb(int n, vector<vector<int>>grid, int i, int count){
    if(count == n )
      return true;
    if(i == grid.size())
     return false;
    for(int j = 0; j < grid[0].size(); j ++){
        if(grid[i][j] == 0 && placed(grid, i, j)){
            grid[i][j] = 2;
            //cout <<i<<" "<<j<<endl;
            if(trycomb(n, grid, i + 1, count + 1)){
                return true;
            }
            grid[i][j] = 0;
        }
    }
    if(trycomb(n, grid, i + 1, count)){
        return true;
    }
    return false;
}
bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {
     return trycomb(N, grid, 0, 0);
}

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string grid_rows_temp;
    getline(cin, grid_rows_temp);

    int grid_rows = stoi(ltrim(rtrim(grid_rows_temp)));

    string grid_columns_temp;
    getline(cin, grid_columns_temp);

    int grid_columns = stoi(ltrim(rtrim(grid_columns_temp)));

    vector<vector<int>> grid(grid_rows);

    for (int i = 0; i < grid_rows; i++) {
        grid[i].resize(grid_columns);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < grid_columns; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    bool result = canPlaceSecurityCameras(N, grid);

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
