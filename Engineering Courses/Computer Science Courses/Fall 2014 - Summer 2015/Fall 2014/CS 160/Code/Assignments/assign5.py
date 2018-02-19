import turtle

window = turtle.Screen();
my_turtle = turtle.Turtle();

my_turtle.shape("turtle");
my_turtle.color("orange");

def star(x,y):
	my_turtle.clear();
	for i in range(5):
		my_turtle.right(144);
		my_turtle.forward(100);

def main():
	my_turtle.onclick(star);

	window.mainloop();

main();
