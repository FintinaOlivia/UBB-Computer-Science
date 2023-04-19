# Assignment 04-05
## Requirements
- You will be given one of the problems below to solve.
- The application must be implemented in C++ and use layered architecture.
- Provide tests and specifications for non-trivial functions outside the UI. Test coverage must be at least 98% for all layers, except the UI.
- Have at least 10 entities in your memory repository.
- Validate the input data.
- Handle the following situations:
    - If an entity that already exists is added, a message is shown and the entity is not stored. You must decide what makes an entity unique.
    - If the user tries to update/delete an entity that does not exist, a message will be shown and there will be no effect on the list of entities.

## Week 5
- Solve the requirements related to the administrator mode.
- Define the `DynamicVector` class which provides the specific operations: `add`, `remove`, `length`, etc. The array of elements must be dynamically allocated.

## Week 6
- Solve all problem requirements.
- `DynamicVector` must be a class template.

## Problem Statements

### Keep calm and adopt a pet
The *“Keep calm and adopt a pet”* shelter needs a software application to help them find adoptive parents for the dogs  they are taking care of. The application can be used in two modes: `administrator` and `user`. When the application is started, it will offer the option to select the mode.\
**Administrator mode:** The application will have a database that holds all the dogs in the shelter at a given moment. The shelter employees must be able to update the database, meaning: add a new dog, delete a dog (when the dog is adopted) and update the information of a dog. Each **Dog** has a `breed`, a `name`, an `age` and a `photograph`. The photograph is memorised as a link towards an online resource (the photograph on the presentation site of the centre). The administrators will also have the option to see all the dogs in the shelter.\
**User mode:** A user can access the application and choose one or more dogs to adopt. The application will allow the user to:
- See the dogs in the database, one by one. When the user chooses this option, the data of the first dog (breed, name, age) is displayed, along with its photograph.
- Choose to adopt the dog, in which case the dog is added to the user’s adoption list.
- Choose not to adopt the dog and to continue to the next. In this case, the information corresponding to the next dog is shown and the user is again offered the possibility to adopt it. This can continue as long as the user wants, as when arriving to the end of the list, if the user chooses next, the application will again show the first dog.
- See all the dogs of a given breed, having an age less than a given number. If no breed is provided, then all the dogs will be considered. The functionalities outlined above apply again in this case.
- See the adoption list.

## Local Movie Database
So many movies, so little time. To make sure you do not miss any good movies, you absolutely need a software application to help you manage your films and create watch lists. The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.\
**Administrator mode:** The application will have a database which holds all the movies. You must be able to update the database, meaning: add a new movie, delete a movie and update the information of a movie. Each **Movie** has a `title`, a `genre`, a `year of release`, a `number of likes` and a `trailer`. The trailer is memorised as a link towards an online resource. The administrators will also have the option to see all the movies in the database.\
**User mode:** A user can create a watch list with the movies that she wants to watch. The application will allow the user to:
- See the movies in the database having a given genre (if the genre is empty, see all the movies), one by one. When the user chooses this option, the data of the first movie (title, genre, year of release, number of likes) is displayed and the trailer is played in the browser.
- If the user likes the trailer, she can choose to add the movie to her watch list.
- If the trailer is not satisfactory, the user can choose not to add the movie to the watch list and to continue to the next. In this case, the information corresponding to the next movie is shown and the user is again offered the possibility to add it to the watch list. This can continue as long as the user wants, as when arriving to the end of the list of movies with the given genre, if the user chooses next, the application will again show the first movie.
- Delete a movie from the watch list, after the user watched the movie. When deleting a movie from the watch list, the user can also rate the movie (with a like), and in this case, the number of likes the movie has in the repository will be increased.
- See the watch list.

## Proper Trench Coats
Trench coats are cool. Everyone should own a trench coat. The *“Proper Trench Coats”* store sells fashionable, elegant trench coats and the store needs software to allow their customers to order online. The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.\
**Administrator mode:** The application will have a database which holds available trench coats at a given moment. The store employees must be able to update the database, meaning: add a new trench coat, delete a trench coat (when it is sold out) and update the information of a trench coat. Each **Trench Coat** has a `size`, a `colour`, a `price`, a `quantity` and a `photograph`. The photograph is memorised as a link towards an online resource (the photograph on the presentation site of the store). The administrators will also have the option to see all the trench coats in the store.\
**User mode:** A user can access the application and choose one or more trench coats to buy. The application will allow the user to:
- See the trench coats in the database, having a given size, one by one. If the size is empty, then all the trench coats will be considered. When the user chooses this option, the data of the first trench coat (size, colour, price, quantity) is displayed, along with its photograph.
- Choose to add the trench to the shopping basket. In this case, the price is added to the total sum the user has to pay. The total sum will be shown after each purchase.
- Choose not to add the trench coat to the basket and to continue to the next. In this case, the information corresponding to the next trench coat is shown and the user is again offered the possibility to buy it. This can continue as long as the user wants, as when arriving to the end of the list, if the user chooses next, the application will again show the first trench coat.
- See the shopping basket and the total price of the items.

## Master C++
You are very passionate about programing (otherwise you wouldn't be reading this) and C++ is a language close to your heart. On your way to becoming a guru, you study a lot and watch many tutorials. To make sure you do not miss any good tutorials, you absolutely need a software application to help you manage your tutorials and create watch lists. The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.\
**Administrator mode:** The application will have a database , which holds all the tutorials. You must be able to update the database, meaning: add a new tutorial, delete a tutorial and update the information of a tutorial. Each **Tutorial** has a `title`, a `presenter` (name of the presenter person), a `duration` (minutes and seconds), a number of `likes` and a `link` towards the online resource containing the tutorial. The administrators will also have the option to see all the tutorials in the database.\
**User mode:** A user can create a watch list with the tutorials that he/she wants to watch. The application will allow the user to:
- See the tutorials in the database having a given presenter (if the presenter name is empty, see all the tutorials), one by one. When the user chooses this option, the data of the first tutorial (title, presenter, duration, number of likes) is displayed and the tutorial is played in the browser.
- If the user likes the tutorial, he/she can choose to add it to his/her tutorial watch list.
- If the tutorial seems uninteresting, the user can choose not to add it to the watch list and continue to the next. In this case, the information corresponding to the next tutorial is shown and the user is again offered the possibility to add it to the watch list. This can continue as long as the user wants, as when arriving to the end of the list of tutorials with the given presenter, if the user chooses next, the application will again show the first tutorial.
- Delete a tutorial from the watch list, after the user watched the tutorial. When deleting a tutorial from the watch list, the user can also rate the tutorial (with a like), and in this case, the number of likes for the tutorial will be increased.
- See the watch list.

## Life After School
Lectures, seminars and labs ... school in general must be taken seriously; BUT so must be your social life and leisure time. To manage the latter and be always informed about the interesting events happening in your city you will implement a software application. The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.\
**Administrator mode:** The application will have a database which holds all the interesting events in your area. You must be able to update the database, meaning: add a new event, delete an event and update the information of an event. Each **Event** has a `title`, a `description`, a `date and time`, a `number of people` who are going and a `link` towards the online resource containing the event. The administrators will also have the option to see all the events in the database.\
**User mode:** A user can create a list with the events that he/she is interested in. The application will allow the user to:
- See the events in the database for a given month (if there is no month given, see all the events, ordered chronologically), one by one. When the user chooses this option, the data of the first event (title, description, date and time, number of people who are going) is displayed, and the event is opened in the browser (e.g. Facebook event).
- If the user wants to participate in the event he/she can choose to add it to his/her events list. When this happens, the number of people who are going to the event increases (for the event in the repository).
- If the event seems uninteresting, the user can choose not to add it to the list and continue to the next. In this case, the information corresponding to the next event is shown, and the user is again offered the possibility to add it to his/her list. This can continue as long as the user wants, as when arriving to the end of the list of events for the given month, if the user chooses next, the application will again show the first event.
- Delete an event from the list. When the user deletes an event from his/her list, the number of people who are going to the event decreases.
- See the list of events the user wants to attend.
