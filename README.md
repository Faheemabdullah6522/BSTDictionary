# BSTDictionary

Implemented a C++ template-based Binary Search Tree dictionary with insert, search, and remove functionalities. Added a Qt GUI to visualize and interact with the dictionary. Focus was on data structures; GUI was added for demonstration!

## Features

- Template-based Binary Search Tree implementation.
- Dictionary operations:
  - Insert / Update words and meanings
  - Search for words
  - Remove words
- In-order traversal for displaying all words.
- Save/load dictionary data to `dictionary.txt`.
- Simple Qt GUI to interact with the dictionary.

## Screenshots

<img width="702" height="508" alt="image" src="https://github.com/user-attachments/assets/74ca5b2f-4e10-4ded-9b9c-2e9d29538688" />

<img width="701" height="505" alt="image" src="https://github.com/user-attachments/assets/ad954ee7-09c7-4ad5-be92-61be11d131f2" />


## Build Instructions (Linux / WSL)

1. Install Qt6 and CMake:

sudo apt update
sudo apt install qt6-base-dev qt6-tools-dev qt6-tools-dev-tools cmake g++

2 .Clone the repository:

git clone <repo-url>
cd BSTDictionary

3 .Build:

mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt6
cmake --build .

4. Run:

./bst_dictionary_gui


