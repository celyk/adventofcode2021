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

	if len(stack) > 0:
		stack.reverse()
		return "".join(stack) #completion string

def score(s):
	table = {
		')': 1,
		']': 2,
		'}': 3,
		'>': 4
	}

	score = 0
	for c in s:
		score = score*5 + table[c]

	return score


scores = []

with open("input.txt", "r") as file:
	for line in file:
		print(line.rstrip())

		result = parse(line.rstrip())
		if type(result) == str:
			print("hi:", result)

			scores.append(score(result))
		else:
			print(line[:result[1]])
			print("Error! expected a",result[0],", but found",line[result[1]],"instead")
			continue

scores.sort()

print(scores[len(scores)//2])