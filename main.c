#include <stdio.h>
#include "memc_connector.h"

int main()
{
	int ret;
	char *key = "asd";
	char *value1 = "value1";
	char *value2 = "value2";
	size_t len = 0;
	char *tmp = NULL;

	ret = memcached_connect_to_server();
	if (ret < 0) {
		printf("Failed to connect server!\n");
		return -1;
	}

	ret = memcached_set_value(key, strlen(key), value1, strlen(value1), 0);
	if (ret < 0) {
		printf("Failed to set value, memcached is not running?\n");
		goto out;
	}
	printf("Set k/v [%s:%s]\n", key, value1);
	ret = memcached_get_value(key, strlen(key), &tmp, &len, NULL);
	if (ret < 0) {
		printf("Failed to get value, memcached is not running?\n");
		goto out;
	}
	printf("Get k/v [%s:%s]\n", key, tmp);
	
	ret = memcached_set_value(key, strlen(key), value2, strlen(value2), 0);
	if (ret < 0) {
		printf("Failed to set value, memcached is not running?\n");
		goto out;
	}
	printf("Set k/v [%s:%s]\n", key, value2);
	ret = memcached_get_value(key, strlen(key), &tmp, &len, NULL);
	if (ret < 0) {
		printf("Failed to get value, memcached is not running?\n");
		goto out;
	}
	printf("Get k/v [%s:%s]\n", key, tmp);
out:
	memcached_disconnect_to_server();
	return ret;
}
