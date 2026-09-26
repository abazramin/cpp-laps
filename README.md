# C++ Problem Solving & Practice

A collection of C++ exercises, algorithms, and small projects created as part of my journey to improve my programming and problem-solving skills.

The main goal of this repository is **practice, experimentation, and continuous improvement** rather than building production-ready applications.

## 🎯 Goals

This repository helps me practice and strengthen my understanding of:

* C++ fundamentals
* Variables and data types
* Conditions and loops
* Functions
* Arrays
* Strings
* Vectors
* Structs
* Enums
* References and pointers
* File handling
* Matrices
* Random number generation
* Problem solving and algorithms
* Code refactoring
* Small console-based projects

## 📚 Topics Covered

### C++ Fundamentals

Practice with:

* `if / else`
* `switch`
* `for / while / do-while`
* Functions
* Arrays
* Strings
* Input validation
* Mathematical operations

### Functions

Examples of reusable functions for:

```cpp
CalculateAverage()
RandomNumber()
ValidateNumber()
CounterLetters()
PrintMatrix()
```

The goal is to break large problems into smaller and reusable functions.

### Structs & Enums

Using `struct` and `enum` to organize related data and represent specific states.

Example:

```cpp
struct stGameInfo
{
    int RandomNumber;
    short UserInput;
    int TryCount;
};
```

### Arrays & Matrices

The repository contains several exercises involving:

* One-dimensional arrays
* Two-dimensional arrays
* Matrix printing
* Matrix comparison
* Row and column calculations
* Matrix sums
* Identity matrices
* Palindrome matrices
* Sparse matrices
* Searching inside matrices

Example:

```text
1  2  3
4  5  6
7  8  9
```

### Strings

Practice with:

* Counting characters
* Counting uppercase/lowercase letters
* Searching for characters
* String manipulation
* Character validation

Example:

```cpp
short CounterLetters(string s1, char target)
{
    short count = 0;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == target)
        {
            count++;
        }
    }

    return count;
}
```

### Vectors

Practice with:

```cpp
vector<int>
vector<string>
```

including:

* `push_back()`
* Iterators
* Range-based loops
* Passing vectors by reference

### File Handling

Practice with C++ file streams:

```cpp
ifstream
ofstream
fstream
```

Examples include:

* Reading files
* Writing files
* Reading lines using `getline()`
* Loading file data into vectors

Example:

```cpp
void LoadDataToVectors(
    const string& FileName,
    vector<string>& vText)
{
    ifstream MyFile(FileName);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vText.push_back(Line);
        }

        MyFile.close();
    }
}
```

## 🎮 Small Projects

The repository also contains small console-based projects designed to combine multiple C++ concepts.

### Rock Paper Scissors

A console game using:

* Enums
* Structs
* Functions
* Random numbers
* Loops
* Game statistics

### Math Game

A small console game that generates mathematical questions and evaluates the player's answers.

Practices:

* Random numbers
* Enums
* Functions
* Conditions
* Loops
* Input handling

### Guess Number

A number guessing game that practices:

* Random number generation
* User input
* Loops
* Structs
* Game statistics
* Validation

## 🛠️ Technologies

* **C++**
* Standard C++ Library
* VS Code
* Git
* GitHub

## 💻 Running the Exercises

Clone the repository:

```bash
git clone https://github.com/abazramin/cpp-laps.git
```

Navigate to the project:

```bash
cd cpp-laps
```

Compile a C++ file:

```bash
g++ main.cpp -o main
```

Run it:

```bash
./main
```

> The exact compilation command may differ depending on the file and operating system.

## 📈 Learning Approach

I am using this repository as a personal training ground.

The general approach is:

```text
Learn a concept
      ↓
Solve small problems
      ↓
Write my own solution
      ↓
Find bugs
      ↓
Refactor the code
      ↓
Practice again
```

The code may not always represent the most modern or optimal C++ approach because the main purpose is to **learn the fundamentals and improve problem-solving skills**.

## 🔄 Continuous Improvement

This repository is continuously updated as I learn new C++ concepts.

Future improvements may include:

* More advanced algorithms
* Object-Oriented Programming
* STL
* Modern C++
* Better error handling
* More refactoring
* Larger console applications

## 📌 Note

This repository is primarily for **learning and practice**.

Some solutions may contain beginner-level implementations, experiments, or intentionally simple approaches. As my C++ knowledge improves, I will revisit older solutions and refactor them.

---

## 👨‍💻 Author

**Abaz Ramin**

GitHub:
https://github.com/abazramin
