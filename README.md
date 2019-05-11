# 103_PageRank

First opportunity I had to work with data structures like vectors. Really cool application to follow the math and implement into a program to compute page rank. 

Using a RandomWalk approach, I was able to model a simulation of X walkers beginning at different pages and sending them to random outbound links over a series of Y simulations. At the completion of the program, the number of walkers were counted at each webpage and divided by the total X walkers to calculate pagerank.

Command line prompt:
./ pagerank < graphinput > < graphoutput > < Number of walkers > < Number of simulations >

//where graphinput and graphoutput are txt files

