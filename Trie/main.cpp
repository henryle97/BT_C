#include <iostream>
#include <string>

using namespace std;

const int MAX = 26;
struct TrieNode {
    struct TrieNode *children[MAX];  // mang con tro chua 26 ky tu
    bool isEnd;                     //true neu la leaf
};
typedef struct TrieNode TrieNode;

//Tao node voi cac con la NULL
TrieNode *getNode(void)
{
    TrieNode *pNode = new TrieNode;

    for (int i = 0; i < MAX; i++)
    {
        pNode->children[i] = NULL;
    }
    pNode->isEnd = false;

    return pNode;
}

// Chen node
void insertTrie(TrieNode *head, string key)
{
    TrieNode *pDuyet = head;
    for (int i = 0; i < key.length(); i++)          //Duyet tung ky tu cua key
    {
        int id = (int)(key[i] - 'a');
        if (pDuyet->children[id] == NULL)            //Neu con dang NULL thi them vao
            pDuyet->children[id] = getNode();
        pDuyet = pDuyet->children[id];
    }
    pDuyet->isEnd = true;
}
//Kiem tra da duyet het chua
// return 0 neu node hien tai van dang co con
// return 1 neu all con deu NULL
int isLastNode(TrieNode *head)
{
    for (int i = 0; i < MAX; i++)
    {
        if (head->children[i] != NULL)
            return 0;
    }
    return 1;                   //La node cuoi cung cua cay
}

void goiy(TrieNode *head, string iPrefix)
{
    if (head->isEnd == true)       //Ket thuc 1 tu( buoc co so)
        cout << iPrefix;
        cout << endl;
    if (isLastNode(head))       //Tat ca cac con deu la NULL
        return;
    for (int i = 0; i < MAX; i++)
    {
        if (head->children[i] != NULL)      //!= NULL
        {
            iPrefix.push_back(97 + i);
            goiy(head->children[i], iPrefix);
        }
    }
}

int printAutoGoiY(TrieNode *head, const string query)
{
    TrieNode *pDuyet = head;
    int n = query.length();
    for (int i = 0; i < n; i++)
    {
        int id = (int )(query[i]);
        if (pDuyet->children[id] != NULL)
            return 0;

        pDuyet = pDuyet->children[id];
    }
    bool isWord = (pDuyet->isEnd == true);

    bool isLast = isLastNode(pDuyet);

    if (isWord && isLast)
    {
        cout << query <<endl;
        return -1;
    }

    if (!isLast)
    {
        string prefix = query;
        goiy(pDuyet, prefix);
        return 1;
    }
}
int main()
{
    TrieNode *root = getNode();
    insertTrie(root, "hoy");
    insertTrie(root, "hoanh");
    printAutoGoiY(root, "h");
    return 0;
}
