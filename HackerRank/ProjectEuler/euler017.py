'''
Number to Words
https://www.hackerrank.com/contests/projecteuler/challenges/euler017
'''

def getTenties(num):
    return {
        10: "Ten",
        11: "Eleven",
        12: "Twelve",
        13: "Thirteen",
        14: "Fourteen",
        15: "Fifteen",
        16: "Sixteen",
        17: "Seventeen",
        18: "Eighteen",
        19: "Nineteen"
    }[num]

def getTens(digit):
    return {
        0: "",
        2: "Twenty",
        3: "Thirty",
        4: "Forty",
        5: "Fifty",
        6: "Sixty",
        7: "Seventy",
        8: "Eighty",
        9: "Ninety"
    }[digit]

def getOnes(digit):
    return {
        0: "",
        1: "One",
        2: "Two",
        3: "Three",
        4: "Four",
        5: "Five",
        6: "Six",
        7: "Seven",
        8: "Eight",
        9: "Nine"
    }[digit]

#Divide the number in parts of three
#and get the corresponding word
#And append the corresponding "place"
#as given in the method getThousandMultiple
def getThreeDigitWords(num):
    d1 = num%10
    d2 = (num%100)//10
    d3 = (num%1000)//100
    
    words = ""
    if d3 != 0:
        words += (getOnes(d3) + " Hundred " if getOnes(d3) else "")

    if d2 == 1:
        words += getTenties(d2 * 10 + d1)
    else:
        words += (getTens(d2) + " " if getTens(d2) else "")
        words += (getOnes(d1) if getOnes(d1) else "")
    return words.strip()
        
def getThousandMultiple(num):
    return {
        1: "",
        1000: "Thousand",
        1000000: "Million",
        1000000000: "Billion",
        1000000000000: "Trillion"
    }[num]

def getNumWords(num):
    if not num:
        return "Zero"
    
    num = str(num)
    size = len(num)
    
    words = ""
    i = size
    current_place = 1
    while i > 0:
        start = max(0, i-3)
        toAdd = getThreeDigitWords(int(num[start:i]))
        if toAdd:
            toAdd += " " + getThousandMultiple(current_place)
            words = toAdd + " " + words
        i -= 3
        current_place *= 1000
    return words

T = int(input().strip())
for t in range(T):
    n = int(input().strip())
    
    print(getNumWords(n).strip())