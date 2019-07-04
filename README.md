# Tetris

- **Binary name:** tetris \<folder>
- **Group members:**  
  - [@Kilio22](https://github.com/Kilio22)
  - [@HeyShafty](https://github.com/HeyShafty)
- **Mark:**

## Subject

The goal of this project is to recreate the Tetris game in a UNIX terminal, with the Gameboy version rules.  
You have to use ncurses.
In the folder of your binary, there must be a *tetriminos* directory, which contains files that describe the game pieces.

These files are composed in the following way:
- on the first line, the size and color of the piece in this format: width height color_code\n (the number of the color corresponds to the ncurses capacity’s color numbers),
- on the h following lines (where h is the height of the tetrimino), the piece’s shape composed with asterisks (*) and spaces (‘ ’).  
> You will find in the tetriminos.tgz a full folder with tetriminos

The pieces (randomly chosen) fall from the top of the map and pile up on the bottom. Each time a line is completed, it disappears, leaving all of  the pieces above it to fall.
The level increases by 1 for every 10 deleted lines. The falling speed increases proportionally to the level.
When it is no longer possible for pieces to fall from the top of the map, the player loses.
