#include "deQue.h"

int main(void)
{
    DQueType* DQ1 = createDQue(); // µ¥Å© »ý¼º[cite: 4]
    element data;

    printf("\n ***** µ¥Å© ¿¬»ê ***** \n");
    printf("\n front »ðÀÔ A>> "); insertFront(DQ1, 'A'); printDQ(DQ1);
    printf("\n front »ðÀÔ B>> "); insertFront(DQ1, 'B'); printDQ(DQ1);
    printf("\n rear  »ðÀÔ C>> "); insertRear(DQ1, 'C');  printDQ(DQ1);
    printf("\n front »èÁ¦  >> "); data = deleteFront(DQ1); printDQ(DQ1);
    printf("\t»èÁ¦ µ¥ÀÌÅÍ: %c\n", data);
    printf("\n rear  »èÁ¦  >> "); data = deleteRear(DQ1);  printDQ(DQ1);
    printf("\t»èÁ¦ µ¥ÀÌÅÍ: %c\n", data);
    printf("\n rear  »ðÀÔ D>> "); insertRear(DQ1, 'D');  printDQ(DQ1);
    printf("\n front »ðÀÔ E>> "); insertFront(DQ1, 'E'); printDQ(DQ1);
    printf("\n front »ðÀÔ F>> "); insertFront(DQ1, 'F'); printDQ(DQ1);

    data = peekFront(DQ1); printf("\n peek Front item : %c \n", data);
    data = peekRear(DQ1);  printf(" peek Rear item : %c \n", data);

    getchar(); return 0;
}
