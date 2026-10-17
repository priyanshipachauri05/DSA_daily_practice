#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//'current to store the elements picked so far, and currentSize tracks how many elements are there in each subset'
void subset(int arr[],int n,int current[],int currentSize,int m=0)
{
    if(m==n)
    {
        cout<<"[";
        for(int i=0;i<currentSize;i++)
        {
            cout<<current[i]<<" ";
        }
        cout<<"]";
        cout<<endl;
        return;
    }
    //Choice 1 says exclude the current element arr[m] and move to the next, i.e copy the current array as it is
    subset(arr,n,current,currentSize,m+1);
    //Choice 2 says include the current element arr[m] and add it to the current open slot.
    current[currentSize]=arr[m];// add the element in the current array.
    subset(arr,n,current,currentSize+1,m+1); //pass current size +1 to include the element
}
// A function to count number of subsets of an array
// Mathematically
int noOfSubsets(int arr[],int n)
{
    //1<<n is a bitwise shift operator equivalent to 2 raised to the power n
    return 1<<n;
}
//Recursively
int countSubsetsRecursive(int n,int m=0)
{
    // Base case: We have made a choice for every element, which equals 1 valid subset
    if (m == n) {
        return 1;
    }

    // Total subsets = (subsets excluding current element) + (subsets including current element)
    int excludeChoice = countSubsetsRecursive(n, m + 1);
    int includeChoice = countSubsetsRecursive(n, m + 1);

    return excludeChoice + includeChoice;
}
//initialize the current sum as 0

int sumOfAllSubsets(int arr[],int n,int current=0,int m=0)
{
    /*If we have made the decision for each and every element of the array
    then we reach a point that m reaches n. it means a unique subset has been fully formed.
    'current now holds the sum of the fully formed subset.
    hence we return it.'*/

    if(m==n)
    {
        return current;
    }
    /*
    1.Include the elemet:
    add the current element's value to
    the running sum and move to the next index in the array.
    By recursively doing this we make a subset of the array.
    */
    int include_sum=sumOfAllSubsets(arr,n,current+arr[m],m+1);
    /*
    2. Exclude Path: Keep the running sum as it is (ignore the current element.)
    and move to the next index(m+1)*/
    int exclude_sum=sumOfAllSubsets(arr,n,current,m+1);
    /*Return to the combined sum gathered from both the decision branches.
    */
    return include_sum+exclude_sum;
}
//Another approach of finding the sum of all the subsets.
//In a set of size n, every single element appears in exactly
//half of the total subsets(2^(n-1) times). So sum of all the subsets
//is simply the sum of array muliplied by (2^n-1).
int sumOfAllSubsetsMath(int arr[],int n)
{
    int total_sum=0;
    for(int i=0;i<n;i++)
    {
        total_sum+=arr[i];
    }
    return total_sum*(1<<(n-1)); //1<<(n-1) calculates 2^(n-1).
}
/*Now we have calculated the sum of all the possible subsets
We now want to apply some constraints over the sum
to meet a target. Rn to calculate the sum we are
having O(2^n) complexity. We can cut it down using DP to
O(nXtarget sum)*/

//We are using 2D array(matrix) for memoization.dp[index][current_sum]
//Assuming max possible size of array is 100 and max possible target sum is 1000.
int dp[105][1005]
bool subsetSumDP(int arr[],int target,int m=0,int current=0)
{

    //Constraints check: If we exactly hit the target sum, we found a match!
    if(current==target)
    {
        return true;
    }
    //Base case: if we run out of elements or exceed the target, stop exploring the further elements.
    if(m==n||current>target)
        return false;

    //DP Lookup: If we have already calculated this exact state, return the saved answer.
    if(dp[m][current]!=-1)
    {
        return dp[m][current];
    }
    //Recursive inclusion and exclusion choices
    bool include=subsetSumDP(arr,n,target,m+1,current,arr[m]);
    bool exclude=subsetSumDP(arr,n,target.m+1,current);
    //MEMOIZATION SETP: Save the result of this decision branch before returning it.
    return dp[m][current]=(include||exclude);
}

//Method 2: Just check the remaining target rather than growing the current sum.
bool subsetSumRemaining(int arr[],int n,target_left,int m=0)
{
    if(target_left==0)return true;
    if(m==n||target_left<0)return false;
    //Check if this remaining target is already present in the Memoization table?
    if(dp[m][target_left]!=-1)
    {
        return dp[m][target_left];
    }
    bool include=subsetSumRemaining(arr,n,target-arr[m],m+1);
    bool exclude=subsetSumRemaining(arr,n,target,m+1);
    return dp[m][target_left]=(include||exclude);
}
int main()
{
    int n;
    cout<<"Enter the length of the array:";
    cin>>n;
    //Dynamic memory allocation to the array so as to avoid variable length array compiler errors.
    int* arr=new int[n];
    //Allocating temporary array to hold the elements of the current subset.
    int* current=new int[n+1];
    cout<<"Enter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The possible subsets of the given set are:";
    subset(arr,n,current,0);

    //Clean up the dynamically allocated memory to avoid memory leaks
    delete [] arr;
    delete [] current;
    return 0;
}

//Study these Questions
/*1. Subsets with Duplicates (e.g., LeetCode 90)
• The Twist: The input array contains duplicate numbers (like [1, 2, 2]), but your output cannot contain duplicate subsets.
• Why standard DP/Backtracking fails: It will treat the first 2 and the second 2 as unique choices, producing [1, 2] twice.
• The Fix: Sort the array first. During recursion, if the current element is identical to the previous one, you skip the "include" branch to avoid generating duplicate combinations.
*/

/*
2. The Partitions Problems
Instead of just finding subsets, you are asked to split the main array into subsets that satisfy a group condition:
• Partition Equal Subset Sum: Can you split an array into two subsets that have the exact same sum? (This is solved by finding a subset that sums up to exactly Total_Sum / 2).
• Partition to K Equal Sum S
*/


/*
3. Number of Subsets with a Given Difference
The Twist: You must divide the array into two subsets, S₁ and S₂, such that their sums satisfy Sum(S₁) - Sum(S₂) = difference.
The Fix: Using algebra, you can convert this constraint into a standard target sum problem. Since Sum(S₁) + Sum(S₂) = Total_Sum, substituting the target equation yields:
You then use your standard subset-sum counting DP to search for that single target value. 
*/



/*
4. Subsets with Size Constraints (Combinations)
The Twist: Find all subsets of a set, but only those that contain exactly K elements.
• The Fix: You add a size condition to your base cases. If your current subset reaches size K, you save it. If the remaining elements in the array aren't enough to reach size K, you prune the branch early.

*/



