void dfs(vector<vector<pair<int,int>>>& edg, vector<int>& dp, int u, int ind) {
    for (auto it : edg[u]) //iterate through all the node connecter to the u node
    {
        if (dp[it.fs] == 0)// cheaking if the connected node is already processed
        {
            dp[it.fs] = dp[u];
            if (it.sc < ind) dp[it.fs]++;// calculation as per problem statement
            dfs(edg, dp, it.fs, it.sc);// recursive part
        }
    }
}
