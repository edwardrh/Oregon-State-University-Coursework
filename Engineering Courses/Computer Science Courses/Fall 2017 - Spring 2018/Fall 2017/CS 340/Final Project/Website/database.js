var express = require('express');
var mysql = require('./dbcon.js');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', process.argv[2]);

app.get('/',function(req,res,next){
  var context = {};
  var createString = "CREATE TABLE diagnostic(" +
  "id INT PRIMARY KEY AUTO_INCREMENT," +
  "text VARCHAR(255) NOT NULL)";
  mysql.pool.query('DROP TABLE IF EXISTS diagnostic', function(err){
    if(err){
      next(err);
      return;
    }
    mysql.pool.query(createString, function(err){
      if(err){
        next(err);
		return;
      }
	  mysql.pool.query('INSERT INTO diagnostic (`text`) VALUES ("MySQL is Working!")',function(err){
	    mysql.pool.query('SELECT * FROM diagnostic', function(err, rows, fields){
		  context.results = JSON.stringify(rows);
		  res.render('home',context);
		});
	  });
    });
  });
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});

/*SECLECTING DATA*/
app.get('/',function(req,res){
  var context = {};
  pool.query('SELECT * FROM traveler', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    context.results = JSON.stringify(rows);
    res.render('home', context);
  });
});

/*INSERTING DATA*/
app.get('/insert',function(req,res,next){
  var context = {};
  pool.query("INSERT INTO traveler (`fname`) VALUES (?)", [req.query.c], function(err, result){
    if(err){
      next(err);
      return;
    }
    context.results = "Inserted id " + result.insertId;
    res.render('home',context);
  });
});

/*DELETING DATA*/
app.get('/delete',function(req,res,next){
	var context = {};
	pool.query("DELETE FROM traveler WHERE id=?",
	[req.query.id],function(err,result){
		if(err){
			next(err);
			return;
		}
		context.results = "Deleted " + result.changedRows + " rows.";
		res.render('home', context);
	});
	pool.query("DELETE FROM destination WHERE id=?",
	[req.query.id],function(err,result){
		if(err){
			next(err);
			return;
		}
		context.results = "Deleted " + result.changedRows + " rows.";
		res.render('home', context);
	});
	pool.query("DELETE FROM trip_duration WHERE id=?",
	[req.query.id],function(err,result){
		if(err){
			next(err);
			return;
		}
		context.results = "Deleted " + result.changedRows + " rows.";
		res.render('home', context);
	});
	pool.query("DELETE FROM activity WHERE id=?",
	[req.query.id],function(err,result){
		if(err){
			next(err);
			return;
		}
		context.results = "Deleted " + result.changedRows + " rows.";
		res.render('home', context);
	});
});

/*UPDATING DATA*/
app.get('/update',function(req,res,next){
  var context = {};
  pool.query("SELECT * FROM traveler WHERE id=?", [req.query.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    if(result.length == 1){
      var curVals = result[0];
      pool.query("UPDATE traveler SET fname=?, lname=?, phone=?, happiness=?, town=?, city=?, state=?, country=?, days=?, begin=?, stime=?, end=?, etime=?, aname=?, length=?, cost=?, energy=? WHERE id=? ",
        [req.query.fname || curVals.fname, req.query.lname || curVals.lname, req.query.phone || curVals.phone, 
		req.query.happiness || curVals.happiness, /*req.query.town || curVals.town, req.query.city || curVals.city, 
		req.query.state || curVals.state, req.query.country || curVals.country, req.query.days || curVals.days, 
		req.query.begin || curVals.begin, req.query.stime || curVals.stime, req.query.end || curVals.end, 
		req.query.etime || curVals.etime, req.query.aname || curVals.aname, req.query.energy || curVals.energy, 
		req.query.length || curVals.length, req.query.cost || curVals.cost, */req.query.id],
        function(err, result){
        if(err){
          next(err);
          return;
        }
        context.results = "Updated " + result.changedRows + " rows.";
        res.render('edit',context);
      });
    }
  });
});

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	document.getElementById('adventureSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		req.open('GET', '/insert', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
	document.getElementById('updateSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		req.open('GET', '/update', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
	document.getElementById('deleteSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var id = document.getElementById('id').value;
		req.open('GET', '/delete', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
}

/*
Previous Notes:

-- RESETTING TABLE

app.get('/reset-table',function(req,res,next){
  var context = {};
  pool.query("DROP TABLE IF EXISTS workouts", function(err){ 
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
    pool.query(createString, function(err){
      context.results = "Table reset";
      res.render('home',context);
    })
  });
});

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	document.getElementById('adventureSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var name = document.getElementById('name').value;
		var reps = document.getElementById('reps').value;
		var weight = document.getElementById('weight').value;
		var measurement = document.getElementById('measurement').value;
		var date = document.getElementById('date').value;
		req.open('GET', '/insert', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
				document.getElementById('name1').textContent = response.main.name;
				document.getElementById('reps1').textContent = response.main.reps;
				document.getElementById('weight1').textContent = response.main.weight;
				document.getElementById('lbs1').textContent = response.main.lbs;
				document.getElementById('date1').textContent = response.main.date;
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
	document.getElementById('updateSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var name = document.getElementById('name').value;
		var reps = document.getElementById('reps').value;
		var weight = document.getElementById('weight').value;
		var measurement = document.getElementById('measurement').value;
		var date = document.getElementById('date').value;
		req.open('GET', '/update', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
				document.getElementById('name').textContent = response.main.name;
				document.getElementById('reps').textContent = response.main.reps;
				document.getElementById('weight').textContent = response.main.weight;
				document.getElementById('lbs').textContent = response.main.lbs;
				document.getElementById('date').textContent = response.main.date;
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
	document.getElementById('deleteSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var id = document.getElementById('id').value;
		req.open('GET', '/delete', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
}
*/
