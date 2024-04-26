Sections header store info about a section

| Section header                       |
| ------------------------------------ |
| Type of the section                  |
| Offset of the section from the start |
| Size of the section                  |
| Number of entry in the section       |
Type is the type of the section :
- team
- channel
- thread
- message

```c
typedef struct section_hdr {
	char type;
	unsigned long int offset;
	unsigned long int section_size;
	unsigned int no_section_entry;
} section_hdr_t;
```

See [[Sections]]
