# avc2020
The purpose of this project is to write software which guides a robot through a maze. The robot is equipped with a video camera and two wheels.
The camera image is an input for the program. The program controls the speeds of left and right motors. This year the robot and maze are virtual.

Starting point is top left. Finish point is marked by checkers flag at bottom left.
There are obstacles - walls (red rectangles) and ducks (or something else, like trees). All obstacles are rectangular. If robot hits the obstacle - it stops. There are several mazes for Core, Completion and Challenge.
In simple case robot should follow the white line. For the Challenge robot should follow the corridor formed by the walls.
Robot control functions:
set_motor(vLeft, vRight) - set the speed of the left and right robot motors. Positive speed makes wheel push robot forward.
take_picture() - takes a screenshot from the camera. Individual pixels of the screenshot can be accessed using the get_pixel(row,column,colour) function.
"
