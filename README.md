# Devanagari Text Recognizer

A C++ application for recognizing hand-drawn Devanagari characters using OpenCV.  
The program can output either the dataset label (e.g., `character_01_ka`) or the actual Unicode character (e.g., `क`) directly in the terminal.

---

## Demo
[DemoVideo](https://drive.google.com/file/d/1GDn705DO_rK5NiWEEcGwn6dVurG5dbHy/view?usp=drive_link)
Example command:

```bash
./build/Debug/DevanagriTextRecognizer.exe "dataset" "test_images/char1.png" -i
```

Output:

```
क
```

---

## Features

- Recognizes hand-drawn Devanagari characters
- Supports two output modes:  
  - `-l` → prints recognized label (e.g., `character_01_ka`)  
  - `-i` → prints recognized Devanagari Unicode character (e.g., `क`)  
- Dataset-based recognition approach
- Simple command-line interface

---

## Project Structure

```
DevanagriTextRecognizer/
│── dataset/               # Training/Template dataset images
│── test_images/           # Test images for recognition
│── src/                   # Source files (main.cpp, recognizer.cpp, recognizer.h, etc.)
│── build/                 # Build directory (generated after compilation)
│── CMakeLists.txt         # Build configuration file
│── README.md              # Project documentation
```

---

## Requirements

- C++17 or higher  
- OpenCV (>= 4.x recommended)  
- CMake (>= 3.15)  
- Compiler: MSVC / MinGW / GCC / Clang  

---

## Build Instructions

```bash
# Clone the repository
git clone https://github.com/username/DevanagriTextRecognizer.git
cd DevanagriTextRecognizer

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build . --config Debug
```

---

## Usage

```bash
./build/Debug/DevanagriTextRecognizer.exe "<dataset_path>" "<test_image_path>" [option]
```

### Options:
- `-l` → print recognized label (e.g., `character_01_ka`)  
- `-i` → print Devanagari Unicode character (e.g., `क`)  

### Example:
```bash
./build/Debug/DevanagriTextRecognizer.exe "dataset" "test_images/char1.png" -i
```

Output:
```
क
```

---

## Unicode Notes (Windows)

If you see garbled output (e.g., `añò` instead of `क`), configure your terminal to use UTF-8:

- **PowerShell / CMD**:
  ```powershell
  chcp 65001
  ```
- **Git Bash / Windows Terminal**:  
  UTF-8 is typically supported by default.

---

## Future Work

- Expand support for all Devanagari characters and digits  
- Integrate machine learning for improved recognition accuracy  
- Add a GUI with a drawing pad for interactive input  

---


