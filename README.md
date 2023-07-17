
# cpp_bomberman

## Intro

This repository contains a simple custom game engine written in C++ that allows you to run the classic game Bomberman. The game engine provides a basic framework for creating and rendering the game, handling user input, and managing game logic.

## Features

1. Tile-based game environment with customizable dimensions.
2. Real-time rendering using [SDL2](https://www.libsdl.org/) graphics library.
3. <details><summary> Animations </summary><blockquote> 

    https://github.com/EC2121/cpp_bomberman/assets/89205380/ac4c05a0-29f7-46a1-bd39-4e1d48f40611

    </blockquote></details>
4. <details><summary> Simple geometry collision </summary><blockquote> 

    https://github.com/EC2121/cpp_bomberman/assets/89205380/3d8cb216-36ea-46e9-b1da-608ab75c1544

    https://github.com/EC2121/cpp_bomberman/assets/89205380/d635cd59-82f3-4481-8b9a-3799dbe28b68


  
    </blockquote></details>
## Work in progress

Please note that this game engine is a work in progress, and as such, not all features may be fully implemented or functional at the moment. While the current version provides a basic framework for running Bomberman, some advanced features, such as multiplayer networking, advanced AI behavior, or additional game modes, are still under development. 

## Nice to have
1. Multiple players with individual controls.
2. Power-ups
3. Basic AI
4. Sounds Effect

## Build and run

 To build and run the game engine in Visual Studio, please follow these steps:

1. Download the repository as a ZIP file from the GitHub page by clicking on the "Code" button and selecting "Download ZIP". Save the file to your desired location on your computer.

2. Extract the contents of the ZIP file to a folder of your choice. This folder will be referred to as the project directory.

3. Open the sln file using Visual Studio 2022.

4. Build the project by selecting "Build" -> "Build Solution" from the menu bar, or by pressing Ctrl+Shift+B. Visual Studio will compile the project and generate the executable.

5. After a successful build, locate the generated executable (typically named "bomberman.exe") in the project's output directory.

6. Launch the game by double-clicking on the executable or selecting "Debug" -> "Start Without Debugging" from the menu bar. The game should start running.

Please note that the steps provided assume you have Visual Studio properly installed on your system and configured for C++ development. If you encounter any issues during the process, ensure that you have the necessary dependencies set up correctly and review the project settings within Visual Studio to ensure they align with your system configuration.

## Game Controls

WASD keys (W, A, S, D) to move, Spacebar to place a bomb.

## Customizing the Game

You can easily customize every parameter of the game!
For example you can customize the controls of the player changing the values of the SDL_SCANCODE in the file [Player.cpp(40)](https://github.com/EC2121/cpp_bomberman/blob/main/Bomberman/Bomberman/source/Actors/player.cpp)
```cpp

		if (keys[SDL_SCANCODE_D])
		{
			velocity.x = 1;
		}
		else if (keys[SDL_SCANCODE_A])
		{
			velocity.x = -1;
		}
		if (keys[SDL_SCANCODE_W])
		{
			velocity.y = -1;
		}
		else if (keys[SDL_SCANCODE_S])
		{
			velocity.y = 1;
		}

```

## Acknowledgments
The game engine was developed as a learning project and heavily inspired by the original Bomberman game. Special thanks to the [SDL2](https://www.libsdl.org/) team for their excellent librerie.

## Contributing
Contributions are welcome! I'm always open to constructive criticism. If you have any suggestions, bug reports, or enhancements, please open an issue or submit a pull request.

