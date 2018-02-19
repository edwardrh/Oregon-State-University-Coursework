<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: November 16th, 2015
	  Filename: signup.php
   -->
   <head>
      <title>Sign-Up</title>
	  <link rel="stylesheet" type="text/css" href="style.css" />
	  <script type = "text/javascript"  src = "validation.js" > </script>	
   </head>
   <body>
	  <nav>
	     <a href="signup.php">Sign-Up</a> &nbsp; &nbsp;
		 <a href="login.php">Log-In</a> &nbsp; &nbsp;
		 <a href="rps.php">Play the Game</a> &nbsp; &nbsp;
		 <a href="score.php">Scoreboard</a> &nbsp; &nbsp;
	  </nav>
	  <h1>Sign-Up</h1>
	  <p>
		<!--
		Ran out of time in order to debug this code in order for the program
		to work correctly.
		-->
		<?php
		require_once('connectvars.php');
		$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
		
		if (isset($_POST['submit'])) {
			$userName = mysqli_real_escape_string($dbc, trim($_POST['username']));
			$password = mysqli_real_escape_string($dbc, trim($_POST['password']));
			$first_name = mysqli_real_escape_string($dbc, trim($_POST['first_name']));
			$last_name = mysqli_real_escape_string($dbc, trim($_POST['last_name']));
			if (!empty($username) && !empty($password)) {
				$query = "SELECT * FROM rps WHERE username = '$username'";
				$data = mysqli_query($dbc, $query);
				if (mysqli_num_rows($data) == 0) {
					$query = "INSERT INTO rps (username, password, first_name, last_name) VALUES ('$username', '$password', '$first_name', '$last_name')";
					mysqli_query($dbc, $query);
					echo '<p>Your new account has been made!</p>';
					mysqli_close($dbc);
					exit();
				}
				else {
					echo '<p class="error">Username is already taken.</p>';
					$username = "";
				}
			}
			else {
				echo '<p class="error">Check your entered information again.</p>';
			}
		}
		
		mysqli_close($dbc);
		?>
		<form method="post" action="<?php echo $_SERVER['rps']; ?>">
		<fieldset>
			<legend>Sign Up</legend>
			<label for="first_name">First Name:</label>
			<input type="text" id="first_name" name="first_name" /><br/> 
			<label for="last_name">Last Name:</label>
			<input type="text" id="last_name" name="last_name" /><br/> 
			<label for="username">Username:</label>
			<input type="text" id="username" name="username" value="<?php if (!empty($username)) echo $username; ?>" /><br/>
			<label for="password">Password:</label>
			<input type="password" id="password" name="password" /><br/>
		</fieldset>
		<input type="submit" value="Sign Up" name="submit" />
		</form>
		</p>
		<footer>
		</footer>
   </body>
</html>