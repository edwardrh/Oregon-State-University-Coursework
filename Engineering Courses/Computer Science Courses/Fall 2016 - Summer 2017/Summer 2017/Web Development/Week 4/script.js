/* TABLE */

var table = document.createElement("table");

var headRow = document.createElement("tr");
for(var i = 1; i < 5; i++) {
	var headCol = document.createElement("th");
	headCol.textContent = "Header " + i;
	headRow.appendChild(headCol);
}
table.appendChild(headRow);

var row1 = document.createElement("tr");
for(var i = 1; i < 5; i++) {
	var col1 = document.createElement("td");
	col1.textContent = i + ", 1";
	row1.appendChild(col1);
}
table.appendChild(row1);

var row2 = document.createElement("tr");
for(var i = 1; i < 5; i++) {
	var col2 = document.createElement("td");
	col2.textContent = i + ", 2";
	row2.appendChild(col2);
}
table.appendChild(row2);

var row3 = document.createElement("tr");
for(var i = 1; i < 5; i++) {
	var col3 = document.createElement("td");
	col3.textContent = i + ", 3";
	row3.appendChild(col3);
}
table.appendChild(row3);

document.body.appendChild(table);

table.style.textAlign = "center";
table.style.border = "1px solid black";

/* BUTTONS */

var up = document.createElement("button");
var down = document.createElement("button");
var left = document.createElement("button");
var right = document.createElement("button");

up.textContent = "Up";
down.textContent = "Down";
left.textContent = "Left";
right.textContent = "Right";

document.body.appendChild(up);
document.body.appendChild(down);
document.body.appendChild(left);
document.body.appendChild(right);

up.style.margin = "5px";
down.style.margin = "5px";
left.style.margin = "5px";
right.style.margin = "5px";

var mark = document.createElement("button");
mark.textContent = "Mark Cell";
document.body.appendChild(mark);
mark.style.margin = "5px";

/* SELECTION */

var cur = row1;
cur = cur.firstElementChild;
cur.style.border = "3px solid black";

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons(){
	right.addEventListener("click", function(event){
		if(cur.nextElementSibling == null) {
			cur.style.border = "3px solid black";
		} else {
			cur.style.border = "3px solid white";
			cur = cur.nextElementSibling;
			cur.style.border = "3px solid black";
		}
	});
	left.addEventListener("click", function(event){
		if(cur.previousElementSibling == null) {
			cur.style.border = "3px solid black";
		} else {
			cur.style.border = "3px solid white";
			cur = cur.previousElementSibling;
			cur.style.border = "3px solid black";
		}
	});
	up.addEventListener("click", function(event){
		var test = cur;
		test = test.parentNode;
		test = test.previousElementSibling;
		if(test.children[0].textContent == "Header 1") {
			cur.style.border = "3px solid black";
		} else if(cur.textContent == "1, 3" || cur.textContent == "1, 2") {
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.previousElementSibling;
			cur = cur.children[0];
			cur.style.border = "3px solid black";
		} else if(cur.textContent == "2, 3" || cur.textContent == "2, 2") {
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.previousElementSibling;
			cur = cur.children[1];
			cur.style.border = "3px solid black";
		} else if(cur.textContent == "3, 3" || cur.textContent == "3, 2") {
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.previousElementSibling;
			cur = cur.children[2];
			cur.style.border = "3px solid black";
		} else { //cur.textContent == "4, 3" || cur.textContent == "4, 2"
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.previousElementSibling;
			cur = cur.children[3];
			cur.style.border = "3px solid black";
		}
	});
	down.addEventListener("click", function(event){
		var test = cur;
		test = test.parentNode;
		test = test.nextElementSibling;
		if(test == null) {
			cur.style.border = "3px solid black";
		} else if(cur.textContent == "1, 1" || cur.textContent == "1, 2") {
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.nextElementSibling;
			cur = cur.children[0];
			cur.style.border = "3px solid black";
		} else if(cur.textContent == "2, 1" || cur.textContent == "2, 2") {
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.nextElementSibling;
			cur = cur.children[1];
			cur.style.border = "3px solid black";
		} else if(cur.textContent == "3, 1" || cur.textContent == "3, 2") {
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.nextElementSibling;
			cur = cur.children[2];
			cur.style.border = "3px solid black";
		} else { //cur.textContent == "4, 1" || cur.textContent == "4, 2"
			cur.style.border = "3px solid white";
			cur = cur.parentNode;
			cur = cur.nextElementSibling;
			cur = cur.children[3];
			cur.style.border = "3px solid black";
		}
	});
	mark.addEventListener("click", function(event){
		cur.style.backgroundColor = "yellow";
	});
}
