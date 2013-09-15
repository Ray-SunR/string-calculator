#Hand-held String Calculator
Contributor: Renchen Sun (Ray)

#Compilation
The program can be compiled by using the following command
make (make -f Makefile)

An executable called "scalculator" will be produced

#Instruction

 This program defined a new 'improved' string type named 'istring' which has the following structure:
	
	struct iString
	{
		char* chars;
		unsigned int length;
		unsigned int capacity;
		iString();//
		iString(const char* a);
		iString(const iString& other);
		~iString();
	};
 
 You are provided with four spaces where you can store those strings. The position is denoted by using 'a' 'b' 'c' 'd'

 
#Commands
 Commands are given in a regex style:    
 e.g. saba, p a 3, f a, etc    
 Copy Constructor needs to work before operator* and operator+ can be tested    
 Delete (command e) iStrings before allocating new ones - otherwise memory leak    
 e.g. Delete an iString before you try to write to it, if you have previously written to it    
 Do something like:     
 'fa ea na foo'    
 and not     
 'fa na foo'     
 which would cause a memory leak    
 
 *Note on commands: Spaces are not necessary but are used here for readability*    
 Command descriptions:    
 1. s destination source1 source2 // operator+    
 2. t destination source1 string // operator+    
 3. r destination string // operator >>, read a string into an iString object    
 4. p destination source int // operator*    
 5. m destination int source // operator*    
 6. n destination string // iString(char*) - create an iString object with given string as contents    
 7. i destination source // copy constructor - copy an existing iString object (like strdup)    
 8. f destination // default constructor - create empty iString (basically, empty string)    
 9. e source // delete source/call destructor - cleans up memory    
 10. l source // print length of iString       

 Test Cases are provided in the 'Test' folder where you can test the program by using the following commands:      
	./runsuite /Test/suite2.txt scalculator      

	Note: For the use of ./runsuite, take a look at my repository: Ray-SunR/Runsuite which facilitates auto-testing.    

#Examples:    

**Input:**    
bcde    
3    
abc    
8    
abcdeabc     
6    
abcabc     
6     
abcabc    
3    
cde    
8    
abcdeabc    
5    
cdefg    
0    
     
3    
abc    
    
    
**Output:**    
5    
abcde   
3    
abc    
8    
abcdeabc    
6    
abcabc    
6    
abcabc    
3    
cde    
8    
abcdeabc    
5     
cdefg    
0    
    
3     
abc    
    
