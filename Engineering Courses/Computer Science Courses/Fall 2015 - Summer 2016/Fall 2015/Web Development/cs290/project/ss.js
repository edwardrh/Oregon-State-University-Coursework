//Setting global variables
var slides = document.querySelectorAll("#slideshow img");
var total_slides = slides.length;
var slide_width = 400;
var current_slide = 0;
var screen = document.createElement("div");

//Creating an array of the images
screen.setAttribute("id", "slideshow-screen");

for (var i = 0; i < slides.length; i++) {
    screen.appendChild(slides[i]);
}

document.getElementById("slideshow").appendChild(screen);

screen.style.width = (slide_width * slides.length) + "px";

//Moves the slideshow forward a slide
function moveSlide() {
	//Case when the screen displays the last image of the array
    if (current_slide == total_slides - 1) {
        current_slide = 0;
    } 
	else {
        current_slide++;
    }
    screen.style.marginLeft = -(slide_width * current_slide) + "px";
}

//Moves the slideshow back a slide
function moveSlideBack() {
	//Case when the screen displays the first image of the array
    if (current_slide == 0) {
        current_slide = total_slides - 1;
    } 
	else {
        current_slide--;
    }
    screen.style.marginLeft = -(slide_width * current_slide) + "px";
}

//Main function, calls other function when the web page is initially loaded
window.onload = function() {
	//Setting variables for the buttons
    var next = document.getElementById("next");
	var back = document.getElementById("back");
    
	//Function calls based on which button is selected
    next.addEventListener("click", function() {
              moveSlide();       
    	}
	);
    back.addEventListener("click", function() {
              moveSlideBack();       
    	}
	);
};