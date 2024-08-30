# 42_PUSH_SWAP
Implementing a sorting algorithm in stacks

# About
Being the first Rank02 project of 42 Common Core, Push_swap is all about sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
The goal is to write a program in C which calculates and displays on the standard output the list of operations between two stacks that sorts in ascending order the integers received as arguments.
For this I needed to choose for a sort algorithm that optimized the most this whole proccess, and my choice was the Turk Algorithm.
# Operations Allowed
- `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.
#  Walkthrough
- Error Management: The program should only accept parameters within the range of integers from the minimum to the maximum. Anything different from that it will prompt the message ``Error``, followed by a new line, and then finish the program. If no parameters are specified or the numbers provided are already sorted, the program must not display anything and give the prompt back.
- Creating the stacks: I implemented the stacks using singly linked lists, where each node incorporates the following: the value itself, index, and cost (all integers); previous, next, and target nodes (pointers); and a boolean indicating whether the index was above the median element.
- Developing the operations: Each operation is meticulously designed to perform specific tasks such as swapping elements, pushing elements between stacks, and rotating elements within a stack. This phase was pivotal to the project serving as a valuable learning experience in effectively managing linked lists and contributing to my understanding of data structure manipulation.
- Sorting two elements: When only two integers are passed as arguments, the program will apply ``sa``(swap a) operation to rectify the order.
- Sorting three elements: When only three integers are provided, a three-step process is followed. First, if the largest number is at the top, the program executes ``ra`` (rotate a) operation. Alternatively, if the largest number is in the second position, ``rra`` (reverse rotate a) operation is applied. Following these rotations, if the first element remains greater than the second, ``sa`` (swap a) operation is executed to achieve the sorting.
- Sorting more than three elements: When dealing with more than three integers, the program applies the Turk Algorithm, explained here ["Push Swap — A journey to find most efficient sorting algorithm"](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
