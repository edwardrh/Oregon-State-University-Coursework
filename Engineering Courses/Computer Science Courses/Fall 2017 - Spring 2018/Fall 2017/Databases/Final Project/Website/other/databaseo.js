var mysql = require('mysql');
var pool = mysql.createPool({
	host : 'localhost',
	user : 'student',
	password: 'default',
	database: 'student'
});
var express = require('express');
var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 9303);

/*SECLECTING DATA*/
app.get('/',function(req,res){
  var context = {};
  pool.query('SELECT * FROM workouts', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    context.results = JSON.stringify(rows);
    res.render('home', context);
  });
});

/*app.get('/get-request',function(req,res){
  var qParams = [];
  for (var p in req.query){
    qParams.push({'key':p,'value':req.query[p]})
  }
  var context = {};
  context.dataList = qParams;
  res.render('get', context);
});*/

/*INSERTING DATA*/
app.get('/insert',function(req,res,next){
  var context = {};
  pool.query("INSERT INTO workouts (`name`) VALUES (?)", [req.query.c], function(err, result){
    if(err){
      next(err);
      return;
    }
    context.results = "Inserted id " + result.insertId;
    res.render('home',context);
  });
});

/*UPDATING DATA*/
app.get('/update',function(req,res,next){
  var context = {};
  pool.query("SELECT * FROM workouts WHERE id=?", [req.query.id], function(err, result){
    if(err){
      next(err);
      return;
    }
    if(result.length == 1){
      var curVals = result[0];
      pool.query("UPDATE workouts SET name=?, reps=?, weight=?, lbs=?, date=? WHERE id=? ",
        [req.query.name || curVals.name, req.query.reps || curVals.reps, req.query.weight || curVals.weight, 
		req.query.lbs || curVals.lbs, req.query.date || curVals.date, req.query.id],
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

/*DELETING DATA*/
app.get('/delete',function(req,res,next){
	var context = {};
	pool.query("DELETE FROM workouts WHERE id=?",
	[req.query.id],function(err,result){
		if(err){
			next(err);
			return;
		}
		context.results = "Deleted " + result.changedRows + " rows.";
		res.render('home', context);
	});
});

/*RESETTING TABLE*/
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

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	document.getElementById('workoutSubmit').addEventListener('click', function(event){
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
