/* binary search tree implementation of insert deleted and in order display */  

#include<stdio.h>
#include<stdlib.h>

struct Node{
int val ;
struct Node *rlink, *llink ;
};

typedef struct Node node ;

node * getnode(){

node * n1 = (node*) malloc(sizeof(node));
n1->val = -1 ;
n1->rlink = NULL ;
n1->llink = NULL ;

return n1 ;
}


node* insert(node* root , int a);
void printInorder(node* root);
node* delete(node* root, int a );


int main(){
node* Root = NULL ;

int choice , a;
for(;;){
 printf("Enter choice \n 1.insert\n 2.display \n 3.delete \n");
 scanf("%d",&choice);
	switch(choice){
	  case 1: printf("Enter num\n"); scanf("%d",&a); Root = insert(Root,a); break ;
	  case 2:  printInorder(Root); printf("\n"); break ;
	  case 3:   printf("Enter num\n"); scanf("%d",&a); Root = delete(Root,a); break ;
	  default : exit(0);
	}

}


return 0 ;
}

node* insert(node* root ,int a){
node* Root = root ;

 if(Root == NULL){
      Root = getnode();
      Root->val = a ;
      return Root ;
  }

  while(root != NULL){
      if(a < root->val ){
	  if(root->llink != NULL) { root = root->llink;  continue ;}
	  else{ root->llink = getnode(); root->llink->val = a ; break ;
	     }
	}
       else{
             if(root->rlink != NULL) { root = root->rlink;  continue ;}
	    else{ root->rlink = getnode(); root->rlink->val = a ; break ;
	     }
	}
    
   }
 
   return Root ;
}

node* delete(node* root, int a ){


  node*  Root = root ;
  node*  prev =root ;
  node*  sucessor ; 
  node*  presuc ;  

 if(Root == NULL){
      printf("Empty \n");
      return Root ;
  }


  while(root != NULL){
      if(a == root->val ) break ;
      else if(a<root->val){ if(root->llink != NULL) {  prev = root ;root = root->llink;  continue ;}
	                    else break ; }
            else { if(root->rlink != NULL) { prev = root ; root = root->rlink;  continue ;}
	                    else break ; }
   
   }
 
   if(root->val != a ){ printf("not found \n") ; return Root ;}

   if(root->llink == NULL && root->rlink == NULL){
       if (prev->llink->val == a ){ free(root); prev->llink = NULL ;}
       else  if (prev->rlink->val == a ){ free(root); prev->rlink = NULL ;}

     return Root ;
   }


   else if(root->llink == NULL || root->rlink == NULL){
     
       if (prev->llink->val == a ){  
		if(root->llink == NULL) {prev->llink = root->rlink  ;} 
		 else{prev->llink = root->llink  ; } 
		free(root);}
       else  if (prev->rlink->val == a ){ 
		if(root->rlink == NULL) {prev->rlink = root->llink  ;}
		else{prev->rlink = root->llink  ; } 
		 free(root);}
	 return Root ;

   }

    
   else if(root->llink != NULL && root->rlink != NULL){
	
     printf("Entered \n");

	        sucessor = root ;
                presuc = root ;
		sucessor = sucessor->rlink ;
		while(sucessor->llink != NULL){

		    presuc =  sucessor ;
                    sucessor = sucessor->llink ;
		    
	            
		}
                root->val = sucessor->val ;

              if(sucessor->rlink == NULL && sucessor->llink == NULL){
		
		if (presuc->llink->val == sucessor->val  ){  
 		presuc->llink = NULL ;
		 free(sucessor);

	           }
       		else  if (presuc->rlink->val == sucessor->val ){ 
		presuc->rlink = NULL ;
		 free(sucessor);
             	  }
		
		}
	     else if (sucessor->rlink != NULL ){

                   if (presuc->llink->val == sucessor->val  ){  
 		presuc->llink = sucessor->rlink ;
		 free(sucessor);

     		    }
      		  else  if (presuc->rlink->val == sucessor->val ){ 
		presuc->rlink = sucessor->rlink ;
		 free(sucessor);
        	  }
                    
                }

     
       


	 return Root ;

   }

   


   return Root ;
}



void printInorder(node* root){

  if(root == NULL ) return ;
  printInorder(root->llink) ;
  printf("%d ",root->val);
  printInorder(root->rlink) ;
}
