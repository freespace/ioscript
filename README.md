# Description
 
IOScript is a simple GPIO scripting interface for quickly manipulating
and reading pins on an Arduino board. IOScript commands consists of
single character commands and optional argument (normally an integer). 

When a command is read it is echoed back for clarity, and when the
command has finished executing '.' will be printed.

It is being developed on an as-needed basis.

# Commands

- `o#`: output LOW on Arduino pin #
- `O#`: output HIGH on Arduino pin #
- `d#`: delay for # number of milliseconds
- `r#`: digitalRead pin #

# Planned Features

- Support for basic loops with conditional break
