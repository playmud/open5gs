/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright 2013 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 *  Copyright Beman Dawes 2008
 *  Copyright 2009-2010 Vicente J. Botet Escriba
 *
 *  Distributed under the Boost Software License, Version 1.0.
 *  See http://www.boost.org/LICENSE_1_0.txt
 */

/*
 * Copyright (C) 2019-2020 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined(OGS_CORE_INSIDE) && !defined(OGS_CORE_COMPILATION)
#error "This header cannot be included directly."
#endif

#ifndef OGS_TIME_H
#define OGS_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int64_t ogs_time_t;

#define OGS_INFINITE_TIME (-1)
#define OGS_NO_WAIT_TIME (0)

/** number of microseconds per second */
#define OGS_USEC_PER_SEC (1000000LL)

/** @return ogs_time_t as a second */
#define ogs_time_sec(time) ((time) / OGS_USEC_PER_SEC)

/** @return ogs_time_t as a usec */
#define ogs_time_usec(time) ((time) % OGS_USEC_PER_SEC)

/** @return ogs_time_t as a msec */
#define ogs_time_msec(time) (((time) / 1000) % 1000)

/** @return ogs_time_t as a msec */
#define ogs_time_to_msec(time) ((time) ? (1 + ((time) - 1) / 1000) : 0)

/** @return milliseconds as an ogs_time_t */
#define ogs_time_from_msec(msec) ((ogs_time_t)(msec) * 1000)

/** @return seconds as an ogs_time_t */
#define ogs_time_from_sec(sec) ((ogs_time_t)(sec) * OGS_USEC_PER_SEC)

int ogs_gettimeofday(struct timeval *tv);

ogs_time_t ogs_time_now(void); /* This returns GMT */
int ogs_time_from_lt(ogs_time_t *t, struct tm *tm, int tm_usec);
int ogs_time_from_gmt(ogs_time_t *t, struct tm *tm, int tm_usec);

/** @return number of microseconds since an arbitrary point */
ogs_time_t ogs_get_monotonic_time(void);
/** @return the GMT offset in seconds */
int ogs_timezone(void);

void ogs_localtime(time_t s, struct tm *tm);
void ogs_gmtime(time_t s, struct tm *tm);

void ogs_msleep(time_t msec);
void ogs_usleep(time_t usec);

#define ogs_mktime mktime
#define ogs_strptime strptime
#define ogs_strftime strftime

#ifdef __cplusplus
}
#endif

#endif /* OGS_TIME_H */
