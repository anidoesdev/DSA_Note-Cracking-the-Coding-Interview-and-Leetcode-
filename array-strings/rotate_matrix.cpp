```python
def rotate_matrix(matrix):
    m = len(matrix)
    n = len(matrix[0])
    for i in range(m):
        for j in range(i+1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(m):
        matrix[i] = matrix[i][::-1]

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))

def main():
    matrix = [[i * 3 + j + 1 for j in range(3)] for i in range(3)]
    print("Original Matrix:")
    print_matrix(matrix)
    rotate_matrix(matrix)
    print("Rotated Matrix:")
    print_matrix(matrix)

if __name__ == "__main__":
    main()
```