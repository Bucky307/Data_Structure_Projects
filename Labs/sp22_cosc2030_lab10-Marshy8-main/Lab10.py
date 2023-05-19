import random #this imports the random library for your use
import string

dict = open("dict.txt") #opens the file
dict = dict.read() #reads it in
dict = dict.split("\n") #split the file into a list based on on the new line character
word = ""
word2 = ""
symbols = "!@#$%^&*1234567890"
count = 0
word = word + dict[random.randrange(133168)]
word = word + dict[random.randrange(133168)]
word = word + dict[random.randrange(133168)]

for char in word:
    rand = random.randrange(3)
    if rand == 1:
        word2 += word[count].upper()
    elif rand == 2:
        word2 += symbols[random.randrange(8)]
    else:
        word2 += word[count]
    count += 1

print("The random 3 words from the dictionary was:")
print(word)
print("The password generator returned:")
print(word2)
