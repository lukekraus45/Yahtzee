#include <stdio.h>
#include <stdlib.h>
//global variables
int ones =0;
int twos=0;
int threes=0;
int fours=0;
int fives=0;
int sixes=0;
int bonus=0;
int bonus_total=0;
int three_of_a_kind=0;
int four_of_a_kind=0;
int small_straight=0;
int large_straight=0;
int full_house=0;
int yahtzee=0;
int chance=0;
int total = 0;
int flag = 1;

int roll_funct(){
unsigned int num;
int o = open("/dev/dice", O_RDONLY);
int r = read(i,&num,sizeof(int));

return num;
}


int cmpfunc(const void *a, const void *b){
return (*(int*)a- *(int*)b);
}
int main(){
int rounds = 0;
while(rounds < 13){
rounds++;
int play = 0;
int selection;

//first roll and stores the value of the dice
int dice[5];
dice[0] = roll_funct();
dice[1] = roll_funct();;
dice[2] = roll_funct();;
dice[3] = roll_funct();;
dice[4] = roll_funct();;

//-----------------------FIRST ROLL---------------------
printf("Welcome to Yahtzee\n");
printf("We will roll the dice for you and show you your roll\n");
printf("If you want to reroll you will be given the option up to reroll twice\n");
printf("When you are satisfied with your dice you will be able to place them in their correct categories\n");
printf("If you choose to place the dice in a spot where they dont fit you will be given 0\n");
printf("Your Roll: %d %d %d %d %d  \n", dice[0], dice[1], dice[2], dice[3], dice[4]);

//role the dice and print out the value
//printf("\n ... \n");


//ask the user which dice need to be rerolled 
int roll;
printf("Do you want to reroll any dice? (Enter 1 if yes or 0 if no)\n");
scanf("%d", &play);
if(play == 1){ 
int i;
for(i=0; i<5; i++){
printf("Do you want to reroll dice %d (Enter 1 if yes or 0 if no)\n", i);
scanf("%d", &roll);
if(roll == 1){
dice[i] = roll_funct();;
}
}

printf("Your Dice after the reroll: %d %d %d %d %d  \n", dice[0], dice[1], dice[2], dice[3], dice[4]);
}


//---------------------------SECOND ROLL-----------------------
if(play == 1){
printf("Your Second Roll: \n");

//print second roll

printf("Do you want to reroll any dice? (Enter 1 if yes or 0 if no)\n");
scanf("%d", &play);
if(play == 1){
int i;
for(i=0; i<5; i++){
printf("Do you want to reroll dice %d (Enter 1 if yes or 0 if no)\n", i);
scanf("%d", &roll);
if(roll == 1){
dice[i] = roll_funct();;
}
}

printf("Your Dice after the second reroll: %d %d %d %d %d  \n", dice[0], dice[1], dice[2], dice[3], dice[4]);
}


}
//----------------------------SELECTIONS-------------------
int selection2;
int counter=0;
printf("Place dice into: \n");
printf("1) Upper Section\n");
printf("2) Lower Section\n");
printf("3) No Play (take 0 in a collumn of your choice)\n");
scanf("%d", &selection);

int i;
//if the user wants to enter 0 for a column
if(selection ==3){
printf("\n1) Ones\n");
printf("2) Twos\n");
printf("3) Threes\n");
printf("4) Fours\n");
printf("5) Fives\n");
printf("6) Sixes\n");
printf("7) Three of a Kind\n");
printf("8) Four of a Kind\n");
printf("9) Full House\n");
printf("10) Small straight\n");
printf("11) Large straight\n");
printf("12) Yahtzee\n");
printf("13) Chance\n");
scanf("%d", &selection2);
if(selection2==1){
}
if(selection2==2){
ones =0;
}
if(selection2==3){
twos=0;
}
if(selection2==4){
threes=0;
}
if(selection2==5){
fours=0;
}
if(selection2==6){
fives=0;
}
if(selection2==7){
sixes = 0;}
if(selection2==8){
three_of_a_kind = 0;
}
if(selection2==9){
four_of_a_kind = 0;
}
if(selection2==10){
small_straight = 0;
}
if(selection2==11){
large_straight = 0;
}
if(selection2==12){
yahtzee = 0;
}
if(selection2==13){
chance = 0;
}
}




//upper section
if(selection == 1){
printf("\n1) Ones\n");
printf("2) Twos\n");
printf("3) Threes\n");
printf("4) Fours\n");
printf("5) Fives\n");
printf("6) Sixes\n");
scanf("%d", &selection2);
if(selection2 == 1){
for(i=0; i<6;i++){
if(dice[i]==1){
counter++;
}
}
ones = counter;
bonus_total = bonus_total+ones;
total = total +ones;
}
if(selection2 == 2){
for(i=0; i<6;i++){
if(dice[i]==2){
counter++;
}
}
counter = counter * 2;
twos= counter;
bonus_total = bonus_total+twos;
total = total +twos;
}
if(selection2 == 3){
for(i=0; i<6;i++){
if(dice[i]==3){
counter++;
}
}
counter = counter * 3;
threes= counter;
bonus_total = bonus_total+threes;
total = total +threes;
}
if(selection2 == 4){
for(i=0; i<6;i++){
if(dice[i]==4){
counter++;
}
}
counter = counter *4;
fours= counter;
bonus_total = bonus_total+fours;
total = total +fours;
}
if(selection2 == 5){
for(i=0; i<6;i++){
if(dice[i]==5){
counter++;
}
}
counter = counter *5;
fives = counter;
bonus_total = bonus_total+fives;
total = total +fives;
}
if(selection2 == 6){
for(i=0; i<6;i++){
if(dice[i]==6){
counter++;
}
}
counter = counter * 6;
sixes = counter;
bonus_total = bonus_total+sixes;
total = total +sixes;
}

}






//lower section
if(selection ==2){

qsort(dice, 6, sizeof(int),cmpfunc );
int one_counter=0;
int two_counter=0;
int three_counter=0;
int four_counter=0;
int five_counter=0;
int six_counter=0;

for(i=0;i<6;i++){
if(dice[i]==1){
one_counter++;
}
if(dice[i]==2){
two_counter++;
}
if(dice[i]==3){
three_counter++;
}
if(dice[i]==4){
four_counter++;
}
if(dice[i]==5){
five_counter++;
}
if(dice[i]==6){
six_counter++;
}
}
if(rounds!=1){
six_counter = six_counter-1;}
printf("\n1) Three of a Kind, Four of a Kind\n");
printf("2) Full House\n");
printf("3) Small straight\n");
printf("4) Large straight\n");
printf("5) Yahtzee\n");
printf("6) Chance\n");
printf("One: %d Two: %d Three: %d Four: %d Five: %d Six: %d\n", one_counter, two_counter, three_counter, four_counter, five_counter, six_counter);
scanf("%d", &selection2);
int i;
if(selection2 == 1){
if(one_counter==3||two_counter==3||three_counter==3||four_counter==3||five_counter==3||six_counter==3){
for(i=0;i<5;i++){
counter = dice[i] + counter;
}
three_of_a_kind = counter;
total = total +three_of_a_kind;
}
else if(one_counter==4||two_counter==4||three_counter==4||four_counter==4||five_counter==4||six_counter==4){
for(i=0;i<5;i++){
counter = dice[i] + counter;
}
four_of_a_kind = counter;
total = total +four_of_a_kind;
}
else{
three_of_a_kind==0;
}
}
if(selection2 == 2){
if((one_counter==3||two_counter==3||three_counter==3||four_counter==3||five_counter==3||six_counter==3)&&(one_counter==2||two_counter==2||three_counter==2||four_counter==2||five_counter==2||six_counter==2)){
full_house = 25;
total = total +full_house;}
}
if(selection2 == 3){
if((dice[0]==(dice[1]-1))&&(dice[0]==(dice[2]-2))&&(dice[0]==(dice[3]-3))){
small_straight = 30;
total = total +small_straight;}
else{
small_straight=0;
}
}
if(selection2 == 4){
if((dice[0]==(dice[1]-1))&&(dice[0]==(dice[2]-2))&&(dice[0]==(dice[3]-3))&&(dice[0]==(dice[4]-4))){

large_straight = 40;
total = total +large_straight;}
else{
large_straight = 0;
}

}
if(selection2 == 5){
if(one_counter==5||two_counter==5||three_counter==5||four_counter==5||five_counter==5||six_counter==5){
yahtzee = 50;
total = total +yahtzee;
}
}
if(selection2 == 6){
for(i=0;i<5;i++){
counter = dice[i] + counter;
}
chance=counter;
total = total +chance;
}


}




//------------------------------FINAL VALUES-------------------------------
if(bonus_total >=63 && flag == 1){
bonus = 35;
total = total +35;
flag = 0;
}
printf("\nYour score so far is: %d\n\n", total);
printf("Ones: %d \tFours: %d\n" , ones, fours);
printf("Twos: %d \tFives: %d\n", twos, fives);
printf("Threes: %d \tSixes: %d\n", threes, sixes);
printf("Upper Selection Bonus: %d\n", bonus);
printf("Three of a Kind: %d \tFour of a Kind: %d\n", three_of_a_kind, four_of_a_kind);
printf("Small Straight: %d \tLarge Straight: %d\n", small_straight, large_straight);
printf("Full House: %d \tYahtzee: %d\n", full_house, yahtzee);
printf("Chance: %d\n", chance );

}
}


