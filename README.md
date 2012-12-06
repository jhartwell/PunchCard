PunchCard Programming Language
==============================

What is it?
-----------

PunchCard is my entry for the [PLT Games Competition for December, 2012](http://www.pltgames.com/competition/2012/12) in which
we are to create a [Turing tarpit](http://en.wikipedia.org/wiki/Turing_tarpit).

### About

PunchCard works just like a punch card from the days of ol' or the a [ScanTron](http://en.wikipedia.org/wiki/Scantron) test. It has 
only one true operator `x` and how you modify memory all depends on the location of the `x`.

Here are the different arrangements that are available:

`+-----------------+` : indicates the start/end of the file
`| - - - - - - - - |` : marks a line to be jumped to
`| x - - - - - - - |` : moves to the next memory cell
`| - x - - - - - - |` : increments the current cell by 1
`| - - x - - - - - |` : decrements the current cell by 1
`| - - - x - - - - |` : accepts input and stores it in the current cell
`| - - - - x - - - |` : outputs the current cell to the screen
`| - - - - x - - x |` : outputs the current cell to the screen in a pretty way (meaning will try to convert to char)
`| - - - - - x - - |` : will jump to the last marked jumped line if current cell is equal to zero
`| - - - - - - x - |` : will jump to the last marked jumped line if the current cell is not equal to zero

### Behind the scenes

PunchCard uses a memory model similar to that of [Brainfuck](http://en.wikipedia.org/wiki/Brainfuck). The default memory layout is an array of
3000 ints (though it can be modified, it is not supported currently) that will loop back once you have hit the end of the memory. It is written in 
C++ using Visual Studio 2012 (Express) as an exercise for myself to get more familiar with C++ and learn the new features implemented (so far) of C++11. It makes
use of lambdas and unique_ptr<T>, which means that if you are going to try and run this, you need to have a compiler that supports those features.

The interpreter (hoping to add a bytecode compiler soon) is very loose in its parsing as well. All that really matters is the location of the `x`. For instance:
`| - x - - - - - - |` is just as valid as `| 1 x 2 3 4 5 6 7 |` or `| i x n c r e m e |`. The only criteria is that each indicator spot (originally marked by a `-` or `x`) is
just one character/digit in size. Anything else may give skewed results.


An example
-------------------

Finally, we get to an example. I didn't want to put this first since a simple program is quite large. Here is a simple program that will output "HELLO" to the console.

<codeblock>
  <p>
	+-----------------+
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - - - - x - - x |
| x - - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - - - - x - - x |
| x - - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - - - - x - - x |
| x - - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - - - - x - - x |
| x - - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - - - - x - - x |
| x - - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
| - x - - - - - - |
+-----------------+
</p>
</codeblock>

Feedback Welcome
----------------

I'm always looking for feedback on whatever I do and this is no exception. Love this? Hate it? Suggestions to make it better? Please let me know at jon@dontbreakthebuild.comPunchCard
=========

Programming language for PLT Games December contenst