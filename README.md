# getnextline
The purpose of this project was to read from a given file descriptor until a newline was found.
Successive calls to the function getnextline() will allow a user to read in an entire document, one line at a time.

###Restrictions:
- no more than 5 functions in a file
- no more than 1 file
- file must conform to the "code norm" of the school
- no global variables
- only 1 static variable
- does not error (no double free, segfault, unexpected termination)

###Bonus functionality:
- no memory leaks
- being able to handle multiple file descriptors

We were also allowed the option of including our "libft", a recoded library of several C standard library functions.
I opted not to include mine, and instead coded the entire project by hand.
