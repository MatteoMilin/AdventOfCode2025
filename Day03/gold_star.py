f = open("Day03/code.txt")
batteries = f.read().split("\n")
batteries = batteries[:-1]
number_of_battery_that_can_be_turned_on = 12
sum_jolt = 0

for battery in batteries:
    indexes = [-67] * number_of_battery_that_can_be_turned_on
    for i in range(0, number_of_battery_that_can_be_turned_on):
        for j in range(0 if i == 0 else (indexes[i - 1] + 1), len(battery) - number_of_battery_that_can_be_turned_on + 1 + i):
            if indexes[i] == -67 or battery[j] > battery[indexes[i]]:
                indexes[i] = j
    max = ""
    for index in indexes:
        max += battery[index]
    sum_jolt += int(max)

print(sum_jolt)
