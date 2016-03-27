/*
 * List type functions
 *
 * Copyright (c) 2010, Joachim Metz <jbmetz@users.sourceforge.net>
 * Copyright (C) 2008-2010, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBSMDEV_LIST_TYPE_H )
#define _LIBSMDEV_LIST_TYPE_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#if defined( __cplusplus )
extern "C" {
#endif

enum LIBSMDEV_LIST_COMPARE_DEFINITIONS
{
	LIBSMDEV_LIST_COMPARE_LESS,
	LIBSMDEV_LIST_COMPARE_EQUAL,
	LIBSMDEV_LIST_COMPARE_GREATER
};

typedef struct libsmdev_list_element libsmdev_list_element_t;

struct libsmdev_list_element
{
	/* The previous element
	 */
	libsmdev_list_element_t *previous;

	/* The next element
	 */
	libsmdev_list_element_t *next;

	/* The list element value
	 */
	intptr_t *value;
};

typedef struct libsmdev_list libsmdev_list_t;

struct libsmdev_list
{
	/* The number of elements
	 */
	int number_of_elements;

	/* The first list element
	 */
	libsmdev_list_element_t *first;

	/* The last list element
	 */
	libsmdev_list_element_t *last;
};

int libsmdev_list_element_initialize(
     libsmdev_list_element_t **list_element,
     liberror_error_t **error );

int libsmdev_list_element_free(
     libsmdev_list_element_t **list_element,
     int (*value_free_function)(
            intptr_t *value,
            liberror_error_t **error ),
     liberror_error_t **error );

int libsmdev_list_initialize(
     libsmdev_list_t **list,
     liberror_error_t **error );

int libsmdev_list_free(
     libsmdev_list_t **list,
     int (*value_free_function)(
            intptr_t *value,
            liberror_error_t **error ),
     liberror_error_t **error );

int libsmdev_list_empty(
     libsmdev_list_t *list,
     int (*value_free_function)(
            intptr_t *value,
            liberror_error_t **error ),
     liberror_error_t **error );

int libsmdev_list_clone(
     libsmdev_list_t **destination,
     libsmdev_list_t *source,
     int (*value_clone_function)(
            intptr_t **destination,
            intptr_t *source,
            liberror_error_t **error ),
     liberror_error_t **error );

int libsmdev_list_get_number_of_elements(
     libsmdev_list_t *list,
     int *number_of_elements,
     liberror_error_t **error );

int libsmdev_list_get_element(
     libsmdev_list_t *list,
     int element_index,
     libsmdev_list_element_t **element,
     liberror_error_t **error );

int libsmdev_list_get_value(
     libsmdev_list_t *list,
     int element_index,
     intptr_t **value,
     liberror_error_t **error );

int libsmdev_list_prepend_element(
     libsmdev_list_t *list,
     libsmdev_list_element_t *element,
     liberror_error_t **error );

int libsmdev_list_prepend_value(
     libsmdev_list_t *list,
     intptr_t *value,
     liberror_error_t **error );

int libsmdev_list_append_element(
     libsmdev_list_t *list,
     libsmdev_list_element_t *element,
     liberror_error_t **error );

int libsmdev_list_append_value(
     libsmdev_list_t *list,
     intptr_t *value,
     liberror_error_t **error );

int libsmdev_list_insert_element(
     libsmdev_list_t *list,
     libsmdev_list_element_t *element,
     int (*value_compare_function)(
            intptr_t *first,
            intptr_t *second,
            liberror_error_t **error ),
     liberror_error_t **error );

int libsmdev_list_insert_value(
     libsmdev_list_t *list,
     intptr_t *value,
     int (*value_compare_function)(
            intptr_t *first,
            intptr_t *second,
            liberror_error_t **error ),
     liberror_error_t **error );

int libsmdev_list_remove_element(
     libsmdev_list_t *list,
     libsmdev_list_element_t *element,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

