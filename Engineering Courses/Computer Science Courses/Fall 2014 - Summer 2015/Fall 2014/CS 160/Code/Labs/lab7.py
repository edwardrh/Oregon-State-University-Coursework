num = int(input("How many numbers would you like your list to consist of?: "));

value = [0] * num;

for i in range(len(value)):
	value[i] = int(input("Enter a whole number: "));

print(value);

for i in range(len(value)):
	print(value[i]);

replacement = int(input("Would you like to replace a number on your list? (yes-1, no-0): "));
if replacement == 0:
	exit();
elif replacement == 1:
	picked = int(input("What number would you like to replace?: "));
	want = int(input("What number would you like to replace it with?: "));
	for n, i in enumerate(value):
		if i==picked:
			value[n]=want;
	print(value);
	for i in range(len(value)):
		print(value[i]);
