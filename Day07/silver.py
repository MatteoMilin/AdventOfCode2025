f = open("Day07/code.txt")
rows = f.read().split("\n")
rows = rows[:-1]
total_split = 0
start_index = rows[0].find('S')
laser_indexes = [start_index]

for row in rows:
    new_indexes = []
    for laser_index in laser_indexes:
        if row[laser_index] == '^':
            total_split += 1
            if (laser_index > 0):
                new_indexes.append(laser_index - 1)
            if (laser_index < len(row) + 1):
                new_indexes.append(laser_index + 1)
        else:
            new_indexes.append(laser_index)
    laser_indexes = set(new_indexes)

print(total_split)
