terminate = False;

while not terminate:
	operation = input("Enter a number operation (+, -, /, *, **, %): ");
	num1 = int(input("Enter your 1st number: "));
	num2 = int(input("Enter your 2nd number: "));
	game_over = False;

	while not game_over:
		if operation == "+":
			print(num1 + num2);
		elif operation == "-":
			print(num1 - num2);
		elif operation == "/":
			print(num1 / num2);
		elif operation == "*":
			print(num1 * num2);
		elif operation == "**":
			print(num1 ** num2);
		elif operation == "%":
			print(num1 % num2);

		game_over = True;

		if game_over:
			entry = input("Would you like to play again? (0 - no, 1 - yes): ");

			if entry == "0":
				terminate = True;

print("Thank you for using this calculator.");
