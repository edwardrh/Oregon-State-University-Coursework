<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: November 16th, 2015
	  Filename: login.php
   -->
    <!--
	Ran out of time in order to debug this code in order for the program
	to work correctly.
	-->
   <?php
		session_start();
		include 'connectvars.php';
	
		if ((isset($_POST['username'])) && (isset($_POST['password'])) ){
			$username = $_POST['username'];
			$password = $_POST['password'];
			$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
			if (!$dbc) {
				die('Could not connect.');
			}
			$query = "SELECT * FROM rps WHERE username='$username' and password='$password'";
			$result = mysqli_query($dbc, $query);
			if (mysqli_num_rows($result) == 1) {
				$row = mysqli_fetch_array($result);
				$_SESSION['first_name'] = $row['first_name'];
				$_SESSION['valid_user'] = $row['username'];
			}
			else {
				echo "Incorrect Username/Password";
			}
			mysqli_free_result($result);
			mysqli_close($dbc);
	}  
	?>
   <head>
      <title>Log-In</title>
	  <link rel="stylesheet" type="text/css" href="style.css" />
   </head>
   <body>
	  <nav>
	     <a href="signup.php">Sign-Up</a> &nbsp; &nbsp;
		 <a href="login.php">Log-In</a> &nbsp; &nbsp;
		 <a href="rps.php">Play the Game</a> &nbsp; &nbsp;
		 <a href="score.php">Scoreboard</a> &nbsp; &nbsp;
	  </nav>
	  <h1>Log-In</h1>
	  <p>
	   <?php
			if (isset($_SESSION['valid_user'])) {
				echo " <h3> You are logged in as </h3><p> User: ".$_SESSION['valid_user']; 
				echo " <p> First Name: ".$_SESSION['first_name']; 
				echo "<p> <a href='logout.php'>Log out </a><br />";
			}
			else {
				if (isset($username)) {
					echo "<h2> Unable to log in. </h2>";
				} 
				else {
					echo " <h2> Have not logged in yet. </h2> ";
				}
				echo " <form method='post' action='login.php' > ";
				echo " Username <input type='text' name='username'> <br /> ";
				echo " Password <input type='password' name='password' /> <br />";
				echo '<input type="submit" value="Log In" name="submit" />';
				echo "</form>";
			}	
		?>
	  </p>
	  <footer>
      </footer>
   </body>
</html>