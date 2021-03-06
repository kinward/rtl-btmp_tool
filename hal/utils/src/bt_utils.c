/******************************************************************************
 *
 *  Copyright (C) 2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

/************************************************************************************
 *
 *  Filename:      bt_utils.c
 *
 *  Description:   Miscellaneous helper functions
 *
 *
 ***********************************************************************************/
#define LOG_TAG "BT_UTILS"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/resource.h>

#include "bt_syslog.h"
#include "data_types.h"
#include "bt_utils.h"


#ifndef PROPERTY_VALUE_MAX
#define PROPERTY_VALUE_MAX  128
#endif

/*******************************************************************************
**  Type definitions for callback functions
********************************************************************************/
static pthread_once_t g_DoSchedulingGroupOnce[TASK_HIGH_MAX];
static BOOLEAN g_DoSchedulingGroup[TASK_HIGH_MAX];
static pthread_mutex_t         gIdxLock;
static int g_TaskIdx;

/*****************************************************************************
**
** Function        bt_utils_init
**
** Description     Initialize bluedroid util
**
** Returns         void
**
*******************************************************************************/
void bt_utils_init() {
    int i;
    pthread_mutexattr_t lock_attr;

    for(i = 0; i < TASK_HIGH_MAX; i++) {
        g_DoSchedulingGroupOnce[i] = PTHREAD_ONCE_INIT;
        g_DoSchedulingGroup[i] = TRUE;
    }
    pthread_mutexattr_init(&lock_attr);
    pthread_mutex_init(&gIdxLock, &lock_attr);
}

/*****************************************************************************
**
** Function        bt_utils_cleanup
**
** Description     Clean up bluedroid util
**
** Returns         void
**
*******************************************************************************/
void bt_utils_cleanup() {
    pthread_mutex_destroy(&gIdxLock);
}

/*****************************************************************************
**
** Function        check_do_scheduling_group
**
** Description     check if it is ok to change schedule group
**
** Returns         void
**
*******************************************************************************/
//static void check_do_scheduling_group(void) {
    //char buf[PROPERTY_VALUE_MAX];
    //int len = property_get("debug.sys.noschedgroups", buf, "");
    //if (len > 0) {
    //    int temp;
    //    if (sscanf(buf, "%d", &temp) == 1) {
    //        g_DoSchedulingGroup[g_TaskIdx] = temp == 0;
    //    }
    //}
//}
