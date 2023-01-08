
    void dfs(vector<vector<int>>& visi, int i, int j) {
        // boundary checking
        if(i < 0 || i >= visi.size() || j < 0 || j >= visi[0].size())
            return;
        // return if current position is of water or is already visited
        if(visi[i][j] == 1)
            return;
        // mark the current as visited
        visi[i][j] = 1;
        // do dfs in all 4 directions
        dfs(visi, i+1, j);
        dfs(visi, i, j-1);
        dfs(visi, i-1, j);
        dfs(visi, i, j+1);
    }
