import random


def trans(logicaladdress):
    pagenumber = int(logicaladdress) / pagesize
    offestaddress = int(logicaladdress) % pagesize
    blocknumber = pagetable[int(pagenumber)]
    physicalregister = offestaddress
    realaddress = int(blocknumber) * pagesize + int(physicalregister)
    return realaddress


pagesize = input("Enter size of page (maxsize=256) ")
pagesize = int(pagesize)
ranges = 256 / pagesize
pagetable = [str(i) for i in range(ranges)]
random.shuffle(pagetable)

logical = raw_input("Enter your input address 0~255: ")
while logical != "exit":

    real = trans(logical)
    print("Physical address is ")
    print(real)
    print("pagenumber  blocknumber")
    for i in range(ranges):
        print(i, pagetable[i])

    logicaladdress = raw_input("Enter your input address 0~9: ")
