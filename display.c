#include "fns.h"

// displays relevant data from a CSCICLASS
void display(CSCICLASS structure) {
	printf("| %-30s\t%-10s\t%-20s\t%d\t%s",
	structure.class_name, structure.title, structure.professor, structure.seats_total, structure.times);
}
