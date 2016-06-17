     _______________________________________
    |   _______  ____  __     ____  ______  |
    |  /__  __/ / __/ / /    / __/ /  ___/  |
    |    / /   / __/ / /__  / __/ /___  /   |
    |   /_/   /___/ /____/ /___/ /_____/    |
    |_______________________________________|

# ReadMe

## Contents

(1) Introduction

(2) Use

(3) Environment

(4) Building

(5) API

(6) Testing

(7) Bugs

(8) Tasks

(9) About

## (1) Introduction

### What is this program?

Here we have a completely unnecessary, but a very cool way of delivering web
content to the web.

### Aims

The following are the aims of the software to be written:

  * The system must be lightweight on system resources per client, no more
  heavy than would be expected from a HTTP file load.
  * The code must be simple and understandable.
  * The system should not add complexity to generating content for the site.

### History

This program was conceived and written in April, 2016. After the Wikipedia
April Fools joke with pages served in `telnet`, I want to do the same for my
pages where all HTML tags are simply ignored. This way only content is
displayed in the simplest way possible.

## (2) Use

To use the program, you can run it as follows:

    teles <PORT> <DIR>

  * `teles` - The program itself.
  * `<PORT>` - The port to run the server on.
  * `<DIR>` - The directory to serve the files from.

An example of how the program can be run is the following:

    teles 23 www

Other settings will be settable in the configuration file at a later date.

## (3) Environment

You will need to install the following programs:

    sudo apt-get install cmake g++ pandoc

These programs do the following tasks:

  * `cmake` - Organises how a program is built.
  * `g++` - The compiler for the program to be built.
  * `pandoc` - The compiler for markdown documentation.

The following programs are recommended but not required:

    sudo apt-get install git

These programs do the following tasks:

  * `git` - Enables access to the repository.

These programs are not required but recommended if no alternative exists:

  * `git-gui` - Allows for git commits to be visualised.
  * `gitk` - Allows for git branches to be visualised.
  * `vim` - Text editor.

## (4) Building

### First Build

For the first build, you will need to do the following:

    cmake .

This will produce a series of files, allowing you to run:

    ccmake .

This will introduce a menu, in which you should press `c` to configure and `g`
to generate the parameters. For non-standard set-ups it may be required to
change some of the settings in order to get a desired build, by default most
systems should work.

You can now go to the "Normal Build" process.

### Normal Build

To build the files, simply run the following:

    make

You may add the option `-j`, followed by the number of cores your machine has
plus 1.

For example, for a dual core machine you may want to write `make -j3` to get
the most out of your CPU.

## (5) API

The API is yet to be written. The following are the planned languages to be
implemented:

  * `c++`

If you are able to implement an API in other languages, please contact me via
the information found in other places of this documentation.

## (6) Testing

Testing is to be done via multiple methods:

  * **API** - The API will provide testing of the main core, but will also
  require test coverage itself in order to make sure these align. This will be
  done where possible.
  * **Static Coverage** - Static coverage will be used where possible to detect
  issues that may occur whilst the program is being run.
  * **Test Cases** - Every method in the core where possible should be tested,
  other than the low risk entry and exit points of the code where it is
  expected they should work. This should dramatically reduce the risk of
  running issues.

## (7) Bugs

If you detect any bugs, please check the following lists before sending a
report.

### Existing Bugs

    |---|-------|--------|----------------------------------------------------|
    | # | Ver   | Name   | Description                                        |
    |---|-------|--------|----------------------------------------------------|
    | 1 | 0.0.0 | DBARRY | Windows doesn't do line feed                       |
    |---|-------|--------|----------------------------------------------------|
    | 2 | 0.0.0 | DBARRY | Windows sends characters as pressed                |
    |---|-------|--------|----------------------------------------------------|
    | 3 | 0.0.0 | DBARRY | Temp buffer unnecessary for array byte shift       |
    |---|-------|--------|----------------------------------------------------|
    | 4 | 0.0.0 | DBARRY | Remove BUGS list from client                       |
    |---|-------|--------|----------------------------------------------------|

### Fixed Bugs

    |---|-------|--------|----------------------------------------------------|
    | # | Ver   | Name   | Description                                        |
    |---|-------|--------|----------------------------------------------------|
    | 0 | 0.0.0 | DBARRY | Example of bug layout to be used when reporting    |
    |   |       |        | bugs. This format should be respected at all       |
    |   |       |        | times.                                             |
    |---|-------|--------|----------------------------------------------------|

### New Bug

If your bug is not listed, please contact one of the following accounts:

  * `danbarry16@googlemail.com`

## (8) Tasks

The following is a list of tasks yet to be completed for the project:

    |---|-----|------------|--------|-----------------------------------------|
    | # | Dne | Date       | Owner  | Description                             |
    |---|-----|------------|--------|-----------------------------------------|
    | 0 | [/] | 17/04/2016 | DBARRY | Write the main server to accept telnet  |
    |   |     |            |        | connections.                            |
    |---|-----|------------|--------|-----------------------------------------|
    | 1 | [/] | 17/04/2016 | DBARRY | Server display information to           |
    |   |     |            |        | requester.                              |
    |---|-----|------------|--------|-----------------------------------------|
    | 2 | [/] | 17/04/2016 | DBARRY | Server accept characters from           |
    |   |     |            |        | requester.                              |
    |---|-----|------------|--------|-----------------------------------------|
    | 3 | [ ] | 17/04/2016 | DBARRY | Write test cases for the code.          |
    |---|-----|------------|--------|-----------------------------------------|
    | 4 | [ ] | 17/04/2016 | DBARRY | Write c++ API.                          |
    |---|-----|------------|--------|-----------------------------------------|

## (9) About

         _
     _ _|_|
    |_|_|_|
    |_| |_|

Written by Daniel Barry, April 2016.
