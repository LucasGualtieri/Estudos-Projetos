squares = [x**2 for x in range(2, 10, 1) if x % 2 == 0]

print("squares lenth", len(squares))

def fn(list):
	list.append(4)

# x = 1
# print("x:", x)
# def foo(x: int):
# 	x

# foo(x)
# print("x:", x)

print(squares)
fn(squares)
print(squares)

# for i in range(len(squares)):
# 	print(i + 1, "I:", squares[i])