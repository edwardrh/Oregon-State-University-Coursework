#1 Find all films with maximum length or minimum rental duration (compared to all other films). 
#In other words let L be the maximum film length, and let R be the minimum rental duration in the table film. You need to find all films that have length L or duration R or both length L and duration R.
#You just need to return attribute film id for this query. 

SELECT film_id FROM film 
WHERE length = (SELECT MAX(length) FROM film) 
AND rental_duration = (SELECT MIN(rental_duration) FROM film);


#2 We want to find out how many of each category of film ED CHASE has started in so return a table with category.name and the count
#of the number of films that ED was in which were in that category order by the category name ascending (Your query should return every category even if ED has been in no films in that category).

SELECT category.name, edc_category.film_count FROM category 
LEFT JOIN (
	SELECT category.name AS "category_name", 
	COUNT(film.film_id) AS "film_count" FROM category 
	INNER JOIN film_category ON film_category.category_id = category.category_id 
	INNER JOIN film ON film.film_id = film_category.film_id 
	INNER JOIN film_actor ON film_actor.film_id = film.film_id  
	INNER JOIN actor ON actor.actor_id = film_actor.actor_id 
	WHERE actor.first_name="ED" AND actor.last_name="CHASE" 
	GROUP BY category.name
) AS edc_category ON edc_category.category_name = category.name;
	

#3 Find the first name, last name and total combined film length of Sci-Fi films for every actor
#That is the result should list the names of all of the actors(even if an actor has not been in any Sci-Fi films)and the total length of Sci-Fi films they have been in.

SELECT actor.first_name, actor.last_name, sf_time.total FROM actor 
LEFT JOIN (
	SELECT category.name AS "category_name", 
	film_actor.actor_id AS 'actor_id', 
	SUM(film.length) AS 'total' FROM actor 
	INNER JOIN film_actor ON film_actor.actor_id = actor.actor_id 
	INNER JOIN film ON film.film_id = film_actor.film_id 
	INNER JOIN film_category ON film_category.film_id = film.film_id 
	INNER JOIN category ON category.category_id = film_category.category_id 
	WHERE category.name="Sci-Fi" 
	GROUP BY actor.actor_id
) AS sf_time ON sf_time.actor_id = actor.actor_id;

#4 Find the first name and last name of all actors who have never been in a Sci-Fi film

SELECT actor.first_name AS "firstName", actor.last_name AS "lastName" FROM actor 
WHERE actor.actor_id NOT IN (
	SELECT actor.actor_id FROM actor 
	INNER JOIN film_actor ON film_actor.actor_id = actor.actor_id 
	INNER JOIN film ON film.film_id = film_actor.film_id 
	INNER JOIN film_category ON film_category.film_id = film.film_id 
	INNER JOIN category ON category.category_id = film_category.category_id 
	WHERE category.name = "Sci-Fi"
) GROUP BY actor.actor_id; 

#5 Find the film title of all films which feature both KIRSTEN PALTROW and WARREN NOLTE
#Order the results by title, descending (use ORDER BY title DESC at the end of the query)
#Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
#the box a bit to figure out how to get a table that shows pairs of actors in movies

SELECT film.title FROM film 
INNER JOIN film_actor fa1 ON fa1.film_id = film.film_id 
INNER JOIN actor a1 ON a1.actor_id = fa1.actor_id 
INNER JOIN film_actor fa2 ON fa2.film_id = film.film_id 
INNER JOIN actor a2 ON a2.actor_id = fa2.actor_id 
WHERE a1.first_name="KIRSTEN" AND a1.last_name="PALTROW" 
AND a2.first_name="WARREN" AND a2.last_name="NOLTE" 
GROUP BY film.title DESC;

