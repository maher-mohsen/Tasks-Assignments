

//Implementation Level

            typedef struct stack{
                int top;
                StackEntry entry[MAXSTACK];
                }Stack;

           /*Complexity O(1 )*/ void CreateStack(Stack *ps){
                ps->top=0; //just to make sure that is first element to output is zero
                // Same as '*ps.top=0'

            }

            /*Pre : The stack is initialized and not full
            Post : the element e has been stored at the top of stackn and e does not change V 1.0*/
                              void Push(StackEntry e,Stack*ps){
                              ps->entry[ps->top++]=e;//first access entry then top and store value of e,Increment Top to next push

                               
             }
            /*Pre : The stack is initialized 
            Post : Grantee that stack not full & the element e has been stored at the top of stackn and e does not change V 1.0*/
                              int Push(StackEntry e,Stack*ps){
                                  if(ps->top==MAXSTACK){
                                      return 0;
                                  }
                                  else{
                                     ps->entry[ps->top++]=e;//first access entry then top and store value of e,Increment Top to next push
                                        return 1;
                                  }

                               
             }
            /*Pre : The stack is initialized 
            Post : Grantee that stack full or not*/
                              int StackFull(Stack*ps){
                                  if(ps->top==MAXSTACK){
                                      return 1;
                                  }
                                  else{
                                        return 0;
                                  }

                               
             } 

              /*Pre : The stack is initialized 
            Post : Grantee that stack empty or not*/
                              int StackEmpty(Stack*ps){
                                  if(ps->top==0){
                                      return 1;
                                  }
                                  else{
                                        return 0;
                                  }

                               
             }    
            /*Pre : The stack is initialized 
            Post : Grantee that stack empty or not*/
                              int StackEmpty(Stack*ps){
                                  return !ps->top;                
             }  
           /*Pre : The stack is initialized 
            Post : Grantee that stack full or not V2*/
                              int StackFull(Stack*ps){
                                 return ps->top>=MAXSTACK;
                                  }

                               
          /*Pre : The stack is initialized & not empty
            Post : poping last input*/
                   int Pop(StackEntry *pe,Stack *ps){
                       if(!(!ps->top)){
                            return 0;
                       }
                       else{
                           *pe=ps->entry[--ps->top ]; 
                       }
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
        /*Pre : The stack is initialized 
          Post : just return size of stack*/
                int StackSize(Stack*ps){
                    return ps->top;
                }
        /*Pre : The stack is initialized 
          Post : destroy all elements ,stack looks intialized*/
                void ClearStack(Stack*ps){
                    ps->top=0;
                }

                /*Pre : the Stackis initialized
          post : just passing all elements without changes                                      */    
                void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
                   //Method 1 
                   for(int i=ps->top;i>0;i--)
                        (*pf)(ps->entry[i-1]);

                /*Method 2
                    int i=(ps->top)-1
                    while(i--){
                        (*pf)(ps->entry[i])
                    }   
                */

                }

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
            Stack s;  //Going to memory to reserveing some contigous addresses with first address name s (Garabge)
            CreateStack(&s); //Let top =0
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
