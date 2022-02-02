int issueBooks(vector<int> prices)
{
    map<int, int> help;
    int sum = 60,n = prices.size();
    help[0]=0;
    for(int i=0; i<n; i++)
    {
        help[prices[i]%60]++;
    }
    
    int ans = 0;
    
    for(int i=1;i<30;i++){
        ans+=help[i]*help[60-i];
    }
    ans+=help[30]*(help[30]-1)/2;
    ans+=help[0]*(help[0]-1)/2;

    return ans ;
}