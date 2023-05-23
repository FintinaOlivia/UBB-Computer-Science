**Car Manager**

A company needs an application to manage their cars. Each Car has as attributes: manufacturer’s name, model, year of fabrication and colour. Create a file that contains at least 5 cars. See below some examples of such cars (are separated by “|”): \

Fiat | Bravo | 2007 | red\
Fiat | Idea | 2003 | black\
Audi | A5 | 2007 | blue\
Mercedes-Benz | SUV | 2013 | blue \
Ford | Fiesta | 2015 | green

Write a car manager application with a graphical user interface (use the Qt framework) which allows to:
1. Visualize all the cars in a list (QListWidget or QListView). The list will display the manufacturer’s name and the model. When the application starts, the list is populated automatically (2.5p) and the cars are sorted by manufacturer (1.5p).
2. Show the cars in the list such that the font colour of each one is the same as the car’s colour (assume we only have colours the same as Qt predefined colours – class QColor). (1p)
3. Show the cars and the number of cars, for a given manufacturer. The manufacturer is input in a QLineEdit and when the button “Show cars” is clicked, the cars and number of cars from that specific manufacturer will be shown in a list (2p) and a QLineEdit/QLabel/new widget (1p), respectively.
   Write specifications and tests for the function that computes the number of cars, by manufacturer. (0.5p specification, 0.5p - tests)
  
Obs.
- If the data are not read from the file, 0.5 points are subtracted from the indicated score for each functionality.
- The application must use layered architecture in order for functionalities to be graded.
- No score is awarded for a console-based user interface.
  You may use Qt Designer, as well as the following sites for documentation:
- http://doc.qt.io/qt-6/
- http://en.cppreference.com/w/
- http://www.cplusplus.com/
  Time: 60 minutes.
  1p - of