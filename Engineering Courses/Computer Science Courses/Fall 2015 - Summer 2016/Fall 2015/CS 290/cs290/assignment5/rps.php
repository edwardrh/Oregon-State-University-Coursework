<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: November 26th, 2015
	  Filename: rps.php
   -->
	<!--
	Ran out of time in order to debug this code in order for the program
	to work correctly.
	-->
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
		 <?php
		include 'connectvars.php'; 
	
		$conn = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
		if (!$conn) {
			die('Could not connect: ' . mysqli_error());
		}
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
		mysqli_close($conn);
		?>
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
		<p>
		How to Play:<br>
		In order to win a round of Rock, Paper, Scissors, you must choose the dominate
		object of two being played.<br>
		Rock dominates Scissors<br>
		Paper dominates Rock<br>
		Scissors dominates Paper<br>
		For every round played, the player who wins that round gets a point added to
		their overall score. Ties and loses have no affect on the players score.
	  </p>
	     <table>
			<tr>
				<th>Rock, Paper, or Scissors?</th>
				<th>Computer Chooses...</th>
			</tr>
			<tr>
				<td>
				<button type="button" onclick="compare(rock, choice2)">Rock</button>
				<button type="button" onclick="compare(paper, choice2)">Paper</button>
				<button type="button" onclick="compare(scissors, choice2)">Scissors</button>
				</td>
				<th>.  .  .  .  .  .</th>
			</tr>
			<tr>
				<td>
					<img id="default1" src="images/start.png" alt="default" width="400" style="display:visible;">
					<img id="rock1" src="images/rock.png" alt="rock" width = "400" style="display:none;">
					<img id="paper1" src="images/paper.png" alt="paper" width = "400" style="display:none;">
					<img id="scissors1" src="images/scissors.png" alt="scissors" width = "400" style="display:none;">
				</td>
				<td>
					<img id="default2" src="images/start.png" alt="default" width="400" style="display:visible;">
					<img id="rock2" src="images/rock.png" alt="rock" width = "400" style="display:none;">
					<img id="paper2" src="images/paper.png" alt="paper" width = "400" style="display:none;">
					<img id="scissors2" src="images/scissors.png" alt="scissors" width = "400" style="display:none;">
				</td>
			</tr>
		 </table>
		 <p id="round_result">Let's Play!</p>
		</p>
		<footer>
			<a href="logout.php">Logout</a>
		</footer>
   </body>
</html>