```c
typedef struct channel {
	int no_message;
	uuid_t uuid;
	long int *messages; //no_thread
} channel_t
```

no_message is the number of messages

uuid is the uuid of the team

messages is an array of int. Each int is an offset in the message section

