import numpy as np

maxresource = np.array([10, 5, 7])
avaResour = np.array([3, 3, 2])
allocation = np.array([[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]])
maxRequest = np.array([[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]])
need = np.array([[7, 4, 3], [1, 2, 2], [6, 0, 0], [0, 1, 1], [4, 3, 1]])
askResource = np.array([0, 0, 0])
done = np.array([0, 0, 0, 0, 0])


def count():
    used = np.array([0, 0, 0])
    for i in range(3):
        used = used + allocation[i]
    return used


def allocate(i, ask):
    global avaResour
    avaResour = avaResour - ask
    need[i] = need[i] - ask
    allocation[i] = allocation[i] + ask
    if equals(allocation[i], maxRequest[i]):
        avaResour = avaResour + allocation[i]
        allocation[i] = np.array([0, 0, 0])
        done[i] = 1
        print("第" + str(i) + "个进程完成运行")


def reverse(i, ask):
    global avaResour
    avaResour = avaResour + ask

    need[i] = need[i] + ask
    allocation[i] = allocation[i] - ask


def formerbig(A, B):
    for i in range(3):
        if A[i] < B[i]:
            return 0

    return 1


def equals(A, B):
    for i in range(3):
        if A[i] != B[i]:
            return 0
    return 1


def safe():
    idd = 0
    j = 0
    k = 0
    ll = 0
    m = 5
    n = 3

    work = avaResour.__deepcopy__(avaResour)
    finish = done.__deepcopy__(done)
    p = np.array([0, 0, 0, 0, 0])
    while idd < 5:
        if finish[idd] != 1:
            if formerbig(work, need[idd]):
                finish[idd] = 1
                work = work + allocation[idd]
                p[ll] = idd
                print(idd)
                ll = ll + 1
                idd = -1

        if ll == m:
            print("系统是安全的，安全序列为：")
            print(p)
            return 1
        idd += 1

    print("系统不安全的")
    return 0


def show():
    print("分配矩阵")
    print(allocation)
    print("需求矩阵")
    print(need)
    print("空闲资源")
    print(avaResour)


show()
safe()
cmd = 1
fatal = 0
num = 7
while cmd >= 1 and fatal == 0:

    num = int(input("please input the number of procession"))
    askResource[0] = int(input("please input the number of resource A"))
    askResource[1] = int(input("please input the number of resource B"))
    askResource[2] = int(input("please input the number of resource C"))
    if done[num] == 0:
        print(need[num], askResource)
        if formerbig(need[num], askResource):
            allocate(num, askResource)
            if safe():
                print("passed the security test and allocated successfuly ")
                show()
            else:
                print("failed to pass the test")
                reverse(num, askResource)
                fail = 1
        else:
            print("request too much!")
    else:
        print("the process has been done")

    if equals(avaResour, [10, 5, 7]):
        print("完成所有分配")
        fatal = 1
    cmd = int(input("Input 1 to continue and 0 to exit"))
    if cmd == 2:
        show()
