#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int no_vertices;
struct node{
    int data;
    struct node*next;
};
void readgraph(struct node *adj[]) {
   struct node* newnode;
   int k,data;
   for(int i=0;i<no_vertices;i++) {
        struct node*last=NULL;
        printf("\nNo. of vertices adjacent to %d:",i);
        scanf("%d",&k);
        for(int j=1;j<=k;j++) {
            newnode=(struct node*)malloc(sizeof(struct node*));
            printf("Enter the %d neighbour of %d :",j,i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            if(adj[i]==NULL){
                adj[i]=newnode;
            }
            else{
                last->next=newnode;
            }
            last=newnode;
        }
   }
}

void printgraph(struct node*adj[]){
    struct node*temp;
    for(int i=0;i<no_vertices;i++){
        temp=adj[i];
        printf("\nVertices adjacent to %d are:",i);
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

void bfs(struct node *ad[],int start,int visited[]){
    int queue[no_vertices],front=-1,rear=-1;
    struct node *ptr;
    queue[++rear]=start;
    front++;
    printf("\nThe BFS traversal from %d is:",start);
    while(front<=rear){
        start=queue[front++];
        ptr = ad[start];
        visited[start]=1;
        printf("%d ",start);
        while(ptr!=NULL){
            if(visited[ptr->data]!=1){
                queue[++rear]=ptr->data;
                visited[ptr->data]=1;
            }
            ptr=ptr->next;
        }
    }
}
  
void dfs(struct node *ad[],int start,int visited[]){
        visited[start]=1;
        printf("%d ",start);
        struct node *ptr = ad[start];
        while(ptr!=NULL){
            if(visited[ptr->data]!=1){
                dfs(ad,ptr->data,visited);
            }
            ptr=ptr->next;
        }
}

int main() {
    int choice,data,visited[20];
    clock_t start,end;
    double t1,t2;
    printf("Enter the number of vertices in the graph:");
    scanf("%d",&no_vertices);
    struct node *adj[no_vertices];
    for(int i=0;i<no_vertices;i++) {
        adj[i]=NULL;
    }
    readgraph(adj);
    printf("Enter the starting vertex:");
    scanf("%d",&data);
    for(int i=0;i<no_vertices;i++){
    	visited[i]=0;
    }
    start=clock();
    bfs(adj,data,visited);
    end=clock();
    printgraph(adj);
    t1=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThe CPU time for BFS traversal is %f",t1);
    
	for(int i=0;i<no_vertices;i++){
    	visited[i]=0;
    }
    printf("\nThe DFS traversal is:");
    start=clock();
    dfs(adj,data,visited);
    end=clock();
    printgraph(adj);
    t2=(double)(end-start)/CLOCKS_PER_SEC;
   	printf("\nThe CPU time for DFS traversal is %f\n",t2);
    return 0;
}
