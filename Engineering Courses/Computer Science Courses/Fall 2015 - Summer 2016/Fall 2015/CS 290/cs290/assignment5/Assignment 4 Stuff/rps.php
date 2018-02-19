<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: November 16th, 2015
	  Filename: rps.php
   -->
	<!--
	Ran out of time in order to debug this code in order for the program
	to work correctly.
	-->
   <?php
		if (isset($_POST[‘submitted’]) == 1) {
			$wins = $_POST[‘wins’];
			$losses = $_POST[‘losses’];
			$draws = $_POST[‘draws’];
			$user = $_POST[‘user’];
		
			$random = rand(1,3);
			if ($random == 1) {
				$computer = "Rock";
			}
			if ($random == 2) {
				$computer = "Paper";
			}
			if ($random == 3) {
				$computer = "Scissors";
			}	
		
			if ($computer == $user) {
				$outcome = "It was tie";
				$draws++;
			}
			if ($computer == "Rock" && $user == "Paper") {
				$outcome = "You Won!";
				$wins++;
			}
			if ($computer == "Paper" && $user == "Scissors") {
				$outcome = "You Won!";
				$wins++;
			}
			if ($computer == "Scissors" && $user == "Rock") {
				$outcome = "You Won!";
				$wins++;
			}
			if ($computer == "Scissors" && $user == "Paper") {
				$outcome = "Computer Won...";
				$losses++;
			}
			if ($computer == "Paper" && $user == "Rock") {
				$outcome = "Computer Won...";
				$losses++;
			}
			if ($computer == "Rock" && $user == "Scissors") {
				$outcome = "Computer Won...";
				$losses++;
			}
		} 	
		else {
			$wins = 0;
			$losses = 0;
			$draws = 0;
			$outcome = “ ”;
			$user = “ ”;
			$computer = “ ”;
		}
	?>
   <head>
      <title>Rock, Paper, Scissors</title>
	  <link rel="stylesheet" type="text/css" href="style.css" />
   </head>
   <body>
	  <nav>
	     <a href="signup.php">Sign-Up</a> &nbsp; &nbsp;
		 <a href="login.php">Log-In</a> &nbsp; &nbsp;
		 <a href="rps.php">Play the Game</a> &nbsp; &nbsp;
		 <a href="score.php">Scoreboard</a> &nbsp; &nbsp;
	  </nav>
	  <h1>Rock, Paper, Scissors</h1>
		<p>
		<form action="" method="post" style="">
			<input name="submitted" type="hidden" value="1" />
			<input name="wins" type="hidden" value=”<?php echo $wins; ?>” />
			<input name="losses" type="hidden" value=”<?php echo $losses; ?>” />
			<input name="draws" type="hidden" value=”<?php echo $draws; ?>” />
			<label><input type="submit" name="user" value="Rock" id="throw_1"></label>
			<label><input type="submit" name="user" value="Paper" id="throw_2"></label>
			<label><input type="submit" name="user" value="Scissors" id="throw_3"></label>
		</form>
		<p><?php echo $outcome; ?></p>
		<p>You Pick: <?php echo $user; ?></p>
		<p>Computer's Pick: <?php echo $computer; ?></p>
		<p>Wins: <?php echo $wins; ?></p>
		<p>Losses: <?php echo $losses; ?></p>
		<p>Draws: <?php echo $draws; ?></p>
		<form method="get" action="">
			<input type="submit" value="reset">
		</form>
		</p>
		<footer>
			<a href="logout.php">Logout</a>
		</footer>
   </body>
</html>