\# 2D Airport Runway Simulator



A 2D computer graphics project built in C++ using OpenGL and GLUT/FreeGLUT inside Code::Blocks. The application renders an interactive, multi-facility airport complex with dynamic environment elements, a custom vector font rendering system, and a smooth airplane takeoff animation sequence.



\---



\## Project Details \& Features



This project simulates a fully functioning, labeled airport environment built strictly using OpenGL primitives and dynamic transformations.



\### Key Capabilities \& Mechanics

1\. Airplane Takeoff Animation Loop: Features smooth linear translation across the runway followed by pitch elevation as the aircraft ascends into the sky. The animation continuously loops back to the runway once off-screen.

2\. Custom Vector Font Engine (`drawChar` \& `drawString`): Renders all text labels (`CARGO`, `FIRE RESCUE`, `ATC`, `TERMINAL 1`) using procedural line vectors, bypassing external font asset dependencies.

3\. Complex Airport Structures:

&#x20;  1. Cargo \& Freight Hub: Features loading bays and structural framework.

&#x20;  2. Fire \& Rescue Station: Houses emergency response vehicles.

&#x20;  3. Air Traffic Control (ATC) Tower: Multi-tiered observation tower positioned centrally.

&#x20;  4. Terminal 1: Multi-story terminal structure rendered with linear color gradients.

4\. Ground Support \& Logistics: Rendered emergency vehicles (Fire Engine and Ambulance) stationed on operational service lanes.

5\. Environment \& Sky Operations: Procedural background tree canopy, dynamic layered clouds, and dual-layer runway markings with conditional landing gear rendering based on altitude.

6\. Smooth Frame Timing: Utilizes `glutTimerFunc` running at 60 FPS (\~16ms refresh rate) for fluid movement.



\---



\# Setup Instructions



\## Dependencies \& System Requirements

1\. IDE: Code::Blocks (configured with MinGW C/C++ compiler)

2\. Graphics Framework: OpenGL and GLUT / FreeGLUT libraries



\### How to Build



1\. Set Up GLUT in Code::Blocks:

&#x20;  1. Place `glut.h` (or `freeglut.h`) in your MinGW include path (`MinGW\\include\\GL\\`).

&#x20;  2. Place `libglut32.a` (or `libfreeglut.a`) in your MinGW library path (`MinGW\\lib\\`).

&#x20;  3. Place `glut32.dll` (or `freeglut.dll`) into `C:\\Windows\\System32` or directly inside your project folder.



2\. Configure Linker Settings:

&#x20;  1. Open the project file (`.cbp`) in Code::Blocks.

&#x20;  2. Navigate to \*\*Settings\*\* -> \*\*Compiler\*\* -> \*\*Linker settings\*\*.

&#x20;  3. Add the following flags under \*\*Other linker options\*\*:

&#x20;     ```text

&#x20;     -lopengl32 -lglu32 -lglut

&#x20;     ```



3\. Compile:

&#x20;  1. Press `Ctrl + F9` or select \*\*Build\*\* -> \*\*Build\*\* from the top menu.



\---



\## How to Run the Code



1\. Open the project in Code::Blocks and press `F9` (\*\*Build and Run\*\*).

2\. Alternatively, navigate to your project directory, open the `bin/Debug` or `bin/Release` folder, and launch the generated executable directly \*(ensure `glut32.dll` or `freeglut.dll` is present in the same directory as the `.exe` file)\*.



\---



\## Project Specifications



1\. Window Dimensions: 1400 x 800 pixels

2\. Projection: 2D Orthographic Projection (`gluOrtho2D`)

3\. Display Mode: Double-Buffered RGB (`GLUT\_DOUBLE | GLUT\_RGB`)

