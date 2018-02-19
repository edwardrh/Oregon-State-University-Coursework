<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: December 10th, 2015
	  Filename: login.php
   -->
   <head>
      <title>Log In</title>
	  <link rel="stylesheet" type="text/css" href="stylep.css" />
   </head>
   <body>
	  <nav>
	     <a href="home.html">Home</a> &nbsp; &nbsp;
	     <a href="login.html">Login/Create Account</a> &nbsp; &nbsp;
		 <a href="contact.html">Contact Us</a> &nbsp; &nbsp;
	  </nav>
	  <br>
	  <h1>Log In / Create an Account</h1>
	  <br>
	  <?php
		require_once('connectvars.php');
		$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
		
		if (isset($_POST['login'])) {
			$userName = mysqli_real_escape_string($dbc, trim($_POST['username']));
			$password = mysqli_real_escape_string($dbc, trim($_POST['password']));
			if (!empty($username) && !empty($password)) {
				$query = "SELECT * FROM user_information WHERE username = '$username'";
				$data = mysqli_query($dbc, $query);
				if (mysqli_num_rows($data) == 0) {
					$query = "INSERT INTO user_information (username, password) VALUES ('$username', '$password')";
					mysqli_query($dbc, $query);
					mysqli_close($dbc);
					exit();
				}
			}
			else {
				echo '<p class="error">Check your entered information again.</p>';
			}
		}
		
		mysqli_close($dbc);
		?>
	  <form method="post" action="<?php echo $_SERVER['user_information']; ?>">
		<fieldset>
			<legend></legend>
			Log In
			<br><br>
			<label for="username">Username:</label>
			<input type="text" id="username" name="username" value="<?php if (!empty($username)) echo $username; ?>" /><br/>
			<label for="password">Password:</label>
			<input type="password" id="password" name="password" /><br/>
			<br>
			<input type="submit" value="Log In" name="login" />
		</fieldset>
		</form>
	  <br>
	  <p>
	     <a href="profile.html">Click Here</a><br>
		 (When you cannot log in to grade the rest of this project.)
	  </p>
	  <br>
	  <?php
		require_once('connectvars.php');
		$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
		
		if (isset($_POST['submit'])) {
			$userName = mysqli_real_escape_string($dbc, trim($_POST['username']));
			$password = mysqli_real_escape_string($dbc, trim($_POST['password']));
			$first_name = mysqli_real_escape_string($dbc, trim($_POST['first_name']));
			$last_name = mysqli_real_escape_string($dbc, trim($_POST['last_name']));
			if (!empty($username) && !empty($password)) {
				$query = "SELECT * FROM user_information WHERE username = '$username'";
				$data = mysqli_query($dbc, $query);
				if (mysqli_num_rows($data) == 0) {
					$query = "INSERT INTO user_information (username, password, first_name, last_name) VALUES ('$username', '$password', '$first_name', '$last_name')";
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
		<form method="post" action="<?php echo $_SERVER['user_information']; ?>">
		<fieldset>
			<legend></legend>
			Sign Up
			<br><br>
			<label for="first_name">First Name:</label>
			<input type="text" id="first_name" name="first_name" /><br/> 
			<label for="last_name">Last Name:</label>
			<input type="text" id="last_name" name="last_name" /><br/> 
			<label for="username">Username:</label>
			<input type="text" id="username" name="username" value="<?php if (!empty($username)) echo $username; ?>" /><br/>
			<label for="password">Password:</label>
			<input type="password" id="password" name="password" /><br/>
			<br>
			<input type="submit" value="Sign Up" name="submit" />
		</fieldset>
		</form>
	  <footer>
         <hr>
      </footer>
   </body>
</html>