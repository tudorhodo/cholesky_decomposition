import numpy as np

matrix = np.random.randint(1, 9999, (5000, 5000))
new_matrix = np.dot(matrix, matrix.T)
with open("troll.txt", "a+") as f:
    np.savetxt(f, new_matrix, fmt="%d")
