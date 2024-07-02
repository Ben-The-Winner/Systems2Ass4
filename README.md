# Systems2Ass4
a repository for systems2 assignment 4. The structure of the files in your directory should look like this

.
├── CMakeLists.txt
├── tree.cpp
├── main.cpp
├── complex.h
└── tree.h

##Running the project

to run this project you need the libraries  Qt 5 and Cmake. here are 5 steps for running this project

1. Clone the repository: write this in the terminal
    ```
    git clone https://github.com/yourusername/tree-gui-project.git
    cd tree-gui-project
    ```

2. Create a build folder and enter it:
    ```
    mkdir build
    cd build
    ```
3. Run CMake to generate the build files:
    ```
    cmake ..
    ```
4. Build the project:
    ```
    make
    ```
5. After building, you can run the project from the `build` directory:
```
./TreeGui
