class Solution {
  public:
  
    bool canPlaceCows(vector<int> &stalls, int dist, int k) {
        int n = stalls.size();
        int i = 0, prev_loc = stalls[0];
        k -= 1;
        while (i < n) {
            if (stalls[i] - prev_loc >= dist) {
                k--;
                prev_loc = stalls[i];
            }
            if (k == 0) {
                break;
            }
            i++;
        }
        
        return k == 0;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int s = stalls[1] - stalls[0];
        for (int i = 0; i < n-1; i++) {
            s = min(s, stalls[i+1] - stalls[i]);
        }
        int e = stalls[n-1] - stalls[0];
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (canPlaceCows(stalls, mid, k)) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        return e;
    }
};
