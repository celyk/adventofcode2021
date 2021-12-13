def parse(line):
	s0 = "([{<"
	s1 = ")]}>"

	stack = []

	for i,c in enumerate(line):
		if c in s0: 
			stack.append(s1[ s0.find(c) ])
		elif c == stack[-1]:
			stack.pop()
		else: 
			return [stack[-1], i]
'''
	if len(stack) > 0:  
		print("hm")
		return [stack[-2], i]
'''

score = 0

with open("input.txt", "r") as file:
	for line in file:
		print(line.rstrip())

		result = parse(line.rstrip())
		if result:
			print(line[:result[1]])
			print("Error! expected a",result[0],", but found",line[result[1]],"instead")

			c = line[result[1]]

			dic = {
				')': 3,
				']': 57,
				'}': 1197,
				'>': 25137
			}

			score += dic[c]

print(score)