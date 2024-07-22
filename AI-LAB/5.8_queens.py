def is_safe(board, row, col):
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True

def solve_queens(board, row):
    n = len(board)
    if row == n:
        return True
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            if solve_queens(board, row + 1):
                return True
            board[row] = -1  # Backtrack
    return False

def print_solution(board):
    n = len(board)
    for i in range(n):
        row = ["." for _ in range(n)]
        row[board[i]] = "Q"
        print(" ".join(row))
    print()

def solve_8_queens():
    board = [-1] * 8
    if solve_queens(board, 0):
        print("Solution:")
        print_solution(board)
    else:
        print("No solution exists.")

solve_8_queens()
