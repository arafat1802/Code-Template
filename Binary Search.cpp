#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int *a,int n,int x)
{
    int L = 0;
    int R = n-1;
    while(L < R){
        int mid = L + (R - L)/2;
        if(a[mid] > x){
            R = mid;
        }
        else if(a[mid] < x){
            L = mid+1;
        }
        else return mid;
    }
    return -1;
}
int main()
{
    printf("Binary Search\n");
    return 0;
}
