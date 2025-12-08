f = open("Day04/code.txt")
rows = f.read().split("\n")
rows = rows[:-1]
sum_accessible_roll = 0

for i in range(0, len(rows)):
    for j in range(0, len(rows[i])):
        case = rows[i][j]
        if (case != '@'):
            continue
        near_roll = 0
        for y in range(i - 1, i + 2):
            for x in range(j - 1, j + 2):
                if y < 0 or x < 0 or y >= len(rows) or x >= len(rows[0]) or (y == i and x == j):
                    continue
                if rows[y][x] == '@':
                    near_roll += 1
        if (near_roll < 4):
            sum_accessible_roll += 1

print(sum_accessible_roll)
