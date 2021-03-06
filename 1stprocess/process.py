class PCB(object):
    ID = ''
    runtime = 0
    pri = 0

    def __init__(self, ID, runtime, pri, state):
        self.ID = ID
        self.runtime = runtime
        self.pri = pri
        self.state = state


# def find_pri_max():
#     max = -100
#     maxp = -100
#     j = 0
#     for j in [0, 1, 2, 3, 4]:
#         if LofPCB[j].pri > maxp:
#             max = j
#             maxp = LofPCB[j].pri
#     return max


def bubbleSort():
    for i in range(len(LofPCB) - 1):  # 这个循环负责设置冒泡排序进行的次数
        for j in range(len(LofPCB) - i - 1):  # ｊ为列表下标
            if LofPCB[j].pri < LofPCB[j + 1].pri:
                LofPCB[j], LofPCB[j + 1] = LofPCB[j + 1], LofPCB[j]


def show(t):
    print("第" + str(t) + "次运行结果")
    l = "done"
    for i in [0, 1, 2, 3, 4]:
        if LofPCB[i].pri == -1000:
            print(LofPCB[i].ID, LofPCB[i].runtime, l, LofPCB[i].state)
        else:
            print(LofPCB[i].ID, LofPCB[i].runtime, LofPCB[i].pri, LofPCB[i].state)


def test(t):
    if LofPCB[t].runtime == 0:
        LofPCB[t].pri = -1000
        LofPCB[t].state = 'F'
    else:
        LofPCB[t].state = 'R'


def run():
    show(0)
    x = 1
    for i in range(1, timemax + 1):
        bubbleSort()
        x = 0
        LofPCB[x].pri = LofPCB[x].pri - 1
        LofPCB[x].runtime = LofPCB[x].runtime - 1
        LofPCB[x].state = 'P'
        if LofPCB[x].runtime == 0:
            LofPCB[x].pri = -1000
            LofPCB[x].state = 'P->F'
        show(i)
        test(x)


LofPCB = []
timemax = 0
ID = 0
runtime = 0
pri = 0
i = 1

for i in [0, 1, 2, 3, 4]:
    j = i + 1
    ID = 'P' + str(j);
    runtime = input("请输入P" + str(j) + " PCB块时间：");
    pri = input("请输入P" + str(j) + " PCB块优先级：");
    pcb = PCB(ID, int(runtime), int(pri), 'R')
    LofPCB.append(pcb)
    timemax = timemax + int(runtime)

run()
