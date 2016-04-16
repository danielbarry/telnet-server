     _______  ____  __     ____  ______
    /__  __/ / __/ / /    / __/ / ____/
      / /   / __/ / /__  / __/ /___  /
     /_/   /___/ /____/ /___/ /_____/

# ReadMe

## Contents

(1) Introduction

(2) Environment

(3) Building

(4) Bugs

(5) About

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

## (2) Environment

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

## (3) Building

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

## (4) Bugs

If you detect any bugs, please check the following lists before sending a
report.

### Existing Bugs

    |---|-------|--------|----------------------------------------------------|
    | # | Ver   | Name   | Description                                        |
    |---|-------|--------|----------------------------------------------------|
    | 0 | 0.0.0 | DBARRY | Example of bug layout to be used when reporting    |
    |   |       |        | bugs. This format should be respected at all       |
    |   |       |        | times.                                             |
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

## (5) About

Written by Daniel Barry, April 2016.

             ___
            |   |
     _______|___|
    |   |   |   |
    |___|___|___|
    |   |   |   |
    |___|   |___|
