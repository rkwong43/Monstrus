# Game

Temporary README until I figure out more details to what I want to create. So far, it's supposed to be an deck-building auto-battler with procedurally generated enemies and levels.

For now, things are pretty barebones.

Controller handles the main game loop and is the bridge between the view and the model. It handles user input as well.

The model handles game logic and game states.

The view handles basic rendering and asset loading. Will also handle animations.

## Installation and Running

Install some kind of C++ 17+ compiler. I personally used Visual Studio on Windowws and its compiler and generator. Also, install CMake and Python3.

To run what I have so far as an executable:

```sh
py launch.py
```

## Other links

Lucidchart has some of my scratch space and design notes on game flow and components etc.

<https://lucid.app/lucidchart/fba73b43-d0a4-4023-b97c-87bf7c7fa9cb/edit?invitationId=inv_4fe9b785-8b03-43a8-a01a-3aa92f6de195>

<https://lucid.app/lucidchart/ef53d16f-2844-4e87-862a-08844a3a949b/edit?invitationId=inv_d6feeafb-e056-4c67-b9bb-b3051963d38a>
