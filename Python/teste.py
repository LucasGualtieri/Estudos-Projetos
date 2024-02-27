def main(args):
	print(args[0])
	print(args[1])

	x = 2
	print("x:", x)
	x = "Sou uma string"
	print("x:", x)

	return "deu bom"

print(main(["OLA", "MUNDO"]))
