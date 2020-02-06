This document gives details of the implementation of the Sailing Club Membership Service, outlined in the assignment brief for the CS23820 module, and the files submitted alongside with it.

It consist of the file and code build description.

All of the requirements for the Membership program were fulfilled, but no attempt at the Race program (15% of the assignment) was undertaken. 

=== FILES BEING SUBMITTED ===

README.txt – current file.

vek1_membership.zip – the zip file which contains all the code required for the membership program. Notice that the text file with the previous member data is not included within the project and requires to be inputted as a directory path within the program.

vek1_membership/main.c – the file, which contains code for the implementation of the simple command-line menu and manages most of the interaction with the user.

vek1_membership/membership.c – the file, which contains all the function required for the interaction with the binary tree and performing all the actions from the menu.

vek1_membership/membership.h – the header file, which contains the definition of the member struct and all the signatures for functions used throughout the project.

vek1_evaluation.pdf – a pdf document, which talks about the code design and implementation. Contains a title page and 2 pages of text.

=== CODE BUILD ===

C99 Executable is being used to make the project. All the warning are turned on. GCC compiler is being used.

The required standard libraries are already included in the header file and need no additional work in order to use them. The standard libraries <stdio.h>, <stdlib.h> <strings.h>, <string.h> are the ones being used.

In order to create a binary search tree from the file – insert the path to the file WITH the name of the file at the end (e.g. ../../data-set-one/members.txt). Notice, that it may slightly vary system from system.



