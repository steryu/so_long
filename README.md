# so_long
A mini 2D video game.

[![svan-ass's 42 so_long Score](https://badge42.vercel.app/api/v2/clfladlx3000608l58byc7e5w/project/2439931)](https://github.com/JaeSeoKim/badge42)
### **Objective**
The aim of this project was to gain familiarity with fundamental game development components such as textures, sprites, animations, and basic gameplay mechanics. The game was implemented in the C programming language and utilized the MiniLibX library, which is available on the school's machines.

![so_long](https://user-images.githubusercontent.com/95487148/156332575-e7c72aaf-5233-465b-904b-da44ec4ea71d.gif)

### **The Game**
The game challenges the player to navigate through a maze-like environment using the WASD keys, collecting all of the collectibles scattered throughout the map, and finally reaching the exit.

### **Development Process**
The development process for this project was divided into several key stages:

- **Map Reading and Processing**\
The game world was defined by a .ber map file, which consisted of four types of characters - 0, 1, C, and E - representing open space, walls, collectibles, and exits, respectively. The map was read line by line using [`get_next_line`](https://github.com/steryu/library-42) (a project I made previously, and stored in a data structure linked list. Error-checking was also performed during this phase.

- **Sprite Loading**\
Next, self-designed sprites were added to the data structure for later rendering on the screen.\
![cloudfloor](https://github.com/steryu/so_long/blob/main/sprites/pngs/cloudfloor.png)
![cloud](https://github.com/steryu/so_long/blob/main/sprites/pngs/cloud.png)
![wolkje](https://github.com/steryu/so_long/blob/main/sprites/pngs/wolkje.png)

- **Rendering the Screen**\
The screen was rendered by iterating through the map data structure and placing the appropriate sprite at each location. This was accomplished by first reading the color of each pixel in the sprite image, buffering it and then pushing it to the window. Custom functions were developed for this purpose based on the [MiniLibx Tutorial](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html).

- **Handling Key Input and Animations**
Finally, the game's key inputs were handled using hook events as outlined in the tutorial, while the animations were created by cycling through a set of 9 sprites and changing them every 10 iterations. Although not a particularly reliable approach, it proved to be effective.

### **Conclusion**
Through the development of so_Long, I gained valuable experience in creating images using their addresses and manipulating individual pixels. I also enjoyed creating the pixel art assets and refining the little gameplay mechanics, such as walking, collecting items, and ensuring that the game only ends when all collectibles are obtained. Although this was a small project, it felt like a game and has inspired me to pursue further projects in game development.

### **How to compile**
``` sh
make && ./so_long maps/[INSERT_MAP].ber
```
