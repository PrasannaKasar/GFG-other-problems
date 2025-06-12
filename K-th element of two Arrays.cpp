class Solution {
  public:
  
    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        vector<int> min_arr, max_arr;
        if (n1 < n2) {
            min_arr = nums1;
            max_arr = nums2;
        } else {
            min_arr = nums2;
            max_arr = nums1;
        }

        int s = max(0, k - (int)max_arr.size()), e = min(k, (int)min_arr.size());
        while (s <= e) {
            int mid1 = s + (e - s) / 2;
            int mid2 = k - mid1;

            int l1 = (mid1 != 0) ? min_arr[mid1-1] : INT_MIN;
            int l2 = (mid2 != 0) ? max_arr[mid2-1] : INT_MIN;
            int r1 = (mid1 != min_arr.size()) ? min_arr[mid1] : INT_MAX;
            int r2 = (mid2 != max_arr.size()) ? max_arr[mid2] : INT_MAX;

            if (l2 > r1) {
                s = mid1 + 1;
            } else if (l1 > r2) {
                e = mid1 - 1;
            } else {
                int ans = max(l1, l2);
                return ans;
            }
        }
        return -1;
    }
};
