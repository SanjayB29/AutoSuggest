import os
import string
import time

def input_char():
    while True:
        c = input("Enter a character: ")
        if len(c) == 1 and (c.isalpha() or c in string.ascii_letters):
            return c

def displays(x, n):
    y = x[0][0]
    if not y.isupper():
        x[0] = y.upper() + x[0][1:]
    print("The sentence:", " ".join(x) + ".")

def check(word, x):
    return word in x

def cont():
    while True:
        opt = int(input("Do you want to move to the next word?\n1. Yes\n2. No\n--> "))
        if opt in [1, 2]:
            return opt == 1

def check_empty(x):
    return x[-1] == ""

class Hello:
    def __init__(self):
        self.hello = "Welcome"
        self.bye = "Thanks!"

x = [
    "able", "acid", "aged", "also", "cast", "cats",
    "does", "dogs", "done", "door", "funk", "grey",
    "grow", "jump", "jury", "just", "lack", "land",
    "lady", "last", "lazy", "ugly", "unit", "upon"
]
sent = []
hell1 = Hello()

print(hell1.hello)
os.system("color E5")

with open("text.txt", "r") as fptr:
    content = fptr.read()
    print(content, end="")
    time.sleep(0.005)

print("\n\n\n")
os.system("color E0")

flag1 = True
m = 0
while flag1:
    flag3 = False
    while not flag3:
        fi = input_char()
        f1 = False
        for i in range(len(x)):
            if x[i][0] == fi:
                print(f"{i + 1}: {x[i]}")
                f1 = True
        
        if f1:
            opt1 = int(input("0: none of the above\nChoose the option: "))
            if opt1 == 0:
                s = input_char()
                f2 = False
                for i in range(len(x)):
                    if x[i][0] == fi and x[i][1] == s:
                        print(f"{i + 1}: {x[i]}")
                        f2 = True
                
                if f2:
                    opt1 = int(input("0: none of the above\nChoose the option: "))
                    if opt1 == 0:
                        t = input_char()
                        f3 = False
                        for i in range(len(x)):
                            if x[i][0] == fi and x[i][1] == s and x[i][2] == t:
                                print(f"{i + 1}: {x[i]}")
                                f3 = True
                        
                        if f3:
                            opt1 = int(input("0: none of the above\nChoose the option: "))
                            if opt1 == 0:
                                fo = input_char()
                                f4 = False
                                for i in range(len(x)):
                                    if x[i][0] == fi and x[i][1] == s and x[i][2] == t and x[i][3] == fo:
                                        print(f"The word is {x[i]}")
                                        f4 = True
                                
                                if not f4:
                                    lc = 3
                            else:
                                print(f"The word is {x[opt1 - 1]}")
                                word = x[opt1 - 1]
                                f4 = True
                        else:
                            lc = 2
                    else:
                        print(f"The word is {x[opt1 - 1]}")
                        word = x[opt1 - 1]
                        f4 = True
                else:
                    lc = 1
            else:
                print(f"The word is {x[opt1 - 1]}")
                word = x[opt1 - 1]
                f4 = True
        else:
            lc = 0
        
        flag3 = True
    
    if not f4:
        print("No word found!!!")
        if lc == 1:
            s = input_char()
            t = input_char()
            fo = input_char()
        elif lc == 2:
            t = input_char()
            fo = input_char()
        elif lc == 3:
            fo = input_char()
        
        word = fi + s + t + fo
        new = word
        print(f"The word is {new}")
        sent.append(new)
    
    flag = check(word, x)
    if flag == 0:
        opt = None
        while opt not in [1, 2]:
            opt = int(input("Do you want to add the word to the dictionary?\n1. Yes\n2. No\n--> "))
        
        empty_flag = check_empty(x)
        if empty_flag == 1:
            if opt == 1:
                x.append(word)
                x.sort()
                print("Word added to the dictionary successfully!")
        else:
            print("No more spaces!")
        
        flag1 = cont()
    else:
        flag1 = cont()

displays(sent, m)

while True:
    z = int(input("Do you want to see the dictionary?\n1. Yes\n2. No\n--> "))
    if z == 1:
        for i in range(len(x)):
            print(x[i])
        break
    elif z == 2:
        break

print(hell1.bye)
