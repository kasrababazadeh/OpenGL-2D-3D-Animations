# OpenGL Animation Projects

This repository contains three different OpenGL projects that demonstrate various animation techniques, such as object motion, Bezier curve interpolation, and object rotation. Each project focuses on a different concept to showcase OpenGL’s powerful rendering capabilities for interactive graphics and animations.

## Projects Overview:

### 1. Moving Square Along Bezier Curve
This project animates a square that moves along a **Bezier curve** path defined by four control points. The movement is smooth and follows the curve trajectory, illustrating how parametric curves can be used for object motion in 2D graphics.

- **Key Features**:
  - Animation using a cubic Bezier curve.
  - Dynamic position updates at regular intervals.
  - Smooth transitions along the curve.

- **Technologies**: OpenGL, GLUT

- **Execution**:
  ```bash
  g++ bezier_square.cpp -lGL -lGLU -lglut -o bezier_square
  ./bezier_square

### 2. Rotating 3D Rings with Keyboard Interaction

This project features 3D rings that rotate along different axes. The user can control the rotation by stopping or starting the rotation along the x, y, or z axes using the keyboard.

- **Key Features**:
  - Real-time rotation of 3D rings.
  - Keyboard interaction (`x`, `y`, `z` keys to stop/start rotation on respective axes).
  - 3D rendering with lighting and color effects.

- **Technologies**:
  - OpenGL
  - GLUT

- **Execution**:
  ```bash
  g++ rotating_rings.cpp -lGL -lGLU -lglut -o rotating_rings
  ./rotating_rings

### 3. Moving Square in 2D Space

This project shows a simple 2D square moving vertically within a window. The square moves up and down in a loop, demonstrating basic 2D animation principles with position updates over time.

- **Key Features**:
  - Basic 2D motion animation.
  - Simple color rendering.
  - Position updates based on a timer.

- **Technologies**:
  - OpenGL
  - GLUT

- **Execution**:
  ```bash
  g++ moving_square.cpp -lGL -lGLU -lglut -o moving_square
  ./moving_square

## Requirements

To run these OpenGL projects, you'll need to have the following installed on your system:

- **OpenGL**
- **GLUT** (OpenGL Utility Toolkit)
- A **C++ compiler** (e.g., `g++`, `clang++`)

## Setup Instructions:

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/yourusername/your-repo-name.git
    cd your-repo-name
    ```

2. Navigate to the directory of the project you want to run and compile the C++ file using your preferred compiler:

    ```bash
    g++ <project_name>.cpp -lGL -lGLU -lglut -o <output_file_name>
    ./<output_file_name>
    ```
## Project Structure

  .
  ├── bezier_square.cpp       # Bezier Curve animation for moving square
  ├── rotating_rings.cpp      # Rotating 3D rings with keyboard control
  ├── moving_square.cpp       # Simple 2D square animation
  └── README.md               # Project documentation

## License

This project is licensed under the [MIT License](LICENSE).
