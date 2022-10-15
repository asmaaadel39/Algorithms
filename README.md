# Algorithms
Some problems solved using C++ language 

Problem 1
Assume that a disk scheduler is to handle file data requests A, B, and C to tracks (or
cylinders) 100, 50, and 190, respectively, and that the disk read/write head is initially at
track 140. Assume it takes 1 time-­‐unit for the disk to seek (move) a distance of one track. If
the file data requests are handled in first-­‐come-­‐first-­‐serve order (A,B,C), then the total seek
time is 40+50+140=230 time-­‐units. Suppose the requests S are to be serviced in the order
which minimizes total seek time instead. The goal is to compute the minimal seek time
f({A,B,C}, 140) = 190, which can be achieved by the order (C,A,B).

Problem 2
You are so lucky in 2021 and finally you have bought your dream car. You decided to travel
to many cities. The car tank capacity is C litres. And each trip will cost x liters of fuel. You
can fill the tank when visiting each city.
The expected inputs
N : number of cities
C : Tank capacity
A[]: the fuel amount you can fill from each city
B[]:the fuel consumption to travel from city i and city i+1
The output
The maximum number of cities you can travel

Problem 3
You are given a connected weighted undirected graph without any loops and multiple
edges. Let us remind you that a graph's spanning tree is defined as an acyclic connected sub
graph of the given graph that includes all of the graph's vertexes. The weight of a tree is
defined as the sum of weights of the edges that the given tree contains. The minimum
spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum
possible weight. For any connected graph obviously exists the minimum spanning tree, but
in the general case, a graph's minimum spanning tree is not unique.
Your task is to determine the following for each edge of the given graph: whether it is either included
in any MST, or included at least in one MST, or not included in any MST.

Problem 4
Ilya is working for the company that constructs robots. Ilya writes programs for
entertainment robots, and his current project is "Bob", a new-­‐generation game robot. Ilya's
boss wants to know his progress so far. Especially he is interested if Bob is better at playing
different games than the previous model, "Alice".
So now Ilya wants to compare his robots' performance in a simple game called "1-­‐2-­‐3". This
game is similar to the "Rock-­‐Paper-­‐Scissors" game: both robots secretly choose a number
from the set {1, 2, 3} and say it at the same moment. If both robots choose the same
number, then it's a draw and noone gets any points. But if chosen numbers are different,
then one of the robots gets a point: 3 beats 2, 2 beats 1 and 1 beats 3.
Both robots' programs make them choose their numbers in such a way that their choice
in (i + 1)-­‐th game depends only on the numbers chosen by them in i-­‐th game.
Ilya knows that the robots will play k games, Alice will choose number a in the first game,
and Bob will choose b in the first game. He also knows both robots' programs and can tell
what each robot will choose depending on their choices in previous game. Ilya doesn't want
to wait until robots play all k games, so he asks you to predict the number of points they
will have after the final game.

