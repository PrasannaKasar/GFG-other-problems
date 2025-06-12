class Solution {
  public:
  
    int count_1s(vector<int> &arr) {
        int n = arr.size();
        int s = 0, e = n - 1;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (arr[mid] == 1) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        
        return n - s;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        int row_idx = -1, max_count = 0;
        int n = arr.size(), m = arr[0].size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i][m-1] == 1) {
                int row_count = count_1s(arr[i]);
                if (row_count > max_count) {
                    max_count = row_count;
                    row_idx = i;
                }
            }
        }
        
        return row_idx;
    }
};
