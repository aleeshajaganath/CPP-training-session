# Assignment
<p> Implementing Symbol Tables with Linked Lists
<summary>Content</summary>

- src/symtable.h 
  - contains function declarations used by all other cpp files
- src/symtable.cpp
  - Implementation of all function in symtable.h 
- src/symtable_link.cpp
  - CPP file impliments singly linked list and its operations.
- symtable_test.cpp
  - unit testing all functions defined in symtable.cpp file
- build/cmake
  -  generate makefile which will compile a main program from source code
- bin.sh
  - bash script to run main.cpp 
- gtest.sh
  - bash script to run symtable_test.cpp 
- build/out
  -  valgrind summary by running
  ```
  cd build
  valgrind -v ./testSll >& out 
  ```

<summary>Compile and Run the Project</summary>
- symtable_link.cpp

```
source bin.sh
```

- Testing using unit test

```
source gtest.sh
```

