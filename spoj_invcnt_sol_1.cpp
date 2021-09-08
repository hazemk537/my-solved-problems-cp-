```cpp
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define  ll long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    ordered_set os;
    long long total;
    cin>>total;//1
    while(total--)
    {
        long long n;
        scanf("%lld",&n);
        long long temp;
        vector<long long>veco;
        for(long long i=0; i<n; ++i)
        {
            scanf("%lld",&temp);
            os.insert(temp);
            veco.push_back(temp);
        }
        long long ans=0;
        for(long long i=0; i<n; ++i)
        {
//you cannot use distance function because it is o(n) so you canot use ordinary set 
            long long x=os.order_of_key(veco[i]);
            ans+=x;
            os.erase(os.find_by_order(x));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

