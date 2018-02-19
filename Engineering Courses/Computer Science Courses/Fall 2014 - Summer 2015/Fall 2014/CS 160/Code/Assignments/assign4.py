num = int(input("What number would you like to know the square root of by using the Babylonian algorithm?: "));
guess = num/2
end = int(input("How many times would you like the Babylonian algorithm to run through your number?: "));
for x in range (0, end-1):
	random = num / guess
	guess = (guess + random) / 2
print("This is your answer by using the Babylonian algorithm: " + str(guess));
answer = (num)**(1/2)
print("Here is the difference between the Babylonian algorithm and the acutal square root of the your initial inputted number: ");
print("Babylonian algorithm answer: " + str(guess));
print("Actual answer: " + str(answer));
