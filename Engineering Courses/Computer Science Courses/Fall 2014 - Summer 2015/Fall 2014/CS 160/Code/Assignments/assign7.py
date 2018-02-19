def get_initial_input():
	initial = [0,0,0,0,0];
	initial[0] = int(input("How many tests did you have in the class?: "));
	initial[1] = int(input("How many assignments did you have in the class?: "));
	initial[2] = int(input("How many quizzes did you have in the class?: "));
	initial[3] = int(input("How many labs did you have in the class?: "));

	x = input("Did you have a final in the class? (y/n): ");
	while x != "y" and x != "n":
		x = input("Please enter y or n: ");
	if x == "y":
		initial[4] = 1;
	else:
		initial[4] = 0;

	return initial;

def get_percentages(initial):
	percentage = [];
	if initial[0] != 0:
		percentage[0] = float(input("What is the weighted percentage for each test?: "));
	if initial[1] != 0:
		percentage[1] = float(input("What is the weighted percentage for each assignment?: "));
	if initial[2] != 0:
		percentage[2] = float(input("What is the weighted percentage for each quiz?: "));
	if initial[3] != 0:
		percentage[3] = float(input("What is the weighted percentage for each lab?: "));
	if initial[4] != 0:
		percentage[4] = float(input("What is the weighted percentage for the final?: "));

	return percentage;

def get_scores(initial):
	tests = [0] * initial[0];

	for i in range(len(tests)):
		tests[i] = float(input("Enter your test score: "));

	assignments = [0] * initial[1];

	for i in range(len(assignments)):
		assignments = float(input("Enter your assignment score: "));

	quizzes = [0] * initial[2];

	for i in range(len(quizzes)):
		quizzes = float(input("Enter your quiz score: "));

	labs = [0] * initial[3];

	for i in range(len(labs)):
		labs = float(input("Enter your lab score: "));

	final = [0] * initial[4];

	for i in range(len(final)):
		final = float(input("Enter your grade on the final: "));

	return tests;
	return assignments;
	return quizzes;
	return labs;
	return final;

def calculate_weighted_avg(percentage, tests, assignments, quizzes, labs, final):
	scores_avgs = [];

	sum = 0;
	k = 0;
	while k < len(tests):
		sum = sum + tests[k][0];
		k = k + 1;
	scores_avgs[0] = sum / float(len(tests));

	sum = 0;
	k = 0;
	while k < len(assignments):
		sum = sum + assignments[k][0];
		k = k + 1;
	scores_avgs[1] = sum / float(len(assignments));

	sum = 0;
	k = 0;
	while k < len(quizzes):
		sum = sum + quizzes[k][0];
		k = k + 1;
	scores_avgs[2] = sum / float(len(quizzes));

	sum = 0;
	k = 0;
	while k < len(labs):
		sum = sum + labs[k][0];
		k = k + 1;
	scores_avgs[3] = sum;

	scores_avgs[4] = final;

	scores_percentages = [];
	k = 0;
	while k < len(scores_avgs):
		weighted_percentage = scores_avgs[k] * percentage[k];
		scores_percentages.append(weighted_percentage);
		k = k + 1;

	return scores_percentages;

def calculate_class_grade(scores_percentages):
	sum = 0;
	k = 0;
	while k < len(scores_percentages):
		sum = sum + scores_percentages[k][0];
		k = k + 1;
	class_grade = sum;
	print("Your overall grade in the class is " + class_grade);

def main():
	terminate = False;

	while not terminate:
		get_initial_input();
		get_percentages(get_initial_input);
		get_scores(get_initial_input);
		calculate_weighted_avg(get_percentages, get_scores);
		calculate_class_grade(calculate_weighted_avg);

		response = input("Would you like to calculate a grade for another class? (y/n): ");
		while response != "y" and response != "n":
			response = input("Please enter y or n: ");
		if response == "n":
			terminate = True;


main();
