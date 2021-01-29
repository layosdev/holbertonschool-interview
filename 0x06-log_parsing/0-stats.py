#!/usr/bin/python3
"""Module to compute metrics from logs.
"""
from sys import stdin

total = 0

stats = {
    "200": 0,
    "301": 0,
    "400": 0, "401": 0, "403": 0, "404": 0, "405": 0,
    "500": 0
}

lines = 0

try:

    for i in stdin:

        data = i.split(' ')

        if len(data) > 6:
            status, size = data[-2:]
            total += int(size)
            if status in stats:
                stats[status] += 1
            lines += 1

        if lines == 10:
            print('File size: {}'.format(total))
            for (code, count) in sorted(stats.items()):
                if count > 0:
                    print('{}: {}'.format(code, count))
                lines = 0

finally:
    print('File size: {}'.format(total))
    for (code, count) in sorted(stats.items()):
        if count > 0:
            print('{}: {}'.format(code, count))
