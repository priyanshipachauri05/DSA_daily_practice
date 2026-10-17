#include <iostream>
#include <algorithm>
using namespace std;
//Rope cutting Problem
//Given a rope of lenhth n and three possible cut lengths a,b
//and c, cut the rope into maximum possible number of pieces,
//where every piece must have length a,b or c.
//If impossible to use the whole rope, return -1

int cutRope(int n,int a,int b,int c)
{
    if(n==0)
        return 0;
    if(n<0)
        return -1;
//Use inilializer list{} so std::max can take 3 arguments
    int res=max({cutRope(n-a,a,b,c),
                     cutRope(n-b,a,b,c),
                     cutRope(n-c,a,b,c)});
    if(res==-1)
        return -1;
    return res+1;  //one is added to make sure that we count the piece we just cut.
}
/*The approach above has the complexity of O(3^n).
This could be optimized using Dynamic Programming
where we can solve this problem with just O(n).*/
/*Just store the number of cuts required for a smaller length
rather than calculate it multiple times to avoid high time
complexity*/
/*We could use Tabulation method.*/
//Cutting the rope using Dynamic Programming.

int cutRopeDP(int n,int a,int b,int c)
{
    int *dp=new int[n+1];
    //Initialize all the values with -1 (dp is the base address and dp+n+1 is the final address of the array.)
    fill(dp,dp+n+1,-1);
    //Rope of length 0 requires number of cuts =0
    dp[0]=0;
    //Build the solution from length=1 to n
    for(int i=1;i<=n;i++)
    {
        if(i>=a && dp[i-a]!=-1)
        {
            dp[i]=max(dp[i],dp[i-a]+1);
        }
        if(i>=b && dp[i-b]!=-1)
        {
            dp[i]=max(dp[i],dp[i-b]+1);
        }
        if(i>=c && dp[i-c]!=-1)
        {
            dp[i]=max(dp[i],dp[i-c]+1);
        }
    }
    int result=dp[n];
    delete[] dp;
    return result;

}
int main()
{
    int n,a,b,c;
    cout<<"Enter the length of rope:";
    cin>>n;
    cout<<"Enter the length of cuts:";
    cin>>a>>b>>c;
    int res=cutRope(n,a,b,c);
    cout<<"The number of possible cuts are:"<<res;
    return 0;
}
```cpp
// 1. Maximum Coin Change
// Given an amount n and three possible coin denominations a, b, and c,
// find the maximum possible number of coins that can be used to make
// exactly the amount n. Each coin can be used any number of times.
// If it is impossible to make exactly n, return -1.


// 2. Minimum Coin Change
// Given an amount n and three possible coin denominations a, b, and c,
// find the minimum possible number of coins required to make exactly
// the amount n. Each coin can be used any number of times.
// If it is impossible to make exactly n, return -1.


// 3. Rod Cutting
// Given a rod of length n and the prices of rods of different lengths,
// cut the rod into smaller pieces such that the total selling price is
// maximized. A piece of any valid length can be used any number of times.
// Return the maximum possible revenue.


// 4. Integer Break
// Given an integer n, break it into the sum of at least two positive
// integers such that the product of those integers is maximized.
// Return the maximum possible product.


// 5. Climbing Stairs
// Given n stairs, you can climb either 1 stair or 2 stairs at a time.
// Find the total number of distinct ways to reach the top of the stairs.
// Two ways are considered different if the sequence of steps is different.


// 6. Dice Sum
// Given a target sum n, find the number of different sequences of
// dice rolls needed to obtain exactly n, where each roll can have a
// value from 1 to 6. A value can be used any number of times.


// 7. Minimum Jumps
// Given an array where arr[i] represents the maximum number of positions
// you can jump forward from index i, find the minimum number of jumps
// required to reach the last index. Return -1 if the last index cannot
// be reached.


// 8. Coin Change - Number of Ways
// Given an amount n and a set of coin denominations, find the total
// number of different combinations that can be used to make exactly n.
// Each coin can be used any number of times. The order of coins does
// not matter.


// 9. Unbounded Knapsack
// Given a knapsack with maximum capacity W and a set of items where
// each item has a weight and a value, find the maximum total value that
// can be obtained. Each item can be selected any number of times.
// Return the maximum possible value without exceeding capacity W.
```

