```c
typedef struct channel {
	int no_thread;
	uuid_t uuid;
	long int *threads; //no_thread
} channel_t
```

no_thread is the number of threads

uuid is the uuid of the team

threads is an array of int. Each int is an offset in the thread section

