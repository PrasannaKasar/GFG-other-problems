class Solution {
  public:
  
    int upperBound(vector<int> &nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
    
    int count_nums_less_than_mid(vector<vector<int>> &mat, int mid) {
        int count = 0;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            count += upperBound(mat[i], mid);
        }
        return count;
    }
  
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int s = mat[0][0], e = mat[0][m-1];
        for (int i = 0; i < n; i++) {
            s = min(s, mat[i][0]);
            e = max(e, mat[i][m-1]);
        }
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int count_less_than_mid = count_nums_less_than_mid(mat, mid);
            // cout << mid << " " << count_less_than_mid << endl;
            if (count_less_than_mid <= n*m / 2) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        return s;
    }
};
