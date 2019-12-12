# Makefile Genrator

This is a program that can be used to generate makefiles of C or C++ programs.
This is also my first attempt at Test Driven Developement.

# Basic Usage

### Compiling

On systems having g++ and make , one can create the executable by running make command. For other systems one can compile individual files and then fianl program as per the makefile.  
The Final compiled program is name mkgen by default.

### Usage

To create a makefile of a project, copy this executable in the Project folder,and run :  
./mkgen &lt;main_file&gt; [-e]
Where the main_file is the file containing the main method, or for which the makefile is to be generated.

the -e flag is optional and is used to change the default options :

<ul>
<li>C Compiler (gcc)</li>
<li>C++ Compiler (g++)</li>
<li>Compiler Options (None)</li>
<li>Name of Generated Makefile (makefile)</li>
<li>Name of final executable output file (a.out)</li>
<li>Add statement in makefile to remove all the .o files in the folder after creating final executable  (false)</li>
</ul>

## Other Points

This project was also an attempt at Test Driven Developement,thus various modules were developed using tests , which are in testfile folder, as well as their respective makefiles. To run a test, copy the .cpp and respective makefile outside the testfile folder, reanme the makefile to 'makefile' and run make.

This was also successful at generating its own makefile, which is the main makefile. The original makefile used to create the first executable of the program is in testfiles folder by name makefile_original.

## Notes and Warnings

<ul>
<li>This is currently in its first version, so it only tracks the custom dependencies declared in .h or .hpp file, not .c or .cpp files,that is any non-standerd .h or .hpp file that is to be included should be included in the .h or .hpp of respective .c or .cpp files.</li>
<li>In case of error of same class/function/other-thing being declared multiple times, one should check if the #include of same file is done multiple times in a dependency chain. Eg :  A includes B, A include C, but B also includes C. This can be Overcame by checking no duplicate includes are declared or by using #ifndef #define #endif in include files.</li>
<li><b>This cannot handle the #includes done from parent or subfolders well.</b> So for best results put all dependencies in same folder and run mkgen.</li>
</ul>
