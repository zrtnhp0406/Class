#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SORT_BY_ARRIVAL 0
#define SORT_BY_PID 1
#define SORT_BY_BURST 2
#define SORT_BY_START 3

typedef struct {
    int iPID;
    int iArrival, iBurst;
    int iStart, iFinish, iWaiting, iResponse, iTaT;
} PCB;

void inputProcess(int n, PCB P[]) {
    for (int i = 0; i < n; i++) {
        printf("Input PID of %d-th process: ", i + 1);
        scanf("%d", &P[i].iPID);
        printf("Input Arrival time of %d process: ", P[i].iPID);
        scanf("%d", &P[i].iArrival);
        printf("Input Burst time %d process: ", P[i].iPID);
        scanf("%d", &P[i].iBurst);
    }
}

void printProcess(int n, PCB P[]) {
    for (int i = 0; i < n; i++) {
        printf("===== P%d =====\n", P[i].iPID);
        printf("Start time: %d\n", P[i].iStart);
        printf("Finish time: %d\n", P[i].iFinish);
        printf("Waiting time: %d\n", P[i].iWaiting);
        printf("Response time: %d\n", P[i].iResponse);
        printf("Turnaround time: %d\n", P[i].iTaT);
    }
}

void exportGanttChart(int n, PCB P[]) {
    int i, j;
    printf("\nGantt Chart:\n");

    // In biểu đồ Gantt
    for (i = 0; i < n; i++) {
        printf("| P%d ", P[i].iPID);
    }
    printf("|\n");

    // In thời gian bắt đầu và kết thúc
    printf("%d ", P[0].iStart);
    for (i = 0; i < n; i++) {
        printf("%d ", P[i].iFinish);
    }
    printf("\n");
}

void pushProcess(int *n, PCB P[], PCB Q) {
    P[(*n)] = Q;
    ++(*n);
}

void removeProcess(int *n, int index, PCB P[]) {
    for (int i = index; i < (*n) - 1; i++) {
        P[i] = P[i + 1];
    }
    --(*n);
}

void swapProcess(PCB *P, PCB *Q) {
    PCB temp = *P;
    *P = *Q;
    *Q = temp;
}

int partition(PCB P[], int low, int high, int iCriteria) {
    PCB pivot = P[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        int condition = 0;
        if (iCriteria == SORT_BY_ARRIVAL) {
            condition = P[j].iArrival < pivot.iArrival;
        } else if (iCriteria == SORT_BY_PID) {
            condition = P[j].iPID < pivot.iPID;
        } else if (iCriteria == SORT_BY_BURST) {
            condition = P[j].iBurst < pivot.iBurst;
        } else if (iCriteria == SORT_BY_START) {
            condition = P[j].iStart < pivot.iStart;
        }

        if (condition) {
            i++;
            swapProcess(&P[i], &P[j]);
        }
    }
    swapProcess(&P[i + 1], &P[high]);
    return (i + 1);
}

void quickSort(PCB P[], int low, int high, int iCriteria) {
    if (low < high) {
        int pi = partition(P, low, high, iCriteria);

        quickSort(P, low, pi - 1, iCriteria);
        quickSort(P, pi + 1, high, iCriteria);
    }
}

void calculateAWT(int n, PCB P[]) {
    printf("\nProcess & Waiting Time\n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("\nP%d %d\n", P[i].iPID, P[i].iWaiting);
        sum += P[i].iWaiting;
    }
    printf("\nAWT: %.5f\n", 1.0 * sum / n);
}

void calculateATaT(int n, PCB P[]) {
    printf("\nProcess & Turnaround Time\n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d %d\n", P[i].iPID, P[i].iTaT);
        sum += P[i].iTaT;
    }
    printf("\nATaT: %.5f\n", 1.0 * sum / n);
}

void calculateART(int n, PCB P[]) {
    printf("\nProcess & Response Time\n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d %d\n", P[i].iPID, P[i].iResponse);
        sum += P[i].iResponse;
    }
    printf("\nART: %.5f\n", 1.0 * sum / n);
}

int main() {
    PCB Input[10];
    PCB ReadyQueue[10];
    PCB TerminatedArray[10];
    int iNumberOfProcess=0;

    printf("Please input number of Process: ");
    scanf("%d", &iNumberOfProcess);
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0;

    inputProcess(iNumberOfProcess, Input);

    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL);

    pushProcess(&iReady, ReadyQueue, Input[0]);

    removeProcess(&iRemain, 0, Input);

    ReadyQueue[0].iStart = ReadyQueue[0].iArrival;
    ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst;
    ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival;
    ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
    ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival;

    printf("\nReady Queue: ");
    printProcess(1, ReadyQueue);

    while (iTerminated < iNumberOfProcess) {
     // Đẩy các tiến trình từ Input sang ReadyQueue nếu đã đến
         bool flag=false;
         while (iRemain > 0) {
             if (Input[0].iArrival <= ReadyQueue[0].iFinish) {
                pushProcess(&iReady, ReadyQueue, Input[0]);
                removeProcess(&iRemain, 0, Input);
                flag=true;
                continue;
             }
         else {


            break;
            }
         }
         // Sắp xếp ReadyQueue theo Burst Time tru ReadyQueue[0] da duoc xu ly
            if(flag== true){
                quickSort(ReadyQueue, 1, iReady - 1, SORT_BY_BURST);
             }
    // Xử lý tiến trình có Burst Time nhỏ nhất
    if (iReady > 0) {
        pushProcess(&iTerminated, TerminatedArray, ReadyQueue[0]);
        removeProcess(&iReady, 0, ReadyQueue);

        if (iReady > 0) {
            ReadyQueue[0].iStart = TerminatedArray[iTerminated - 1].iFinish;
            ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst;
            ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival;
            ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
            ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival;
        }
    }
}


    printf("\n===== SJF Scheduling =====\n");
    exportGanttChart(iTerminated, TerminatedArray);
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);

    printProcess(iTerminated, TerminatedArray);

    calculateART(iTerminated, TerminatedArray);
    calculateAWT(iTerminated, TerminatedArray);
    calculateATaT(iTerminated, TerminatedArray);
    printf("\n");
    return 0;
}