int max_sum(vector<int> a, int size) 
{
    int mx = INT_MIN;
    int x = 0;
    
    for (int i = 0; i < size; i++) 
    {
        x += a[i];
        if (mx < x) 
        {
            mx = x;
        }
        if (x < 0) 
        {
            x = 0;
        }
    }
    return mx;
}
