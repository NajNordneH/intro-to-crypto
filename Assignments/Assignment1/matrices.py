import numpy as np

def print_after_iter(matrix, n):
    print(np.linalg.matrix_power(matrix, n))


M = np.array([[0, 0, 0, 1],
              [1, 0, 0, 0],
              [0, 1, 0, 0],
              [0, 0, 1, 1]])

print(np.linalg.matrix_power(M, 2))

print(np.linalg.matrix_power(M, 3))

print(np.linalg.matrix_power(M, 6))

print_after_iter(M,8)

print_after_iter(M,14)
