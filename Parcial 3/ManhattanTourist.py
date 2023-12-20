def ManhattanTourist(WDown, WRight, n, m):

    s = []

    # Creacion de una matriz nula.
    for i in range(n):
        s.append([])
        for j in range(m):
            s[i].append(0)
    max = [0, 0]

    # Llenado de posicion nx0
    for i in range(1, n):
        s[i][0] = s[i-1][0] + WDown[i][0]

    # Llenado de posicion 0xm
    for j in range(1, n):
        s[0][j] = s[0][j-1] + WRight[0][j]

    # Buscando la mejor ruta.

    for i in range(1, n):
        for j in range(1, m):
            max[0] = s[i-1][j] + WDown[i][j]
            max[1] = s[i][j-1] + WRight[i][j]
            if (max[0] > max[1]):
                s[i][j] = max[0]
            else:
                s[i][j] = max[1]

    # impresion de la matrix resultante.
    for elem in s:
        print(elem)

    # Regresa el camino con mayor score.
    return s[n-1][m-1]


WDown = [[0, 0, 0, 0, 0],
         [1, 0, 2, 4, 3],
         [4, 6, 5, 2, 1],
         [4, 4, 5, 2, 1],
         [5, 6, 8, 5, 3]]

WRight = [[0, 3, 2, 4, 0],
          [0, 3, 2, 4, 2],
          [0, 0, 7, 3, 4],
          [0, 3, 3, 0, 2],
          [0, 1, 3, 2, 2]]

n = 5
m = 5

Max = ManhattanTourist(WDown, WRight, n, m)
print('El mejor camino tiene un valor de:', Max)
