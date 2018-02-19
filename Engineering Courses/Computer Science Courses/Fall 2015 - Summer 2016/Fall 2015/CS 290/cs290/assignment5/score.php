<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: November 26th, 2015
	  Filename: score.php
   -->
   <head>
      <title>Scoreboard</title>
	  <link rel="stylesheet" type="text/css" href="style.css" />
   </head>
   <body>
	  <nav>
	     <a href="signup.php">Sign-Up</a> &nbsp; &nbsp;
		 <a href="login.php">Log-In</a> &nbsp; &nbsp;
		 <a href="rps.php">Play the Game</a> &nbsp; &nbsp;
		 <a href="score.php">Scoreboard</a> &nbsp; &nbsp;
	  </nav>
	  <h1>Scoreboard</h1>
	  <p>
		<!--
		I was meaning to take this code and change it in order for it to work correctly,
		but I did not have enough time to do so.
		-->
	     <?php
			include 'connectvars.php'; 
	
			$conn = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
			if (!$conn) {
				die('Could not connect: ' . mysqli_error());
			}
			$result = mysqli_query($conn, "SHOW TABLES");
			if (!$result) {
				die("Query to show fields from table failed");
			}
			$num_row = mysqli_num_rows($result);	
	
			echo "<h1>Choose one table:<h1>"; 
			echo "<form action=\"showTable.php\" method=\"POST\">";
			echo "<select name=\"table\" size=\"1\" Font size=\"+2\">";
	
			for($i=0; $i<$num_row; $i++) {
				$tablename=mysqli_fetch_row($result);
				echo "<option value='$tablename[0]' >".$tablename[0]."</option>";
			}
	
			echo "</select>";
			echo "<div><input type=\"submit\" value=\"submit\"></div>";
			echo "</form>";
		
			mysqli_free_result($result);
			mysqli_close($conn);
		?>
		<table>
			<tr>
				<th>User</th>
				<th>Score</th>
			</tr>
		</table>
	  </p>
	  <footer>
		<a href="logout.php">Logout</a>
      </footer>
   </body>
</html>