import time
from typing import List

def helper(cand, tar, sum, begin, pres, res):
    if sum == tar:
        res.append(pres.copy())
    else:
        for i in range(begin, len(cand)):
            if i != begin and cand[i] == cand[i-1]:
                continue
            if sum+cand[i] <= tar:
                pres.append(cand[i])
                helper(cand, tar, sum+cand[i], i+1, pres.copy(), res)   # important to pass in pres.copy!
                pres = pres[:-1]


def combination(cand, tar):
    res = []
    pres = []
    cand.sort()
    print(cand)
    helper(cand, tar, 0, 0, pres, res)
    return res


cand = [10,1,2,7,6,1,5]
print(combination(cand, 8))

def combinationSum(candidates: List[int], target: int) -> List[List[int]]:
    def dfs(begin, path, residue):
        if residue == 0:
            res.append(path[:])
            return

        for index in range(begin, size):
            if candidates[index] > residue:
                break

            if index > begin and candidates[index - 1] == candidates[index]:
                continue

            path.append(candidates[index])
            dfs(index + 1, path, residue - candidates[index])
            path.pop()

    size = len(candidates)
    if size == 0:
        return []

    candidates.sort()
    res = []
    dfs(0, [], target)
    return res



if __name__ == '__main__':
    start_time = time.time()
    cand = [10,1,2,7,6,1,5]
    print(combination(cand, 8))
    print('======= Time taken: %f =======' %(time.time() - start_time))