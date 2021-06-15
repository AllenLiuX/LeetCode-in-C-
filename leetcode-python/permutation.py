import time


def permutate(nums):
    global res
    res = []

    def backtrace(selected, choice):
        if not choice:
            res.append(selected)
            return
        for i in range(len(choice)):
            cur_choice = choice[:i]+choice[i+1:]
            backtrace(selected+[choice[i]], cur_choice)     # selected, 不能用append, return Nonetype

    choice = nums
    backtrace([], choice)
    return res


if __name__ == '__main__':
    start_time = time.time()
    res = permutate([1,2,3])
    print(res)
    print('======= Time taken: %f =======' %(time.time() - start_time))