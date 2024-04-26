| Field name                  | Value                                   |
| --------------------------- | --------------------------------------- |
| Identification              | 0x7f, 'm', 'y', 't', 'e', 'a', 'm', 's' |
| First section header offset |                                         |
| Size of a section header    |                                         |
| Number of section header    |                                         |

```c
typedef struct hdr {
	char identification[8] // filled with 0;
	unsigned long int shdr_offset;
	unsigned long int shdr_size;
	unsigned int no_section_hdr;
} hdr_t
```

See [[Sections header]]
