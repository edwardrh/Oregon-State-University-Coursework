import turtle

window = turtle.Screen();
my_turtle = turtle.Turtle();

my_turtle.shape("turtle");
my_turtle.color("orange");

def name(x,y):
	my_turtle.clear();
	my_turtle.write("Rhea Mae Edwards", move=True, align="center", font=("Arial", 50, "normal"));

def main():
	my_turtle.onclick(name);

	window.mainloop();

main();
