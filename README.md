# Huffman-Encoding
This project depicts **Huffman Encoding** of each and every character and also shows the number of bits reduced after using Huffman Encoding.
## THEORY
* When the distribution of characters are **not even**, then we can use **Huffman Encoding**, so that we can reduce the total number of bits to save each character.
* We will use **Prefix Codes** inorder to make unique Encoding and Decoding Possible.
* The character which is having the **Highest Frequency** is represented with the **Least** number of bits.
### PREFIX CODE
* It means that if we are using any pattern to represent any character, then that pattern should not be a prefix of any other character.

## DATA STRUCTURES USED
1. Min Heap
2. Arrays
3. Trees

## COMPLEXITY ANALYSIS
* Time Complexity: O(n * log(n))
* Space Complexity: O(n)

 Here n represents number of characters entered.

## CODE OUTPUT
![](https://github.com/sumnandi/Huffman-Encoding/blob/master/HuffMan%20Encoding%20Output.PNG)
