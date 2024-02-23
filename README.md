# cop4520prog2
cop4520 programming assignment 2

# Problem 1: Minotaur’s Birthday Party

- Approach


- Experimental Evaluation


- Instructions
1. Download 'problem1.cpp'
2. Move file to directory of your choice
3. Compile by typing 'g++ problem1.cpp'
4. Execute the file by typing './a.out'

# Problem 2: Minotaur’s Crystal Vase

- Approach

Strategy 1 is simple and allows for flexibility but lacks consistency or communication. Since large amounts of guests could gather around the vase in the same room simultaneously, there is a higher chance for the vase to become accidentally broken, which we do not want at all.

Strategy 2 is a more sufficient implementation by using 'signs' to keep at most one guest in the room. This greatly decreases chances of the vase being broken, but still has no consistency or communication, since guests could gather around the door waiting for the sign to turn back to 'AVAILABLE', and no one would know who would go next.

Strategy 3 is the best implementation for the guests, as it provides communication between them--when the guests exit, they notify the next guest to come in. A queue also keeps at most one guest in the room, which greatly decreases the chance of the vase breaking due to accidents.

- Experimental Evaluation


- Instructions
1. Download 'problem2.cpp'
2. Move file to directory of your choice
3. Compile by typing 'g++ problem2.cpp'
4. Execute the file by typing './a.out'
