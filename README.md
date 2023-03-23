# so_long
A mini 2D video game.

**Purpose**\
The purpose was to get used to working with textures, sprites, animations and some other very basic gameplay elements.
The project was written in C and made use of the MiniLibX library availibe of the school machines.

![so_long](https://user-images.githubusercontent.com/95487148/156332575-e7c72aaf-5233-465b-904b-da44ec4ea71d.gif)

**The Game**\
The goal of the game was to walk trough the map with the WASD keys tocollect all the collectibles and end at the exit. 

**Process**\
First was to initialize the mlx and mlx_window to the desired size.

- **Read and Process the Map**\
The map needed a .ber map file that composed of 0, 1, C and E (open space, wall, collectible and exit).
I used [get_next_line](https://github.com/steryu/library) (an other project I made) to read the map line for line and save it in a data struct linked list.
Then check the map for errors and the first part was done.

- **Loading Sprites**\
I then put all my self made spites in the data struct to push them to the screen later.\
![cloudfloor](https://github.com/steryu/so_long/blob/main/sprites/pngs/cloudfloor.png)
![cloud](https://github.com/steryu/so_long/blob/main/sprites/pngs/cloud.png)
![wolkje](https://github.com/steryu/so_long/blob/main/sprites/pngs/wolkje.png)

- **Render Screen**\
For this part I looped trough the map struct and everytime you encountered a specific character you put the right sprite to the frame.
in order to do that, you first loop trough the sprite image and take the color of every pixel. Once the image was buffered you then push it to the window. I used the [MiniLibx Tutorial](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html) to make custom functions that does the above.

- **Key Input and Animations**\
Lastly i took care of the key input using hook events, also explained in the tutorial. The animations I made by looping trough 9 sprites and changing them every 10 incremitaions. It may not be an reliable method, but it worked :).

**Closing thoughts**\
I learned how to create an image using its address and the right pixels. Learned pixel art (which was really fun) and fixining all the little game mechanics, for example walking, collectiing and only exiting when all the collectibles were taken.
It was a small project but its was our first graphical one and it felt like a real game.
It made me really excited to make more projects like this one. 

**How to compile**\
``make && ./so_long maps/[INSERT_MAP].ber``
