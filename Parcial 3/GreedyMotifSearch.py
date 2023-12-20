def matriz_perfilamiento(motivos):
    t = len(motivos)
    k = len(motivos[0])
    matriz_perfilamiento = {
        'a': [],
        'c': [],
        'g': [],
        't': [],
    }

    for j in range(k):
        A_contador = 0
        C_contador = 0
        G_contador = 0
        T_contador = 0

        for i in range(t):
            if motivos[i][j] == 'a':
                A_contador += 1
            elif motivos[i][j] == 'c':
                C_contador += 1
            elif motivos[i][j] == 'g':
                G_contador += 1
            else:
                T_contador += 1

        matriz_perfilamiento['a'].append(A_contador / t)
        matriz_perfilamiento['c'].append(C_contador / t)
        matriz_perfilamiento['g'].append(G_contador / t)
        matriz_perfilamiento['t'].append(T_contador / t)

    return matriz_perfilamiento

def perfil_mas_probable(matriz_perfilamiento, text, k):
    probabilidad_maxima = -9999999
    mas_probable = ''

    for i in range(len(text) - k + 1):
        probabilidad = 1
        s = text[i:i + k]

        for j in range(len(s)):
            probabilidad = probabilidad * matriz_perfilamiento[s[j]][j]

        if probabilidad > probabilidad_maxima:
            probabilidad_maxima = probabilidad
            mas_probable = s

    return mas_probable

def score(motivos):
    score = 0
    k = len(motivos[0])
    t = len(motivos)

    for j in range(k):
        A_contador = 0
        C_contador = 0
        G_contador = 0
        T_contador = 0

        for i in range(t):
            if motivos[i][j] == 'a':
                A_contador += 1
            elif motivos[i][j] == 'c':
                C_contador += 1
            elif motivos[i][j] == 'g':
                G_contador += 1
            else:
                T_contador += 1
        mx = max(A_contador, max(C_contador, max(G_contador, T_contador)))
        score += t - mx

        # num. de filas: el recuento máximo entre a, t, g, c dan la puntuación de una columna.
    return score

def greedy_motif_search(DNA, k, t):
    mejor_motivo = []

    for i in range(len(DNA)):
        mejor_motivo.append((DNA[i])[0:k])

    for i in range(len(DNA[0]) - k + 1):

        # greedy motif matrix
        motivos = [(DNA[0])[i:i + k]]

        for j in range(1, t):

            matriz_perfil = matriz_perfilamiento(motivos)

            motivo = perfil_mas_probable(matriz_perfil, DNA[j], k)
            motivos.append(motivo)

        if score(motivos) < score(mejor_motivo):
            mejor_motivo = motivos

    return mejor_motivo

t = 7
l = 7

ADN = []

with open("C:/Users/Marco/Desktop/C++/ACTIVIDADES/TECNICAS ALGORITMICAS/Parcial 3/data.txt") as fname:
	lineas = fname.readlines()
	for linea in lineas:
		ADN.append(linea.strip('\n'))

# ADN = ['cggggctatgcaactgggtcgtcacattcccctttcgata',
#        'tttgagggtgcccaataaatgcaactccaaagcggacaaa',
#        'ggatgcaactgatgccgtttgacgacctaaatcaacggcc',
#        'aaggatgcaactccaggagcgcctttgctggttctacctg',
#        'aattttctaaaaagattataatgtcggtccatgcaacttc',
#        'ctgctgtacaactgagatcatgctgcatgcaactttcaac',
#        'tacatgatcttttgatgcaacttggatgagggaatgatgc']

mejor_motivo = greedy_motif_search(ADN, l, t)

for motif in mejor_motivo:
    print(motif, "- Score:", score(motif))
