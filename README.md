# PathFinder with A*

The protagonist needs to have sufficient intelligence to navigate in an unknown world, populated
with health packs and enemies. So I developed a path-finding algorithm to calculate the
most appropriate way to get from position (xstart, ystart) to position (xend, yend). This algorithm
will be called when  protagonist move to a certain tile.

There are of course many ways to define what the most appropriate path is, I used a
combination of distance and the difficulty to move to a certain position (e.g. you can see the tile
value as the difficulty to traverse that tile). Tiles with a value of infinity must be seen as impassable.
A* is the most used path-finding algorithm. I implemented my own using the most appropriate data structures 
and generic algorithms available from STL and/orQt.Keep in mind that this is a quite demanding application, so I used
all possible ways to optimize its performance.
Note that the world tiles returned by the library are stored in a specific order (see below)

Protagonist find its way into a big maze (a picture of a maze with dimensions
2400 x 2380, so nearly six million tiles) in a “reasonable” time. 
This is possible in less than 1 second. 

See the images for solution path for big maze 1.17 sec.

![alt text](https://github.com/CemalYet/PathPlanner/blob/production/PathPlanner.png?raw=true)

See the images for visualizing effect of heuristic.

Heuristic_0
![alt text](https://github.com/CemalYet/PathPlanner/blob/production/Heuristic_0.png?raw=true)

Heuristic_0.2
![alt text](https://github.com/CemalYet/PathPlanner/blob/production/Heuristic_0.2.png?raw=true)

Heuristic_0.5
![alt text](https://github.com/CemalYet/PathPlanner/blob/production/Heuristic_0.5.png?raw=true)

Heuristic_1
![alt text](https://github.com/CemalYet/PathPlanner/blob/production/Heuristic_1.png?raw=true)

