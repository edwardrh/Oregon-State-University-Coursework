<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: November 16th, 2015
	  Filename: logout.php
   -->
   <?php
		session_start();
		$username = $_SESSION['valid_user'];
		unset($_SESSION['valid_user']);
		session_destroy();
	?>
   <head>
      <title>Log-Out</title>
	  <link rel="stylesheet" type="text/css" href="style.css" />
   </head>
   <body>
	  <nav>
	     <a href="signup.php">Sign-Up</a> &nbsp; &nbsp;
		 <a href="login.php">Log-In</a> &nbsp; &nbsp;
		 <a href="rps.php">Play the Game</a> &nbsp; &nbsp;
		 <a href="score.php">Scoreboard</a> &nbsp; &nbsp;
	  </nav>
	  <h1>Logged Out</h1>
	  <?php
		if (!empty($username)) {
			echo ''.$username.' has successfully been logged out.';
		} 
		else {
			echo 'You were not logged in!';
		}
	  ?>
	  <footer>
      </footer>
   </body>
</html>