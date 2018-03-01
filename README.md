# coding-at-button

This code is written in response to Button's internship coding challenge 

The code in this assignment was written in the C programming language

## Getting Started

To get started, simply clone the repo and you will get a folder in your directory for the challenge. 
To clone the repo, press the clone button. A link will be presented. Copy the link. 
cd into the directory of your choosing an type git glone, assuming you have git, and you should be all set.
If you dont have git , no problem, just download a zip!

### Prerequisites

Having the terminal for mac or command line for windows!

### Compiling the program

A Makefile will be included for you! 
All you have to do is cd into the directory where the project is stored and type make.
The project will then be compiled.

### Running the program

Once compiled, type ./evalexpression \<input string\> and the program will run

* it is important to not that \<input string\> must be in the form "xxxxxxxx", where xxxxx is input

Because we use spaces as deliminators ./evalexpression + 3 + 4 5 is considered to be 6 arguements, where ./evalexpression "+ 3 + 4 5" is two arguements 

### Valid input

The description of the challenge states the grammer quite clearly

<Operator> <Expression> <Expression>

where \<Operator\> can become + | - <br />
where \<Operator\> \<Expression\> \<Expression\> can become:
\<Operator\> \<Expression\> \<Operator\> \<Expression\> \<Expression\><br />
where: \<Expression\> can become \<Digit\><br />
where: \<Digit\> can become 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 <br />

Examples of valid input:

*Note the challenge description clearly states the input should be space deliminated as follows*

"+ 3 - 4 5"<br />
"+ 4 5"<br />
"- 5 - 6 - 7 - 7 - 8 9"<br />

Examples of invalid input

""<br />
" "<br />
"9"<br />
" 9 + 7 "<br />
"+97"<br />

## Authors

**Christopher LoPresti**

## Acknowledgments

* Thank you for the opportunity, Button!

