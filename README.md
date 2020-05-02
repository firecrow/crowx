# CrowX  
Error handling macros to unify tracking and verification or errors.

see test.c for examples of how to use it, though test.c does a fair amount of
mocking system calls such ass malloc which are only relevant to the tests.

one key element of this being a macro and not a function, is that because it is
expanded into each place the line number and function name on the stack is
relevant to that placement, creating an idea situation for logging out relevant
error dara.
