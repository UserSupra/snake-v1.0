# QTsnake-v1.0
Hi all.

This is my very first 2d game. This is also my first github share.

Here is a Snake. Snake is a classic game of 2000's, from nokia 3310 phone. Game that i think, is perfect for a first 2d game.

To do this project, i'v used QT and create 3 objects:
  - Head -> is the head of the snake, easy... Here, the head of the snake is a big pixel of 20*20px. The head give the direction to de tail.
  - SnakeTail -> is the tail of the snake. The tail is a group, a vector of big pixel of 20*20px. Tail increase his size when snake head eat an apple.
  - Apple -> this is the way to win point and to grow the tail. It's also a pixel of 20*20. You need to "pass over" with the head to eat it, win point, increase your size and increase difficlty.
  
their is 1 more class to controle all these object, a class nommed testsnake.

First i wanted to try to make an object for the menu but, it was a bit difficult. I haven't understand how do that. Isn't easy to work on QWidget/Layer inside of QGraphics.

Finaly, this code can sometimes bug. I don't know why but maybe 1 times on 25, their is a miss eating :(

I hope the younger of us will like this game :)

Supra.

![Screenshot from 2021-01-04 12-38-09](https://user-images.githubusercontent.com/70440132/103595272-5123f180-4efb-11eb-9332-e088f6c2dbad.png)
