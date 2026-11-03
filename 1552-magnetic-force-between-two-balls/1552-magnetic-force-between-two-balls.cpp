class Solution {
public:
    int isPossible(vector<int> &arr, int m, int mid){
        int n = arr.size();
        int lastPos = arr[0];
        int balls = 1;
        for(int i = 1; i<n; i++){
            if(arr[i]-lastPos >= mid){
                lastPos = arr[i];
                balls++;
            }
            if(balls==m){
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int st = 1, end = position[position.size()-1], ans = -1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(isPossible(position, m, mid)){
                ans = mid;
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};