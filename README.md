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
- `i#`: configures pin # as input without pull-up
- `I#`: configures pin # as input with pull-up

Note that pins are set as output or input automatically in order to
fulfil the command. e.g. `o3r3` will result in pin 3 being set as output
then as input.

## Ignored Characters

The character `;`, space and TAB characters are ignored, which is useful for delimiting
and forcing the end to parsing of pin numbers.

## Unknown Characters

When unknown characters are encountered they are echoed and `?` is
printed.

# Planned Features

- Support for basic loops with conditional break
