import math

c = [1, 3, 7]
d = 3
M = 77
bestNumCoins = []

def DPChange(M, c, d):

    for a in range(M+1):
        bestNumCoins.append(0)
    bestNumCoins[0] = 0

    for m in range(1, M+1, 1):
        bestNumCoins[m] = math.inf
        for i in range(d):
            if m >= c[i]:
                if bestNumCoins[m-c[i]] + 1 < bestNumCoins[m]:
                    bestNumCoins[m] = bestNumCoins[m-c[i]] + 1
    return bestNumCoins[M]

print("Tu cambio es:", DPChange(M, c, d))