the original game was adopted from Javier Lopez
http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/

# TetrisGame
Tetris classic game using SDL2 and C++

Menu state:
  Start and Exit text button, work with mouse hovering, and keyboard shortcuts 

Play state:
  control on the left arrow keys, "z","x"
  has pause "esc":
    use mouse to choose continue or exit when in pause

Game over: (not a state generated in gameStateMachine):
  show score
  "Space" to proceed to menu

 
  ease in usage of SDL2 on image, textbox, numBox
  handling events 
  Statemachine
  
  the code use Visual Studio 2013 to compile
  before that the project properties should be set up with the include and library x86 of the SDL2 library and SDL2_image library
  http://lazyfoo.net/SDL_tutorials/
