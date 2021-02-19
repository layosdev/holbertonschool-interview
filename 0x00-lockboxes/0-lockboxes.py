#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """determines if all the boxes can be opened."""

    box_status = False
    keys = [0]
    arr_index = []
    arr_size = len(boxes)

    for i in range(arr_size):
        arr_index.append(i)

    while len(arr_index):
        arr_aux = []
        for key in keys:
            if key in arr_index:
                box_status = True
                for box in boxes[key]:
                    if box in arr_index and box not in keys:
                        arr_aux.append(box)
                arr_index.remove(key)
        keys.extend(arr_aux)

        if not box_status:
            return False
        box_status = False
    return True
