ADN1 = ["A", "G", "C", "T", "C", "A", "C", "A", "G", "G", "C", "A"]
ADN2 = ["G", "C", "T", "G", "G", "C", "C", "A", "G", "G", "C", "A"]
ADN3 = ["C", "T", "G", "G", "T", "A", "A", "A", "G", "G", "C", "A"]
ADN4 = ["G", "G", "C", "G", "T", "T", "C", "A", "G", "G", "C", "A"]
ADN5 = ["A", "C", "C", "G", "G", "C", "C", "A", "G", "G", "C", "A"]

l = 3
t = 1
n = len(ADN1)

def score(ADN1, ADN2):
    score = 0
    for i in range(len(ADN1)):
        if ADN1[i] == ADN2[i]:
            score += 1
    return score


def Branch(ADN, n, l, t):
    AUX = []
    for i in range(n-l+1):
        for j in range(l):
            pos = i + j
            if pos <= n:
                AUX.append(ADN[pos])
        print(AUX, "score:", score(AUX, ADN2)+l)
        AUX.clear()

Branch(ADN1, n, l, t)