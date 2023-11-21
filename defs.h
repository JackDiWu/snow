/*
 * @Author: Jack
 * @Date: 2023-10-29 11:55:21
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-21 10:27:08
 */
#ifndef _SNOW_DEFS_H_
#define _SNOW_DEFS_H_

#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <queue>

#define UNI_STATUS_OK                       0
#define UNI_STATUS_INVALID_BINARY           1001
#define UNI_STATUS_INVALID_UNARY            1002

#define dbg_printf                          printf

#define MAX_BUFFER_SIZE                     1024

#define is_status_ok(s)                     (UNI_STATUS_OK == (s))
#define is_status_fail(s)                   (UNI_STATUS_OK != (s))

#endif
