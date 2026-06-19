Section A: Concept Application (Theoretical – Scenario Based)

Q1. You are building a food delivery application. At which stage would you prefer using a compiler over an interpreter, and why? Explain based on execution speed, error detection and deployment.

Answer:

I would prefer using a compiler during the deployment stage of the food delivery application.
Execution Speed: A compiler converts the entire source code into machine code before execution, making the application run faster.
Error Detection: Many syntax and coding errors are detected during compilation, reducing issues during execution.

Deployment: Compiled programs can be distributed as executable files, making them easier and more secure to deploy.

An interpreter is useful during development and testing because it executes code line by line, but a compiler is better for final deployment.


---

Q2. You are asked to design a program that calculates employee salary with multiple conditions (bonus, tax, overtime). Which programming constructs would you combine to solve this efficiently?

Answer:

To calculate employee salary efficiently, I would combine the following programming constructs:

Variables to store salary, bonus, tax, and overtime values.

Conditional statements (if-else) to apply different bonus and tax rules.

Arithmetic operators to perform calculations.

Functions to separate salary calculation into reusable modules.

This combination makes the program organized, efficient, and easy to maintain.


---

Q3. While developing a menu-driven console application, why are loops preferred over conditional repetition? Explain which loop you would choose and why?

Answer:

Loops are preferred because they allow the menu to repeat automatically until the user chooses to exit. Using only conditional statements would require writing the same code repeatedly.

I would choose a do-while loop because:

The menu is displayed at least once.

The program continues running until the exit condition is met.

It is ideal for menu-driven applications where user interaction is required repeatedly.



---

Q4. A student writes a program to calculate average marks using int variables and gets incorrect output. Identify the probable cause and explain how choosing the correct data type solves the issue.

Answer:

The probable cause is integer division.

When average marks are calculated using int variables, the decimal part is removed automatically, resulting in an inaccurate answer.

For example:

int average = (85 + 86 + 87) / 3;

To get accurate results, the student should use float or double data types:

float average = (85 + 86 + 87) / 3.0;

Using a floating-point data type preserves decimal values and provides a correct average.


---

Q5. You are debugging a program that compiles successfully but crashes at runtime. Which category of error is this? Mention two debugging practices you would follow to resolve it.

Answer:

This is a Runtime Error because the program compiles successfully but fails while executing.

Two debugging practices are:

1. Use a debugger and breakpoints to identify the exact location of the crash.

2. Check variables, pointers, array indices, and file operations to detect invalid memory access or incorrect data handling.

These practices help locate and fix the cause of the runtime error.


---

Q6. You need to store student records with name, marks, and grade. Why would you choose a structure over multiple arrays in this scenario?

Answer:

I would choose a structure because it allows related data to be grouped together in a single unit.

For example:

struct Student
{
    char name[50];
    float marks;
    char grade;
};

Advantages of using a structure:

Keeps all information about a student together.

Improves code readability and organization.

Makes data management easier.

Reduces the risk of mismatching data stored in separate arrays.


Therefore, structures are more efficient and suitable for storing student records.
