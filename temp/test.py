import time
from operator import itemgetter


def binary_search(nums, k):
    num_list = []
    for i in range(len(nums)):
        num_list.append([nums[i], i])
    num_list = sorted(num_list, key=itemgetter(0))
    # print(num_list)

    l, r = 0, len(nums)-1
    while l <= r:
        mid = l+(r-l)//2
        if num_list[mid][0] == k:
            return num_list[mid][1]
        elif num_list[mid][0] < k:
            l = mid+1
        else:
            r = mid-1
    return -1
        

if __name__ == '__main__':
    start_time = time.time()
    res = binary_search([4,1,6,3,7,4,8,3,1,5,2], 5)
    print(res)
    print('======= Time taken: %f =======' %(time.time() - start_time))