typedef struct treenode{
    TreeEntry entry;
    struct treenode *left,*right;
}TreeNode;
typedef struct tree{
    TreeNode* root;
    int size;
    int depth;
}Tree;

/*Pre : Tree Is decalred
Post : Tree is Intialezed and ready to use*/
    void CreateTree(Tree*pt){
        pt->root=NULL;
        pt->depth=0;
        pt->size=0;
    }
/*Pre : Tree Is decalred
Post : return if tree is empty*/
    int TreeEmpty(Tree *pt){
        return(!pt->root);
    }
/*Pre : Tree Is decalred
Post : Return if tree is full and always return zero*/
    int TreeFull(Tree*pt){
        return 0;
    }
/*Pre : Tree Created
Post : Traverse between all elements by a function (inorder traverse)*/
    void InorderRec(Tree*pt,void(*pvisit)(TreeEntry)){
        if(*pt){
            InorderRec(&(*pt)->left,pvisit);
            (*pvisit)((*pt)->entry);
            InorderRec(&(*pt)->right,pvisit);
        }
    }
/*Pre : Tree Created
Post : Tree be Cleared V 1.0*/
    void ClearTreeRec(Tree* pt){
        if(*pt){
            ClearTreeRec(&(*pt)->left);
            ClearTreeRec(&(*pt)->right);
            free(*pt);
            *pt=NULL;
        }
    }
/*Pre : Tree Created
Post : Tree be Cleared V 1.1 (!!We don't need to make pt equals null every call anyways all nodes will be deleted so we can use an Aux Fun to call ClearTree and then make last pt equal null (Faster))*/
    void ClearTreeRecAux(Tree* pt){
        if(*pt){
            ClearTreeRec(&(*pt)->left);
            ClearTreeRec(&(*pt)->right);
            free(*pt);
        }
    }

    void ClearTreeRec(Tree* pt){
       ClearTreeRecAux(pt);
       *pt=NULL;
    }
