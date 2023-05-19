#Danny Radosevich
#Lab 8 for UWYO COSC2030
#Count and return the the most used word

Dict = {} #set up the dictionary stores <key, value> pair
# in this case the individual chars will be the key, and the value will be their count
max = 0
maxLoc =""
test = "dffsmyhcquygqavloseyptlksvintphwwvofahoowtkaftuhqazszaqjxfpmxdtgcdxtzxmlogqmbwxuzqvndqtrtxyjrvrgzygw"
test+= "zpqdedasdfngrkttipaszwgzwemjmlrcawkpqlpxykpwnlfkktbizirrhefnwxniecfnjvdzblbjuemantxaqaqnqmfftskqeehy"
test+= "svaxxypgvlnbpsxqbdkpvvgizchfgcqzhuxvxzwjofykyfdxzbrfbscjwycdqmrtwyexvghzzhdhdlmtvapzdwwpruqvzevqespa"
test+= "koblbgtontnobangmfnjiajqkdzztgocucxjnfskxikpqytpmkqahhzrjcjrjwoktamibytgduupomnfbrrisrtmezxjjehycspp"
test+= "qdyzeaobsjewyfrumafucbqtkuiuhmknqqhbkwzadhjlmiryexyvkfvznffrcpfcoequdcgqujayeeayhshnqkxsbrkgqwspxzto"
for char in test: #for character in the string
    if Dict.get(char):#complete this if statement #if a char already exists in dictionary, increment count
        #print(word)
        Dict[char]+=1
        if Dict[char]>max:#check if the new count is bigger than the current max
            maxLoc = char #save the word that is the new max
            max = Dict[char] #save the count
            #print(str(max)+" "+maxLoc)
    else: 
        Dict[char]=1#char not in dictionary, add it, set count to be 1
            #complete the else statement

#print(maxLoc) # print the most used character
print("The most used char was: "+maxLoc+" which happened "+ str(max)+" times")
#print(Dict) #prints out the dictionary so you can see