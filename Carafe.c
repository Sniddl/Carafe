#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int StartsWith(char *a, char *b)
{
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}

void watching(){
  printf(
    "\n\n"\
    "=====================================\n"\
    "          W A T C H I N G . . .      \n"\
    "=====================================\n"\
    "\n"
  );
}

void connected(){
  printf(
    "\n\n"\
    "=====================================\n"\
    "           C O N N E C T E D         \n"\
    "=====================================\n"\
    "\n"
  );
}

void disconnected(){
  printf(
    "\n\n"\
    "=====================================\n"\
    "       D I S C O N N E C T E D       \n"\
    "=====================================\n"\
    "\n"
  );
}

void serving() {
  printf(
    "\n\n"\
    "=====================================\n"\
    " S E R V I N G   F R O M   F L A S K \n"\
    "=====================================\n"\
    "\n"
  );
}

void stopped() {
  printf(
    "\n\n"\
    "=====================================\n"\
    "     S T O P P E D   C A R A F E     \n"\
    "=====================================\n"\
    "\n"
  );
}


int main(int argc, char * argv[]) {
    // insert code here...
    int env = 0, watch = 0;
    char _env[10], _watch[10];
    _env[0] = _watch[0] = '\0';
    //printf("%i\n", argc);
    if (strcmp(argv[1], "up") == 0) {
              for (int i =0; i<argc; i++){
                  if (StartsWith(argv[i], "--watch") != 0)
                  {
                    watch = 1;
                    strncpy(_watch, argv[i]+7, strlen(argv[i]));
                  }

                  if (StartsWith(argv[i], "--env=") != 0)
                  {
                    env = 1;
                    strncpy(_env, argv[i]+6, strlen(argv[i]));
                  }
              }

              if ((strcmp(_env, "dev") == 0 || !env) && watch){
                serving();
                watching();
                system("./scripts/down &> /dev/null");
                system("./scripts/dev");
                stopped();
              }

              if ((strcmp(_env, "dev") == 0 || !env) && !watch){
                system("./scripts/down &> /dev/null");
                system("./scripts/devd &> /dev/null");
                serving();
              }
    } else if (strcmp(argv[1], "down") == 0 || strcmp(argv[1], "stop") == 0) {
      system("./scripts/down &> /dev/null");
      stopped();
    } else if (strcmp(argv[1], "ssh") == 0) {
      connected();
      system("./scripts/ssh");
      disconnected();
    }



    return 0;
}
