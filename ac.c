#include <stdio.h>
#include <string.h>

void hh(int* p){
    int** g = &p;
    printf("%d\n",p);
    printf("%d\n",*p);
    *p = 10;
    printf("%d\n",g);
    printf("%d\n",*g);
    printf("%d\n",**g);

}

void tok(){
    char s[]= "Hello";
    char* tok = strtok(s," "); 
    while(tok!=NULL){
        printf("%s\n",tok);
        tok = strtok(NULL,s);
    }
}

struct queue{
    int a[10];
    int front;
    int rear;
};

struct queue q;

int isEmpty(){
    if (q.rear==-1 && q.front == -1) return 1;
    else return 0;
}

void enqueue(int data){
    if(isEmpty()){
        q.rear = 0;
        q.front = 0;
        q.a[q.rear] = data;
    }
    else if(q.rear==9){
        printf("\nQUEUE FULL\n");
        return;
    }
    else{
       q.rear+=1;
        q.a[q.rear]=data;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("EMPTY");
        return;
    }
    else{
        printf("Removed %d\n",q.a[q.front]);
        q.front += 1;
    }
    if(q.front>q.rear){
        q.front=q.rear=-1;
    }

}

void pqueue(){
    for(int i=q.front;i<=q.rear;i++){
        printf("%d\t",q.a[i]);
    }
    printf("\n");
}

void rotate(){
    int mat[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};
    int mat2[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            mat2[i][j] = mat[j][2-i];
        }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");
    }
}

void fib(int n){
    long long a[100]={0,1};
    int index = 2;
    for(int i=2;i<n;i++){
        a[i]=a[index-1]+a[index-2];
        index++;
        printf("%d\t",a[i]);
    }
    printf("%d\n",a[n-1]);
}

int fibr(int n){
    if(n<=1){
        return n;
    }else{
        return fibr(n-1)+fibr(n-2);
    }
}

int fac(int n){
    if (n<=1){
        return 1;
    }else{
        return n*fac(n-1);
    }
}

int a[] = {1,2,3,4,5,6,7,8,19};    

void bs(int b,int e,int s){
    if (a[(b+e)/2]==s){
        printf("YES");
    }
    else if(s>a[(b+e)/2]){
     bs((b+e)/2+1,8,s);
    }
    else{
      bs(0,(b+e)/2-1,s);
    }
}

int scmp(char* s1, char* s2){
    int i=0;
    while(s1[i]){
        if(s1[i]!=s2[i]){
            break;
        }
        i++;
    }
    return s1[i]-s2[i];
}
void scp(char* s1,char* s2){
    int i=0;
    while(s2[i]!='\0'){
        s1[i]=s2[i];
        i++;
    }
}
void hc(char* s1){
    int i=0;
    printf("%s",&s1[i]);
}

int prime(int n){
    for(int i=2;i<=n/2;i++){
        if(n%i==0)
        return 0;
    }
    return 1;
}

int r(){
    static int num = 7;
    return num--;
}

int main(){
    // int x = 78;
    // tok();
    // hh(&x); 
    // rotate();
    // printf("%d",fibr(3));
    // printf("%d",fac(5));
    // bs(0,8,11);
    // char s2[10];
    // scp(s2,"poopoo");
    // printf("%d",scmp("e","e"));
    // int g[4][3] = {1,2,3,4,5,6,1,2,3,17,25,29};
    // for(int i=0;i<4;i++){
    // for(int j=0;j<3;j++)
    // printf("%d\t",prime(g[i][j]));
    // printf("\n");
    // hc("hi");
    // char s[10];
    // scanf("%s",s);
    // int ct = 0;
    // for(int i=0;i<sizeof(s)/sizeof(s[0]);i++){
    //     for(int j=i;j<ct;j++){
    //         printf("%c",s[j]);
    //     }
    //     printf("\n");
    //     ct+=1;
    // }    

    // int ap[10];
    // for(int i=0;i<10;i++){
    //     printf("\n%d",ap[i]);
    // }

    for(r();r();r())
        printf("%d ",r());

}  
