```c
typedef struct team {
	int no_channel;
	uuid_t uuid;
	long int *channels; //no_channel
} team_t
```

no_channel is the number of channel

uuid is the uuid of the team

channels is an array of int. Each int is an offset in the channel section

