OOP with C++ – Files and Streams
📚 Files and Streams in C++

This repository contains C++ programs and practical implementations based on the Files and Streams unit of Object-Oriented Programming with C++.

The programs demonstrate file handling concepts such as opening, reading, writing, navigating files, using file pointers, and handling file-related errors.

👩‍🎓 Student Details
Student Name: Divya Dhumane
Course: Object Oriented Programming with C++
Unit: Files and Streams
Year: Second Year Engineering
Programming Language: C++
📖 Topics Covered
1. Introduction to File Handling

File handling is used to store and retrieve data from files permanently.

C++ provides file handling through the fstream library.

2. Types of Files

The main types of files are:

Text Files
Binary Files

Text files store data in a human-readable format, while binary files store data in binary form.

3. Streams

A stream represents the flow of data between a program and an input/output source.

Common file stream classes:

ifstream → Reading from a file
ofstream → Writing to a file
fstream → Reading and writing
4. Header Files

The main header file used for file handling is:

#include <fstream>

Other commonly used headers include:

#include <iostream>
#include <string>
📂 File Operations
5. Opening a File

A file can be opened using open().

ofstream file;

file.open("data.txt");

A file can also be opened while creating the stream object:

ofstream file("data.txt");
6. Writing to a File

ofstream is used to write data into a file.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("data.txt");

    file << "Hello C++ File Handling";

    file.close();

    return 0;
}
7. Reading from a File

ifstream is used to read data from a file.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("data.txt");

    string text;

    while (getline(file, text))
    {
        cout << text << endl;
    }

    file.close();

    return 0;
}
8. Reading and Writing Using fstream

fstream can be used for both reading and writing.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file("data.txt", ios::in | ios::out | ios::app);

    file << "New Data" << endl;

    file.close();

    return 0;
}
📍 File Pointers and Navigation

C++ provides functions for navigating within files.

seekg()

Moves the get/read pointer.

file.seekg(0);
seekp()

Moves the put/write pointer.

file.seekp(0);
tellg()

Returns the current position of the read pointer.

cout << file.tellg();
tellp()

Returns the current position of the write pointer.

cout << file.tellp();
⚠️ Error Handling

File operations can fail for several reasons, such as:

File does not exist
File cannot be opened
Permission problems
Reading beyond the available data

C++ provides functions to check file status:

file.is_open()
file.eof()
file.fail()
file.good()
file.bad()

Example:

if (!file.is_open())
{
    cout << "File could not be opened.";
}
