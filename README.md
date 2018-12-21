# C_GETINPUT

Good alternative to scanf in C language.

I couldn't find on internet a correct way to get input from the users in my C programms. As I've found on Internet, `scanf` is not a suitable function, it could give a lot of errors. So I've made this custom function `getinput` that uses a lot versatile method: `fgets`.

Example code could be found in the `getinput.c` file.


The function
--
The function is `int getinput(char data[], int dim, unsigned int par, unsigned int par2)`

So let's explain something :)

- The return value is an integer that could be used as a bool var fo some kind of checks. In my example code this value is used to check if the input is correct.
- First argument is our input container. It's a string in which we put our input.
- Second argument is string dimension. It's used to check if we could store buffer in data string.
- Third argument is used to determine if input has the minimum ammount of chars. If this parameter remain 0, there's no minimum.
- Las argument is used to check input content: 0 - no check, 1 - if we need only alphabetic input, 2 - if we need only numeric input, 3 - if we need only alphanumeric input.

Here we create our buffer string to store some input and we use `fgets` method to get input from user. Of course we check if the input is `NULL`, meaning that something went wrong...
```
char buffer[255];

	if (fgets(buffer, sizeof buffer, stdin) != NULL) {
		int x = strlen(buffer);
```
- [ ] - Finish this readme
- [ ] - Correct typos
- [ ] - Got blamed fot my unexperience in C
- [x] - LOL
