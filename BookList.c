#include<stdio.h>
#include<stdlib.h>

#define NewNode (struct Book *)malloc(sizeof(struct Book)) 


struct Book
{
  int Bid;
  char Bname[50],Bauthor[50];
  float Bprice;
  struct Book *next;
}*Head = NULL;
 
struct Book * AcceptData()
{
  struct Book *T;

  T = NewNode;

  printf("\nEnter Book ID : ");
  scanf("%d",&T->Bid);
  printf("\nEnter Book Name : ");
  fflush(stdin);
  scanf("%s",T->Bname);
  printf("\nEnter Book Author : ");
  fflush(stdin);
  scanf("%s",T->Bauthor);
  printf("\nEnter Book Price : ");
  fflush(stdin);
  scanf("%f",&T->Bprice);
 T ->next =NULL;

printf("*****************************");

 return T;

}


struct Book * AddBook(int n)
{
  struct Book *Temp1,*Temp2,*Iterator;

  Temp1 = AcceptData();
  Temp2 = Temp1;

  for(int i = 2; i<=n; i++)
  {
    Temp2->next = AcceptData();
    Temp2 = Temp2->next;
  }
  if(Head ==NULL)
   return Temp1;
  else
  {
    for(Iterator = Head; Iterator->next != NULL;     Iterator = Iterator->next);
    Iterator->next = Temp1;
    return Head;
  }

}

void Display()
{
   struct Book *Temp;
  for(Temp = Head ;Temp != NULL; Temp = Temp->next)
  {
    printf("\nBook ID : %d\nBook Name : %s\nBook Author : %s\nBook Price : %f\n********************",Temp->Bid,Temp->Bname,Temp->Bauthor,Temp->Bprice);
  }
  printf("\n");
}

void DeleteBook(int bid)
{
  struct Book *Temp1,*Temp2;

  for(Temp1 = Head;Temp1 != NULL && Temp1->Bid != bid; Temp1 = Temp1 ->next)
  {
    Temp2 = Temp1;
  }
  if(Temp1 != NULL)
  {
    Temp2->next = Temp1->next;
    free(Temp1);
  }
  else
    printf("\n%d Book ID does not exist",bid);
}

int main()
{
   int ch,n;
 
   do
   {
     printf("\n1.Add Book\n2.Delete Book\n3.Display Book List\n4.Exit\nSelect option : ");
     scanf("%d",&ch);
     switch(ch)
     {
    case 1: printf("\nNumber of books to add in List :");
            scanf("%d",&n);
            Head = AddBook(n);
            break;
    case 2: printf("\nGive Book ID to delete :");
            scanf("%d",&n);
            DeleteBook(n);
            break;
    case 3: Display(); 
            break;        
               
     }

   }while(ch != 4);


   return 1;
}






