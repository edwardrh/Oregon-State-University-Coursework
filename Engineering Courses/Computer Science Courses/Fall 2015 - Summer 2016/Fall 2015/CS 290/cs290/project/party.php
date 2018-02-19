<!DOCTYPE html>
<html>
   <!--
      Name: Rhea Mae Edwards
	  Date: December 10th, 2015
	  Filename: party.php
   -->
   <head>
      <title>Party Planner</title>
	  <link rel="stylesheet" type="text/css" href="stylep.css" />
   </head>
   <body>
	  <nav>
	     <a href="profile.html">Profile</a> &nbsp; &nbsp;
		 <a href="friends.html">Find Friends</a> &nbsp; &nbsp;
		 <a href="games.html">Game Ideas</a> &nbsp; &nbsp;
		 <a href="party.php">Party Planner</a> &nbsp; &nbsp;
	  </nav>
	  <br>
	  <h1>Party Planner</h1>
	  <br>
	  <p>
	  When is the Party At???
	  </p>
	  <br>
	  <table>
		<tr>
			<th>Sunday</th>
			<th>Monday</th>
			<th>Tuesday</th>
			<th>Wednesday</th>
			<th>Thursday</th>
			<th>Friday</th>
			<th>Saturday</th>
		 </tr>
		 <tr>
		    <td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
		 </tr>
		 <tr>
		    <td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
		 </tr>
		 <tr>
		    <td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
		 </tr>
		 <tr>
		    <td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
			<td> ... </td>
		 </tr>
	  </table>
	  <br>
	  <?php
		require_once('connectvars.php');
		$dbc = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
		
		if (isset($_POST['plan'])) {
			$Date = mysqli_real_escape_string($dbc, trim($_POST['Date']));
			$Description = mysqli_real_escape_string($dbc, trim($_POST['Description']));
				if (mysqli_num_rows($data) == 0) {
					$query = "INSERT INTO parties (Date, Description) VALUES ('$Date', '$Description')";
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
	  <form method="post" action="<?php echo $_SERVER['parties']; ?>">
		<fieldset>
			<legend></legend>
			Make it Official!
			<br><br>
			<label for="Date">Date:</label>
			<input type="text" id="date" name="date" /><br/>
			<label for="Description">Description:</label>
			<input type="text" id="description" name="description" /><br/>
			<br>
			<input type="submit" value="Plan It!" name="plan" />
		</fieldset>
		</form>
	  <p>
	  <a href="home.html">Logout</a>
	  </p>
	  <footer>
         <hr>
      </footer>
   </body>
</html>