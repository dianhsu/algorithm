#!/usr/bin/env python3

def rotate(mat: list[list]) -> list[list]:
    """
    Rotate a 2D matrix 90 degrees clockwise.
    """
    return [list(reversed(col)) for col in zip(*mat)]
def diff(a: list[list], b: list[list]) -> int:
    """
    Count the number of different elements between two 2D matrices.
    """
    return sum(1 for i in range(len(a)) for j in range(len(a[0])) if a[i][j] != b[i][j])

N = int(input())
A = []
B = []
for i in range(N):
    a = list(input())
    A.append(a)
for i in range(N):
    b = list(input())
    B.append(b)
ans = 10**9
for idx in range(4):
    ans = min(ans, diff(A, B) + idx)
    A = rotate(A)
print(ans)