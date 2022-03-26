/* 
    What2Eat is a simple game programm which helps to decide food to order.
    Copyright (C) <2022>  <Muhamad Usmoni>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Struct describing choices. Will use will add all choices and then assighn points.
struct choices{
	int points;
	char *meal;

};
//The threshold
static int threshold = 10;


int main(int argc, char* argv[]){
    
    int number_Of_people; 
    printf("Enter number of people:\n");

//Got the number of people. 
    scanf("%d", &number_Of_people);
//I did the size 6 cuz i wanne use start from 1 not from 0
    struct choices preferences[6];
    preferences[1].meal = "Kebab";
    preferences[1].points = 0;
    
    preferences[2].meal = "Burger";
    preferences[2].points = 0;
    
    preferences[3].meal = "Pasta";
    preferences[3].points = 0;

    preferences[4].meal = "Lahmacun";
    preferences[4].points = 0;

    preferences[5].meal = "Salad";
    preferences[5].points = 0;

    printf("       Choices:\n");

    // printf(" Size of preferences: %ld\n", sizeof(preferences)/sizeof(preferences[1]));
    for(int i = 1; i < sizeof(preferences)/sizeof(preferences[1]); i++){
        printf(" %d. %s\n", i, preferences[i].meal);
    }
// Getting the choices and assigning points. For example the highes points goes to first choosen food. If i choose Kebab first it assighn 5 points the from remining 4,3,2,1 points.  
    printf("Please make your choices. \n");
    for(int i = 0; i < number_Of_people; i++){
        int choice;
        printf("Person %d choices:\n", i+1);
        printf(" 1 Kebab\n 2 Burger\n 3 Pasta\n 4 Lahmacun\n 5 Salad\n");
        for(int j = 1; j <= 5; j++){
            scanf("%d", &choice);
            preferences[choice].points += 6 - j;
        }
        
    }

//print the preferences above 10 and move them to short_preferences 
    printf("Short list of preferences which got more that 10 pts: \n");
    struct choices short_preferences[6];
    int above_ten = 0;
    for(int i = 1; i <= sizeof(preferences)/sizeof(preferences[1]) - 1; i++){
        if(preferences[i].points >= 10){
            printf("Food: %s is %d points\n", preferences[i].meal, preferences[i].points);
            above_ten += 1;
            short_preferences[above_ten].meal = preferences[i].meal;
            short_preferences[above_ten].points = preferences[i].points;
        }
        
    }
//No any above 10
    if(above_ten == 0){
        printf("You are eating at home/dorm today!\n");
        exit(0);
    }
//if there is only one choice no nedd to do second round.
    if(above_ten == 1){
        printf("%s is the only choice above 10. It is gonna be ordered!\n", short_preferences[1].meal);
        exit(0);
    }
    

    
    
    printf("                     Going to Second Round\n  Short List:\n");
//Just printing
    for (int al = 1; al <= above_ten; al++) {
        printf(" %d %s\n", al, short_preferences[al].meal);
    }
//Assigning points 2nd time. 
    printf("Please make your choices among short list. \n");
    for(int i = 0; i < number_Of_people; i++){
        int choice;
        printf("Person %d choices:\n", i+1);
        for(int j = 1; j <= above_ten; j++){
            scanf("%d", &choice);
            short_preferences[choice].points += above_ten + 1 - j;
        }
        
    }

    for (int al = 1; al <= above_ten; al++) {
        printf("%s is %d\n", short_preferences[al].meal, short_preferences[al].points);
    }
//finding the food with hisghest amount of points.
    int max_points = short_preferences[1].points;
    char *name = short_preferences[1].meal;
    for(int i = 1; i <= above_ten; i++){
        if(short_preferences[i].points > max_points){
            max_points = short_preferences[i].points;
            name = short_preferences[i].meal;
        }
    }

    printf("------------------------%s is ordered!------------------------\n", name);

    return 0;
}