//Setting global variables
var rock = "rock";
var paper = "paper";
var scissors = "scissors";
var computer_score = 0;
var user_score = 0;

//Preforming function, displays ouputs based on inputs
function compare(choice1, choice2) {
	//Resets initial display to the user before each round
	document.getElementById('default1').style.display="visible";
	document.getElementById('rock1').style.display="none";
	document.getElementById('paper1').style.display="none";
	document.getElementById('scissors1').style.display="none";
	document.getElementById('default2').style.display="visible";
	document.getElementById('rock2').style.display="none";
	document.getElementById('paper2').style.display="none";
	document.getElementById('scissors2').style.display="none";

	//Sets randomly generated computer's choice
	var computerChoice = Math.random();
    if (computerChoice < 0.34) {
      choice2 = "rock";
    } 
	else if(computerChoice > 0.67) {
      choice2 = "paper";
    } 
	else{
      choice2 = "scissors";
    }

	//When the user and computer choose the identically
    if (choice1 == choice2) {
		document.getElementById("round_result").innerHTML  = "It's a tie."; 
	    if(choice1 == rock){
			document.getElementById('default1').style.display="none";
			document.getElementById('rock1').style.display="visible";
			document.getElementById('default2').style.display="none";
			document.getElementById('rock2').style.display="visible";
	    }
	    else if(choice1 == paper){
			document.getElementById('default1').style.display="none";
			document.getElementById('paper1').style.display="visible";
			document.getElementById('default2').style.display="none";
			document.getElementById('paper2').style.display="visible";
	    }
	    else{
			document.getElementById('default1').style.display="none";
			document.getElementById('scissors1').style.display="visible";
			document.getElementById('default2').style.display="none";
			document.getElementById('scissors2').style.display="visible";
	    }
    } 
	//When user chooses rock
	else if (choice1 == rock) {
		document.getElementById('default1').style.display="none";
		document.getElementById('rock1').style.display="visible";
		if (choice2 == paper) { 
			document.getElementById('default2').style.display="none";
			document.getElementById('paper2').style.display="visible";
			computer_score += 1;
			document.getElementById("round_result").innerHTML  = "Paper covers rock. Computer wins..."; 
        }
		else{
			document.getElementById('default2').style.display="none";
			document.getElementById('scissors2').style.display="visible";
			user_score += 1;
			document.getElementById("round_result").innerHTML  = "Rock breaks scissors. You win!"; 
        }
    } 
	//When user chooses paper
	else if (choice1 == paper) {
		document.getElementById('default1').style.display="none";
		document.getElementById('paper1').style.display="visible";
		if (choice2 == rock) {
			document.getElementById('default2').style.display="none";
			document.getElementById('rock2').style.display="visible";
			document.getElementById("round_result").innerHTML  = "Paper covers rock. You win!"; 
			user_score += 1;
        } 
		else{
			document.getElementById('default2').style.display="none";
			document.getElementById('scissors2').style.display="visible";
			document.getElementById("round_result").innerHTML  = "Scissors cut paper. Computer wins..."; 
			computer_score += 1;
        }
    } 
	//When user chooses scissors
	else if (choice1 == scissors) {
		document.getElementById('default1').style.display="none";
		document.getElementById('scissors1').style.display="visible";
		if (choice2 == rock) {
			document.getElementById('default2').style.display="none";
			document.getElementById('rock2').style.display="visible";
			document.getElementById("round_result").innerHTML  = "Rock breaks scissors. Computer wins..."; 
			computer_score += 1;
        }
		else{
			document.getElementById('default2').style.display="none";
			document.getElementById('paper2').style.display="visible";
			document.getElementById("round_result").innerHTML  = "Scissors cut paper. You win!"; 
			user_score += 1;
	    }
    }
	
	//Diplays current scores
    document.getElementById("user_score").innerHTML  = user_score;
    document.getElementById("computer_score").innerHTML  = computer_score;
    }
	
/*
Note About My Program:
I was unable to figure out why my Javascipt is unable to be implemented along with
my HTML file. This is unfortunate because my Rock, Paper, Scissors game is unable to
be played. I have done my best before this assignment was due in order to fix the issue.
I have tried my very best in writing my code, and I have studied my code many times
to see what was the problem, being unable to solve it at the end. I am understanding and
accept my future consequences for this assignment.
Thank you for time and consideration. :)
*/