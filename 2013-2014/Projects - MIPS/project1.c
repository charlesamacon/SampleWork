//
//  project1.c
//  project1
//  double linked list processing
//
//  Created by Charles Shelor on 2/9/15.
//

#include <stdio.h>

//  define the type for the list items as an incomplete type
typedef struct item_rec item;

//  define the item_rec structure
struct item_rec {
	item	*next;
	item	*prev;
	int		key;
	char	data[32];
};


//  define the functions to be used
item *add_item(item *header, item *itm);
item *del_item(item *itm);
item *find_item(item *header, int key);
item *find_small(item *header);
void print_list(item *header);
void print_data(item *itm);

int main(int argc, const char * argv[]) {
	item	*header;		//  main list header
	item	*itm;			//  pointer to item of interest
	item	itm1 = {0, 0, 233, "1 32-character string is here\n\0"};
	item	itm2 = {0, 0, 277, "2 32-character string is here\n\0"};
	item	itm3 = {0, 0, 107, "3 32-character string is here\n\0"};
	item	itm4 = {0, 0, 313, "4 32-character string is here\n\0"};
	item	itm5 = {0, 0, 617, "5 32-character string is here\n\0"};
	item	itm6 = {0, 0, 401, "6 32-character string is here\n\0"};
	item	itm7 = {0, 0,   7, "7 32-character string is here\n\0"};
	item	itm8 = {0, 0, 295, "8 32-character string is here\n\0"};
	item	itm9 = {0, 0, 163, "9 32-character string is here\n\0"};
	item	itm10 = {0, 0,  41, "10 32-character string is here\n\0"};
	item	itm11 = {0, 0, 181, "11 32-character string is here\n\0"};
	item	itm12 = {0, 0, 376, "12 32-character string is here\n\0"};
	item	itm13 = {0, 0, 523, "13 32-character string is here\n\0"};
	item	itm14 = {0, 0, 431, "14 32-character string is here\n\0"};
	item	itm15 = {0, 0, 331, "15 32-character string is here\n\0"};
	item	itm16 = {0, 0,  11, "16 32-character string is here\n\0"};
	item	itm17 = {0, 0, 599, "17 32-character string is here\n\0"};
	
	header = NULL;		//  indicate empty list
	
	//  add items 1-17 to the list
	header = add_item(header, &itm1);
	add_item(header, &itm2);
	add_item(header, &itm3);
	add_item(header, &itm4);
	add_item(header, &itm5);
	add_item(header, &itm6);
	add_item(header, &itm7);
	add_item(header, &itm8);
	add_item(header, &itm9);
	add_item(header, &itm10);
	add_item(header, &itm11);
	add_item(header, &itm12);
	add_item(header, &itm13);
	add_item(header, &itm14);
	add_item(header, &itm15);
	add_item(header, &itm16);
	add_item(header, &itm17);
	
	//  print the list structure
	print_list(header);
	
	//  delete items with keys 295 and 376
	itm = find_item(header, 295);
	del_item(itm);
	
	del_item(find_item(header, 376));
	
	//  print the data segments of the list in ascending key order
	print_data(header);
	

	return 0;
}


//  add_item function
//  first see if header is NULL, if so itm becomes first on list
//  second see if there is only 1 item on list, add item either as both next and prev
//  starting with head item, find item with key smaller and key larger and insert between
//    if end of list encountered add item as new end of list (smallest or largest key)
//	return itm (used to initialize header if first addition)
item *add_item(item *header, item *itm) {
	item	*large_itm;
	int		large_val;
	item	*small_itm;
	int		small_val;
	if (header == NULL) 
	{	//	true when list empty
		header = itm;		//  header points to item
		itm->next = itm;	//	itm->next is itm
		itm->prev = itm;	//	itm->prev is itm
	} 
	else if (header->next == header) 
	{
		header->next = itm;
		header->prev = itm;
		itm->next = header;
		itm->prev = header;
	} 
	else 
	{
		small_itm = header;
		small_val = header->key;
		large_itm = header->next;
		large_val = header->next->key;
		if (small_val > large_val) 
		{	//  true when header points to end of list
			small_itm = header->prev;	//  move beginning points towards smaller keys
			small_val = header->prev->key;
			large_itm = header;
			large_val = header->key;
		}
		
		if (itm->key > small_val  &&  itm->key < large_val) 
		{	//  insert between small_itm and large_itm
			;
		} 
		else if (itm->key > large_val) 
		{		//  find spot towards end of list
			while (1) 
			{
				small_itm = large_itm;
				small_val = large_val;
				large_itm = large_itm->next;
				large_val = large_itm->key;
				if (itm->key < large_val  ||  large_val < small_val) 
				{
					break;						//	found spot for inserting itm
				}
			}
			
		} 
		else 
		{								//  find spot towards start of list
			while (1) 
			{
				large_itm = small_itm;
				large_val = small_val;
				small_itm = small_itm->prev;
				small_val = small_itm->key;
				if (itm->key > small_val  ||  large_val < small_val) {
					break;						//	found spot for inserting itm
				}
			}
			
		}
		//  At this point, itm needs to be added between small_itm and large_itm
		itm->prev = large_itm->prev;
		itm->next = small_itm->next;
		small_itm->next = itm;
		large_itm->prev = itm;
	}
	return itm;
	
}



//  del_item  function  deletes an item from the list it is in, returns pointer to next, NULL if last item
//  first check to see if itm->next == itm; this indicates deletion of last item on list, so return NULL
//	update links to the item to remove it and return its previous itm->next value
item *del_item(item *itm) {
	item	*new_hdr;
	if (itm->next == itm) {
		new_hdr = NULL;			//  last item on list so make header NULL
	} else {
		new_hdr = itm->next;
	}
	itm->prev->next = itm->next;
	itm->next->prev = itm->prev;
	itm->next = NULL;			//	make links NULL so cannot be used as a list item
	itm->prev = NULL;
	return new_hdr;
}



//  find_item  function  search list for an item matching the key, return pointer if found, NULL if not found
//  first determine if already found
//  second, determine search direction
//  return when found, or if not found, return null
item *find_item(item *header, int key) {
	item	*itm = header;
	if (header->key == key) {				//	equal, so found it, go no further
		;
	} else if (header->key < key) {			//	search for larger keys
		while (1) {
			itm = itm->next;
			if (itm->key == key) {			//	found it
				break;
			} else if (itm->key > key) {	//  list keys now larger than search key so not found
				itm = NULL;
				break;
			} else if (itm->next->key < itm->key) {		//  itm is last on list, so not found
				itm = NULL;
				break;
			}								//	keep looking
		}
	} else {								//	search for smaller keys
		while (1) {
			itm = itm->prev;
			if (itm->key == key) {			//	found it
				break;
			} else if (itm->key < key) {	//  list keys now smaller than search key so not found
				itm = NULL;
				break;
			} else if (itm->prev->key > itm->key) {		//  itm is first on list, so not found
				itm = NULL;
				break;
			}							//	keep looking
		}
	}
	
	return itm;
}



//  find_small  function  locates item with smallest key on the list
item *find_small(item *header) {
	item	*itm = header;
	
	while (itm->prev->key < itm->key) {
		itm = itm->prev;
	}
	return itm;
}



//  print_list function  print address and link values for all items on list
void print_list(item *header) {
	item	*strt = header;
	item	*itm = header;
	
	while (1) {
		printf("Item address: 0x%08X,  next: 0x%08X,  prev: 0x%08X,  key: %d.\n",
			   (unsigned int) itm, (unsigned int) itm->next, (unsigned int) itm->prev, itm->key);
		itm = itm->next;
		if (itm == strt) {
			break;
		}
	}
	
	
}



//  print_data  function  print data from all items on list, beginning with smallest key
void print_data(item *itm){
	item	*strt, *stop;
	
	strt = find_small(itm);
	stop = strt->prev;
	
	while (strt != stop) {
		printf("%s", strt->data);
		strt = strt->next;
	}
	
}


