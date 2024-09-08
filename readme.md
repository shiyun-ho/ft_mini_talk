# Table of Contents

- [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [To Do](#to-do)
  - [Useful commands](#useful-commands)
  - [Documentation](#documentation)
  - [Allowed Functions](#allowed-functions)
  - [Test cases](#test-cases)
    - [References](#references)

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
   
   - To run server
      >> ./server

   - To run client
      >> ./client


## Documentation

1. Create a communication program in the form of client and server. 
2. Start the server. 
3. Upon launch, server has to print PID. 
4. Start the client. 
5. Client takes in two parameters:
   1. Server PID
   2. String to send
6. Client must send the string passed as a parameter to the server. 
7. Once the string has been received, the server must print it. 
   1. Server has to display the string pretty quickly. 
   2. Server should be able to receive strings from several clients in a row without having to restart. 
8. Communication between client and server has to be done only using UNIX signals
9. Can only use two signals: SIGUSR1, SIGUSE2


## Allowed Functions

1. write
2. ft_printf
3. signal(): 
4. a

## Test cases

1. Positive cases
   - Sending normal pid values over server


2. Negative cases
   - Sending invalid pid (-1), 


3. Edge cases
   - NA

### References
1. Explains the concepts of UNIX signals as a form of Inter-Process Communication (IPC): UNIX Signals as IPC: A Comprehensive Guide [https://github.com/ANSANJAY/unix-signals-ipc-guide]
2. Stackoverflow: How do signals work? [https://stackoverflow.com/questions/4208004/how-do-unix-signals-work]
3. Signal Handling in Linux [https://www.youtube.com/watch?v=RU0ULe2f6hI]
