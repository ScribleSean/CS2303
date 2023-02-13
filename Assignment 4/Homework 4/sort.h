/** sort.h
 * file to sort function prototypes for sort.c
 * @author Sean Arackal
 */

#ifndef SORT_H
#define SORT_H

// Function prototypes:
void timesort (int a[], int count, int sort_type);
void print_int_array(int nums[], int count);
void sort_descending(int nums[], int count);
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);
void alt_sort_descending(int nums[], int count);

#endif
