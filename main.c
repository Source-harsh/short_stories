#include<stdio.h>
#include<string.h>

void start_write(){
    char name[100];
    printf("enter the title of the story : ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]="\0";
    char *temp = malloc(strlen(name)+1);
    strcpy(temp,name);
    free(temp);
    FILE * file1=fopen(name,"a");
    char line[256];
    printf("enter exit after writing");
    while(1){
        fgets(line,sizeof(line),stdin);
        if (strncmp(line,"exit",4)==0){
            break;
        }
        fputs(line,file1);
    }
    fclose(file1);
}

void story_read(char filename){
    FILE * file1=open(filename,"r");
    char line[256];
    while(fgets(line,sizeof(line),file1)){
        printf("%s",line);
    }
    fclose(file1);

}

int main(){
    int choice;
    printf('enter the choice 1 : to write and upload story\n2 : to read a story :');
    scanf("%d",&choice);
    if(choice==1)
        start_write();
    else if(choice==2){
        char name[100];
        printf("enter the name of the story");
        scanf("%s",name);
        story_read(name);
    }
    else
        printf("choose the correct choice");

    return 0;

}