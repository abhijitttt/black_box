int zero_one_knapsack(vector<int> wt,vector<int> val,int w,int n )//simple recursion
{
    if(w == 0 || n == 0) return 0;

    if(wt[n-1] <= w)
    {
        return max(val[n-1] + zero_one_knapsack(wt,val,w-wt[n-1],n-1),zero_one_knapsack(wt,val,w,n-1));
    }
    else
    {
        return zero_one_knapsack(wt,val,w,n-1);
    }
}



//
//MEMOIZATION
#include <bits/stdc++.h>


using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9+7;
    
int zero_one_knapsack(vector<int> wt,vector<int> val,vector<vector<int>> x,int w,int n )//using memoization(as fast as top down )                                
{
    
    if(w == 0 || n == 0) return 0;
    if(x[n-1][w-1] != -1)
        return x[n-1][w-1];
    if(wt[n-1] <= w)
    {
        return x[n-1][w-1] = max(val[n-1] + zero_one_knapsack(wt,val,x,w-wt[n-1],n-1),zero_one_knapsack(wt,val,x,w,n-1));
    }
    else
    {
        return x[n-1][w-1] = zero_one_knapsack(wt,val,x,w,n-1);
    }
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n = 4;
        int w = 7;
        vector<int> wt{1,3,4,5};
        vector<int> val{1,4,5,7};
        vector<vector<int>> num(n+1,vector<int>(w+1));
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                num[i][j] = -1;
            }
        }

        int ans = zero_one_knapsack(wt,val,num,w,n);
        cout << ans << endl;
    }
}




//bottom-up approch (DP)
#include <bits/stdc++.h>


using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9+7;
    
int zero_one_knapsack(vector<int> wt,vector<int> val,int w,int n )
{
    vector<vector<int>> num(n+1,vector<int>(w+1));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0) num[i][j] = 0;//it can differ from problem to problem
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(wt[i-1] <= j)
            {
                num[i][j] = max(val[i-1]+num[i-1][j-wt[i-1]],num[i-1][j]);
            }
            else
            {
                num[i][j] = num[i-1][j];
            }
        }
    }

    return num[n][w];


}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n = 4;
        int w = 8;
        vector<int> wt{1,3,4,5};
        vector<int> val{1,2,5,6};
        

        int ans = zero_one_knapsack(wt,val,w,n);
        cout << ans << endl;
    }
}
