#include <iostream>
#include <algorithm> //to get the sort function time complexity=O(nlogn)
using namespace std;
void threeSum(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((arr[i]+arr[j]+arr[k])==0 && (i!=j)&&(j!=k)&&(i!=k))
                    cout<<"["<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"]";
            }
        }
    }
}
/*Two problems with this approach
1. The time complexity is O(n^3).
2.It gives duplicate results.
*/
/*The more optimal approach would be 2 pointer method that'll solve this problem in O(n^2).
By sorting the array first, you can use a fixed pointer i and two
pointer approach (left and right) to find the remaining two numbers in O(n) time per iteration.
*/
void threeSumTwoPointer(int* arr, int n)
{
    //Sort the raw array in place.
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        //Skip duplicate elements for the first position to avoid duplicate triplets
        if(i>0 && arr[i]==arr[i-1])continue;
        int left=i+1;
        int right=n-1;
        while(left<right)
        {
            int current_sum=arr[i]+arr[left]+arr[right];
        if(current_sum==0)
        {
            cout<<"["<<arr[i]<<","<<arr[left]<<","<<arr[right]<<"]";
        //Skip duplicate elements for the second and third positions
        while(left<right && arr[left]==arr[left+1])left++;
        while(left<right && arr[right]==arr[right-1])right--;
        //Once u have assured u won't get more duplicates for first,second and third elements of the triplet then move forward.
        left++;
        right--;
        }
        else if(current_sum<0) //Possibility 2 if sum is smaller than target, you need to add sum larger numbers to it to move it towards zero.
            left++;
        else
            right--; //Possibility 3. If sum is greater than zero then u need to move backwards towards smaller numbers to make sum move towards zero.
        }
    }
}
/*In place sorting requires O(nlogn) time and other procedure requires O(n^2) time hence when added leaves complexity of O(n^2)*/
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    threeSum(arr,n);
    delete arr;
    return 0;
}
