class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        int medianPos = ((m + n) / 2);

        int num1 = 0, num2 = 0;
        int n1 = 0;
        int n2 = 0;

        int i = 0;
        while (i <= medianPos) {
            num1 = num2;
            if (n1 >= m) {
                num2 = nums2[n2];
                n2++;
            } else if (n2 >= n) {
                num2 = nums1[n1];
                n1++;
            } else {
                if (nums1[n1] <= nums2[n2]) {
                    num2 = nums1[n1];
                    n1++;
                } else {
                    num2 = nums2[n2];
                    n2++;
                }

            }
            i++;
        }
        if ((n + m) % 2 == 0) {
            return (num1 + num2) / 2.0;
        }
        return num2;

    }
}