f = open("Day06/code.txt")
rows = f.read().split("\n")
rows = rows[:-1]
final_result = 0
num_list = []

def calculate_row(sign: str, nums: list):
    sum = nums[0]
    for num in nums[1:]:
        if (sign == '*'):
            sum *= num
        if (sign == '-'):
            sum -= num
        if (sign == '/'):
            sum /= num
        if (sign == '+'):
            sum += num
    return sum

for i in range(len(rows[0]) - 1, -1, -1):
    num = ""
    for j in range(0, len(rows) - 1):
        num += rows[j][i]
    if (num.strip() == ""):
        continue
    num_list.append(int(num.strip()))
    if rows[len(rows) - 1][i] in "*+-/":
        new_sum = calculate_row(rows[len(rows) - 1][i], num_list)
        final_result += new_sum
        num_list = []

print(final_result)
