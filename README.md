# Dictionary Search

### 1. Introduction:

> Efficient word search within textual data is crucial for a wide range of
applications, including search engines, spell checkers, and text analysis tools.
The ability to quickly locate specific words or patterns within a given dataset
is fundamental for enhancing user experience and system performance.
Traditional methods for word search often encounter challenges with large
datasets, leading to inefficiencies in retrieval times.
This project centers around addressing the fundamental problem of
word search without revealing specific implementation details. By focusing
solely on the problem statement, we aim to explore various approaches to
improve search speed and accuracy. In this project, we aim to develop
algorithms and techniques capable of quickly and accurately identifying the
presence of target words within the dataset.

### 2. Problem Description

> The primary objective is to design a word search solution that can
handle large datasets containing extensive collections of words. Given the
size and complexity of the dataset, traditional linear search methods are
not viable due to their inefficiency. Therefore, the challenge lies in devising
algorithms and utilizing appropriate data structures to optimize search speed
and minimize computational overhead.

# Code
## Linked List Dictionary Search

This project implements a simple dictionary search using a linked list. The program loads words from a text file into a linked list and provides options to search for words based on different criteria. The implementation is divided into two main files: `Linkedlist.h` and `main.cpp`.

### `Linkedlist.h`

This header file defines the `Node` and `Linkedlist` classes.

#### `Node` Class
- Represents a node in the linked list.
- Contains:
  - `Data`: A string to store the data (word).
  - `Next`: A pointer to the next node in the list.

#### `Linkedlist` Class
- Manages the linked list operations.
- Contains:
  - `Head`: A pointer to the first node in the list.

#### Methods

1. **Constructor**
   - `Linkedlist()`: Initializes an empty linked list by setting `Head` to `NULL`.

2. **Utility Methods**
   - `bool isempty()`: Checks if the linked list is empty.
   - `int Count()`: Returns the number of elements in the list.
   - `int search(string Word)`: Searches for a specific word and returns its position.
   - `vector<string> StartsWith(string key)`: Returns words that start with the given key.
   - `vector<string> EndsWith(string key)`: Returns words that end with the given key.
   - `vector<string> Find(string key)`: Returns words that contain the given key.
   - `bool CheckInsideW(string word, string key)`: Helper function for `Find` to check if a word contains the key.

3. **Insertion Methods**
   - `void InsetFirst(string NewData)`: Inserts a new node at the beginning of the list.
   - `void InsertBefor(string Data, string NewData)`: Inserts a new node before a specific node (not used in this project).
   - `void Append(string NewData)`: Appends a new node at the end of the list.

4. **Display Method**
   - `void Display()`: Prints all the elements in the list.

### `main.cpp`

This file contains the main program logic.

1. **Loading Data**
   - Loads words from a file (`usa.txt`) into the linked list.
   - Displays a message indicating the loading status and the number of items loaded.

2. **User Interface**
   - Presents a menu for the user to choose different search options:
     1. Search for a specific word.
     2. Search for words that start with specific letters.
     3. Search for words that end with specific letters.
     4. Search for words that contain specific letters.
   - Prompts the user for input and performs the corresponding search using the linked list methods.
   - Displays the search results or appropriate messages if no matches are found.
   - Allows the user to exit the program by entering "0" or "end".

### Usage

1. **Compile and Run**
   - Ensure you have `Linkedlist.h` and `main.cpp` in the same directory.
   - Compile the program using a C++ compiler.
     ```sh
     g++ main.cpp -o dictionary_search
     ```
   - Run the executable.
     ```sh
     ./dictionary_search
     ```

2. **Interacting with the Program**
   - Follow the on-screen instructions to search for words based on your criteria.
   - Enter "0" or "end" to exit the program.

### File Format

- The words are loaded from `usa.txt`.
- Ensure `usa.txt` is in the same directory as the executable.

---
