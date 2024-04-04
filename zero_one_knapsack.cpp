int zero_one_knapsack(vector<int> wt,vector<int> val,int w,int n )
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
