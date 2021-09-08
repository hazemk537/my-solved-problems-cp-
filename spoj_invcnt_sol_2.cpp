
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
long long merge(int l1, int r1, int l2, int r2)
{
     long long inverse=0;
    vector < int > right,left;
    for (int i = l1; i <= r1; i++)
        left.push_back(a[i]);
    for (int i = l2; i <= r2; i++)
        right.push_back(a[i]);

    
        int idx_left = 0,
        idx_right = 0;
    while(l1<= r2)
    {
        if (idx_left == left.size())
        {
         a[l1] = right[idx_right++];


        }
        else if (idx_right == right.size())
        {
            a[l1] = left[idx_left++];

        }
   else if (left[idx_left]<right[idx_right])
        {
            a[l1] = left[idx_left++];

        }
        else
        {
            a[l1] = right[idx_right++];

      // remaining numbers in the left    side
            inverse += left.size() - idx_left;
        }
        l1++;

    }
    return inverse;
}
long long  mergesort(int l, int r)
{
   long long  inverse=0;
    if (r>l)
      {
    int mid = (l + r) / 2;
    // go solve for left side
    inverse += mergesort(l, mid);
    // go solve for right side
    inverse += mergesort(mid + 1, r);
    inverse += merge(l, mid, mid+1, r);
      }
      return inverse;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout<<mergesort(0, n - 1)<<endl;
       
    }
    return 0;

}
