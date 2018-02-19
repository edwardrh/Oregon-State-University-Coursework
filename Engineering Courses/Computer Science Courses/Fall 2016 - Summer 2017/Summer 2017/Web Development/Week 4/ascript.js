/*
My OpenWeather Map API Key
71df01a449638bc957641c51f8857249
*/

var apiKey = '71df01a449638bc957641c51f8857249';

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	document.getElementById('citySubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var city = document.getElementById('city').value;
		req.open('GET', 'http://api.openweathermap.org/data/2.5/weather?q=' + city + '&appid=' + apiKey + '&units=imperial', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
				document.getElementById('temp').textContent = response.main.temp + ' F';
				document.getElementById('hum').textContent = response.main.humidity;
				document.getElementById('min').textContent = response.main.temp_min + ' F';
				document.getElementById('max').textContent = response.main.temp_max + ' F';
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
	
	document.getElementById('zipSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var zip = document.getElementById('zip').value;
		req.open('GET', 'http://api.openweathermap.org/data/2.5/weather?zip=' + zip + ',us&appid=' + apiKey + '&units=imperial', true);	
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
				document.getElementById('temp').textContent = response.main.temp + ' F';
				document.getElementById('hum').textContent = response.main.humidity;
				document.getElementById('min').textContent = response.main.temp_min + ' F';
				document.getElementById('max').textContent = response.main.temp_max + ' F';
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(null);
		event.preventDefault();
	});
	
	document.getElementById('secondSumbit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var secondInput = document.getElementById('second').value;
		req.open('POST', 'http://httpbin.org/post', true);
		req.setRequestHeader('Content-Type', 'application/json');
		req.addEventListener('load',function(){
			if(req.status >= 200 && req.status < 400){
				var response = JSON.parse(req.responseText);
				document.getElementById('secondResults').textContent = response.data;
			} else {
				console.log("Error in network request: " + req.statusText);
			}});
		req.send(secondInput);
		event.preventDefault();
  });
}

/* NOTES */

/*
var apiKey = '71df01a449638bc957641c51f8857249';

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	document.getElementById('citySubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var city = document.getElementById('city').value;
		req.open('GET', 'http://api.openweathermap.org/data/2.5/weather?q=' + city + '&appid=' + apiKey + '&units=imperial', false);
		req.send(null);
		var response = JSON.parse(req.responseText);
		document.getElementById('temp').textContent = response.main.temp + ' F';
		document.getElementById('hum').textContent = response.main.humidity;
		document.getElementById('min').textContent = response.main.temp_min + ' F';
		document.getElementById('max').textContent = response.main.temp_max + ' F';
		event.preventDefault();
		})
	}

function bindButtons(){
	document.getElementById('urlSubmit').addEventListener('click', function(event){
		var req = new XMLHttpRequest();
		var payload = {longUrl:null};
		payload.longUrl = document.getElementById('longUrl').value;
		req.open('POST', 'https://www.googleapis.com/urlshortener/v1/url?key=' + apiKey, false);
		req.setRequestHeader('Content-Type', 'application/json');
		req.send(JSON.stringify(payload));
		var response = JSON.parse(req.responseText);
		document.getElementById('originalUrl').textContent = response.longUrl;
		document.getElementById('shortUrl').textContent = response.id;
		event.preventDefault();
		})
	}
*/
	