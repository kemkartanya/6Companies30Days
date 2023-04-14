/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    private:
    int ind = -1;
    void findPeakElement(int low,int high,MountainArray &mountainArr){
        if(low > high){
            return;
        }
        int n = mountainArr.length();
        int mid = low + (high - low) / 2;
        int element = mountainArr.get(mid);
        cout<<element<<endl;
        int x = mountainArr.get((mid+1)%n);
        int y = mountainArr.get((mid-1+n)%n);
        if(element>x && element>y){
            ind=mid;
            return;
        }
        if(mid!=0 && element<y){
            findPeakElement(low,mid-1,mountainArr);
        }
        else{
            findPeakElement(mid+1,high,mountainArr);
        }
    }

    int bin_search(int low, int high, MountainArray &mountainArr, int target, bool isDecreasing) {
        if(low > high){
            return -1;
        }
        int mid = low+(high-low)/2;
        int element = mountainArr.get(mid);
        if(element==target){
            return mid;
        }
        if(element>target){
            if(isDecreasing){
                return bin_search(mid+1,high,mountainArr,target,isDecreasing);
            }
            return bin_search(low,mid-1,mountainArr,target,isDecreasing);
        }
        if(isDecreasing){
            return bin_search(low,mid-1,mountainArr,target,isDecreasing);
        }
        return bin_search(mid+1,high,mountainArr,target,isDecreasing);
    }

    public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        ios_base::sync_with_stdio(false);
        findPeakElement(0,mountainArr.length()-1,mountainArr);
        int ans1 = bin_search(0,ind,mountainArr,target,false);
        int ans2 = bin_search(ind+1,mountainArr.length()-1,mountainArr,target,true);
        if(ans1==-1 && ans2==-1){
            return ans1;
        }
        return ans1==-1?ans2:ans1;
    }
};
