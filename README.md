# To-Do-List
To-Do List with C++

# List
A class which manage a list of task with following attributes:
  1) task name
  2) task due date
  3) task status (1 => Finished, 0 => Not Finished)
 
It has methods for:
<pre>
  1) menu          -> handle options input from users
  2) loadFromFile  -> load latest saved to do list (can be improved with a database)
  3) displayList   -> print tasks on screen
  4) createNewList -> clear current to do list and create an empty one
  5) addNewTask    -> add new task to the list and appends it to file where tasks are stored
  6) removeTask    -> remove specified task
  7) loadToFile    -> clear the file and add to it all tasks making it possible to load tasks later after the program is closed
</pre>
