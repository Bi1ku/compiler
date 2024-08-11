#include <stdbool.h>
#include <string.h>

char in_array(char *arr[], char str[], int length) {
  for (int i = 0; i < length; i++) {
    if (strcmp(arr[i], str) == 0) {
      return 1;
    }
  }

  return 0;
}
