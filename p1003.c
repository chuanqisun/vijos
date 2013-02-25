#include <stdio.h>

/* locate the inner most brackets pair
 * 
 * input: 
 *      lbp -- pointer to the position of the left inner most bracket in opt_list
 *      rbp -- pointer to the position of the right inner most bracket in opt_list
 *      opt_list -- operator list
 * return: 
 *      0 -- inner most bracket exists
 *      1 -- inner most bracket doesn't exist
 */
int findBracket(int* lbp, int* rbp, char* opt_list);  

/* load numbers and operators separately into two lists
 *
 * input
 *      exp -- the expression
 *      num_list -- list of operands
 *      num_count -- number of operands
 *      opt_list -- list of operators
 *      opt_count -- number of operators
 *      opt_num_map -- a mapping from location of operator to location of its first operand
 */
void loadLists(long long num_list[], char* opt_list, int* num_count, int* opt_count, int opt_num_map[]);

/* locate highest order operator in a bracketless range of operators
 *
 * input:
 *      lbp -- pointer to the position of the left inner most bracket in opt_list
 *      rbp -- pointer to the position of the right inner most bracket in opt_list
 *      opt_list -- operator list
 * return:
 *      location of highest order operator in opt_list
 */
int findHighOpt(int* lbp, int* rbp, char* opt_list);

/* compute an binary operation and update num_list, opt_list, opt_num_map
 *
 * input:
 *      opt_loc -- location of the operator in opt_list
 *      num_list -- operands list
 *      opt_list -- operator list
 *      num_count -- number of operands
 *      opt_cout -- number of operators
 *      opt_num_map -- a mapping from location of operator to location of its first operand
 */
void simplify(int opt_loc, long long num_list[], char* opt_list, int* num_count, int* opt_count, int opt_num_map[]);

/* compute value of an expression
 *
 * input:
 *      exp -- expression we want value from
 *      a -- value of the variable
 * output:
 *      value -- value of expression
 */
long long compute(char* exp, int a);

int main(int argc, char* argv[]){
    //read in sample expression
    
    //compute sample value
    
    //read each new expression
    //compute value and compare if equal to sample expression
}
