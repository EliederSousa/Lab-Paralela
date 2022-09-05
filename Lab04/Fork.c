#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

void  processoFilho(int []);

void  main(int  argc, char *argv[]) {
    int    ShmID;
    int    *ShmPTR;
    pid_t  pid;
    int    status;
    
    if (argc != 2) {
        printf("Entre com um argumento ao rodar o programa!", argv[0]);
        exit(1);
    }
    
    ShmID = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (ShmID < 0) {
        printf("Erro no shmget.\n");
        exit(1);
    }
    printf("Servidor iniciado.\n");
    
    ShmPTR = (int *) shmat(ShmID, NULL, 0);
    if ((int) ShmPTR == -1) {
        printf("Erro no shmget.\n");
        exit(1);
    }
    printf("Servidor conectado à memória compartilhada.\n");
    
    ShmPTR[0] = atoi(argv[1]);
    printf("Valor %d foi colocado na memória compartilhada.", ShmPTR[0]);
    
    printf("Criando um processo filho por fork().\n");
    pid = fork();
    if (pid < 0) {
        printf("Erro ao criar o fork().\n");
        exit(1);
    } else if (pid == 0) {
        processoFilho(ShmPTR);
        exit(0);
    }

    wait(&status);
    printf("Servidor detectou o término do processo filho.\n");
    // Utiliza o valor modificado pelo processo filho, adicionando +20.
    ShmPTR[0] += 20;
    printf("Valor final na memória: %d\n", ShmPTR[0]);
    shmdt((void *) ShmPTR);
    // Desacopla a memória compartilhada.
    shmctl(ShmID, IPC_RMID, NULL);
    printf("Servidor finalizado.\n");
    exit(0);
}

void processoFilho(int SharedMem[]) {
    // Quadriplica o valor armazenado na memória compartilhada, somando +1.
    printf("---- Processo filho iniciado\n");
    printf("---- Valor armazenado: %d\n", SharedMem[0]);
    SharedMem[0] *= 4;
    SharedMem[0] += 1;
    printf("---- Finalizando processo filho\n");
}
