#!/usr/bin/env python3

s = input()

for i in range(26):
    t = chr(ord('a') + i)
    if t not in s:
        print(t)
        break