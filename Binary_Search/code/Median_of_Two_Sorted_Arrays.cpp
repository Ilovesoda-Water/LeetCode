#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

double findKth(vector<int>& array1, int s1, vector<int>& array2, int s2, int k){
    int length1 = array1.size()-s1;
    int length2 = array2.size()-s2;
    if (length1 > length2)
        return findKth(array2, s2, array1, s1, k);
    if (length1==0)
        return array2[s2+k-1];
    if (k==1){
        printf("ok4\n");
        double tmp = min(array1[s1],array2[s2])*1.0;
        printf("%lf\n", tmp);
        return min(array1[s1],array2[s2])*1.0;
    }

    int p1 = min(k/2, length1);
    int p2 = k-p1;
    if (array1[s1+p1-1]<array2[s2+p2-1]){
        printf("ok1\n");
        return findKth(array1, s1+p1, array2, s2, k-p1);
    }

    else if (array1[s1+p1-1]>array2[s2+p2-1]){
        printf("ok2\n");
        return findKth(array1, s1, array2, s2+p2, k-p2);
    }

    else{
        return array1[s1+p1-1]*1.0;
    }

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int total = nums1.size()+nums2.size();
//    printf("total num %d\n", total);
    if ((total%2) == 1){
        return findKth(nums1, 0, nums2, 0, total/2+1);
    }
    else{
////        double res1 = 0;
        double res1 = findKth(nums1, 0, nums2, 0, total/2);
        double res2 = findKth(nums1, 0, nums2, 0, total/2+1);
        return (res1+res2)/2.0;
    }

}



int main(){
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    double r = findMedianSortedArrays(nums1,nums2);
    printf("%lf\n", r);
    return 0;
}
