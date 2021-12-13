def outOfBounds(data, x, y) -> bool:
	return not ( y in range(0,len(data)) and x in range(0,len(data[y])) )

def increase(data, x, y):
	if not outOfBounds(data, x, y) and data[y][x] <= 9:
		data[y][x] += 1
		if data[y][x] > 9:
			increase(data, x-1, y-1)
			increase(data, x+0, y-1)
			increase(data, x+1, y-1)

			increase(data, x-1, y+0)
			#current cell
			increase(data, x+1, y+0)

			increase(data, x-1, y+1)
			increase(data, x+0, y+1)
			increase(data, x+1, y+1)

data = []
with open("input.txt", "r") as file:
	for line in file:
		data.append(list(line.rstrip()))
		data[-1] = [int(c) for c in data[-1]]


count = 0

for day in range(0,100):
	print("day",day,":")

	for y in range(0,10):
		for x in range(0,10):
			print(data[y][x],end="")
		print("")
	print("")

	for y in range(0,10):
		for x in range(0,10):
			increase(data, x, y)

	for y in range(0,10):
		for x in range(0,10):
			if data[y][x] > 9: 
				data[y][x] = 0
				count += 1


print("count:", count)
