# Danny Radosevich
# Lab 9
# Written for UWYO COSC 2030
import collections

def rever(toRever):
    returnVal = ""
    revDeq = collections.deque([])
    for char in toRever:
        revDeq.append(char)
    for char in toRever:
        returnVal = returnVal + (revDeq.pop())
    return returnVal

def parenCheck(toCheck):
    checkDeq = collections.deque([])
    count = 0
    for char in toCheck:
        if toCheck[count] == "(":
            checkDeq.appendleft(char)
        else:
            if (count == 0 and toCheck[count] == ")") or (toCheck[count] == ")" and len(checkDeq) == 0):
                return 0
            elif toCheck[count] == ")" and checkDeq[0] == "(":
                checkDeq.popleft()
        count = count + 1
    return not len(checkDeq) #return for the size evaluation

#think of this area as main
print("Starting reversal\n")
print(rever("sekopog"))
print(rever("peehsehttaeb"))
print(rever("sgnirtsgnisreverfoderitsyuguoyera"))
print(rever("maiesuaceb"))

if(parenCheck("(()((((()()()((()(((()()()()(((()(()()()(())()())()()))))()()()))()))()())())())))")):
    print("Paren string 1 is good") #should be
else:
    print("Paren string 1 is bad")

if(parenCheck("(()))")):
    print("Paren string 2 is good")
else:
    print("Paren string 2 is bad") #should be

if(parenCheck("(()((()(()()(()(((((()()(()()()((((()()(()()))()))))()()())))))()()())()()))())())")):
    print("Paren string 3 is good") #should be
else:
    print("Paren string 3 is bad")

if(parenCheck("(()()(((()()(()(()()(()()()()()()(()(((((((((())())))))()))))()()))()())()()))()))")):
    print("Paren string 4 is good") #should be
else:
    print("Paren string 4 is bad")

if(parenCheck("((())")):
    print("Paren string 5 is good")
else:
    print("Paren string 5 is bad") #should be

if(parenCheck(")))(((")):
    print("Paren string 6 is good")
else:
    print("Paren string 6 is bad") #should be