# Disclaimer
A lot of pictures used in this game are not belong to me, I got wild while tweaking the game aesthetics and forgot to ask for permission.  
Please keep in mind that if you/anyone use this to monetize please refer to the true artists  

This game is just a for fun project, I am selling nothing, which I hope to spark joy to others.  

The builded game was in tetris.zip, which always reminds me of how great Tetris is, I just can't stop playing it when I start.  

the original game was adopted from Javier Lopez 
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/  

# TetrisGame
To only download the game please get it [here](https://github.com/Noath2302/TetrisGame/blob/master/tetris.zip) 

- Tetris classic game using SDL2 and C++

Menu state:  
- Start and Exit text button, work with mouse hovering, and keyboard shortcuts 

Play state:  
- control on the left arrow keys, "z", "x"  
- has pause "esc":  
- use mouse to choose continue or exit when in pause  
    
Game over: (not a state generated in gameStateMachine, more like a intermediate step to menu state):  
- show score  
- "Space" to proceed to menu  

Use to write the game: 
- ease in usage of SDL2 on image, textbox, numBox  
- handling events   
  Statemachine  
  
![menu state](https://github.com/Noath2302/TetrisGame/blob/master/git_pic/menu.png?raw=true)  

![in-game state](https://github.com/Noath2302/TetrisGame/blob/master/git_pic/game.png?raw=true)  

![game-over state](https://github.com/Noath2302/TetrisGame/blob/master/git_pic/gameover.png?raw=true)
    
  the code use Visual Studio 2013 to compile  
  before that the project properties should be set up with the include and library x86 of the SDL2 library and SDL2_image library  
  http://lazyfoo.net/SDL_tutorials/   
