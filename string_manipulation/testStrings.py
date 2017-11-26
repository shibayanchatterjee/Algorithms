'''
KMP algorithm implementation
'''
def KMPsearch(pat, txt):
    M = len(pat)
    N = len(txt)
    
    # Creating lps that will hold the longest prefix suffix
    # values for pattern
    lps = [0]*M
    computeLPSArray(pat, M, lps)
    # print lps
    i, j = 0, 0
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1

        if j == M:
            print "Found pattern at index " + str(i-j)
            j = lps[j-1]
        
        # Mismatch after j matches
        elif i < N and pat[j] != txt[i]:
            # Do not match lps[0..[j-1]] characters,
            # they will match anyway
            
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return
def computeLPSArray(pat, M, lps):
    l, i = 0, 1
    lps[0]
    while i < M:
        if pat[i] == pat[l]:
            l += 1
            lps[i] = l
            i += 1
        else:
            if l != 0:
                l = lps[l-1]
            else:
                lps[i] = 0
                i += 1
    return

'''
Naive Approach
'''
def search(pat, txt):
    M = len(pat)
    N = len(txt)

    # A loop to slide pat[] one by one
    for i in range(N-M+1):
        # For current index i, check for pattern match
        for j in range(M):
            if txt[i+j] != pat[j]:
                break
        if j == M-1:
            print "Pattern found at index " + str(i)
    return

'''
Another Naive Approach
'''
def anotherNaiveApproach(pat, txt):
    for i in range(len(txt) - len(pat) + 1):
        if txt[i:i+len(pat)] == pat:
            return i
    return -1

'''
Rabin-Karp Algorithm
'''
def RKsearch(pat, txt, q=101, d=256):
    M = len(pat)
    N = len(txt)
    i = 0
    j = 0
    p = 0    # hash value for pattern
    t = 0    # hash value for txt
    h = 1
 
    # The value of h would be "pow(d, M-1)%q"
    for i in xrange(M-1):
        h = (h*d)%q
 
    # Calculate the hash value of pattern and first window
    # of text
    for i in xrange(M):
        p = (d*p + ord(pat[i]))%q
        t = (d*t + ord(txt[i]))%q
 
    # Slide the pattern over text one by one
    for i in xrange(N-M+1):
        # Check the hash values of current window of text and
        # pattern if the hash values match then only check
        # for characters on by one
        if p==t:
            # Check for characters one by one
            for j in xrange(M):
                if txt[i+j] != pat[j]:
                    break
 
            j+=1
            # if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if j==M:
                print "Pattern found at index " + str(i)
 
        # Calculate hash value for next window of text: Remove
        # leading digit, add trailing digit
        if i < N-M:
            t = (d*(t-ord(txt[i])*h) + ord(txt[i+M]))%q
 
            # We might get negative values of t, converting it to
            # positive
            if t < 0:
                t = t+q

'''
Find anagrams
'''
def findAnagrams(pat, txt):
    indices = []
    if len(txt) < len(pat): return indices
    patArr = [0]*26
    txtArr = [0]*26
    i = 0
    for i in range(len(pat)):
        patind = ord(pat[i]) - ord('A')
        txtind = ord(txt[i]) - ord('A')
        patArr[patind] += 1
        txtArr[txtind] += 1
    if patArr == txtArr: indices.append(0)
    
    for i in range(len(pat), len(txt)):
        txtArr[ord(txt[i]) - ord('A')] += 1
        txtArr[ord(txt[i-len(pat)]) - ord('A')] -= 1
        if patArr == txtArr: indices.append(i-len(pat)+1)
    return indices

# Driver program to test the above function

'''
Minimum Edit Distance
'''
def subcost(x, y):
    return 0 if x == y else 2
def minimumEditDistanceR(target, source):
    t, s = len(target), len(source)
    if t == 0 : return s
    elif s == 0: return t
    
    return (min(minimumEditDistanceR(target[:t-1], source)+1, minimumEditDistanceR(target, source[:s-1])+1,
                minimumEditDistanceR(target[:t-1], source[:s-1]) + subcost(target[t-1], source[s-1])))


txt = "GEEKSFORGEEKS"
pat = "EKEG"
# A prime number
# RKsearch(pat,txt)
# search(pat, txt)
# KMPsearch(pat, txt)
'''
ind = findAnagrams(pat, txt)
print ind
'''
'''
v = minimumEditDistanceR(txt, pat)
print v
'''