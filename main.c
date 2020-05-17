#include "menu.h"
#include "student.h"
//#include "teacher.h"
#include "comm.h"

int main()
{
    node_t *stulist = NULL;
    node_t *tchlist = NULL;
    stulist = loadstu();
    while (1)
    {
        if (login_menu(stulist, tchlist) == 0)
            break;
    }
  
    return 0;
}
