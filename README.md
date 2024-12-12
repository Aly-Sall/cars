# Car Simulation with OpenGL

This project demonstrates a simple simulation of two cars moving on a virtual road using OpenGL. The application is implemented in C++ and uses the GLUT library to render the cars and manage their movement within the defined scene.

## Features
- Two cars (red and blue) that move forward continuously.
- A simple 2D road layout with defined boundaries.
- Keyboard controls to reset or exit the simulation.

## Requirements
To compile and run this program, you need:
- A C++ compiler (e.g., GCC or Clang).
- OpenGL and GLUT libraries installed.

## Installation and Setup
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd <repository_directory>
   ```

2. Compile the code:
   On Linux or macOS:
   ```bash
   g++ voiture.cpp -o voiture -lGL -lGLU -lglut
   ```
   On Windows (with MinGW):
   ```bash
   g++ voiture.cpp -o voiture -lopengl32 -lglu32 -lfreeglut
   ```

3. Run the program:
   ```bash
   ./voiture
   ```

## How It Works
### Simulation Overview
- The two cars are represented as simple rectangles with distinct colors (red and blue).
- The cars move in a straight path along the road.
- If a car reaches the edge of the screen, it loops back to the starting position.

### Controls
- Press `ESC` to close the application.
- Press `R` to reset the car positions.

## Code Structure
### Main Components
1. **Initialization:**
   - Sets up the OpenGL environment and initializes the scene.
   
2. **Rendering:**
   - Uses `glBegin` and `glEnd` to draw the road and cars.

3. **Movement Logic:**
   - Updates car positions in each frame to simulate movement.

4. **Input Handling:**
   - Captures keyboard inputs for reset (`R`) and exit (`ESC`) functionality.

### Functions
- `void drawRoad()`: Draws the road as a simple rectangle.
- `void drawCar(float x, float y, float r, float g, float b)`: Draws a car at a specified position with a specified color.
- `void update(int value)`: Updates car positions and schedules the next update.

## Example Output
The simulation displays a road with two cars moving continuously in a loop. Users can reset their positions or exit the simulation using keyboard inputs.

## Future Enhancements
- Add more cars with varying speeds.
- Include traffic lights or obstacles.
- Add textures for more realistic visuals.


## Acknowledgements
This project began as a simple school assignment to render shapes with OpenGL. The addition of moving cars and keyboard controls was a personal enhancement to make the simulation more interactive and fun.

