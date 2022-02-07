# Game

![The WIP sprite of the Knight](/resources/images/Knight.png)

Please give me game name suggestions! So far, it's supposed to be an deck-building auto-battler with procedurally generated enemies and levels. The general theme will be medieval fantasy with magic and other fantasy elements. In-depth details are included in the Lucidchart links at the bottom of this README. 

For now, things are pretty barebones. The entire project/game is built on modern C++ and CMake, with some utility scripts in Python. Rendering, user input, and the rest of the framework uses [SDL2](https://www.libsdl.org/). Testing is done using CTest for test detection and Catch2 as the testing framework.

Controller handles the main game loop and is the bridge between the view and the model. It handles user input as well.

The model handles game logic and game states.

The view handles rendering and asset loading. Will also handle animations.

## Installation and Running

### Windows

Install some kind of C++ 17+ compiler. I personally used Visual Studio Build Tools on Windows and its default compiler and generator. Also, install CMake and Python3.

To run what I have so far as an executable:

```sh
py launch.py
```

As this is currently early in development, there isn't any distinction between build types yet.

### Linux

Currently, the game is only fully supported to run on Windows. Technically, most of it should still work on Linux but there will be issues with SDL2.

### Running Tests

This project uses [Catch2](https://github.com/catchorg/Catch2) and CTest to run tests. Catch2 is automatically installed using `FetchContent` so all you need to do to run tests is:

```sh
py launch.py --test
```

As the project and testing suite grows, there'll be options for presets and labels.

## Other links

Lucidchart has some of my scratch space and design notes on game flow and components etc.

[Scratch space and UML diagram](https://lucid.app/lucidchart/fba73b43-d0a4-4023-b97c-87bf7c7fa9cb/edit?invitationId=inv_4fe9b785-8b03-43a8-a01a-3aa92f6de195)

[Game flow chart and more scratch space/notes](https://lucid.app/lucidchart/ef53d16f-2844-4e87-862a-08844a3a949b/edit?invitationId=inv_d6feeafb-e056-4c67-b9bb-b3051963d38a)
