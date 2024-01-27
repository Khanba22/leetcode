class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        pointer1 = 0
        pointer2 = 0
        arr = []
        while pointer1 < len(nums1) and pointer2 < len(nums2):
            if nums1[pointer1] > nums2[pointer2]:
                arr.append(nums2[pointer2])
                pointer2+=1
            else:
                arr.append(nums1[pointer1])
                pointer1+=1
        while pointer1 < len(nums1):
            arr.append(nums1[pointer1])
            pointer1+=1
        while pointer2 < len(nums2):
            arr.append(nums2[pointer2])
            pointer2+=1
        length = len(arr)
        if length % 2 != 0:
            print("returning")
            return arr[int(length/2)]
        else:
            print(arr[int(length//2)] , arr[int(length//2)-1] )
            res = float(arr[int(length//2)] + arr[int(length//2)-1])
            return res/2