# makefile lab
* project structure
    ```
    .
    ├── bogay.jpg
    ├── lib
    │   ├── (makefile)
    │   ├── nyancat
    │   └── qdbmp
    │       ├── dep00.c
    |       ├── ...
    │       ├── dep99.c
    │       ├── gemf.py
    │       ├── licence
    │       ├── (makefile)
    │       ├── qdbmp.c
    │       └── qdbmp.h
    ├── main.c
    ├── (makefile)
    └── readme.md
    ```
* task explaination
    this lab required completion of the missing makefile in the project with the following requirement
    1. ```qdbmp``` required to build as shared object(i,e. ```libqdbmp.so```)
    2. ```nyancat``` binary in ```lib/nyancat/src/nyancat``` shall be move to root folder(i,e. ```.```) to make the ```main``` worked
    3. ```main``` shall dynamic link with ```libqdbmp.so```(note: library can be moved to root folder)
    4. a clean command shall be provided to clean every file generated above(i,e. ```make clean```)
