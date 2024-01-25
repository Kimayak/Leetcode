// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if (nums1.size()> nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x; 
        while(low<=high){
            int partitionX = (low+high)/2;
            int partitionY = (x+y+1)/2 - partitionX;
            int maxX = (partitionX == 0)? INT_MIN: nums1[partitionX-1];
            int maxY = (partitionY==0)? INT_MIN: nums2[partitionY-1];
            int minX = (partitionX == x)? INT_MAX: nums1[partitionX];
            int minY = (partitionY == y)? INT_MAX : nums2[partitionY];

            if(maxX<=minY && maxY<=minX){
                if((x+y)%2 == 0){
                    return(max(maxX,maxY)+min(minX,minY))/2.0;

                }
                else{
                    return max(maxX, maxY);
                }
            } 
            else if (maxX>minY){
                high = partitionX - 1;

            }
            else{
                low = partitionX+1;
            }
        }
        throw invalid_argument("Input Arguments not sorted!!"); 
    }

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
    //     int n1 = nums1.size(), n2 = nums2.size();
    //     float med = 0;

    //     vector<int> nums3;
        

    //     nums3.insert(nums3.end(), nums1.begin(), nums1.end());
    //     nums3.insert(nums3.end(), nums2.begin(), nums2.end());

    //     sort(nums3.begin(), nums3.end());
    //     int n3 = nums3.size();

    //     if(n3%2 != 0){
    //         med = nums3[n3/2];
    //     }
    //     else{
    //         med = (nums3[n3/2-1]+nums3[n3/2])/2.0;
    //     }

    //     return  med;



        
    // }
};