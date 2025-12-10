f = open("Day06/code.txt")
rows = f.read().split("\n")
rows = rows[:-1]
final_result = 0
split_rows = []

for row in rows:
    split_rows.append(row.split())

for i in range(0, len(split_rows[0])):
    sum = int(split_rows[0][i])
    for j in range(1, len(split_rows) - 1):
        if (split_rows[len(split_rows) - 1][i] == '*'):
            sum *= int(split_rows[j][i])
        if (split_rows[len(split_rows) - 1][i] == '-'):
            sum -= int(split_rows[j][i])
        if (split_rows[len(split_rows) - 1][i] == '/'):
            sum /= int(split_rows[j][i])
        if (split_rows[len(split_rows) - 1][i] == '+'):
            sum += int(split_rows[j][i])
    final_result += sum
print(final_result)
