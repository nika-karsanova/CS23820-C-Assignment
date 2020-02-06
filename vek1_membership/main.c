#include "membership.h"

int main() {
    int menuOption, end;
    char new_family_name[21], new_personal_names[81], new_email_address[51], new_boat_class[31], new_boat_name[31]; // variables to store the member data
    char search_value[31]; // variable to in which we store user's input for searching
    unsigned int new_membership_id;
    char filepath[201];
    member_node_ptr tree_root = NULL;
    FILE * file;

    printf("Please insert the file directory: \n"); // in the format ../../data-set-one/members.txt
    scanf("%200s", filepath);

    if ((file = fopen(filepath, "r")) == NULL) { // if file not found
        printf("Error when opening the file.\n");
        exit(1);
    }

    while (1) {
        end = fscanf(file, " %[^\n] %[^\n] %d %[^\n] %[^\n] %[^\n]", new_family_name, new_personal_names, // read in the data line by line
                     &new_membership_id, new_email_address, new_boat_class, new_boat_name);
        if (end == EOF) { // break if end of file
            break;
        }

        if (tree_root == NULL) { // if the tree root is NULL it just created the node and leaves it as is
            tree_root = createTreeNode(new_family_name, new_personal_names, new_membership_id, new_email_address,
                                       new_boat_class, new_boat_name);
        } else { // otherwise, add member node to the appropriate place in the data structure
            insertTreeNode(tree_root,
                           createTreeNode(new_family_name, new_personal_names, new_membership_id, new_email_address,
                                          new_boat_class, new_boat_name));
        }

    }
    fclose(file); // close the file once the binary tree is created

    do { // our menu
        printMenu();
        printf("Please input what you would like to do: ");
        scanf(" %d", &menuOption);
        printf("\n");
        switch (menuOption) {
            case 1:
                // Display the membership list by family name
                printf("Displaying all the club members: \n");
                printf("\n");
                printByName(tree_root); // print in alphabetical order starting at the root
                break;
            case 2:
                // Display details by the membership id
                printf("Please provide ID to search for: ");
                scanf(" %[^\n]", search_value);
                if (searchForTheNode(tree_root, search_value, &searchForID) == 0) {
                    printf("No members have an ID of %s.\n", search_value);
                }
                break;
            case 3:
                // Owners of boats of a given class
                printf("Please provide boat class to search for: ");
                scanf(" %[^\n]", search_value);
                if (searchForTheNode(tree_root, search_value, &searchForBoat) == 0) {
                    printf("No members have the boat class of %s.\n", search_value);
                }
                break;
            case 4:
                // add a new member
                createNewMember(tree_root);
                break;
            case 5:
                // save updated binary tree to the file
                updateTheTextFile(filepath, tree_root);
                break;
            case 6:
                printf("Thank you for using our membership program, see you next time!");
                break;
            default:
                printf("Oh no, something went wrong! Please try again or seek assistance");
                break;
        }

    } while (menuOption != 6);

}