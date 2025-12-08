f = open("Day05/code.txt")
rows = f.read().split("\n\n")
ranges = rows[0].split("\n")
ids = rows[1].split("\n")[:-1]
fresh_ids_count = 0
parsed_ranges = []

for i in range(0, len(ranges)):
    range = ranges[i].split("-")
    parsed_ranges.append([int(range[0]), int(range[1])])

for id in ids:
    id = int(id)
    for range in parsed_ranges:
        if range[0] <= id and id <= range[1]:
            fresh_ids_count += 1
            break

print(fresh_ids_count)
