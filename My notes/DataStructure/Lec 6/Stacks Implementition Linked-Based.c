

//Implementation Level

            typedef struct stacknode{
                struct stacknode *next;
                StackEntry entry;
                }StackNode;
                 
            typedef struct stack{
                StackNode *top;
                int size;
            }Stack;

           /*Complexity O(1)*/ void CreateStack(Stack *ps){
                ps->top=NULL; //just to make sure that is pointer pointing to null
                // Same as '*ps.top=NULL'
                ps->size=0;

            }

            /*Complexity O(1)*  /*Pre : The stack is initialized
            Post : creating new StackNode let pn points to the old top and let ps points to new node*/
                              void Push(StackEntry e,Stack*ps){
                              StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
                              pn->entry=e;
                              pn->next=ps->top;
                              ps->top=pn; 
                              ps->size++;
                               
             }
         

                               
         /*Complexity O(1)* /*Pre : The stack is initialized & not empty
            Post : let ps points to next of pe and return e,remove old pe*/
                   void Pop(StackEntry *pe,Stack *ps){
                       StackNode *pn;
                      *pe=ps->top->entry; //till here that is only way to StackTop fn
                      pn= ps->top; //temp pointer
                      ps->top=ps->top->next;
                      free(pn); //that is mean data still there but it is free index can any one use it
                      ps->size--;

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


          /*Pre : The stack is initialized & not empty
            Post : just return copy from last input*/
                   int StackTop(StackEntry *pe,Stack *ps){
                       if(!(!ps->top)){
                            return 0;
                       }
                       else{
                           *pe=ps->entry[ps->top-1 ]; 
                       }
                   }
        /*Complexity O(1)*/ /*Pre : The stack is initialized 
          Post : just return size of stack*/
                int StackSize(Stack*ps){
                   return ps->size;
                }
        /*Pre : The stack is initialized 
          Post : all the elemnts freed V 1.0*/
                void ClearStack(Stack*ps){
                    StackNode *pn=ps->top;
                    StackNode *qn=ps->top;
                    while(pn){
                    pn=pn->next;
                    free(qn);
                    qn=pn;
                    }
                    ps->top=NULL;
                    ps->size=0;
                }

        /*Complexity O(n)*/ /*Pre : The stack is initialized 
          Post : all the elemnts freed V 1.1*/
                void ClearStack(Stack*ps){
                    StackNode *pn=ps->top;
                    while(pn){
                    pn=pn->next;
                    free(ps->top);
                    ps->top=pn;
                    }
                    ps->size=0;
                }

       /*Complexity O(n)*/  /*Pre : the Stackis initialized
          post : just passing all elements without changes                                      */    
                void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
                      for(StackNode *pn=ps->top;pn; pn=pn->next)
                             (*pf)(pn->entry);
                   }
                   /*Another Style :
                        StackNode *pn=ps->top;
                   while(pn){
                       (*pf)(pn->entry);
                       pn=pn->next;
                       }
                   */
                

            

//User Level

        void StackTop(StackEntry *pe,Stack *ps){
            Pop(pe,ps); //Where is '&'?!.... Remember pe and ps already addresses!!
            Push(*pe,ps); //Passing *pe?!.....Push waiting for an element and pe is a pointer !
        }




            void Display(StackEntry e){
                    printf("e is: %d\n", e);
            }

        void main(){
            StackEntry e;
            Stack s;  //Going to memory to reserveing one pointer called s(Garabge)
            CreateStack(&s); //Let pointer =NULL
           if(!Push(e,&s)) ;
           //we can also use :
           if(!StackFull(&s)){
               Push(e,&s);
           }
           if(!Pop(&e,&s));
           if(!StackEmpty(&s)){
               Pop(e,&s);
           }
           if(!StackTop(&e,&s));
           int x=StackSize(&s);
        }
