class Solution {
    public int getLucky(String s, int k) {
        String nums = "";
        for (int i = 0; i < s.length(); i++) {
            int x = (int) s.charAt(i) - (int) 'a' + 1;
            nums = nums + x;
        }
        for (int i = 0; i < k; i++) {
            System.out.println(nums);
            int sum = 0;
            for (int j = 0; j < nums.length(); j++) {
                sum += Integer.parseInt(String.valueOf(nums.charAt(j)));
            }
            nums = String.valueOf(sum);
        }
        return Integer.parseInt(nums);
    }
}