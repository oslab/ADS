#include <stdio.h>
#include <stdbool.h>

#define N 4

bool prefers(int preferences[N][N], int w, int m, int currentPartner[]) {
    for (int i = 0; i < N; i++) {
        if (preferences[w][i] == m)
            return true;
        if (preferences[w][i] == currentPartner[w])
            return false;
    }
    return false;
}

void stableMarriage(int preferences[N][N]) {
    int currentPartner[N] = {-1};
    bool freeMen[N] = {true};
    int engagedCount = 0;

    while (engagedCount < N) {
        int m;
        for (m = 0; m < N; m++) {
            if (freeMen[m])
                break;
        }

        for (int i = 0; i < N && freeMen[m]; i++) {
            int w = preferences[m][i];
            if (currentPartner[w] == -1) {
                currentPartner[w] = m;
                freeMen[m] = false;
                engagedCount++;
            } else {
                int currentPartnerM = currentPartner[w];
                if (prefers(preferences, w, m, currentPartner)) {
                    currentPartner[w] = m;
                    freeMen[m] = false;
                    freeMen[currentPartnerM] = true;
                }
            }
        }
    }

    printf("Stable marriages:\n");
    for (int i = 0; i < N; i++) {
        printf("Woman %d is married to Man %d\n", i, currentPartner[i]);
    }
}

int main() {
    int preferences[N][N] = {
        {1, 0, 3, 2},
        {3, 1, 0, 2},
        {0, 1, 3, 2},
        {1, 0, 3, 2}
    };

    stableMarriage(preferences);
    return 0;
}

