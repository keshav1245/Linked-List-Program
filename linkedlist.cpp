/* This file is created by Keshav Tangri on 18th August,2018
This is for educational purposes only.
This is for B.Tech Students who are or will be studying Data Structures in there curriculum
For queries mail me @ : tangri57@gmail.com
*/


#include<iostream>
#include<cstdlib>
using namespace std;

class Node{
public:
Node* next;
int data;
};

class llist{
public:
Node* head = new Node;
llist(){
head=NULL;
}
Node* createnode(int value);
void addatbeg(int val);
void display();
void addele(int val);
void addatpos(int val);
void deleteele(int pos);
void searchele(int val);
void updateval(int val);
void reverselist();
void sortlist();
};
//MAIN FUNCTION BEGINS HERE !
int main(){
int bhalue;
llist obj;
while(1){
int i;
cout<<"1.Add element at first position\n2.Add element at last position\n3.Add element at a position\n4.Display List\n5.Delete Element\n6.Search an Element\n7.Update Value\n8.Reverse the list\n9.Sort the List\n10.Exit\nChoose your option : ";
cin>>i;
switch(i){
case 1:
cout<<"Enter value you want to add : ";
cin>>bhalue;
cout<<"\n";
obj.addatbeg(bhalue);
break;
case 2:
cout<<"Enter value you want to add : ";
cin>>bhalue;
cout<<"\n";
obj.addele(bhalue);
break;
case 3:
cout<<"Enter value you want to add : ";
cin>>bhalue;
obj.addatpos(bhalue);
break;
case 4:
obj.display();
break;
case 5:
cout<<"Enter position where you want to delete : ";
cin>>bhalue;
obj.deleteele(bhalue);
break;
case 6:
cout<<"Enter the value of element you want to search : ";
cin>>bhalue;
obj.searchele(bhalue);
break;
case 7:
cout<<"Enter the value of the Element you want to update : ";
cin>>bhalue;
obj.updateval(bhalue);
break;
case 8:
obj.reverselist();
break;
case 9:
obj.sortlist();
break;
case 10:
exit(0);
break;
}
}

}
//CLASS FUNCTIONS BEGINS HERE !


//CREATING THE NODE !
Node* llist::createnode(int value){
Node* temp =new Node;
temp->data = value;
return temp;
}

//ADDING ELEMENT AT LAST !
void llist::addele(int val){

if(head == NULL){
    addatbeg(val);
}else{
Node* temp = createnode(val);
Node* ptr =head;
while(ptr->next!=NULL){
ptr=ptr->next;
}
temp->next=NULL;
ptr->next=temp;
}
}
//PRINTING THE LINKED LIST !
void llist::display(){
Node* ptr = head;
if(head==NULL){
cout<<"\nList does not exist !\n";
return;
}
while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr = ptr->next;
}
cout<<"\n\n";
}

//ADD ELEMENT AT BEGINNING !
void llist::addatbeg(int val){
Node* temp = createnode(val);
temp->next = head;
head = temp;
}

//DELETE AT POSITION !
void llist::deleteele(int pos){
if(head == NULL){
cout<<"ERROR !\nLIST IS EMPTY !\n";
return;
}
if(pos==1){
Node* p = head;
head = p->next;
delete p;
cout<<"\nElement Deleted !\n";
}else{
int counter = 0;
Node* p = head;
while(p!=NULL){
p=p->next;
counter++;
}
if(pos>1&&pos<=counter){
p = head;
Node* prev;
for(int i=1;i<pos;i++){
prev =p;
p=p->next;
}
prev->next=p->next;
delete p;
cout<<"\nELEMENT DELETED SUCCESSFULLY !\n";
}else{
cout<<"\nOUT OF RANGE EXCEPTION !\n\n";
}
}
}

//SEARCHING AN ELEMENT FUNCTION !
void llist::searchele(int val){
int counter=0;
Node* p = head;
if(head==NULL){
cout<<"\nEMPTY LIST !\n";
return;
}
while(p!=NULL){
counter++;
if(p->data==val){
cout<<"\nElement Found at : "<<counter<<" position\n\n";
break;
}
p=p->next;
}
if(p==NULL)
cout<<"\nVALUE NOT PRESENT !\n";
}


//UPDATING A VALUE FUNCTION
void llist::updateval(int val){
int counter=0;
Node* p = head;
if(head==NULL){
cout<<"\nEMPTY LIST !\n";
return;
}
while(p!=NULL){
counter++;
if(p->data==val){
break;
}
p=p->next;
}
if(p==NULL){
cout<<"\nVALUE NOT PRESENT !\n";
return;
}
if(p!=NULL){
cout<<"Enter New Value to be updated : ";
int temp;
cin>>temp;
Node* t =head;
for(int i=1;i<=counter;i++){
if(t->data==val){
t->data = temp;
cout<<"\nVALUE UPDATED !\n\n";
break;
}
t=t->next;
}
}
}
//ADDING ELEMENT AT A POSITION !
void llist::addatpos(int val){
cout<<"Enter position where you want to add the element : ";
int pos;
cin>>pos;
Node* ptr = head;
int counter =0;
while(ptr!=NULL){
counter++;
ptr=ptr->next;
}
if(pos==1){
addatbeg(val);
}else{
if(pos>1&&pos<=counter){
Node* prev;
Node* temp = createnode(val);
ptr = head;
for(int i =1;i<pos;i++){
    prev = ptr;
    ptr=ptr->next;
}
prev->next = temp;
temp->next = ptr;
cout<<"\n\nELEMENT ADDED SUCCESSFULLY !\n\n";
}else{
cout<<"END OF RANGE EXCEPTION !";
return;
}
}
}

//REVERSING THE LIST FUNCTION
void llist::reverselist(){
if(head==NULL){
cout<<"\n\nEMPTY LIST !\n\n";
return;
}
Node* curr;
Node* prev;
curr = head;
head = head->next;
curr->next=NULL;
while(head->next!=NULL){
prev = curr;
curr = head;
head = head->next;
curr->next = prev;
}
head->next=curr;
cout<<"\n\nLIST REVERSED SUCCESSFULLY !\n\n";
}

//SORTING THE LIST FUNCTION !
void llist::sortlist(){
if(head==NULL){
cout<<"\n\nEMPTY LIST !\n\n";
return;
}else{
Node* ptr = head;
Node* s=ptr->next;
while(ptr!=NULL){
while(s!=NULL){
if(ptr->data>s->data){
int temp = ptr->data;
ptr->data=s->data;
s->data=temp;
}
s=s->next;
}
ptr=ptr->next;
s=ptr;
}
cout<<"\n\nLIST SORTED SUCCESSFULLY !\n\n";
}
}
