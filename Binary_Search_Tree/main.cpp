#include <iostream>

/* BINARY TREE SEARCH
- Ung dung: Tra tu dien, tra cuu thong tin
- Thao tac: Khoi tao, chen, XOA, tim kiem, duyet theo thu tu


*/
using namespace std;

// Khoi tao cay (ban dau root = NULL)
struct BNode {
    int data;
    struct BNode *pLeft;
    struct BNode *pRight;
};
typedef struct BNode BNode;

BNode* CreatNode(int value) {
    BNode *p = new BNode;
    if (p == NULL)
    {
        cout << "Out of memory!";

    }
    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;

    return p;
}
// Chen node
BNode* InsertNode(BNode* nodePtr, int value)  //nodePtr: con tro de duyet tu goc den vi tri cha cua nut moi
{
    /*Neu cay rong thi return new node*/
    if (nodePtr == NULL)
        return CreatNode(value);
    /*Otherwise, recur down the tree (di xuong phia duoi)*/
    else if (value < nodePtr->data)
    {
        nodePtr->pLeft = InsertNode(nodePtr->pLeft, value); //di chuyen sang trai
    }
    else if (value > nodePtr->data)
    {
        nodePtr->pRight = InsertNode(nodePtr->pRight, value); //di chuyen sang phai
    }
    /*Return the node (unchange-root) node pointer */
    return nodePtr;         //Tra lai node goc (root) ban dau

}

/* Tim kiem trong cay, tra lai dia chi node x neu tim thay*/
BNode* Search(BNode *root, int x)
{
    if (root == NULL)
        return NULL;
    else if (root->data == x)
        return root;
    else if (x < root->data)
    {
        return Search(root->pLeft, x);       //Tim sang trai
    }
    else if (x > root->data)
    {
        return Search(root->pRight, x);      //Tim sang phai
    }
}
/* Nhap cay */
void CreatTree(BNode* &root)
{
    int x = 1;
    do {
        cout << "Nhap node (nhap 0 de dung lai): ";
        cin >> x;
        if (Search(root, x) != NULL)    //gia tri node da co trong tree
        {
            cout << "Node da ton tai"<<endl;
            continue;
        }
        else if (x != 0)
            root = InsertNode(root, x);
    } while (x != 0);
}
//FIND MIN : con trai nhat
BNode* FindMin(BNode* T)
{
    while (T->pLeft != NULL)
    {
        T = T->pLeft;
    }
    return T;           //Tra lai node min
}
//DELETE NODE
/* Xoa node :
    - Node ko con: Bo lien ket toi cha
    - Node 1 con: Xoa no va lien ket con cua x voi cha cua x
    - Neu 2 con :
        +Tim node y la gia tri nho nhat cua cay con phai cua x
        +Go y ra khoi cay
        +Noi con phai cua y vao cha cua y
        +Thay the node x bang node y
*/
BNode* DeleteNode(BNode* T, int x)       //Xoa NODE co gia tri x
{
    BNode* Temp;
    /* base case */
    if (T == NULL)
        return T;
    //Duyet tim vi tri cua key
    if (x < T->data)
        T->pLeft = DeleteNode(T->pLeft, x);
    else if (x > T->data)
        T->pRight = DeleteNode(T->pRight, x);
    else {
        //Neu 2 con
        if (T->pLeft && T->pRight)
        {
            Temp = FindMin(T->pRight);
            T->data = Temp->data;                            //Thay the node x boi min con phai
            T->pRight = DeleteNode(T->pRight, T->data);     //Xoa temp (min con phai)
        }
        else {
            /*Co 1 hoac 0 con */
            if (T->pLeft == NULL)      //Chi co con phai or ko con
                T = T->pRight;        // T = con phai neu 1 con : T = NULL neu ko con
            else if (T->pRight == NULL)
                T = T->pLeft;
        }
    }
    return T;

}
// Print InOder (In theo thu tu giua)
void PrintInOrder(BNode* root)
{
    if (root != NULL)
    {
        PrintInOrder(root->pLeft);
        cout << root->data <<endl;
        PrintInOrder(root->pRight);
    }
}

int main()
{
    BNode *root = NULL;

    CreatTree(root);

    /*Duyet cay theo InOrder */
    cout << "Duyet cay theo thu tu giua la:"<<endl;
    PrintInOrder(root);

    /*Tim kiem
    int x;
    cout << "Nhap key tim kiem: ";
    cin >> x;
    BNode *result = Search(root, x);
    if (result == NULL)
        cout << "Ko tim thay key trong tree";
    else
        cout << "Tim thay "<< result->data<<endl;
    */
    int key;
    cout << "Nhap node can xoa: ";
    cin >> key;
    DeleteNode(root, key);
    PrintInOrder(root);

    return 0;
}
