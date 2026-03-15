```python
def zero_matrix(matrix):
    row = {}
    column = {}
    m = len(matrix)
    n = len(matrix[0])
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                row[i] = 1
                column[j] = 1
    for i in range(m):
        for j in range(n):
            if i in row or j in column:
                matrix[i][j] = 0

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))

def main():
    matrix = [[0, 1, 2], [2, 3, 4], [6, 0, 7]]
    print("Original Matrix:")
    print_matrix(matrix)
    zero_matrix(matrix)
    print("Matrix after zeroing:")
    print_matrix(matrix)

if __name__ == "__main__":
    main()
```