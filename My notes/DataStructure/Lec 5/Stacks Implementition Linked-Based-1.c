
//Implementation Level

            typedef struct stacknode{
                struct stacknode *next;
                StackEntry entry;
                }StackNode;
                 
            typedef struct stack{
                StackNode *top;
            }Stack;

           /*Complexity O(1)*/ void CreateStack(Stack *ps){
                ps->top=NULL; //just to make sure that is pointer pointing to null
                // Same as '*ps.top=NULL'

            }

            /*Complexity O(1)*  /*Pre : The stack is initialized
            Post : creating new StackNode let pn points to the old top and let ps points to new node*/
                              void Push(StackEntry e,Stack*ps){
                              StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
                              pn->entry=e;
                              pn->next=ps->top;
                              ps->top=pn; 
                               
             }
         

                               
         /*Complexity O(1)* /*Pre : The stack is initialized & not empty
            Post : let ps points to next of pe and return e,remove old pe*/
                   void Pop(StackEntry *pe,Stack *ps){
                       StackNode *pn;
                      *pe=ps->top->entry; //till here that is only way to StackTop fn
                      pn= ps->top; //temp pointer
                      ps->top=ps->top->next;
                      free(pn); //that is mean data still there but it is free index can any one use it
                       

                   }
                   /*Pre : The stack exists
                   Post : returns if empty (1),or not (0)*/
                   int StackEmpty(Stack *ps){
                       return ps->top==NULL;// or ' return !ps->top'
                   }
                   /*Pre : The stack exists
                   Post : returns if full (1),or not (0)*/
                    int StackFull(Stack *ps){
                        return 0;
                   }

