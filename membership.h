#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#define MAX_CLASS 31

/** Member struct which stores all the relevant information about members
*/

typedef struct member {
        char family_name[21];
        char personal_names[81];
        unsigned int membership_id;
        char email_address[51];
        char boat_class[MAX_CLASS];
        char boat_name[MAX_CLASS];
        struct member *left;
        struct member *right;

} member_node;

typedef member_node * member_node_ptr; // defining the pointer to the node


/** All of the function signatures. See functions.c for more comments on those
 */

member_node_ptr createTreeNode(char *new_family_name, char *new_personal_names, unsigned int new_membership_id, char *new_email_address, char *new_boat_class, char *new_boat_name);
void insertTreeNode(member_node_ptr current_node, member_node_ptr new_node);
void printMenu();
void printByName(member_node_ptr tree_ptr);
void updateTheTextFile(char filepath[201], member_node_ptr tree_node);
void createNewMember(member_node_ptr tree_root);
void printSingleNode(member_node_ptr tree_node);
int searchForTheNode(member_node_ptr tree_node, char * search_value, int (* action)(member_node_ptr, char *));
int searchForID(member_node_ptr tree_node, char * search_value);
int searchForBoat(member_node_ptr tree_node, char * search_value);
void exportData(FILE * file, member_node_ptr tree_node);