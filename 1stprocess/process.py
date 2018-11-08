class PCB(object):
    ID = ''
    runtime = 0
    pri = 0



    def __init__(self, ID, runtime,pri,state):
        self.ID = ID
        self.runtime = runtime
        self.pri=pri
        self.state=state




def find_pri_max():

    max=-100
    maxp=-1000
    j=0
    for j in [1,2,3,4,5]:
        if LofPCB[j].pri > maxp :
            max = j
            maxp=LofPCB[j].pri
    return max

def show(t):
    print("第"+str(t)+"次运行结果")
    l="done"
    for i in [1, 2, 3, 4, 5]:
        if LofPCB[i].pri==-1000:
            print(LofPCB[i].ID, LofPCB[i].runtime, l, LofPCB[i].state)
        else:
            print(LofPCB[i].ID,LofPCB[i].runtime,LofPCB[i].pri,LofPCB[i].state)

def test(t):
    if LofPCB[t].runtime==0 :
        LofPCB[t].pri=-1000
        LofPCB[t].state = 'F'
    else :
        LofPCB[t].state = 'R'


def run():
    show(0)
    x=1
    for i in range(1,timemax+1):
        x=find_pri_max()
        LofPCB[x].pri = LofPCB[x].pri-1
        LofPCB[x].runtime = LofPCB[x].runtime - 1
        LofPCB[x].state = 'P'
        if LofPCB[x].runtime == 0:
            LofPCB[x].pri = -1000
            LofPCB[x].state = 'P->F'

        show(i)
        test(x)






LofPCB=[]
timemax=0
ID=0
runtime=0
pri=0
i=1
pcb=PCB(0, 0,0,'R')
LofPCB.append(pcb)

for i in [1,2,3,4,5]:

    ID      = 'P'+ str(i);
    runtime = input("请输入P" + str(i)  + " PCB块时间：");
    pri     = input("请输入P" + str(i)  + " PCB块优先级：");
    pcb=PCB(ID, int(runtime),int(pri),'R')
    LofPCB.append(pcb)
    timemax=timemax + int(runtime)

run()
