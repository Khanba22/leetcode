class Solution {
    public int getLucky(String s,int k) {

        int sum = 0;
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
              int val = s.charAt(i) - 'a'+1;  
            str.append(val);
        }
         String ans = str.toString();

        for (int i = 0; i < ans.length(); i++) {
            sum += ans.charAt(i) - '0';
        }
        for (int i = 0; i < k-1; i++) {
            if (sum < 10){
                break;
            }
            sum = helper(sum);
        }
        return sum;
    }
    public int helper(int num){
        int sum = 0;
        while(num != 0){
            int digit = num%10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }
}