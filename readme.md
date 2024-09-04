# Table of Contents

- [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [To Do](#to-do)
  - [Useful commands](#useful-commands)
  - [Documentation](#documentation)
  - [Test cases](#test-cases)

## Description
Mini talk is a project which codes a small data exchange program
using UNIX signals in C.

- Requirements: 
  - Signals are used only for communication between server and client. 
  - Message transmission is possible:
    - For messages of any side
    - Received messages must be displayed by server correctly
    - Server should never get stuck or print wrong characters
    - Server can receive multiple strings without needing to be restarted.
    - Only one global variable per program is allowed
  - Communication is done only using signals SUGUSR1 && SIGUSR2.

## To Do
- [ ] Update [makefile](Makefile) to include functions whenever appropriate

## Useful commands
	- Ensure that libftprintf.a has been archived
		>> make


## Documentation

1. Format argument is reused whenever necessary to convert all given arguments.
   > printf %s a b

   > 'ab'



## Test cases

1. Positive cases
   - %c single character


2. Negative cases
   - %c single character


3. Edge cases
   - Dealing with format specifiers out of scope within printf

