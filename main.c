#include <stdio.h>
#include "memc_connector.h"


int main()
{
	char *key = "asd";
	char *value1 = "value1";
	char *value2 = "value2";
	memcached_set_value(key, strlen(key), value1, strlen(value1), 0);

	size_t len = 0;
	char *tmp = NULL;
	memcached_get_value(key, strlen(key), &tmp, &len, NULL);
	memcached_set_value(key, strlen(key), value2, strlen(value2), 0);

	puts(tmp);
	memcached_get_value(key, strlen(key), &tmp, &len, NULL);
	puts(tmp);
	return 0;
}
