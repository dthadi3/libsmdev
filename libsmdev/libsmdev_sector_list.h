/*
 * Sector list
 *
 * Copyright (c) 2010, Joachim Metz <jbmetz@users.sourceforge.net>
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

#if !defined( _LIBSMDEV_SECTOR_LIST_H )
#define _LIBSMDEV_SECTOR_LIST_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#include "libsmdev_list_type.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libsmdev_sector_list_value libsmdev_sector_list_value_t;

struct libsmdev_sector_list_value
{
	/* The first sector
	 */
	uint64_t first_sector;

	/* The number of sectors
	 */
	uint64_t number_of_sectors;
};

typedef struct libsmdev_sector_list libsmdev_sector_list_t;

struct libsmdev_sector_list
{
	/* The number of elements
	 */
	int number_of_elements;

	/* The first element
	 */
	libsmdev_list_element_t *first_element;

	/* The last element
	 */
	libsmdev_list_element_t *last_element;

	/* The current list element
	 */
	libsmdev_list_element_t *current_element;

	/* The current list element index
	 */
	int current_element_index;
};

int libsmdev_sector_list_value_initialize(
     libsmdev_sector_list_value_t **sector_list_value,
     liberror_error_t **error );

int libsmdev_sector_list_value_free(
     intptr_t *sector_list_value,
     liberror_error_t **error );

int libsmdev_sector_list_value_clone(
     intptr_t **destination_sector_list_value,
     intptr_t *source_sector_list_value,
     liberror_error_t **error );

int libsmdev_sector_list_initialize(
     libsmdev_sector_list_t **sector_list,
     liberror_error_t **error );

int libsmdev_sector_list_free(
     libsmdev_sector_list_t **sector_list,
     liberror_error_t **error );

int libsmdev_sector_list_empty(
     libsmdev_sector_list_t *sector_list,
     liberror_error_t **error );

int libsmdev_sector_list_clone(
     libsmdev_sector_list_t **destination_sector_list,
     libsmdev_sector_list_t *source_sector_list,
     liberror_error_t **error );

int libsmdev_sector_list_get_number_of_elements(
     libsmdev_sector_list_t *sector_list,
     int *number_of_elements,
     liberror_error_t **error );

int libsmdev_sector_list_append_sector(
     libsmdev_sector_list_t *sector_list,
     uint64_t first_sector,
     uint64_t number_of_sectors,
     uint8_t merge_ranges,
     liberror_error_t **error );

int libsmdev_sector_list_get_sector(
     libsmdev_sector_list_t *sector_list,
     int index,
     uint64_t *first_sector,
     uint64_t *number_of_sectors,
     liberror_error_t **error );

int libsmdev_sector_list_get_sector_by_value(
     libsmdev_sector_list_t *sector_list,
     uint64_t sector_value,
     uint64_t *first_sector,
     uint64_t *number_of_sectors,
     liberror_error_t **error );

int libsmdev_sector_list_range_is_present(
     libsmdev_sector_list_t *sector_list,
     uint64_t first_sector,
     uint64_t number_of_sectors,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

