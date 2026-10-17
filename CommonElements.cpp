//Common elements in two arrays
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int no_of_common(int a1[],int a2[],int n)
{
    int no_of_common=0;
    for (int i=0;i<n;i++)
    {
        /*But if the same elements aren't on same index
        this method fails.
        if(a1[i]==a2[i])
        {
            no_of_common+=1;
        }*/
        //But this method results in O(n^2) complexity and it could be minimized
        for(int j=0;j<n;j++)
        {
            if(a1[i]==a2[j])
            {
                no_of_common+=1;
                break; //break prevents counting duplicates if an element matches more than once.
            }
        }
    }
    return no_of_common;
}
//Two Pointer Method
int no_of_common_updated(int a1[],int a2[],int n)
{
    int no_of_common=0;
    int i=0;
    int j=0; //Here i is the pointer to array 1 and j is the pointer to array 2.
    while(i<n && j<n)
    {
        if(a1[i]==a2[j]){
        no_of_common+=1;

        //to handle duplicate elements in the array and avoid double counting the same pair twice.
        int current_val=a1[i];
        while(i<n && a1[i]==current_val)i++;
        while(j<n && a2[j]==current_val)j++;
    }
    else if(a1[i]<a2[j])
        i++;  //Mobe pointer 1 forward because its current element is smaller than the element in hand of second array
    else
        j++;  //Move pointer 2 forward because its current element is smaller than the element in hand of first array.
    return no_of_common;
    }
}

//Using Hash Set
/*
Methodology
1. Insert all elements of the first array into an unordered set.This automatically remove thes
any duplicate from the first array.
2.Iterate through the second array. For each element, check if it exist in the set.
3. If it exists, you increment the counter and erase that element from the set.
Erasing ensure that if the second array has duplicate values,
they won't be counted multiple times.
*/
int no_of_common_hashset(int a1[],int a2[],int n)
{
    unordered_set<int> elements_set;
    //Insert all elements of array 1 into the hash set
    //Time Complexity: O(n)
    for(int i=0;i<n;i++)
    {elements_set.insert(a1[i]);}
    int no_of_common=0;
    //Step 2 & 3: Check elements of array 2 against the set
    //Time complexity:O(n)
    for(int i=0;i<n;i++)
    //.find() looks up an element in O(1) average time
    {
        if(elements_set.find(a2[i])!=elements_set.end())
        {
            no_of_common++;
            //Erase the element so we don't count duplicates from array 2
            elements_set.erase(a2[i]);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a1[n];
    int a2[n];
    cout<<"Enter elements of array 1:";
    for(int i=0;i<n;i++)
    {cin>>a1[i];}
    cout<<"Enter elements of array 1:";
    for(int i=0;i<n;i++)
    {cin>>a2[i];}
    cout<<"No of common elememts:"<<no_of_common(a1,a2,n);
    return 0;
}

/*Other problems related to this core problem
1.Handling Frequency and Duplicates
In this base problem, we only looked for unique common elements.
Variation often change how duplicates are treated.
-> Intersection of Two arrays(With multiplicity): If
a1=[4,9,5,4] and a2=[9,4,9,8,4], the output must be [4,4,9].
*/
int* intersect(int a1[],int n,int a2[],int m)
{
    unordered_map<int,int>counts;  //This creates an array with each entry acts as an pointer to a bucket.
    for(int i=0;i<n;i++)
    {
        //Track frequencies of the first array
        counts[a1[i]]++;  //Update the entry in the bucket.
    }
    //Allocate the maximum possible size for the result array
    int max_possibleSize=min(n,m); //The intersection will equal to less than the size of the shorter array.
    int* result=new int[max_possibleSize];
    int resultSize=0; //Tracks the actual number of intersecting elements.
    //Step 2: Match and decrement frequencies using second array
    for(int i=0;i<m;i++)
    {
        int currentNum=a2[i];
        if(counts[currentNum]>0)
        {
            result[resultSize]=currentNum;
            resultSize++;
            counts[currentNum]--; //Handle Multiplicity
        }
    }
    return result;
}
/*• Union of Two Arrays: Find all distinct elements present in either of the arrays.
• Set Difference (A - B): Find all elements that are present in the first array but not in the second array.*/
