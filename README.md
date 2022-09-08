FOR PART 1:

FOR PART 2: 

When testing, please make sure all code goes through the try block to be able to handle an error when trying to reference an invalid location.
  If an invalid location attempts to be accessed, an error will appear saying that the location does not exist, and the program will terminate.
  
ulliststr_test.cpp is made so that you can perform whatevers operations you want in a code (it will say where to put the operations, along with sample operations).
  Then, the rest of main will cout the list, the front and back using front() and back(), and the size using size_
  If at any point an invalid location is to be accessed, then the program will throw an error and terminate. 
  IF MY TEST CODE REMAINS UNCHANGED, this will only happen if you pass in an empty Item struct because my main is trying to print the first value, and there is no value, it will throw an exception.
    My main automatically prints out all values in the list (as for testing purposes) and does so in a while loop, so there will be no chance for it to get an invalid location unless the code is changed to try accessing one.
    
