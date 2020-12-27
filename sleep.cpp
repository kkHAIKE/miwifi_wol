#include <stdlib.h>
#include <unistd.h>

int main(int argn, const char *argv[]) {
  int s = atoi(argv[1]);
  sleep(s);
  return 0;
}
