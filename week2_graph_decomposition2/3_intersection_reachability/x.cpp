string Solution::minWindow(string A, string B)
{
    int n = A.size();
    int m = B.size();
    if (m == 0)
        return "";
    unordered_map<char, int> mb;
    unordered_map<char, int> ma;
    //creating hash map for A called mb
    for (int i = 0; i < m; i++)
    {
        mb[B[i]]++;
    }
    /*
    for(auto it : mb)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }*/
    int len = 0, l = -1, r = -1;
    int flag = 0;
    // flag=0 for j pointer to move and flag=1 for i pointer to move.
    string ans = "";
    int i = 0, j = 0;
    // travsersing A
    while (i <= j && j < n)
    {

        if (flag == 0)
        {
            // cout<<"i = "<<i<<" j = "<<j<<" l = "<<l<<" r = "<<r<<endl;
            if (mb.find(A[j]) != mb.end()) // looking for A[j] in mb
            {
                if (ma.find(A[j]) == ma.end()) // inserting in ma hash map for A if not already present
                {
                    ma[A[j]] = 1;
                    j++;
                }
                else if ((ma.find(A[j]) != ma.end()) && (ma[A[j]] < mb[A[j]])) // if already present and freq in ma<mb inc freq and j
                {
                    ma[A[j]]++;
                    j++;
                }
                else if ((ma.find(A[j]) != ma.end()) && (ma[A[j]] >= mb[A[j]])) // if already present and freq is same compare ma and mb and compare len and store l and r and inc i
                {
                    i++;
                    flag = 1;
                }
            }
            else
            {
                j++;
            }
        }
        else
        {
            // cout<<"i = "<<i<<" j = "<<j<<" l = "<<l<<" r = "<<r<<endl;
            if (mb.find(A[i]) != mb.end()) // looking for A[i] in mb
            {
                if (ma[A[i]] <= mb[A[i]]) // if freq in ma < mb, inc j
                {
                    j++;
                    flag = 0;
                }
                else if (ma[A[i]] > mb[A[i]]) // if freq of A[i] ma>mb, reduce freq and inc i
                {
                    ma[A[i]]--;
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        if (ma == mb)
        {
            if (flag == 0)
            {
                l = i;
                r = j - 1;
            }
            else
            {
                l = i;
                r = j;
            }
            int curlen = r - l + 1;
            if (curlen < len)
            {
                len = curlen;
            }
        }
    }
    if (r != -1 && l != -1)
        for (int o = l; o <= r; o++) // store answer string in ans from l to r
        {
            ans.push_back(A[o]);
        }
    return ans;
}