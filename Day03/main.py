f = open("Day03/code.txt")
batteries = f.read().split("\n")
batteries = batteries[:-1]
sum_jolt = 0

for battery in batteries:
    print(battery)
    first_max_index = -67
    second_max_index = -67
    for i in range(0, len(battery) - 1):
        if first_max_index == -67 or battery[i] > battery[first_max_index]:
            first_max_index = i

    for i in range(first_max_index + 1, len(battery) ):
        if second_max_index == -67 or battery[i] > battery[second_max_index]:
            second_max_index = i
    max = battery[first_max_index] + battery[second_max_index]
    sum_jolt += int(max)

print(sum_jolt)
