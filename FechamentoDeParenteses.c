#include <stdio.h>
#include "pilhas.h"

int main()
{
    char abrir[] = {'(', '[', '{'};
    char fechar[] = {')', ']', '}'};
    char caract;
    STACK* Seq;
    Seq = Inicializar(Seq);

    printf("Digite a sequência: \n");

    Seq = Inicializar(Seq);

    do
    {
        int i;
  
        scanf("%c", &caract);

        for (i = 0; i < 3; i++)
        {
            if (caract == abrir[i])
            {
                PUSH(Seq, i);
                break;
            }
        }

        if (i == 3)
        {
            for(int j = 0; j < 3; j++)
            {
                if(caract == fechar[j])
                {

                    if (POP(Seq) != j)
                    {
                        Liberar(Seq);
                        return 0;
                    }

                    break;
                }
            }
        }
    } while (caract != '\n');

    if (Seq -> TOPO != NULL)
    {
    	Liberar(Seq)
        return 0;
    }

    Liberar(Seq);
    return 1;
}
