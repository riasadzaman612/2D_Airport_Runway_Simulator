# 2D Airport Runway Simulator

A 2D computer graphics project developed in C++ using OpenGL and GLUT/FreeGLUT framework in Code::Blocks. The application simulates a dynamic airport complex featuring an airplane takeoff sequence, ground support vehicles, facility infrastructure, and a custom vector-based font engine.

---

## 📷 Preview

![2D_Airport_Runway_Simulator](screenshots/demo.png)


---

## 📌 Project Overview & Features

This project models a fully functional, labeled airport environment constructed purely with OpenGL primitives and dynamic matrix transformations.

1. **Airplane Takeoff Animation Loop:** Features smooth linear translation across the runway followed by pitch elevation as the aircraft ascends into the sky. The animation continuously loops back to the runway once off-screen.
2. **Custom Vector Font Engine (`drawChar` & `drawString`):** Renders all text labels (`CARGO`, `FIRE RESCUE`, `ATC`, `TERMINAL 1`) using procedural line vectors, bypassing external font asset dependencies.
3. **Complex Airport Structures:**
   1. Cargo & Freight Hub: Features loading bays and structural framework.
   2. Fire & Rescue Station: Houses emergency response vehicles.
   3. Air Traffic Control (ATC) Tower: Multi-tiered observation tower positioned centrally.
   4. Terminal 1: Multi-story terminal structure rendered with linear color gradients.
4. **Environment & Sky Operations:** Procedural background tree canopy, dynamic layered clouds, and dual-layer runway markings with conditional landing gear rendering based on altitude.
5. **Smooth Frame Timing:** Utilizes `glutTimerFunc` running at 60 FPS (~16ms refresh rate) for fluid movement.

---

## 🛠️ Setup & Prerequisites

1. IDE: Code::Blocks (configured with MinGW C/C++ compiler)
2. Framework: OpenGL / GLUT (or FreeGLUT)

---

## ⚙️ How to Build

1. Set Up GLUT in Code::Blocks:
   1. Copy `glut.h` (or `freeglut.h`) into your MinGW include directory (`MinGW\include\GL\`).
   2. Copy `libglut32.a` (or `libfreeglut.a`) into your MinGW library directory (`MinGW\lib\`).
   3. Place `glut32.dll` (or `freeglut.dll`) inside `C:\Windows\System32` or directly within your project directory.

2. Configure Linker Settings:
   1. Open your `.cbp` project file in Code::Blocks.
   2. Go to **Settings** -> **Compiler** -> **Linker settings**.
   3. Add the following flags under **Other linker options**:
      ```text
      -lopengl32 -lglu32 -lglut
      ```

3. Compile:
   1. Press `Ctrl + F9` (or select **Build** -> **Build** from the menu bar).

---

## 🚀 How to Run

1. Open the project in Code::Blocks and press `F9` (**Build and Run**).
2. Alternatively, navigate to your project directory, open the `bin/Debug` or `bin/Release` folder, and launch the executable directly *(ensure `glut32.dll` or `freeglut.dll` is present in the same directory as the `.exe` file)*.

---

## 💻 Project Specifications

1. Resolution: 1400 x 800 pixels
2. Projection Mode: 2D Orthographic Projection (`gluOrtho2D`)
3. Display Mode: Double-Buffered RGB (`GLUT_DOUBLE | GLUT_RGB`)

---

## 👥 Course & Authors Information

* **Course:** Computer Graphics

### Authors
1. **Riasad Zaman** — ID: `233000612`
2. **Mosammat Antaba Shakera** — ID: `233013012`
