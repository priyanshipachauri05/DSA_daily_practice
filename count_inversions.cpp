#include <iostream>
using namespace std;
/*Approach 1. This is the brute force approach to this problem.
Two pointers i and j. For each value of i, j checks the all the
elements of array such that arr[i] >arr[j], if true increase the number of inversion.*/
int noOfInversion(int* arr,int n)
{
    int no_of_inversion=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                no_of_inversion++;
            }
        }
    }
    return no_of_inversion;

}
//Although the above approach works it results in O(n^2) time complexity and O(1) space complexity.
/*Approach 2: This approach works on the Mechanism of Merge Sort.
When merging two sorted halves, if an element in the left subarray is greater than
the element in the right subarray, it forms an inversion. Because the left subarray is already sorted,
all remaining elememts in that left subarray will also be greater than the current right element, Hence we can count multiple
inversions at once.*/
//Merge two sorted subarrays and count the cross inversion
long long mergeCount(int arr[],int temp[],int left,int mid,int right)
{
    int i=left;     //Starting index for left subarray
    int j=mid+1;    //Starting index for right subarray
    int k=left;     //Starting index to be filled in temp array;
    long long inv_count=0;
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j]){
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
                inv_count+=(mid-i+1); //if arr[i] is found greater than arr[j] then all the other elements in left subarray will be greater than arr[j] hence, number of inversion will be all the remaining elements in left subarray.
                //Since left subarray is sorted, arr[i] to arr[mid] are all > arr[j]
            }

        }
    }
    //Copy all the remaining elements of left subarray, if any
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[i++];
    }
    //Copy back the merged elements to the original array
    for(i=left;i<=right;i++)
        arr[i]=temp[i];
    return inv_count;
}
//Auxillary function that uses merge sort to count the total number of inversions in array. This will update the values of mid and keep dividing the array into subarrays until there are only single elements left.
long long mergeSortandCount(int arr[],int temp[],int left,int right)
{
    long long inv_count=0;
    if(left<right)
    {
        int mid=left+(right-left)/2;
        //Count inversions on the left subarray
        inv_count+=mergeSortandCount(arr,temp,left,mid);
        //Count inversions on the right subarray
        inv_count+=mergeSortandCount(arr,temp,mid+1,right);
        //Count cross inversions
        inv_count+=mergeCount(arr,temp,left,mid,right);
    }
    return inv_count;
}
long long noOfInversionUpadted(int *arr,int n)
{
    int *temp=new int[n];
    long long ans=mergeSortandCount(arr,temp,0,n-1);
    delete[] temp;
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the length of array:";
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res=noOfInversion(arr,n);
    cout<<"Number of inversions in the given array is="<<res;

    delete arr;
    return 0;
}
