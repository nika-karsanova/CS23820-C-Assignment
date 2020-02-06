#include "membership.h"

/** Function to print out the options of the command line menu
 */

void printMenu() {
    printf("\n======= MENU =======\n");
    printf("1 – Display a membership list of all members in order of their family names.\n");
    printf("2 – Display details for a single member by specifying their membership ID.\n");
    printf("3 – Display a list of all members owning a boat of a given class with their names, membership IDs and boat names or numbers.\n");
    printf("4 – Add a new member.\n");
    printf("5 – Save updated data.\n");
    printf("6 – Quit.\n");
    printf("\n");
}

/** Function to create the binary tree node.
 *
 * @param new_family_name the family name of the member being created
 * @param new_personal_names the personal names of the member being created
 * @param new_membership_id the membership id of the member being created
 * @param new_email_address the email address of the member being created
 * @param new_boat_class the boat class of the member being created
 * @param new_boat_name the name of the boat of the member being created
 * @return the created node
 */

member_node_ptr createTreeNode(char *new_family_name, char *new_personal_names,
                               unsigned int new_membership_id, // passing in all the needed data
                               char *new_email_address, char *new_boat_class, char *new_boat_name) {

    member_node_ptr new_node_ptr = malloc(
            sizeof(member_node)); // assigning the size for each of the member nodes with a pointer

    if (new_node_ptr == NULL) { // fail if the new node is for some reason NULL
        printf("Failure.\n");
        return NULL;
    } else { // otherwise, assign the data to the new node
        strcpy(new_node_ptr->family_name, new_family_name);
        strcpy(new_node_ptr->personal_names, new_personal_names);
        new_node_ptr->membership_id = new_membership_id;
        strcpy(new_node_ptr->email_address, new_email_address);
        strcpy(new_node_ptr->boat_class, new_boat_class);
        strcpy(new_node_ptr->boat_name, new_boat_name);
    }
    return new_node_ptr; // return created node
}

/** Function to add the node in the correct place of the binary search tree.
 *
 * @param current_node the node with which we are moving across the tree
 * @param new_node the node we want to add
 */

void insertTreeNode(member_node_ptr current_node, member_node_ptr new_node) {

    if (strcmp(current_node->family_name, new_node->family_name) <
        0) { // will return a number less than zero if the current's family name sorts first

        if (current_node->right == NULL) { // if the node has no right child
            current_node->right = new_node; // make the node we want to add the right child of the current node
        } else {
            insertTreeNode(current_node->right, new_node); // recurse otherwise by moving to the next node on the right
        }

    } else {  // if the new node's family name sorts first

        if (current_node->left == NULL) { // if the node has no left child
            current_node->left = new_node; // make the new node – the left child of the current node
        } else {
            insertTreeNode(current_node->left,
                           new_node); // recurse otherwise by moving to the left child of the current node
        }
    }
}

/** Function to print the created binary search tree in alphabetical order, uses in-order traversal
 *
 * @param tree_ptr the pointer to go through the tree
 */

void printByName(member_node_ptr tree_ptr) {
    if (tree_ptr != NULL) { // unless the end of the tree

        printByName(tree_ptr->left); // go through the left tree, since BST is ordered that way

        printSingleNode(tree_ptr); // printing by passing the current tree node

        printByName(tree_ptr->right); // go through the right tree once done with left tree
    }
}

/** Function to print our information held by the node
 *
 * @param tree_node the node we print information from
 */
void printSingleNode(member_node_ptr tree_node) {

    printf("\n==== MEMBER %d ====\n", tree_node->membership_id);
    printf("Family name: %s.\n Personal names: %s.\n Membership ID: %d.\n Email address: %s.\n Boat class: %s.\n Boat name: %s.\n",
           tree_node->family_name,
           tree_node->personal_names,
           tree_node->membership_id,
           tree_node->email_address,
           tree_node->boat_class,
           tree_node->boat_name);
}

/** Function to traverse a tree and perform a search
 *
 * @param tree_node the pointer moving across the tree
 * @param search_value the value imputed by the user which we'll be searching for
 * @param action what will be performed on each node we access
 * @return number more than 0 if the element was found
 */
int searchForTheNode(member_node_ptr tree_node, char *search_value, int (*action)(member_node_ptr, char *)) {

    int found_flag = 0; // flag to track whether or not element is in the BST

    if (tree_node->left != NULL) {
        found_flag += searchForTheNode(tree_node->left, search_value, action); // remains the same
    }

    if (action(tree_node, search_value) == 1) {
        found_flag++; // if value is in the tree increase by one
    }

    if (tree_node->right != NULL) {
        found_flag += searchForTheNode(tree_node->right, search_value, action); // remains the same
    }

    return found_flag; // returns value greater than 0 if elements are found

}

/** Function to search for the member in the BST by their membership id
 *
 * @param tree_node
 * @param search_value
 * @return 1 if element was found, 0 otherwise
 */

int searchForID(member_node_ptr tree_node, char *search_value) { //fix to enter details only once

    unsigned int search_id = (unsigned int) atoi(search_value); // converting the search value in an int

    if (tree_node->membership_id == search_id) { // if membership id of the node equals to the one we searching for
        printSingleNode(tree_node); // print node info
        return 1;
    }

    return 0;
}

/** Function to search for the owners of required boat class
 *
 * @param tree_node
 * @param search_value
 * @return 1 if element was found, 0 otherwise
 */

int searchForBoat(member_node_ptr tree_node, char *search_value) {

    if (strcmp(tree_node->boat_class, search_value) == 0) { // if the boat class of the boar equals to the one we searching for
        printSingleNode(tree_node); // print boat info
        return 1;
    }
    return 0;
}

/** Function to create the new member to the Binary Search Tree
 *
 * @param tree_root iterating using tree root to find an appropriate space to insert the node
 */
void createNewMember(member_node_ptr tree_root) {
    char new_family_name[21], new_personal_names[81], new_email_address[51], new_boat_class[31], new_boat_name[31]; // variables to store the newly created info
    unsigned int new_membership_id;

    // scan everything in
    printf("Please insert family name: ");
    scanf(" %[^\n]", new_family_name);
    printf("Please insert personal names: ");
    scanf(" %[^\n]", new_personal_names);
    printf("Please insert membership id: ");
    scanf(" %d", &new_membership_id);
    printf("Please insert email: ");
    scanf(" %[^\n]", new_email_address);
    printf("Please insert boat class: ");
    scanf(" %[^\n]", new_boat_class);
    printf("Please insert boat name: ");
    scanf(" %[^\n]", new_boat_name);

    if (tree_root != NULL) {
        insertTreeNode(tree_root, createTreeNode(new_family_name, new_personal_names, new_membership_id, // creating and inserting the node in appropriate place
                                                 new_email_address, new_boat_class, new_boat_name));
    }

    printByName(tree_root); // print updated BST
}

/** Function to open the members.txt file for writing
 *
 * @param filepath the name of the file to write the binary tree in
 * @param tree_node starting node for writing
 */
void updateTheTextFile(char filepath[201], member_node_ptr tree_node) {

    FILE * file;
    file = fopen(filepath, "w"); // open in the writing mode

    if (file == NULL) {
        printf("Error when writing to the file.\n");
        exit(1);
    }

    exportData(file, tree_node); // write to the file

    fclose(file);

    printf("==== DONE ====\n");

}
/** Function to write into the file, uses pre-order traversal
 *
 * @param file pointer to our file
 * @param tree_node with which we traversing the BST
 */

void exportData(FILE * file, member_node_ptr tree_node) {
    if (tree_node != NULL) { // unless no nodes left

        // overwrite all the data in the file with the data from nodes
        fprintf(file, "%s\n", tree_node->family_name);
        fprintf(file, "%s\n", tree_node->personal_names);
        fprintf(file, "%d\n", tree_node->membership_id);
        fprintf(file, "%s\n", tree_node->email_address);
        fprintf(file, "%s\n", tree_node->boat_class);
        fprintf(file, "%s\n", tree_node->boat_name);

        exportData(file, tree_node->left); // traverse through the left subtree
        exportData(file, tree_node->right); // traverse through the right subtree


    }
}



