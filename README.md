# my_world

## Description

The goal of this project is to create your own terraformer program.

Your challenge is to display a map and edit it at runtime.
The map is a wireframed map with tiles that are squares having all the same size.
The ground must be altered by raising, lowering or tilting tiles.

### MANDATORY
:warning: The following features are mandatory (if your project is missing one of them, it will not be evaluated further):
- [X] the window can be closed using events,
- [X] the game manages the input from the mouse click and keyboard,
- [X] animations in your program are frame rate independent.

### MUST
- [X] The map must be displayed using a 3D projection (whether isometric or parallel),
- [X] the tiles and their corners must be selected using the mouse,
- [X] at least 3 effects (including the modification of altitude) must be implemented and selectable with a
toolbar in the window (e.g. reinitialization of the tiles’ altitudes, modification of the size of the area of
effect, switching between “tiles selectable” and “corners selectable”).

### SHOULD
- [X] Your window should stick between 800x600 pixels and 1920x1080 pixels,
- [X] the size of the map should be selected using editable textboxes in the window,
- [X] help boxes should appear as the mouse hovers elements in the toolbar(s),
- [X] the buttons should have at least 3 visual states : idle, hover, and clicked,
- [X] tiles should have a texture,
- [ ] the format of saved maps should be in a .legend file,
- [X] moving around on the map should be done with arrow keys and/or by positionning the mouse cursor
on the edges of the window,
- [X] zooming up and down should be done with keyboard and/or the scrolling button of the mouse.

### COULD
- [X] The program could save the map in a file at the end of the program in the terminal,
- [X] the program could save the map in a file at runtime using buttons and tools,
- [X] the program could load a map at the beginning of the program in the terminal (argument or stdin),
- [X] the program could load a map at runtime using buttons and tools,
- [X] the name of the saved files could be chosen at runtime,
- [X] tools can be selected using keyboard shortcuts,
- [X] sounds could be played on user actions,
- [X] textures of the tiles could change depending on the direction of their slope,
- [ ] elements (e.g. buildings, roads) could be added on the map in compliance with the landforms,
- [X] water areas could be added.

### Bonus

- Procedural generation using perlin noise.
- Lot of animations using 3d formulas.

## Screenshots of the game
![Image1](/resources/screenshots/anim1.png)

![Image2](/resources/screenshots/test.png)

![Image3](/resources/screenshots/mountain.png)

![Image4](/resources/screenshots/perlin.png)
