# A mess with the train timetable!

## Problem

You are working as a programmer in a railway company. Your duty is to write a software that generates personalized train timetables to users of the company's web system. Everything is going fine until suddenly you drop the coffee into the server that contains the complete trains schedule database .. time to panic! You have only time to print the contents of a table in the database that contains the assignment of trains to train stations. Then, PUM! .. the server blows up! And you do not even know if the data printed is not corrupted!

Now you have an herculean task: Given several pairs of numbers printed in the sheet of paper that, eventually, correspond to the assignment of trains to train stations, you have to find out whether this data is corrupted or not. Clearly, it is corrupted if a pair of numbers corresponds to two trains or two train stations.. how to find this?

## Input

The first line for each test case has two integers n and m corresponding, respectively, to the total number of trains and train stations, and the number of pair assignments printed in the sheet of paper. Then, m lines of data follow. Each line has a pair of integers, each one corresponding to the ID of a train or a train station. Note that the train and train station IDs are distinct and range from 1 to n. Also, you do not know the exact number of trains or train stations. Other test cases may follow.

## Constraints

n ≤ 500<br/>
m ≤ 65 000

## Output

The output for each test case is a line containing "NO" if the data is corrupted and "NOT SURE" otherwise.

## Example

### Input:

5 4<br/>
1 2<br/>
1 4<br/>
1 5<br/>
2 3<br/>
5 5<br/>
1 3<br/>
2 4<br/>
2 5<br/>
3 4<br/>
4 5<br/>

### Output:

NOT SURE<br/>
NO
