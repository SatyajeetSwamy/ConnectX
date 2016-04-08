NAME - SATYAJEET SWAMY

DESCRIPTION OF BUGS:

1) The first bug is in the Constructor as we are checking the condition for width or height or X to be less than or equal to 0.

Now, because of short circuit evaluation, the compiler is going to check for either one of these conditions to be true and therefore it does not do a very good job for checking the width, height or X!

2) The other bug is in inBounds(int w, int h) function, and this can be proven when we try to give a False or invalid value to width and its still goes ahead and checks the height to be False or True.
