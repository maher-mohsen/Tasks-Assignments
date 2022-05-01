//Implementation Level

typedef struct queue{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;


/*Pre : Queue is decaled
  Post : Intitalize Queue */
void CreateQueue(Queue *pq){
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
/*Pre : Queue is intitalized 
  Post : Push Element in tail of queue*/
void Append(QueueEntry e,Queue* pq){
    pq->rear = (pq->rear+1)%MAXQUEUE;
    pq->entry[pq->rear]=e;
    pq->size++;
}
/*Pre : Queue is intiatalized 
  Post : Serve First Input*/
void Serve (QueueEntry *pe,Queue *pq){
    *pe=pq->entry[pq->front];
    pq->front=(pq->front+1)%MAXQUEUE;
    size--;
}

/*Pre : Queue is intiatalized 
  Post : Empty or not*/
int QueueEmpty(Queue *pq){
    return !pq->size;
}

/*Pre : Queue is intiatalized 
  Post : Full or not*/
int QueueFull(Queue *pq){
    return (pq->size==MAXQUEUE);
}
/*Pre : Queue is intiatalized 
  Post : return size*/
int QueueSize(Queue *pq){
    return pq->size;
}
/*Pre : Queue is intiatalized 
  Post : Re-Initiatalized*/
void ClearQueue (Queue *pq){
    pq->front=0;
    pq->rear=-1;
    pq_size=0;
}



/*Pre : Queue is intiatalized
  Post : Passing all elements by User's Function*/
void TraverseQueue (Queue *pq,void(*pf)(QueueEntry)){
    int pos,s;
        for(pos=pq->front,s=0;s<pq->size;s++){
        (*pf)(pq->entry[pos]);
            pos=(pos+1)%MAXQUEUE;
            }

}









//User Level
void main(){
Queue q;
CreateQueue(&q);
}