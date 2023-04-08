# Lab 1 - Computer Graphics

## To run

``` python
python3 compiler.py. 
```

Then run the executable file that is generated in the same folder called `app.exe`.

This might not work on your Operating System.

## Structure
- `compiler.py` - The main file that runs the compiler for c++ including the libraries and dependencies
- dependencies - The folder that contains the dependencies for the compiler, mostly stuff related to OpenGL.
- src - The folder that contains the source code for the program. Here is divided into:
    - `main.cpp` - The main file that contains the main function and the code for the program.
    - gui/ - The folder that contains the code for the GUI.
    - vectors/ - The folder that contains the code for the vectors.
        - /manual - The folder that contains the code for the manual vectors. Manual refers to the vectors that are not generated by an external library like glm, here the vectors are generated by the a custom class.
        - /glm - The folder that contains the code for the vectors generated by glm library. Usually used by graphic libraries like OpenGL.

## Sucessful Output
The output of the program should look like this: 
![show](https://user-images.githubusercontent.com/49286935/230539913-16ae9925-338d-497b-9b3e-d7e2e5ed8bb1.png)

You can see in the image that the program is able to work with Vectors in 3 dimensiones and do some basic operations. Two approaches were used to generate the vectors, one using glm library and the other using an "artisanal" custom class. The custom class is used to show how the vectors are generated and how they work. The outputs of the operations are exactly the same regardless of the approach used.
## TODO
- [X] Edit compiler.py to make it work across all Operating Systems

## Colaborators
- [Mavelyn Sterling Londoño](https://github.com/MavelSterling)
- [Juan Sebastián Velasquez Acevedo](https://github.com/Odzen)
- [Sebastián Tutistar Valencia](https://github.com/xlPlanetarizaGol)