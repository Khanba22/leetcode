class Solution:
    def frequencySort(self, s: str) -> str:
        o=[]
        for i in set(s):
            count1=s.count(i)
            o.append(i*count1)
        o=sorted(o,key=len)[::-1]
        return "".join(o)