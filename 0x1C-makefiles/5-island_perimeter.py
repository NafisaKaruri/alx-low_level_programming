#!/usr/bin/python3
"""Defines island_perimeter method"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    i = 0
    length = len(grid) - 1
    width = len(grid[0]) - 1

    for x, y in enumerate(grid):
        for a, b in enumerate(y):
            if b == 1:
                if x == 0 or grid[x - 1][a] != 1:
                    i = i + 1
                if a == 0 or grid[x][a - 1] != 1:
                    i = i + 1
                if a == width or grid[x][a + 1] != 1:
                    i = i + 1
                if x == length or grid[x + 1][a] != 1:
                    i = i + 1
    return i
