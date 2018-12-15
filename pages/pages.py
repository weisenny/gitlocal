
import random


def trans(str1):

    num = int(str1)
    return pagetable[num]

pagelength = input("Enter length of page (1~7): ")
pagelength = int(pagelength)
ranges = pow(10, pagelength)
pagetable = [str(i).zfill(pagelength) for i in range(ranges)]
random.shuffle(pagetable)

logicaladdress = raw_input("Enter your input address 00000000-99999999: ")
while logicaladdress != "exit":
    pagenumber = logicaladdress[0:pagelength]
    offestaddress = logicaladdress[pagelength:8]
    blocknumber=trans(pagenumber)
    physicalregister = offestaddress
    realaddress=blocknumber+physicalregister
    print("Physical address is "+realaddress)
    logicaladdress = raw_input("Enter your input address 00000000-99999999: ")






