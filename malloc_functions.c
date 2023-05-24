#include "monty.h"
/**
 * _calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */

#define MAX_STACK_SIZE 100

typedef struct {
  int data[MAX_STACK_SIZE];
  int top;
} Stack;

void push(Stack *stack, int value) {
  if (stack->top == MAX_STACK_SIZE) {
    fprintf(stderr, "Stack overflow\n");
    exit(EXIT_FAILURE);
  }

  stack->data[stack->top++] = value;
}

void pall(Stack *stack) {
  if (stack->top == 0) {
    return;
  }

  for (int i = stack->top - 1; i >= 0; i--) {
    printf("%d\n", stack->data[i]);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  Stack stack;
  stack.top = 0;

  char line[100];
  while (fgets(line, sizeof(line), file)) {
    char *opcode = strtok(line, " ");

    if (strcmp(opcode, "push") == 0) {
      int value;
      if (sscanf(line, "%d", &value) != 1) {
        fprintf(stderr, "Error: Invalid push instruction\n");
        exit(EXIT_FAILURE);
      }

      push(&stack, value);
    } else if (strcmp(opcode, "pall") == 0) {
      pall(&stack);
    } else {
      fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
      exit(EXIT_FAILURE);
    }
  }

  fclose(file);

  return 0;
}
