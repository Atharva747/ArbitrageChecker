# ArbitrageChecker
The following problem is from the book 'Introduction to Algorithms' by CLRS:


Arbitrage is the use of discrepancies in currency exchange rates to transform one unit of a currency
into more than one unit of the same currency. Suppose, 1
U.S. dollar bought 0.82 Euro,
1 Euro
bought
129.7 Japanese Yen,
1 Japanese Yen bought
12 Turkish Lira, and one Turkish Lira bought
0.0008 U.S. dollars.
Then, by converting currencies, a trader can start with 1
U.S. dollar and buy 0.82 x 129.7 x 12 x 0.0008
= 1.02 U.S. dollars, thus turning a 2% profit. Suppose that we are given n currencies C1, C2, C3, ... , Cn
and an n x n table " of exchange rates, such that one unit of currency Ci buys R[i, j]+
units of currency Cj .
(a) Give an efficient algorithm to determine whether or not there exists a sequence of
currencies <Ci1, Ci2, Ci3 , ... , Cik> such that:

R[i1,i2] * R[i2,i3] * ... * R[ik,i1] > 1

Solution: Take the negative log values of the weights and apply Bellman-Ford algorithm for shortest paths in order to find whether there exists a
negative weight cycle. If there is a negative weight cycle, then are discrepancies in the conversion rates and the trader can make a profit.
