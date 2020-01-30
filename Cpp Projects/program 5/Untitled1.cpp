#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node *pNext;
};
 
 
//------------------------------------------------------
void displayList( Node *pHead)
{
    while( pHead != NULL) {
        cout << pHead->data << " ";
        pHead = pHead->pNext;   // Advance to the next node
    }
    cout << endl;
}
 
 
//------------------------------------------------------
// Prepend this number in front of the current head of the list.
void prepend( Node *&pHead, int userInput)
{
    Node *pTemp = new Node;
    pTemp->data = userInput;
    pTemp->pNext = pHead;
    pHead = pTemp;
}
 
//------------------------------------------------------
Node *findLastNodeOnList( Node *pTemp)
{
    while( pTemp != NULL && pTemp->pNext != NULL) {
        pTemp = pTemp->pNext;
    }
     
    return pTemp;
}
 
 
//------------------------------------------------------
void append( Node *&pHead, int userInput)
{
    // Get a new node and put the data in it
    Node *pTemp = new Node;
    pTemp->data = userInput;
    pTemp->pNext = NULL;
     
    // Connect the new node at the end of the list
    // First find the last node on the list
    Node *pLastNode = findLastNodeOnList( pHead);
    if( pLastNode == NULL) {
        pHead = pTemp;
    }
    else {
        pLastNode->pNext = pTemp;
    }
}
     
 
//------------------------------------------------------
void recursiveDeleteList( Node *pHead)
{
    // Base condition
    if( pHead == NULL) {
        return;
    }
    else {
        // Recursive step
        recursiveDeleteList( pHead->pNext);
        cout << "About to delete " << pHead->data << endl;
        delete pHead;
    }
}
 
 
//------------------------------------------------------
Node * deleteList( Node *pHead)
{
    Node *pTemp;
    while( pHead != NULL){
        pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
    }
     
    return pHead;   
}
 
//------------------------------------------------------
int countNodes( Node *pTemp)
{
    int count = 0;
    while( pTemp!=NULL) {
        pTemp=pTemp->pNext;
        count++;
    }
    return count;   
}
 
 
//------------------------------------------------------
void insertInOrder( Node *&pHead, int userInput) 
{
    Node *pNewNode;
     
    // If list is empty, insert the first node
    if( pHead == NULL) {
        pHead = new Node;
        pHead->data = userInput;
        pHead->pNext = NULL;
    }
    else {
        if( userInput < pHead->data){
            // Insert new node before the list head
            pNewNode = new Node;
            pNewNode->data = userInput;
            pNewNode->pNext = pHead;
            pHead = pNewNode;
        }
    }
}
 
     
//------------------------------------------------------
int main()
{
    int userInput;
    Node *pHead = NULL;
    Node *pLastNode;
     
    cout << "Enter numbers for list, followed by -1: ";
    cin >> userInput;
     
    // Keep looping until end of input flag of -1 is given
    while( userInput != -1) {
        // prepend( pHead, userInput);   // Add new node before the current list head
        // append( pHead, userInput);      // Add new node after the current end of list
        insertInOrder( pHead, userInput);  // Insert nodes in ascending order
 
        // cout << "Last node has value: " << pLastNode->data << endl;
        cin >> userInput;
    }
     
    // Display first list
    cout << "List is: ";
    displayList( pHead);
     
    // Display number of nodes on the list
    cout << "Number of nodes on list is: " << countNodes( pHead) << endl;
     
    // pHead = deleteList( pHead);
    // recursiveDeleteList( pHead);
 
     
    return 0;
}
