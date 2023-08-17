/*
 * \brief  Libc <sig .../> test
 * \author Timo Nicolai
 * \date   2023-08-23
 */

/*
 * Copyright (C) 2023 Genode Labs GmbH
 * Copyright (C) 2023 Gapfruit AG
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#include <assert.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int received_sighup = 0;

void sighup_handler(int signum)
{
	if (signum != SIGHUP)
		return;

	received_sighup = 1;
}

int main()
{
	struct sigaction action;

	action.sa_handler = sighup_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGHUP, &action, NULL);

	while (!received_sighup) {
		sleep(1);
	}

	printf("received SIGHUP");

	return 0;
}
