# Binary Search on Two Sorted Arrays

This program finds the element at a given **rank** (position in sorted order) from the union of two sorted arrays using a binary search approach.

## How it Works

- Two sorted arrays `A` and `B` are provided by the user.
- For each query rank `r`, the program determines which element from `A` or `B` has that rank in the merged sequence.
- Binary search is used to efficiently locate the correct element without fully merging the arrays.

## Input Format

1. Three integers `m`, `n`, `p`:
   - `m`: size of first array
   - `n`: size of second array
   - `p`: number of rank queries
2. `m` integers for the first sorted array.
3. `n` integers for the second sorted array.
4. `p` integers, each representing a rank to query.

## Output

For each query rank `r`, the program prints which element (and from which array) has that rank in the merged order.
