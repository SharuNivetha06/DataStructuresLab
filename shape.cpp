//menu-driven program to calculate and display the area of square,cube,rectangle and cuboid
#include<stdio.h>
#include<cstdlib>

//class definition
class shape{
    private:
    int length;
    int breadth;
    int height;
    int area;
    
    public:
    void square(){
        printf("Enter the side of the square\n");
        scanf("%d",&length);
        area=length*length;
        printf("The area of the square is %d\n",area);
    }
    void cube(){
        printf("Enter the side of the cube\n");
        scanf("%d",&length);
        area=6*length*length;
        printf("The area of the cube is %d\n",area);
        
    }
    void rectangle(){
        printf("Enter the length and breadth of the rectangle\n");
        scanf("%d%d",&length,&breadth);
        area=length*breadth;
        printf("The area of the rectangle is %d\n",area);

    }
    void cuboid(){
        printf("Enter the length,breadth and height of the cuboid\n");
        scanf("%d%d%d",&length,&breadth,&height);
        area=2*((length*breadth)+(breadth*height)+(length*height));
        printf("The area of the cuboid is %d\n",area);
    }
};

//main function
int main(){
    shape one;
    int choice=0;
    printf("The menu is as follows:\n");
    printf("1.Square\n");
    printf("2.Cube\n");
    printf("3.Rectangle\n");
    printf("4.Cuboid\n");
    printf("5.Exit\n\n");
    //prompt the user to enter choice
    printf("Enter your choice\n");
    scanf("%d",&choice);
    do{
    switch(choice){
        case 1:{
            printf("Square:\n");
            one.square();
            printf("\nThe menu is as follows:\n");
            printf("1.Square\n");
            printf("2.Cube\n");
            printf("3.Rectangle\n");
            printf("4.Cuboid\n");
            printf("5.Exit\n\n");
            //prompt the user to enter choice
            printf("Enter your choice\n");
            scanf("%d",&choice);
            break;
        }
        case 2:{
            printf("Cube:\n");
            one.cube();
            printf("\nThe menu is as follows:\n");
            printf("1.Square\n");
            printf("2.Cube\n");
            printf("3.Rectangle\n");
            printf("4.Cuboid\n");
            printf("5.Exit\n\n");
            //prompt the user to enter choice
            printf("Enter your choice\n");
            scanf("%d",&choice);
            break;
        }
        case 3:{
            printf("Rectangle:\n");
            one.rectangle();
            printf("\nThe menu is as follows:\n");
            printf("1.Square\n");
            printf("2.Cube\n");
            printf("3.Rectangle\n");
            printf("4.Cuboid\n");
            printf("5.Exit\n\n");
            //prompt the user to enter choice
            printf("Enter your choice\n");
            scanf("%d",&choice);
            break;
        }
        case 4:{
            printf("Cuboid:\n");
            one.cuboid();
            printf("\nThe menu is as follows:\n");
            printf("1.Square\n");
            printf("2.Cube\n");
            printf("3.Rectangle\n");
            printf("4.Cuboid\n");
            printf("5.Exit\n\n");
            //prompt the user to enter choice
            printf("Enter your choice\n");
            scanf("%d",&choice);
            break;
        }
        case 5:{
            printf("Program Terminated\n");
            exit(0);
        }
        default:{
            printf("Invalid case entered\n");
            break;

        }
    }
}while(choice!=5);

if(choice==5){
    printf("Program terminated\n");
    void exit(void);

}
}