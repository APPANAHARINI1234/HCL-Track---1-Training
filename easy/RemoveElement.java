class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int j = 0;
        while(j < nums.length){
            if(nums[j] != val){
               int temp = nums[j];
               nums[j] = nums[i];
               nums[i] = temp;
               i ++;
            }
            j ++;
        }
        return i;
    }
}