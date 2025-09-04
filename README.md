# BST Dictionary 🔹 C++ / Qt GUI

![C++](https://img.shields.io/badge/C++-17-blue)
![Qt](https://img.shields.io/badge/Qt-6.6-green)

Implemented a C++ template-based Binary Search Tree dictionary with insert, search, and remove functionalities. Added a Qt GUI to visualize and interact with the dictionary. Focus was on data structures; GUI was added for demonstration!


## Features 🔹

| Feature       | Description                              |
|---------------|------------------------------------------|
| Insert/Update | Add new words or update existing entries |
| Search        | Find a word and its meaning              |
| Remove        | Delete a word from dictionary            |
| Show All      | Display all words in order               |


## Screenshots 🖼

<img width="702" height="508" alt="image" src="https://github.com/user-attachments/assets/74ca5b2f-4e10-4ded-9b9c-2e9d29538688" />

<img width="701" height="505" alt="image" src="https://github.com/user-attachments/assets/ad954ee7-09c7-4ad5-be92-61be11d131f2" />


## Clone & Run 🚀

You can quickly clone this repository and run the project locally.

## Build Instructions ⚙

### 1️⃣ Install Dependencies

**Linux / WSL (Ubuntu/Debian):**

```bash

sudo apt update
sudo apt install g++ cmake qt6-base-dev qt6-tools-dev qt6-tools-dev-tools

# Clone the repo
git clone https://github.com/<your-username>/BSTDictionary.git
cd BSTDictionary

# Create a build folder
mkdir build
cd build

# Configure CMake (replace Qt path if needed)
cmake .. -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt6

# Build the project
cmake --build .

# Run the application
./bst_dictionary_gui




