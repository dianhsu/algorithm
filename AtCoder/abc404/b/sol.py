#!/usr/bin/env python3
import sys

for line in sys.stdin:
    a = line.strip()
    print(a.count("1"))