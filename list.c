// list/list.c
//
// Implementation for linked list.
//
// <Sanjaya Subedi>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* function for allocating the lists */
list_t *list_alloc(){
  list_t *my_list = (list_t*) malloc(sizeof(list_t));
  return my_list;
}

/* Prints the list in some format. */
void list_print(list_t *l){
  
  node_t *node = l->head;
  while (node){
    printf("%d->", node->value);
    
    node = node->next;

  }printf("\n");
}

/* Methods for adding to the front of the list. */
void list_add_to_front(list_t *l, elem value){
  node_t*newhead = (node_t*)malloc(sizeof(node_t));
  newhead->value = value;
  if (l->head){
    newhead->next = l->head;
    l->head = newhead;
  }
  else{
    newhead->next = NULL;
    l->head = newhead;
  }
}

/* Methods for adding to the back of the list. */
void list_add_to_back(list_t *l, elem value){
  if (l-> head){
    node_t* node = l->head;
    while (node->next){
      node = node->next;
    }
    node_t*newhead = (node_t*)malloc(sizeof(node_t));
    newhead->value = value;
    node->next = newhead;
    newhead->next = NULL;

  }
  else{
    list_add_to_front(l, value);
  }
}

/* Returns the length of the list. */
int list_length(list_t *l){
  node_t *node = l->head;
  int count = 0;
  while (node){
    count += 1;
    node = node->next;

}return count;
}


/*adds to given index of list and if it is out of bounds it adds to the end of the list*/
void list_add_at_index(list_t *l, elem value, int index){
  if (index == 0 || l-> head == NULL){
    list_add_to_front(l, value);
  }else if(index > list_length(l)){
    list_add_to_back(l, value);
  }
  else{
    node_t* curr = l->head;
    node_t* prev = NULL;
    int i = 0;
    while (curr && i < index){
      prev = curr;
      curr = curr->next;
      i++;
    }
    if (curr == NULL && i == index){
      list_add_to_back(l, value);
    } else if (i == index){
      node_t*newhead = (node_t*)malloc(sizeof(node_t));
      newhead->value = value;
      newhead->next = prev->next;
      prev->next = newhead;

    }

  }
}

/* functions for freeing the lists*/
void list_free(list_t *l){
  node_t* head = l->head;
  while (head != NULL){
    node_t* temp = head;
    head = head->next;
    free(temp);
  }
}




/* Methods for removing from the back of the list. Returns the removed element, or -1 for empty list */
elem list_remove_from_back(list_t *l){
  if (l->head == NULL){
    return -1;
  }
  else{
    node_t* curr = l->head;
    node_t* prev = NULL;
    while(curr->next){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    elem to_remove = curr->value;
    free(curr);
  }

}


/* Methods for removing from the front of the list. Returns the removed element, or -1 for empty list */
elem list_remove_from_front(list_t *l){
  if (l->head == NULL){
    return -1;
  }
  else{
    node_t* curr = l->head;
    elem first_value = curr->value;
    l->head = curr->next;
    free(curr);
    return first_value;
  }
}

/* Methods for removing at the index of the list. Returns the removed element, or -1 for empty list */
elem list_remove_at_index(list_t *l, int index){
  if(index == 0){
    list_remove_from_front(l);
  }
  else if(l->head == NULL){
    return -1;
  }else{
    node_t* curr = l->head;
    node_t* prev = NULL;
    int i = 0;
    while (curr && i < index){
      prev = curr;
      curr = curr->next;
      i++;
    }
    if (curr == NULL && i == index){
      list_remove_from_back(l);
    } else if (i == index){
      elem to_remove =  curr->value;
      prev->next = curr->next;
      free(curr);
      return to_remove;

    }

  }

}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value){
  node_t* curr = l->head;
    while (curr){
      if (curr->value == value){
        return true;
      }curr= curr->next;
    }return false;

}


/* Returns the element at the given index, or -1 if empty or out of bounds */
elem list_get_elem_at(list_t *l, int index){
  if (l-> head == NULL){
    return -1;
  }else if(index >= list_length(l)){
    return -1;
  }
  else{
    node_t* curr = l->head;
    int i = 0;
    while (curr) {
      if (i == index){
        return curr->value;
      }curr = curr->next;
      i+=1;
    }
  }
  

}

/* Returns the index at which the given element appears, or -1 if not found */
int list_get_index_of(list_t *l, elem value){
  if (l-> head == NULL){
    return -1;
  }
  else{
    node_t* curr = l->head;
    int i = 0;
    while (curr) {
      if (curr->value== value){
        return i;
      }curr = curr->next;
      i+=1;
    }return -1;
  }

}
