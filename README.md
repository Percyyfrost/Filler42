 # Filler 42

## Overview

This project is an algorithmic challenge that pits two players against each other in a battle to fill a box with their respective pieces. The goal is to create a player that can outsmart and outmaneuver the default players, using strategic moves and avoiding being trapped.

## Key Features

- Custom VM: The game runs on a custom-built virtual machine, ensuring a fair and consistent environment for all players.
- Two-Player Competition: Players compete head-to-head to claim the most territory within the box.
- Strategic Gameplay: Success requires careful planning, intelligent moves, and the ability to adapt to the opponent's strategies.
- Algorithmic Challenges: Players must employ effective algorithms to navigate the game board, avoid being enclosed, and optimize their piece placement.

## Usage

To run the game:

1. Compile the VM:
   ```bash
   make
   ```
2. Execute the game:
   ```bash
   ./filler_vm -f MAP -p1 ./P1_NAME -p2 P2_NAME -v
   ```
   - `MAP`: The file path to the game map.
   - `P1_NAME`: The file path to the first player's executable.
   - `P2_NAME`: The file path to the second player's executable.
   - `-v`: Optional flag for verbose output.

## Player Development

To create a custom player:

1. Write a C file: Implement your player's logic in a C file.
2. Compile the player: Compile the C file into an executable.
3. Run the game: Specify your player's executable as `P1_NAME` or `P2_NAME` in the game execution command.

## Algorithms

- Quicksort: This algorithm is used to efficiently sort various game elements, such as potential moves or game board sections.

## Strategies

- Avoiding Entrapment: Your player must be able to identify and avoid moves that would lead to being enclosed by the opponent.
- Adapting to the Opponent: The ability to analyze the opponent's moves and adjust strategies accordingly is crucial for success.
- Optimizing Piece Placement: Carefully consider the placement of each piece to maximize territory and block the opponent's progress.

## Contributing

Feel free to contribute to this project by:

- Developing new and improved players.
- Optimizing existing algorithms.
- Suggesting new strategies.
- Identifying and addressing bugs or issues.
