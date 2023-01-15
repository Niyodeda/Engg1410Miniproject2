#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct user_t{
    double altitude, longitude, latitude; // position of users//
    char name[50];
}our_user, other_users[3];

struct relative{
    double distance; // the distance away from user//
    char name[50];
}othrUser_dist[3];

void closest(struct relative *othrUser_dist){
int index =-1;
 int i;
 float smallest =99999999; 
for(i=0; i<3; i++)
{ // Sorts through who is the closest from all other users arrays //
    if(othrUser_dist[i].distance < smallest){
        smallest = othrUser_dist[i].distance;
        index =i;
    }
}

printf("%s is the closest user they are only %lf Units away" ,othrUser_dist[index].name, othrUser_dist[index].distance);
}
void DistCalc(struct user_t *other_users, struct user_t *our_user, struct relative *othrUser_dist){
 double x;
 int i;
    for(i=0; i<3; i++){
 x = sqrt(pow(our_user->longitude - other_users[i].longitude,2)+pow(our_user->latitude - other_users[i].latitude,2)+pow(our_user->altitude - other_users[i].altitude,2)); // 
strcpy(othrUser_dist[i].name, other_users[i].name);
othrUser_dist[i].distance = x;
    } 
}

void scan_user(struct user_t *other_users, struct user_t *our_user, char Filename[30]){
    
    int i;
printf("Enter origin name: \n");
scanf("%s", &(our_user->name));
printf("Enter altitude longitude latitude: \n");
scanf("%lf%lf%lf", &(our_user->altitude), &(our_user->longitude), &(our_user->latitude));
printf("Origin name is: %s, altitude: %lf, longitude: %lf, latitude: %lf, \n", our_user->name, our_user->altitude, our_user->longitude, our_user->latitude);

double buffAlt ,buffLon ,buffLat =0;
    char buff[50];
    

    FILE *fp;
    fp = fopen(Filename, "r");
    int initial;
    fscanf(fp,"%d", &initial);
    if(fp == NULL)
    { // if no file is entered then user will enter manually //
        printf("File Error. Enter other users manually \n");
        fclose(fp);
        printf("Enter other users. Name, altitude, longitude and latitude\n\n ");
    for(i=0; i<3; i++){
    printf("instance %d ",i+1);
    scanf("%s %lf %lf %lf", &other_users[i].name, &other_users[i].altitude, &other_users[i].longitude, &other_users[i].latitude);
    }
    printf("Other users are:\n");
    for(i=0; i<3; i++)
    printf("%s: %lf, %lf, %lf,\n", other_users[i].name, other_users[i].altitude, other_users[i].longitude, other_users[i].latitude);
    
    
    }
    else{
        printf("Other users are:\n");
         for(i=0; i<initial; ++i)
    {    
     fscanf(fp,"%s %lf %lf %lf", buff, &buffAlt,&buffLon,&buffLat);
     strcpy(other_users[i].name, buff);
      other_users[i].altitude = buffAlt;
    other_users[i].longitude = buffLon;
    other_users[i].latitude = buffLat;
     printf("%s: %lf, %lf, %lf,\n", other_users[i].name, other_users[i].altitude, other_users[i].longitude, other_users[i].latitude); 
    }
    fclose(fp);
    }
}
int main()
{
char fname[30];
printf("Enter your file name including the address after the '.' If you wish to enter manually, press a random letter. \n");
scanf("%s",fname);
scan_user(&other_users[0], &our_user, fname);
DistCalc(&other_users[0], &our_user, &othrUser_dist[0]);
closest(&othrUser_dist[0]);

    return 0;
}