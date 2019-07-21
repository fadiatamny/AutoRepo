# AutoRepo
this is a script written in C to run on UNIX/LINUX operating systems to creating and opening git repos

#### Next Step
- [x] remove the system() function replace it with execvp and run both execvp in threads/processes 
- [ ] want to remove the chdir and start using open at instead (try to not change current working directory)
..- basically means to remove all the strcpy and the stuff i did in order to get it to work in any directory. would like it to run in a multithreaded enviroment.
- ... further progress

##### How to compile ? 
the compilation steps used here are what i personally use in order to store said application onto my bin folder and use it as a command.

..- gcc createproject.c -o CreateProject 
..- sudo cp CreateProject /usr/bin