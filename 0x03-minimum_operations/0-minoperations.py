#!/usr/bin/python3
"""Minimum operations"""


def minOperations(n):
    """Given a number n, Calculates the fewest number of operations
    needed to result in exactly n H characters in the file. """

    if n <= 1:
        return 0
    if type(n) != int:
        return 0

    nH = 1
    copy = 1
    count = 1
    while nH < n:
        if nH != copy and n % nH == 0:
            copy = nH
            count += 1
        nH += copy
        count += 1
    if nH == n:
        return count
    return 0
