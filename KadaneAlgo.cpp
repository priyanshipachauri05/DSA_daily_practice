#include <iostream>
#include <algorithm>
using namespace std;
int maxSum(int* arr,int n)
{
    int max_sum=arr[0];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)  //start inner loop with i so that it doesn't reset to zero everytime.
        {
           sum+=arr[j];
           if(sum>=max_sum)
                max_sum=sum;
        }
    }
    return max_sum;
}
/*Problem with this approach
This approach meets the required condition in O(n^2) time
and O(1) space complexity.
New Approach:
Kadane's Algorithm:
This algorithm solves the Maximum subarray sum problem in O(n) time complexity and
O(1) space complexity.
*/
int maxSumKadane(int* arr,int n)
{
    int max_so_far=arr[0];
    int curr_max=arr[0];
    //Decide whether to add the current element to the exisiting subarray
    //or start a new subarray from the current element.
    for(int i=0;i<n;i++)
    {
        curr_max=max(arr[i],curr_max+arr[i]);
        max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far;
}
int main()
{
    int n;
    cout<<"Enter the length of the array:";
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res;
    res=maxSum(arr,n);
    cout<<"The maximum possible sum of subarray possible in the given array is:"<<res;
    delete arr;
    return 0;
}
/*
Q2. Maximum Subarray Sum — All Negative
----------------------------------------
Find the maximum subarray sum when the array may contain
only negative numbers.

Example:
Input  : [-5,-2,-8,-1,-3]
Output : -1

Important:
Do NOT initialize Kadane's variables to 0 here.

------------------------------------------------------------

Q3. Maximum Subarray Sum + Starting/Ending Index
------------------------------------------------
Find:
1. Maximum subarray sum
2. Starting index
3. Ending index

Example:
Input  : [-2,1,-3,4,-1,2,1,-5,4]

Output:
Sum   = 6
Start = 3
End   = 6

Subarray = [4,-1,2,1]

------------------------------------------------------------

Q4. Maximum Subarray Sum with the Subarray
-------------------------------------------
Print the actual subarray that produces the maximum sum.

Example:
Input  : [-2,1,-3,4,-1,2,1,-5,4]

Output:
[4,-1,2,1]


============================================================
LEVEL 2 — KADANE'S VARIATIONS
============================================================

Q5. Maximum Product Subarray
----------------------------
Find the contiguous subarray having the maximum product.

Example:
Input  : [2,3,-2,4]
Output : 6

Explanation:
[2,3] gives product 6.

Hint:
Unlike normal Kadane, you need to keep track of
BOTH maximum and minimum products because multiplying
by a negative number can change the result.

------------------------------------------------------------

Q6. Maximum Sum Subarray of Fixed Size K
----------------------------------------
Find the maximum sum of any contiguous subarray
of exactly K elements.

Example:
Input : [2,1,5,1,3,2], K = 3
Output: 9

Explanation:
[5,1,3] = 9

Note:
This is better solved using Sliding Window rather
than standard Kadane.

------------------------------------------------------------

Q7. Maximum Sum Subarray with At Least K Elements
------------------------------------------------
Find the maximum sum of a contiguous subarray having
at least K elements.

Example:
Input : [1,2,-1,2,-3,4], K = 2

Find the maximum possible sum.

Hint:
Combination of Kadane + prefix/suffix-style reasoning.

------------------------------------------------------------

Q8. Maximum Sum Circular Subarray
---------------------------------
The array is circular, meaning the last element is
connected to the first element.

Find the maximum subarray sum.

Example:
Input  : [5,-3,5]
Output : 10

Explanation:
Circular subarray = [5] + [5] = 10

Hint:
Answer is either:

1. Normal Kadane

OR

2. Total Sum - Minimum Subarray Sum

------------------------------------------------------------

Q9. Maximum Circular Subarray — Edge Case
------------------------------------------
Solve the circular maximum subarray problem correctly
when ALL elements are negative.

Example:
Input : [-3,-2,-5]
Output: -2

Important:
The formula

totalSum - minSubarraySum

cannot be blindly used here.


============================================================
LEVEL 3 — MODIFIED KADANE
============================================================

Q10. Maximum Sum After Deleting One Element
-------------------------------------------
You may delete AT MOST one element from the array.

Find the maximum possible subarray sum.

Example:
Input : [1,-2,0,3]
Output: 4

Explanation:
Delete -2:

[1,0,3] = 4

Hint:
Maintain two states:

noDelete
oneDelete

------------------------------------------------------------

Q11. Maximum Subarray Sum After One Modification
------------------------------------------------
You may change exactly one element of the array
to any value.

Find the maximum possible subarray sum.

Think carefully about:
- Which element should be modified?
- What value should it become?
- Does modifying an element outside the chosen
  subarray matter?

------------------------------------------------------------

Q12. Maximum Subarray Sum with One Sign Flip
--------------------------------------------
You may change the sign of at most ONE element.

Example:
Input : [1,-2,3,4]

You can change -2 → 2.

Find the maximum possible subarray sum.

Hint:
Dynamic programming with two states.

------------------------------------------------------------

Q13. Maximum Subarray with One Replacement
-------------------------------------------
You may replace at most one element with another
integer.

Find the maximum possible contiguous subarray sum.

Challenge:
Decide whether the replacement should:
- improve the current subarray
- start a new subarray
- or not be used.


============================================================
LEVEL 4 — 2D KADANE
============================================================

Q14. Maximum Sum Rectangle in a Matrix
--------------------------------------
Given an N × M matrix, find the rectangular submatrix
having the maximum sum.

Example:

1   2  -1
-3  4   5
2  -1   3

Find the maximum possible rectangle sum.

Hint:
Compress rows/columns and apply 1D Kadane.

Typical Complexity:
O(N² × M)

------------------------------------------------------------

Q15. Maximum Sum Rectangle Coordinates
--------------------------------------
Find:
1. Maximum rectangle sum
2. Top row
3. Bottom row
4. Left column
5. Right column

This is the coordinate version of Q14.

------------------------------------------------------------

Q16. Maximum Sum Square Submatrix
---------------------------------
Given a matrix and an integer K, find the maximum sum
of a K × K square submatrix.

Hint:
This is better solved using Prefix Sum / 2D Prefix Sum
rather than Kadane.


============================================================
LEVEL 5 — THINKING PROBLEMS
============================================================

Q17. Maximum Subarray Sum with Length Constraint
------------------------------------------------
Find the maximum subarray sum where the length of the
subarray must be between L and R.

Example:
Input : [1,-2,3,4,-1,2]
L = 2
R = 4

Find the maximum possible sum.

Hint:
Prefix sums + maintaining minimum prefix values.

------------------------------------------------------------

Q18. Maximum Subarray with Equal 0s and 1s
-------------------------------------------
Given a binary array, find the longest contiguous
subarray containing equal numbers of 0s and 1s.

Example:
Input : [0,1,0,1,1,1,0]

Hint:
Transform:
0 → -1
1 → +1

Then the problem becomes related to prefix sums.

NOTE:
This is NOT directly solved by Kadane.

The goal here is to recognize when Kadane is
NOT the right tool.

------------------------------------------------------------

Q19. Maximum Subarray with More 1s than 0s
------------------------------------------
Given a binary array, find the longest contiguous
subarray containing more 1s than 0s.

Think about:
1 → +1
0 → -1

Again, focus on identifying the correct
prefix-sum formulation.

------------------------------------------------------------

Q20. Maximum Subarray Sum with At Most K Negative Numbers
----------------------------------------------------------
Find the maximum sum contiguous subarray containing
at most K negative numbers.

Example:
Input : [4,-1,2,-3,5,-2,6]
K = 1

Find the maximum possible sum.

Think:
Is standard Kadane enough?
Or do you need another technique?


============================================================
LEVEL 6 — INTERVIEW / ADVANCED
============================================================

Q21. Maximum Subarray Sum in a Repeated Array
---------------------------------------------
Given an array A and integer K, consider the array
A repeated K times.

Find the maximum subarray sum.

Example:
A = [1,2,-1]
K = 3

Repeated:
[1,2,-1,1,2,-1,1,2,-1]

Find maximum sum.

Hint:
Kadane + total array sum + special handling
depending on K.

------------------------------------------------------------

Q22. Maximum Subarray Sum with Circular + Deletion
--------------------------------------------------
Given a circular array, you may delete at most one
element.

Find the maximum possible subarray sum.

This combines:
- Circular Kadane
- Normal Kadane
- One-deletion DP

------------------------------------------------------------

Q23. Maximum Subarray Sum with Exactly One Negative
------------------------------------------------
Find the maximum sum contiguous subarray containing
exactly one negative element.

Think carefully about:
- What happens if there is no negative?
- What if all elements are negative?
- Can the negative element be at either boundary?

------------------------------------------------------------

Q24. Maximum Subarray Sum After Removing K Elements
----------------------------------------------------
You may remove at most K elements from a contiguous
segment.

Find the maximum possible sum.

This is a much harder DP problem.

Do NOT immediately try to force standard Kadane.


============================================================
IMPORTANT CONCEPT CHECK
============================================================

Before solving every problem, ask yourself:

1. Is the answer required to be CONTIGUOUS?

2. Is the objective MAXIMUM SUM?

3. Can the problem be represented as:
       "extend current subarray"
   OR
       "start a new subarray"?

4. Are there additional constraints such as:
   - circular array?
   - fixed length?
   - at least K elements?
   - deletion?
   - modification?
   - product instead of sum?
   - 2D matrix?

5. Is Kadane actually the correct algorithm?

The important skill is NOT memorizing Kadane's code.

The important skill is recognizing:
"When does this problem reduce to Kadane?"

============================================================
*/
