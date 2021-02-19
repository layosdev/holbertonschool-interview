#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding."""
    number_of_bytes = 0
    for decimal_number in data:
        binary_byte = format(decimal_number, '#010b')[-8:]
        if number_of_bytes == 0:
            for bit in binary_byte:
                if bit == '0':
                    break
                number_of_bytes += 1
            if number_of_bytes == 0:
                continue
            if number_of_bytes == 1 or number_of_bytes > 4:
                return False
        else:
            if not (binary_byte[0] == '1' and binary_byte[1] == '0'):
                return False
        number_of_bytes -= 1
    return number_of_bytes == 0
