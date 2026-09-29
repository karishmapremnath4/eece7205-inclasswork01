# EECE 7205 - In-Class Work 01

Six sorting algorithms implemented in C++ from scratch, plus a program that
compares all six on comparison counts and running time.

## Contents

- `INCLASSWORK01_KARISHMAPREMNATH.pdf` - the report: pseudocode, hand traces,
  correctness arguments, complexity analysis and execution screenshots
- `CPP FILE/` - the seven programs

| Problem | File | Algorithm |
| --- | --- | --- |
| 1 | `INCLASSWORK01_PROBLEM 1_KARISHMA.cpp` | Bubble Sort |
| 2 | `INCLASSWORK_PROBLEM2_KARISHMA.cpp` | Insertion Sort |
| 3 | `INCLASSWORK_PROBLEM3_KARISHMA.cpp` | Selection Sort |
| 4 | `INCLASSWORK_PROBLEM4_KARISHMA.cpp` | Quick Sort (Lomuto, last-element pivot) |
| 5 | `INCLASSWORK_PROBLEM5_KARISHMA.cpp` | Merge Sort |
| 6 | `INCLASSWORK_PROBLEM6_KARISHMA.cpp` | Heap Sort |
| 7 | `INCLASSWORK01_PROBLEM7_KARISHMA.cpp` | All six compared |

Every problem sorts `A = {22, 6, 4, 32, 7, 9, 12, 5}`. No library sorting
routine is used; each algorithm is implemented directly.

## Building

```
g++ -std=c++17 -Wall -o problem1 "CPP FILE/INCLASSWORK01_PROBLEM 1_KARISHMA.cpp"
./problem1
```

Karishma Premnath
