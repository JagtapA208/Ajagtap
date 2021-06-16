pre = ["pentillion", "quadrilion", "trillion", "billion", "million", "thousand", ""]
final = []


def NoToWord(no):
    word = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
    tenth = ["", " ", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    EleNi = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
             "nineteen"]
    st = []

    if (no == 0):
        final.append(word[no])
    else:
        if (no >= 1 and no <= 9):
            final.append(word[no])
        elif (no >= 10 and no <= 19):
            final.append(EleNi[no % 10])
        elif (no >= 20 and no <= 99):
            print(tenth[no // 10], word[no % 10])
        else:
            while (no > 0):
                st.append(no % 10)
                no //= 10
            if (st[1] == 1):
                final.append(word[st[2]] + " hundred " + EleNi[st[0]])
            else:
                final.append(word[st[2]] + " hundred " + tenth[st[1]] + " " + word[st[0]])



def AcceptNumber():
    nos = ['0','1','2','3','4','5','6','7','8','9']
    no = input("Enter number less than or equal to 21 digit : ")
    for i in range(len(no)):
        if no[i] not in nos or len(no) > 21:
            print("Please Enter valid number!!")
            break
        else:
            DivideNumber(no)



def DivideNumber(no):
    stack = []

    i = 1
    j = 0
    pivot = len(no) - (3 * i)

    while (pivot >= 0):
        stack.append(no[pivot:len(no) - (3 * j)])
        i += 1
        j += 1
        pivot = len(no) - (3 * i)

    if (pivot == -2):
        stack.append(no[0:1])
    elif (pivot == -1):
        stack.append(no[0:2])

    cnt = len(stack)

    while (cnt > 0):
        NoToWord(int(stack.pop()))
        cnt -= 1

    for i in range(0, len(final)):
        if (final[i] == ""):
            continue
        print(final[i] + " " + pre[len(pre) - (len(final) - i)], end=" ")


AcceptNumber()