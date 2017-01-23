#pragma once

#include <libmemcached/memcached.h>

int memcached_connect_to_server(void);
void memcached_disconnect_to_server(void);

int memcached_set_value(char *key, size_t key_len, char *value, size_t value_len, uint32_t flag);
int memcached_get_value(char *key, size_t key_len, char **value, size_t *value_len, uint32_t *flag);
int memcached_append_value(char *key, size_t key_len, char *value, size_t value_len, uint32_t flag);

int memcached_key_exist(char *key, size_t key_len);
