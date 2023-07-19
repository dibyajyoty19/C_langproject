#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum size of the database
// Define the structure for a courier record
struct Courier {
char name[50];
char address[30];
char phone[20];
float weight;
float cost;
};
// Define the database as a global array of Courier structures
struct Courier db[MAX_SIZE];
int num_records = 0;
// Function prototypes
void insert_record();
void display_records();
void search_record();
void update_delete_record();
void sort_records();
void write_records();
void read_records();
int main() {
printf("\n\n\t\t*****Welcome To Courier Management System*****\t\t\n\n");
printf("Kindly Login To Proceed Further\n");
char uname[30],pword[30];
char defaultu[30] = "admin", defaultp[30] ="main";
printf("Enter Username: ");
scanf("%s",&uname);
printf("Enter Password: ");
scanf("%s",&pword);
if(strcmp(uname,defaultu) == 0 && strcmp(pword,defaultp) == 0) {
printf("\nSucessfully Logged In\n\n");
int choice;
do {
// Display the main menu
printf("\nCourier Management System\n");
printf("1. Insert a new record\n");
printf("2. Display all records\n");
printf("3. Search for a record\n");
printf("4. Update or delete a record\n");
printf("5. Sort records by weight\n");
printf("6. Write Database in a Text File\n");
printf("7. Read Database From Text File\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
insert_record();
break;
case 2:
display_records();
break;
case 3:
search_record();
break;
case 4:
update_delete_record();
break;
case 5:
sort_records();
break;
case 6:
write_records();
break;
case 7:
read_records();
break;
case 0:
printf("Exiting the program...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
break; }
} while (choice != 0);
}
else{
printf("Invalid Credentials");
}
return 0; }
void insert_record() {
// Check if the database is full
if (num_records == MAX_SIZE) {
printf("Error: database is full.\n");
return; }
// Prompt the user to enter the record details
struct Courier new_record;
printf("Enter the name: ");
scanf("%s", new_record.name);
printf("Enter the City : ");
scanf("%s", new_record.address);
printf("Enter the phone number: ");
scanf("%s", new_record.phone);
printf("Enter the weight (in kg): ");
scanf("%f", &new_record.weight);
printf("Enter the cost (in Rs.): ");
scanf("%f", &new_record.cost);
// Add the new record to the database
db[num_records] = new_record;
num_records++;
printf("Record added successfully.\n");
}
void display_records() {
// Check if the database is empty
if (num_records == 0) {
printf("Database is empty.\n");
return; }
// Displays all the records in the database
printf("%-20s %-30s %-20s %-10s %-10s\n", "Name", "City", "Phone", 
"Weight", "Cost");
for (int i = 0; i < num_records; i++) {
printf("%-20s %-30s %-20s %-10.2f %-10.2f\n", db[i].name, 
db[i].address, db[i].phone, db[i].weight, db[i].cost);
}
}
void search_record() {
// Check if the database is empty
if (num_records == 0) {
printf("Database is empty.\n");
return; }
// Prompt the user to enter the name to search for
char name[50];
printf("Enter the name to search for: ");
scanf("%s", name);
// Search for the record in the database
int found = 0;
printf("%-20s %-30s %-20s %-10s %-10s\n", "Name", "City", "Phone", 
"Weight", "Cost");
for (int i = 0; i < num_records; i++) {
if (strcmp(name, db[i].name) == 0) {
printf("%-20s %-30s %-20s %-10.2f %-10.2f\n", db[i].name, 
db[i].address, db[i].phone, db[i].weight, db[i].cost);
found = 1; } }
if (!found) {
printf("Record not found.\n");
} }
void update_delete_record() {
// Check if the database is empty
if (num_records == 0) {
printf("Database is empty.\n");
return; }
// Prompt the user to enter the name of the record to update or delete
char name[50];
printf("Enter the Name of the record to update or delete: ");
scanf("%s", name);
// Search for the record in the database
int found = 0;
int index;
for (int i = 0; i < num_records; i++) {
if (strcmp(name, db[i].name) == 0) {
found = 1;
index = i;
break; } }
if (!found) {
printf("Record not found.\n");
return; }
// Display the record details
printf("%-20s %-30s %-20s %-10s %-10s\n", "Name", "City", "Phone", 
"Weight", "Cost");
printf("%-20s %-30s %-20s %-10.2f %-10.2f\n", db[index].name, 
db[index].address, db[index].phone, db[index].weight, db[index].cost);
// Prompt the user to choose between updating or deleting the record
int choice;
printf("Enter 1 to update the record, or 2 to delete the record: ");
scanf("%d", &choice);
switch (choice) {
case 1: // Update the record
printf("Enter the new City: ");
scanf("%s", db[index].address);
printf("Enter the new phone number: ");
scanf("%s", db[index].phone);
printf("Enter the new weight (in kg): ");
scanf("%f", &db[index].weight);
printf("Enter the new cost (in Rs.): ");
scanf("%f", &db[index].cost);
printf("Record updated successfully.\n");
break;
case 2: // Delete the record
for (int i = index; i < num_records - 1; i++) {
db[i] = db[i + 1];
}
num_records--;
printf("Record deleted successfully.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
break; } }
void sort_records() {
// Check if the database is empty
if (num_records == 0) {
printf("Database is empty.\n");
return; }
// Sort the records by weight using selection sort
for (int i = 0; i < num_records - 1; i++) {
int min_index = i;
for (int j = i + 1; j < num_records; j++) {
if (db[j].weight < db[min_index].weight) {
min_index = j; } }
// Swap the records
struct Courier temp = db[i];
db[i] = db[min_index];
db[min_index] = temp; }
// Display the sorted records
printf("%-20s %-30s %-20s %-10s %-10s\n", "Name", "City", "Phone", 
"Weight", "Cost");
for (int i = 0; i < num_records; i++) {
printf("%-20s %-30s %-20s %-10.2f %-10.2f\n", db[i].name, 
db[i].address, db[i].phone, db[i].weight, db[i].cost);
} }
void write_records()
{
FILE* fp = fopen("cms.txt", "w");
if (fp == NULL) {
printf("Error opening file %s\n", "cms.txt");
exit(1);
}
for (int i = 0; i < num_records; i++) {
fprintf(fp, "%s,%s,%s,%.2f,%.2f\n", db[i].name, db[i].address, 
db[i].phone, db[i].weight, db[i].cost);
}
printf("File Successfully Created\n");
fclose(fp);
}
void read_records() {
FILE* fp = fopen("cms.txt", "r");
if (fp == NULL) {
printf("Error opening file %s\n", "cms.txt");
exit(1);
}
while (fscanf(fp, "%[^,],%[^,],%[^,],%f,%f\n", db[num_records].name, 
db[num_records].address, db[num_records].phone, &db[num_records].weight, 
&db[num_records].cost) != EOF) {
num_records++; }
printf("File Sucessfully Read.\n");
fclose(fp);
}