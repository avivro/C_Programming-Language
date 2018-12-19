
#define FUNCTION_H_
#define MATRIX_SIZE 4
#include <stdbool.h>
#define STRING_SIZE 17


/* casing function for Check function,
 * get matrix with characters
 * output:print and count all words of -"List words" at "isword" function;
 */
 int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);


 /* get matrix with characters-"game",int matrix-"touch" for know if we visit at the [i][j] place so we can"t add this characters,String "word" - for add the characters,index i, index j,index of '\0'
  * output: count words of -"List words at "isword" function from all possible path;
  */
 int Check(char game[MATRIX_SIZE][MATRIX_SIZE],int touch[MATRIX_SIZE][MATRIX_SIZE],char word[STRING_SIZE],int i,int j,int INDEX_0);

 /*function includes "List words"
  *  get: pointer for char[];
  * output: return 1 if the word performing
  */
 bool isWord(char* s);

 /* function for check "touch" matrix,if we visit at the [i][j] place
  * get: int matrix
  * output:print the matrix
  */
 void printArr(int a[MATRIX_SIZE][MATRIX_SIZE]);



