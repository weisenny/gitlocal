
import random


def trans(str1):

    num = int(str1)
    return transtable[num]

pagelength = input("Enter length of page (1~7): ")
pagelength = int(pagelength)
ranges = pow(10, pagelength)
transtable = [str(i).zfill(pagelength) for i in range(ranges)]
random.shuffle(transtable)


strs = raw_input("Enter your input address 00000000-99999999: ")
while strs != "exit":

    str2=trans(strs[0:pagelength])
    print(str2+strs[pagelength:8])
    strs = raw_input("Enter your input address 00000000-99999999: ")






