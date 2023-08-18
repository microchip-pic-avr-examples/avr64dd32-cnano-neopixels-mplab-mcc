/**
 * CCL Generated Header File
 * 
 * @file ccl.h
 * 
 * @defgroup  ccl CCL
 * 
 * @brief This file contains the API prototype for the CCL driver. 
 *
 * @version Driver Version  1.1.0
*/

#include <stdint.h>
#include <stdbool.h>

#ifndef CCL_H_INCLUDED
#define CCL_H_INCLUDED

#include "../system/utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup  ccl
 * @brief Initializes the CCL. This is called only once during the system initialization.
 * @pre None.
 * @param None.
 * @return None.
 */
int8_t CCL_Initialize(void);

#ifdef __cplusplus
}
#endif

#endif /* CCL_H_INCLUDED */
