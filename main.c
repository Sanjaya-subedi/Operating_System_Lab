#include <stdio.h>
#include "list.h"

int main() {
  printf("Write your Tests for your linked list implementation\n");
  
  list_t *my_list;
  my_list = list_alloc();

  list_print(my_list);


  list_add_to_front(my_list, 1);
  list_add_to_front(my_list, 2);
   list_add_to_front(my_list, 3);
  list_add_to_front(my_list, 4);
   list_add_to_front(my_list, 5);
  list_add_to_front(my_list, 6);
  list_print(my_list);



  list_add_to_front(my_list, 1);
  list_add_to_front(my_list, 2);
  list_add_to_back(my_list, 4);
  list_add_to_front(my_list, 2);
  list_print(my_list);


  printf("%d\n",list_length(my_list));
  list_print(my_list);
  
  list_add_at_index(my_list, 5, 8);
  list_add_at_index(my_list, 4, 4);
  list_add_at_index(my_list, 9, 0);
  list_add_at_index(my_list, 8, 2);
  list_add_at_index(my_list, 3, 8);
  list_print(my_list);


  list_remove_from_back(my_list);
  list_remove_from_back(my_list);
  list_remove_from_back(my_list);
  list_print(my_list);
  

  list_remove_from_front(my_list);
  list_remove_from_front(my_list);
  list_remove_from_front(my_list);
  list_print(my_list);


  printf("%d\n", (list_remove_at_index(my_list, 2)));
  printf("%d\n", (list_remove_at_index(my_list, 5)));
  printf("%d\n", (list_remove_at_index(my_list, 9)));
  printf("%d\n", (list_remove_at_index(my_list, 2)));
  list_print(my_list);


  printf("%s\n", list_is_in(my_list, 10)? "true": "false");
  printf("%s\n", list_is_in(my_list, 5)? "true": "false");
  printf("%s\n", list_is_in(my_list, 1)? "true": "false");
  list_print(my_list);

  printf("%d\n", list_get_elem_at(my_list, 8));
  printf("%d\n", list_get_elem_at(my_list, 0));
  printf("%d\n", list_get_elem_at(my_list, 7));


  list_add_at_index(my_list, 5, 5);
  list_add_at_index(my_list, 9, 2);
  list_add_at_index(my_list, 5, 2);
  list_print(my_list);

  printf("%d\n",list_get_index_of(my_list, 1));
  printf("%d\n",list_get_index_of(my_list, 3));
  printf("%d\n",list_get_index_of(my_list, 4));

  list_free(my_list);
  

 
}
