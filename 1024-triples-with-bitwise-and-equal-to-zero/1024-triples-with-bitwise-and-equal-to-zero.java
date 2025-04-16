class Solution {
    public int countTriplets(int[] A) {
    int[] count = new int[1 << 16];
    for(int a: A) for(int b: A) count[a & b]++;
    int res = 0;
    for(int a: A) for(int i = 0; i < count.length; i++) {
    	if((a & i) == 0) res += count[i];
    	else i += (a & i) - 1;
    }
    return res;
}
}