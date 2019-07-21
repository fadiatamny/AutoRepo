# AutoRepo
this is a script written in C to run on UNIX/LINUX operating systems to creating and opening git repos

#### Next Step
- remove the system() function replace it with execvp and run both execvp in threads/processes 


##### How to compile ? 
the compilation steps used here are what i personally use in order to store said application onto my bin folder and use it as a command.

..- gcc createproject.c -o CreateProject 
..- sudo cp CreateProject /usr/bin