#!/usr/bin/python3
"""utf validation module"""


def validUTF8(data):
    """
    determines if a given data set represents a valid UTF-8 encoding.
    """
    b = 0
    for n in data:
        num = format(n, '#010b')[-8:]
        if not b == 0:
            if not (num[0] == '1' and num[1] == '0'):
                return False
        else:
            for bit in num:
                if bit == '0':
                    break
                b += 1
            if b == 0:
                continue
            if b > 4 or b == 0:
                return False
        b -= 1
    response = b == 0
    return response
