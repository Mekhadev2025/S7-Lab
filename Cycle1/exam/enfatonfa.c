 #include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 3  // For alphabets a, b, c

void epsilonClosure(int state, int nfa_with_e[MAX_STATES][MAX_ALPHABET + 1], int closure[], int visited[], int num_states) {
    if (visited[state]) return;
    visited[state] = 1;
    closure[state] = 1;  // Add this state to its own closure
    if (nfa_with_e[state][MAX_ALPHABET] != -1) {  // Check for epsilon transitions
        epsilonClosure(nfa_with_e[state][MAX_ALPHABET], nfa_with_e, closure, visited, num_states);
    }
}

void convertToNFAWithoutEpsilon(int nfa_with_e[MAX_STATES][MAX_ALPHABET + 1], int num_states) {
    int epsilon_closure[MAX_STATES][MAX_STATES] = {0};  // Each state's ε-closure

    // Calculate epsilon-closure for each state
    for (int i = 0; i < num_states; i++) {
        int visited[MAX_STATES] = {0};
        epsilonClosure(i, nfa_with_e, epsilon_closure[i], visited, num_states);
    }

    // Print start state
    printf("Start state: {");
    for (int i = 0; i < num_states; i++) {
        if (epsilon_closure[0][i]) printf("q%d,", i + 1);
    }
    printf("}\n");

    // Print transitions
    printf("Transitions:\n");
    for (int state = 0; state < num_states; state++) {
        for (int symbol = 0; symbol < MAX_ALPHABET; symbol++) {
            printf("{");
            for (int i = 0; i < num_states; i++) {
                if (epsilon_closure[state][i]) printf("q%d,", i + 1);
            }
            printf("}   %c   ->   {", 'a' + symbol);

            int result_closure[MAX_STATES] = {0};
            for (int i = 0; i < num_states; i++) {
                if (epsilon_closure[state][i] && nfa_with_e[i][symbol] != -1) {
                    int next_state = nfa_with_e[i][symbol];
                    for (int j = 0; j < num_states; j++) {
                        if (epsilon_closure[next_state][j]) result_closure[j] = 1;
                    }
                }
            }

            for (int i = 0; i < num_states; i++) {
                if (result_closure[i]) printf("q%d,", i + 1);
            }
            printf("}\n");
        }
    }

    // Print final states
    printf("Final states: ");
    for (int state = 0; state < num_states; state++) {
        int is_final = 0;
        for (int i = 0; i < num_states; i++) {
            if (epsilon_closure[state][i]) is_final = 1;
        }
        if (is_final) {
            printf("{");
            for (int i = 0; i < num_states; i++) {
                if (epsilon_closure[state][i]) printf("q%d,", i + 1);
            }
            printf("}  ");
        }
    }
    printf("\n");
}

int main() {
    int nfa_with_e[MAX_STATES][MAX_ALPHABET + 1];
    int num_states, transitions;

    // Initialize NFA with -1 (no transitions)
    memset(nfa_with_e, -1, sizeof(nfa_with_e));

    printf("Enter number of states: ");
    scanf("%d", &num_states);

    printf("Enter number of transitions: ");
    scanf("%d", &transitions);

    printf("Enter transitions (state symbol next_state) where symbol is a/b/c/e (for epsilon):\n");
    for (int i = 0; i < transitions; i++) {
        int state, next_state;
        char symbol;
        scanf("%d %c %d", &state, &symbol, &next_state);
        if (symbol == 'e') {
            nfa_with_e[state][MAX_ALPHABET] = next_state;  // Store epsilon transition
        } else {
            nfa_with_e[state][symbol - 'a'] = next_state;
        }
    }

    convertToNFAWithoutEpsilon(nfa_with_e, num_states);

    return 0;
}
