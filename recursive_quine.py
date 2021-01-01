# A recursive quine

def main():
	q = open("recursive_quine.py", "r")
	content = q.read()
	print(recursive_quine(content), end='')

def recursive_quine(content):
	start = 0
	end = content[start:].find('\n')
	if end != -1:
		return content[start:end+1] + recursive_quine(content[end+1:])
	else:
		# no newline at end of file
		return content[start:]

if __name__ == "__main__":
	main()
