#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include "bird.h"
#include "mammal.h"
#include "reptile.h"
using namespace std;


reptile* reptileRoot = NULL;
mammal* mammalRoot = NULL;
bird* birdRoot = NULL;




//a function that creates a new a BST mammal
mammal* newmammal(string n, int item, int l)    //Creates a new mammal pointer, name, length, litter and the left
{                                               //and right nodes to NULL
    mammal* current = new mammal;
    current->SetName(n);
    current->SetLength(item);
    current->litter = l;
    current->left = current->right = NULL;
    return current;                  //Returns the mammal object
}

// a function that inserts a new mammal with some length in a BST
mammal* insertMammal(mammal* mammal, string n, int length, int v)
{
    // When tree is empty, a new mammal is returned
    if (mammal == NULL)
        return newmammal(n, length, v);

    // Otherwise, recursive call
    if (length < mammal->GetLength())          //If length is smaller than the
        mammal->left = insertMammal(mammal->left, n, length, v);
    else
        mammal->right = insertMammal(mammal->right, n, length, v);

    // returning mammal pointer
    return mammal;
}
// Given a binary search tree and a length, this function deletes the length and returns the new root

mammal* deleteMammal(mammal* mammalRoot, string n, int k)
{
    // base case
    if (mammalRoot == NULL)
        return mammalRoot;

    // recursive calls, checking ansistors
    if (mammalRoot->GetLength() > k) {
        mammalRoot->left = deleteMammal(mammalRoot->left, n, k);
        return mammalRoot;
    }
    else if (mammalRoot->GetLength() < k) {
        mammalRoot->right = deleteMammal(mammalRoot->right, n, k);
        return mammalRoot;
    }

    // We reach here when mammalRoot is the node
    // to be deleted.

    // If one of the children is empty
    if (mammalRoot->left == NULL) {
        mammal* current = mammalRoot->right;
        if (mammalRoot->GetName().compare(n) == 0) {
            delete(mammalRoot);
        }
        return current;
    }
    else if (mammalRoot->right == NULL) {
        mammal* current = mammalRoot->left;
        if (mammalRoot->GetName().compare(n) == 0) {
            delete(mammalRoot);
        }
        return current;
    }

        // If both children exist
    else {

        mammal* succParent = mammalRoot->right;

        // Find successor
        mammal *succ = mammalRoot->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        succParent->left = succ->right;

        // Copy Successor Data to mammalRoot
        mammalRoot->SetLength(succ->GetLength());
        mammalRoot->SetName(succ->GetName());
        mammalRoot->litter = succ->litter;
        // Delete Successor and return mammalRoot
        if (succ->GetName().compare(n) == 0) {
            delete(succ);
        }
        return mammalRoot;
    }
}

// a function that does inorderMammal traversal of a BST
void inorderMammal(mammal* mammalRoot)
{
    if (mammalRoot != NULL) {
        inorderMammal(mammalRoot->left);
        cout << mammalRoot->GetName() << " " << mammalRoot->GetLength() << " " << mammalRoot->litter << " Mammal" << endl;
        inorderMammal(mammalRoot->right);
    }
}
// a function that does preorder traversal of a BST
void preorderMammal(mammal* mammalRoot)
{
    if (mammalRoot != NULL) {
        cout << mammalRoot->GetName() << " " << mammalRoot->GetLength() << " " << mammalRoot->litter << " Mammal" << endl;
        preorderMammal(mammalRoot->left);
        preorderMammal(mammalRoot->right);
    }
}
// a function that does postorder traversal of a BST
void postorderMammal(mammal* mammalRoot)
{
    if (mammalRoot != NULL) {
        postorderMammal(mammalRoot->left);
        postorderMammal(mammalRoot->right);
        cout << mammalRoot->GetName() << " " << mammalRoot->GetLength() << " " << mammalRoot->litter << " Mammal" << endl;
    }
}




// a function that creates a new a BST reptile
reptile* newreptile(string n, int item, string v)
{
    reptile* current = new reptile;
    current->SetName(n);
    current->SetLength(item);
    current->venom = v;
    current->left = current->right = NULL;
    return current;
}

// a function that does inorder traversal of a a BST
void inorderReptile(reptile* reptileRoot)
{
    if (reptileRoot != NULL) {
        inorderReptile(reptileRoot->left);
        cout << reptileRoot->GetName() << " " << reptileRoot->GetLength() << " " << reptileRoot->venom << " Reptile" << endl;
        inorderReptile(reptileRoot->right);
    }
}
// a function that does preorder traversal of a a BST
void preorderReptile(reptile* reptileRoot)
{
    if (reptileRoot != NULL) {
        cout << reptileRoot->GetName() << " " << reptileRoot->GetLength() << " " << reptileRoot->venom << " Reptile" << endl;
        preorderReptile(reptileRoot->left);
        preorderReptile(reptileRoot->right);
    }
}
// a function that does postorder traversal of a a BST
void postorderReptile(reptile* reptileRoot)
{
    if (reptileRoot != NULL) {
        postorderReptile(reptileRoot->left);
        postorderReptile(reptileRoot->right);
        cout << reptileRoot->GetName() << " " << reptileRoot->GetLength() << " " << reptileRoot->venom << " Reptile" << endl;
    }
}

// a function that inserts a new reptile with given length in a a BST
reptile* insertReptile(reptile* reptile, string n, int length, string v)
{
    // If the tree is empty, return a new reptile
    if (reptile == NULL)
        return newreptile(n, length, v);

    // Otherwise, recurse calls
    if (length < reptile->GetLength())
        reptile->left = insertReptile(reptile->left, n, length, v);
    else
        reptile->right = insertReptile(reptile->right, n, length, v);

    // return reptile pointer
    return reptile;
}
reptile* deleteReptile(reptile* reptileRoot, string n, int k)
{
    // Base case
    if (reptileRoot == NULL)
        return reptileRoot;

    // Recursive calls for ancestors of
    // node to be deleted
    if (reptileRoot->GetLength() > k) {
        reptileRoot->left = deleteReptile(reptileRoot->left, n, k);
        return reptileRoot;
    }
    else if (reptileRoot->GetLength() < k) {
        reptileRoot->right = deleteReptile(reptileRoot->right, n, k);
        return reptileRoot;
    }

    // We reach here when reptileRoot is the node
    // to be deleted.

    // If one of the children is empty
    if (reptileRoot->left == NULL) {
        reptile* current = reptileRoot->right;
        if (reptileRoot->GetName().compare(n) == 0) {
            delete(reptileRoot);
        }
        return current;
    }
    else if (reptileRoot->right == NULL) {
        reptile* current = reptileRoot->left;
        if (reptileRoot->GetName().compare(n) == 0) {
            delete(reptileRoot);
        }
        return current;
    }

        // If both children exist
    else {

        reptile* succParent = reptileRoot->right;

        // Find successor
        reptile *succ = reptileRoot->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        succParent->left = succ->right;

        // Copy Successor Data to reptileRoot
        reptileRoot->SetLength(succ->GetLength());
        reptileRoot->SetName(succ->GetName());
        reptileRoot->venom = succ->venom;
        // Delete Successor and return reptileRoot
        if (succ->GetName().compare(n) == 0) {
            delete(succ);
        }
        return reptileRoot;
    }
}




// a function that creates a new a BST bird
bird* newbird(string n, int item, string f)
{
    bird* current = new bird;
    current->SetName(n);
    current->SetLength(item);
    current->fly = f;
    current->left = current->right = NULL;
    return current;
}

// a function that does inorder traversal of a BST
void inorderBird(bird* birdRoot)
{
    if (birdRoot != NULL) {
        inorderBird(birdRoot->left);
        cout << birdRoot->GetName() << " " << birdRoot->GetLength() << " " << birdRoot->fly << " Bird" << endl;
        inorderBird(birdRoot->right);
    }
}
// a function that does preorder traversal of a BST
void preorderBird(bird* birdRoot)
{
    if (birdRoot != NULL) {
        cout << birdRoot->GetName() << " " << birdRoot->GetLength() << " " << birdRoot->fly << " Bird" << endl;
        preorderBird(birdRoot->left);
        preorderBird(birdRoot->right);
    }
}
// a function that does postorder traversal of a BST
void postorderBird(bird* birdRoot)
{
    if (birdRoot != NULL) {
        postorderBird(birdRoot->left);
        postorderBird(birdRoot->right);
        cout << birdRoot->GetName() << " " << birdRoot->GetLength() << " " << birdRoot->fly << " Bird" << endl;
    }
}

// a function that inserts a new bird with given length in a BST
bird* insertBird(bird* bird, string n, int length, string f)
{
    // If the tree is empty, return a new bird
    if (bird == NULL)
        return newbird(n, length, f);

    // Otherwise, recurse calls
    if (length < bird->GetLength())
        bird->left = insertBird(bird->left, n, length, f);
    else
        bird->right = insertBird(bird->right, n, length, f);

    // return bird pointer
    return bird;
}
bird* deleteBird(bird* birdRoot, string n, int k)
{
    // Base case
    if (birdRoot == NULL)
        return birdRoot;

    // Recursive calls for ancestors of
    // node to be deleted
    if (birdRoot->GetLength() > k) {
        birdRoot->left = deleteBird(birdRoot->left, n, k);
        return birdRoot;
    }
    else if (birdRoot->GetLength() < k) {
        birdRoot->right = deleteBird(birdRoot->right, n, k);
        return birdRoot;
    }

    // We reach here when birdRoot is the node
    // to be deleted.

    // If one of the children is empty
    if (birdRoot->left == NULL) {
        bird* current = birdRoot->right;
        if (birdRoot->GetName().compare(n) == 0) {
            delete(birdRoot);
        }
        return current;
    }
    else if (birdRoot->right == NULL) {
        bird* current = birdRoot->left;
        if (birdRoot->GetName().compare(n) == 0) {
            delete(birdRoot);
        }
        return current;
    }

        // If both children exist
    else {

        bird* succParent = birdRoot->right;

        // Find successor
        bird *succ = birdRoot->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        succParent->left = succ->right;

        // Copy Successor Data to birdRoot
        birdRoot->SetLength(succ->GetLength());
        birdRoot->SetName(succ->GetName());
        birdRoot->fly = succ->fly;
        // Delete Successor and return birdRoot
        if (succ->GetName().compare(n) == 0) {
            delete(succ);
        }
        return birdRoot;
    }
}





//Find Part
int findMammal(mammal* mammalRoot, string n, int val)
{
    if (mammalRoot != NULL) {
        val = findMammal(mammalRoot->left, n, val);
        val = findMammal(mammalRoot->right, n, val);
        if (mammalRoot->GetName().compare(n) == 0) {
            cout << mammalRoot->GetName() << " " << mammalRoot->GetLength() << " " << mammalRoot->litter << " Mammal" << endl;
            return val + 1;
        }
    }
    return val;
}

int findBird(bird* birdRoot, string n, int val)
{
    if (birdRoot != NULL) {
        val = findBird(birdRoot->left, n, val);
        val = findBird(birdRoot->right, n, val);
        if (birdRoot->GetName().compare(n) == 0) {
            cout << birdRoot->GetName() << " " << birdRoot->GetLength() << " " << birdRoot->fly << " Bird" << endl;
            return val + 1;
        }
    }
    return val;
}
int findReptile(reptile* reptileRoot, string n, int val)
{
    if (reptileRoot != NULL) {
        val = findReptile(reptileRoot->left, n, val);
        val = findReptile(reptileRoot->right, n, val);
        if (reptileRoot->GetName().compare(n) == 0) {
            cout << reptileRoot->GetName() << " " << reptileRoot->GetLength() << " " << reptileRoot->venom << " Reptile" << endl;
            return val + 1;
        }
    }
    return val;
}
void find(string n) {
    int foundM = 0, foundR = 0, foundB = 0;
    //cout << "Finding" << endl;
    foundM = findMammal(mammalRoot, n, 0);
    foundR = findReptile(reptileRoot, n, 0);
    foundB = findBird(birdRoot, n, 0);
    cout << "Found Results: " << foundM << ", " << foundR << ", " << foundB << " in Mammals, Reptiles and Birds respectively" << endl;
}
///**********************************
//            Remove Part              //
///**********************************
int removeMammal(mammal* mammalRoot, string n, int val)
{
    if (mammalRoot != NULL) {
        val = removeMammal(mammalRoot->left, n, val);
        val = removeMammal(mammalRoot->right, n, val);
        if (mammalRoot->GetName().compare(n) == 0) {
            cout << mammalRoot->GetName() << " " << mammalRoot->GetLength() << " " << mammalRoot->litter << " Mammal" << endl;
            return mammalRoot->GetLength();
        }
    }
    return val;
}
int removeBird(bird* birdRoot, string n, int val)
{
    if (birdRoot != NULL) {
        val = removeBird(birdRoot->left, n, val);
        val = removeBird(birdRoot->right, n, val);
        if (birdRoot->GetName().compare(n) == 0) {
            cout << birdRoot->GetName() << " " << birdRoot->GetLength() << " " << birdRoot->fly << " Bird" << endl;
            return birdRoot->GetLength();
        }
    }
    return val;
}
int removeReptile(reptile* reptileRoot, string n, int val)
{
    if (reptileRoot != NULL) {
        val = removeReptile(reptileRoot->left, n, val);
        val = removeReptile(reptileRoot->right, n, val);
        if (reptileRoot->GetName().compare(n) == 0) {
            cout << reptileRoot->GetName() << " " << reptileRoot->GetLength() << " " << reptileRoot->venom << " Reptile" << endl;
            return reptileRoot->GetLength();
        }
    }
    return val;
}
void remove(string n) {
    int lengthM = 0, lengthR = 0, lengthB = 0;
    //cout << "Finding" << endl;
    lengthM = removeMammal(mammalRoot, n, 0);
    lengthR = removeReptile(reptileRoot, n, 0);
    lengthB = removeBird(birdRoot, n, 0);
    cout << "Deleting " << ((lengthM != 0) ? lengthM : (lengthR != 0) ? lengthR : lengthB) << endl;
    mammalRoot = deleteMammal(mammalRoot, n, lengthM);
    reptileRoot = deleteReptile(reptileRoot, n, lengthR);
    birdRoot = deleteBird(birdRoot, n, lengthB);
}


//Command Processing Part
//Processing String for commands function
int* commandProc(string n)
{
    string delimiter = " ";
    //cout << "Processing" << endl;
    size_t pos = 0;
    string token;
    if ((pos = n.find(delimiter)) != string::npos) {
        token = n.substr(0, pos);						//To find out the command and store it on token variable
        //cout << token << "Done" << endl;
        if (token.compare("Insert") == 0) {					//Checks for the Insert Command
            n.erase(0, pos + delimiter.length());
            if ((pos = n.find(delimiter)) != string::npos) {
                token = n.substr(0, pos);
                //cout << token << "Done" << endl;
                if (token.compare("reptile") == 0) {						//To check if the mammal command is
                    n.erase(0, pos + delimiter.length());					//entered to add a node with the following
                    int i = 0;								//information
                    string name;
                    int length;
                    string venom;
                    while (((pos = n.find(delimiter)) != string::npos) && i < 3) {
                        token = n.substr(0, pos);
                        //cout << token;
                        if (i == 0) name = token;
                        else if (i == 1) { length = stoi(token); }
                        else {
                            if ((token.compare("venomous") == 0) || (token.compare("non-venomous") == 0)) {
                                venom = token;
                            }
                            else {
                                cout << n << ": Cannot Process; Try <venomous|non-venomous>" << endl;
                            }
                        }
                        n.erase(0, pos + delimiter.length());
                        i++;
                    }
                    if (i == 2) {
                        if ((n.compare("venomous") == 0) || (n.compare("non-venomous") == 0)) {
                            venom = n;
                        }
                        else {
                            cout << n << ": Cannot Process; Try <venomous|non-venomous>" << endl;
                        }
                    }
                    if (i < 2) {
                        cout << "reptile syntax Error" << endl;
                        exit(0);
                    }
                    //cout << name << " " << length << " " << venom << endl;
                    reptileRoot = insertReptile(reptileRoot, name, length, venom);
                }
                else if (token.compare("mammal") == 0) {						//To check if the reptile command is
                    n.erase(0, pos + delimiter.length());					//entered to add a node with the following
                    int i = 0;								//information
                    string name;
                    int length;
                    int litter;
                    while (((pos = n.find(delimiter)) != string::npos) && i < 3) {
                        token = n.substr(0, pos);
                        //cout << token;
                        if (i == 0) name = token;
                        else if (i == 1) { length = stoi(token); }
                        else { litter = stoi(token); }
                        n.erase(0, pos + delimiter.length());
                        i++;
                    }
                    if (i == 2) {
                        litter = stoi(n);
                    }
                    if (i < 2) {
                        cout << "mammal syntax Error" << endl;
                        exit(0);
                    }
                    //cout << name << " " << length << " " << venom << endl;
                    mammalRoot = insertMammal(mammalRoot, name, length, litter);
                }
                else if (token.compare("bird") == 0) {						//To check if the bird command is
                    n.erase(0, pos + delimiter.length());					//entered to add a node with the following
                    int i = 0;								//information
                    string name;
                    int length;
                    string fly;
                    while (((pos = n.find(delimiter)) != string::npos) && i < 3) {
                        token = n.substr(0, pos);
                        //cout << token;
                        if (i == 0) name = token;
                        else if (i == 1) { length = stoi(token); }
                        else {
                            if ((token.compare("can-fly") == 0) || (token.compare("cannot-fly") == 0)) {
                                fly = token;
                            }
                            else {
                                cout << token << ": Cannot Process; Try <can-fly|cannot-fly>" << endl;
                            }
                        }
                        n.erase(0, pos + delimiter.length());
                        i++;
                    }
                    if (i == 2) {
                        if ((n.compare("can-fly") == 0) || (n.compare("cannot-fly") == 0)) {
                            fly = n;
                        }
                        else {
                            cout << n << ": Cannot Process; Try <can-fly|cannot-fly>" << endl;
                        }
                    }
                    if (i < 2) {
                        cout << "bird syntax Error" << endl;
                        exit(0);
                    }
                    //cout << name << " " << length << " " << venom << endl;
                    birdRoot = insertBird(birdRoot, name, length, fly);
                }
                else {
                    cout << "Insert Syntax Error" << endl;		//If any Insert syntax error if found
                    exit(0);
                }
            }
            else {
                cout << "Insert Syntax Error" << endl;			//If any Insert syntax error if found
                exit(0);
            }
        }
        else if (token.compare("Find") == 0) {					//Checks if the command is Find Command
            n.erase(0, pos + delimiter.length());				//And executes the steps as below
            if ((pos = n.find(delimiter)) != string::npos) {
                token = n.substr(0, pos);
                n.erase(0, pos + delimiter.length());
                find(token);						//calls the find function to process it
            }
            else
                find(n);
        }
        else if (token.compare("Remove") == 0) {					//Checks if the command is Remove Command
            n.erase(0, pos + delimiter.length());				//And executes the steps as below
            if ((pos = n.find(delimiter)) != string::npos) {
                token = n.substr(0, pos);
                n.erase(0, pos + delimiter.length());
                remove(token);						//Calls the remove function to process further
            }
            else
                remove(n);
        }
        else {
            cout << token << ": Unknown Command" << endl;			//if the command is unknown
        }
    }
    else {
        cout << n << ": Unknown Command" << endl;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    string n = string("Jewel");
    string s;
    ifstream infile;
    infile.open("test.txt");
    if (argc == 2) {
        infile.close();
        infile.open(argv[1]);
    }
    while (getline(infile, s)) {
        commandProc(s);
    }
    cout << endl;
    printf("Reptile BST InOrder Travesal -> \n");
    inorderReptile(reptileRoot);
    cout << endl;
    printf("Mammal BST InOrder  -> \n");
    inorderMammal(mammalRoot);
    cout << endl;

    printf("Bird BST InOrder Traversal -> \n");
    inorderBird(birdRoot);
    cout << endl;



    infile.close();
    return 0;
}


/////////////////////////////









